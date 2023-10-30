/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7: Gramaticas en Forma Normal de Chomsky
 * @author Himar Edhey Hernández Alonso
 * Correo: alu0101552392@ull.edu.es
 * @date Oct 15 2023
 * @date Oct 29 2023
 * @brief Definición de los métodos de la clase Alfabeto
 * @bug No hay errores conocidos
 * @see https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#include "alfabeto.h"

/**
 * @brief Constructor predeterminado de la clase Alfabeto.
 */
Alfabeto::Alfabeto() {}

/**
 * @brief Constructor con parámetro del tipo Simbolo para la clase Alfabeto.
 * @param simbolo Es el objeto tipo Simbolo con el que se inicializa el
 * Alfabeto.
 */
Alfabeto::Alfabeto(Simbolo simbolo) { alfabeto_.insert(simbolo); }

/**
 * @brief Constructor con parámetro tipo Cadena de la clase Alfabeto.
 * @param cadena Es el objeto tipo Cadena con el que se inicializa el Alfabeto.
 */
Alfabeto::Alfabeto(Cadena cadena) {
  for (std::size_t i{0}; i < cadena.getCadena().size(); ++i) {
    alfabeto_.insert(cadena.getCadena()[i]);
  }
}

/**
 * @brief Método que permite insertar un nuevo Simbolo al Alfabeto
 * @param simbolo_nuevo Es el objeto Simbolo a insertar.
 */
void Alfabeto::InsertarSimbolo(const Simbolo simbolo_nuevo) {
  alfabeto_.insert(simbolo_nuevo);
}

/**
 * @brief Sobrecarga del operador de inserción de flujo para imprimir un objeto
 * Alfabeto en un flujo de salida.
 * @param out Flujo de salida en el que se imprimirá el objeto Alfabeto.
 * @param alfabeto Objeto Alfabeto que se imprimirá en el flujo de salida.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto) {
  out << "{";
  std::size_t numero_de_simbolos{1};
  for (auto& simbolo : alfabeto.alfabeto_) {
    out << simbolo;
    if (numero_de_simbolos != alfabeto.alfabeto_.size())
      out << ", ";
    ++numero_de_simbolos;
  }
  out << "}";
  return out;
}

/**
 * @brief Método que comprueba si un Simbolo pertenece al Alfabeto.
 * @param simbolo_ Es el Simbolo a comprobar.
 * @return true en caso de que pertenezca.
 *         false en caso contrario.
 */
bool Alfabeto::ComprobarSimbolo(Simbolo simbolo_) {
  for (auto& simbolo : this->alfabeto_) {
    if (simbolo == simbolo_)
      return true;
  }
  return false;
}
