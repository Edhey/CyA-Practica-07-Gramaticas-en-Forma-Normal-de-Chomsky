/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramaticas en Forma Normal de Chomsky
 * @author Himar Edhey Hernández Alonso
 * Correo: alu0101552392@ull.edu.es
 * @date Oct 29 2023
 * @file cadena.cc
 * @brief Definición de los métodos de la clase Cadena
 * @bug No hay errores conocidos
 * @see
 * https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#include "cadena.h"

/**
 * @brief Constructor predeterminado. Añade la cadena vacía en caso de no tener
 * entrada.
 */
Cadena::Cadena() { this->cadena_.push_back(Simbolo("&")); }

/**
 * @brief Constructor para una std::string.
 * @param cadena Es la string con la que inicializa la cadena.
 */
Cadena::Cadena(std::string cadena) {
  this->cadena_.clear();
  for (int i{0}; i < cadena.size(); ++i) {
    if (cadena[i] != '&') {
      cadena_.push_back(cadena[i]);
    }
  }
  if (cadena_.empty()) {
    cadena_.push_back(Simbolo("&"));
  }
}

/**
 * @brief Getter para el objeto cadena_.
 * @return Devuelve una referencia a cadena_.
 */
std::vector<Simbolo>& Cadena::getCadena() const {
  std::vector<Simbolo>& cadena_aux = const_cast<std::vector<Simbolo>&>(cadena_);
  return cadena_aux; 
}

/**
 * @brief Sobrecarga del operador == para comparar dos objetos Cadena.
 * @param cadena_a_comparar Es la cadena con la que se compara.
 * @return Devuélve true si las cadenas son iguales, false en el caso contrario.
 */
bool Cadena::operator==(const Cadena cadena_a_comparar) const {
  return cadena_ == cadena_a_comparar.cadena_;
}

/**
 * @brief Método que permite concatenar un simbolo a la cadena.
 * @param simbolo Es el simbolo a concatenar.
 */
void Cadena::ConcatenarSimbolo(const Simbolo& simbolo) {
  const Simbolo ampersand("&");
  if (simbolo == ampersand)
    return;
  if (cadena_.size() == 1 && cadena_[0] == ampersand) {
    cadena_.clear();
  }
  for (int i{0}; i < simbolo.getSimbolo().size(); ++i) {
    if (simbolo.getSimbolo()[i] != '&')
      cadena_.push_back(simbolo.getSimbolo()[i]);
  }
}

/**
 * @brief Sobrecarga del operador de inserción de flujo para imprimir un objeto
 * Cadena en un flujo de salida.
 * @param out Flujo de salida en el que se imprimirá el objeto Cadena.
 * @param cadena Objeto Cadena que se imprimirá en el flujo de salida.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Cadena& cadena) {
  for (auto& elemento : cadena.cadena_) {
    out << elemento;
  }
  return out;
}

/**
 * @brief Sobrecarga del operador de extracción de flujo para leer un objeto
 * Cadena desde un flujo de entrada.
 * @param in Flujo de entrada desde el que se leerá el objeto Cadena.
 * @param cadena Objeto Cadena en el que se almacenarán los valores
 * leídos desde el flujo de entrada.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& in, Cadena& cadena) {
  Simbolo simbolo;
  in >> simbolo;
  cadena.cadena_.clear();
  if (simbolo != "&") {
    cadena.cadena_.push_back(simbolo);
  }
  return in;
}

/**
 * @brief Método de la clase Cadena que devuelve longuitud de la cadena de
 * entrada.
 * @return Devuélve un int con la longuitud de la cadena guardada.
 */
int Cadena::Longuitud() {
  for (auto& simbolo : cadena_) {
    if (simbolo == "&") {
      return cadena_.size() - 1;
    }
  }
  return cadena_.size();
}
/**
 * @brief Método de la clase Cadena que invierte una cadena.
 * @return Devuelve la cadena guardada invertida.
 */
Cadena Cadena::Inversa() {
  std::vector<Simbolo> vector_cadena_inversa = cadena_;
  std::reverse(vector_cadena_inversa.begin(), vector_cadena_inversa.end());
  Cadena cadena_inversa(vector_cadena_inversa);
  return cadena_inversa;
}

/**
 * @brief Método de la clase Cadena que imprime en un archivo de salida los
 * prefijos de la cadena guardada.
 * @param nombre_archivo_de_salida Es el nombre del archivo donde se imprimirán
 * los prefijos.
 */
void Cadena::Prefijos(std::string nombre_archivo_de_salida) {
  std::ofstream archivo_de_salida{nombre_archivo_de_salida, std::ios::app};
  if (!archivo_de_salida) {
    std::cerr << "Oh no, ocurrió un error en " << nombre_archivo_de_salida
              << " ¡No se pudo abrir el archivo!" << std::endl;
    return;
  }
  archivo_de_salida << "{&";
  for (std::size_t i{0}; i < cadena_.size(); ++i) {
    std::size_t contador_de_simbolos{0};
    archivo_de_salida << ", ";
    while (contador_de_simbolos <= i) {
      archivo_de_salida << cadena_[contador_de_simbolos];
      ++contador_de_simbolos;
    }
  }
  archivo_de_salida << "}" << std::endl;
}

/**
 * @brief Método de la clase Cadena que imprime en un archivo de salida los
 * sufijos de la cadena guardada.
 * @param nombre_archivo_de_salida Es el nombre del archivo donde se imprimirán
 * los sufijos.
 */
void Cadena::Sufijos(std::string nombre_archivo_de_salida) {
  std::ofstream archivo_de_salida{nombre_archivo_de_salida, std::ios::app};
  if (!archivo_de_salida) {
    std::cerr << "Oh no, ocurrió un error en " << nombre_archivo_de_salida
              << " ¡No se pudo abrir el archivo!" << std::endl;
    return;
  }
  archivo_de_salida << "{&";
  for (int i{cadena_.size() - 1}; i >= 0; --i) {
    int contador_de_simbolos{i};
    archivo_de_salida << ", ";
    while (contador_de_simbolos < cadena_.size()) {
      archivo_de_salida << cadena_[contador_de_simbolos];
      ++contador_de_simbolos;
    }
  }
  archivo_de_salida << "}" << std::endl;
}

/**
 * @brief Método de la clase Cadena que limpia la cadena guardada.
 */
void Cadena::Clear() {
  cadena_.clear();
  cadena_.push_back(Simbolo("&"));
}

// std::set<Simbolo, ComparacionPorLonguitud> Cadena::Prefijos() {
//   std::set<Simbolo, ComparacionPorLonguitud> prefijos;
//   Simbolo ampersand("&");
//   prefijos.insert(ampersand);
//   Simbolo prefijo;
//   for (std::size_t i{0}; i < cadena_.size(); ++i) {
//     prefijo = prefijo + cadena_[i];
//     prefijos.insert(prefijo);
//   }
//   return prefijos;
// }

// std::set<Simbolo, ComparacionPorLonguitud> Cadena::Sufijos() {
//   std::set<Simbolo, ComparacionPorLonguitud> sufijos;
//   Simbolo simbolo_ampersand("&");
//   sufijos.insert(simbolo_ampersand);
//   Simbolo sufijo;
//   for (int i{cadena_.size() - 1}; i >= 0; --i) {
//     sufijo = sufijo + cadena_[i];
//     sufijos.insert(sufijo);
//   }
//   return sufijos;
// }