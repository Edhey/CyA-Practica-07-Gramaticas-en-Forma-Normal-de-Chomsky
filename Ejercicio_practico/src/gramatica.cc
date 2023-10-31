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
 * @file gramatica.cc
 * @brief Definición de los métodos de la clase Gramatica
 * @bug No hay errores conocidos
 * @see
 * https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#include "gramatica.h"

/**
 * @brief Constructor de la clase Gramatica a partir de un fichero.
 * @param nombre_fichero_gra 
 */
Gramatica::Gramatica(std::string nombre_fichero_gra) {
  std::ifstream fichero_gra{nombre_fichero_gra};
  if (!fichero_gra) {
    std::cerr << "Oh no, ocurrió un error en " << nombre_fichero_gra
              << " ¡No se pudo abrir el fichero!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::string datos;
  int numero_de_simbolos_terminales;
  std::getline(fichero_gra, datos);
  numero_de_simbolos_terminales = std::stoi(datos);
  for (int i{0}; i < numero_de_simbolos_terminales; ++i) {
    std::getline(fichero_gra, datos);
    Simbolo simbolo(datos);
    simbolos_terminales_.InsertarSimbolo(simbolo);
  }
  int numero_de_simbolos_no_terminales;
  std::getline(fichero_gra, datos);
  numero_de_simbolos_no_terminales = std::stoi(datos);
  // El número de símbolos no terminales debe ser mayor que 0.
  if (numero_de_simbolos_no_terminales == 0) {
    std::cerr
        << "Error. ¡La gramática necesita al menos un símbolo no terminal!"
        << std::endl;
    std::exit(EXIT_FAILURE);
  }
  for (int i{0}; i < numero_de_simbolos_no_terminales; ++i) {
    std::getline(fichero_gra, datos);
    Simbolo simbolo(datos);
    // Se comprueba que el símbolo no terminal no sea un símbolo terminal.
    if (simbolos_terminales_.ComprobarSimbolo(simbolo)) {
      std::cerr << "Error. ¡El símbolo no terminal " << simbolo
                << " ya está definido como terminal!" << std::endl;
      std::exit(EXIT_FAILURE);
    } else if (simbolo == Simbolo("&")) {
      std::cerr << "Error. ¡La cadena vacía " << simbolo
                << " no puede ser no terminal!" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    simbolos_no_terminales_.InsertarSimbolo(simbolo);
    if (i == 0)
      simbolo_de_arranque_ = simbolo;
  }
  int numero_de_producciones;
  std::getline(fichero_gra, datos);
  numero_de_producciones = std::stoi(datos);
  // El número de producciones debe ser mayor que 0.
  if (numero_de_producciones == 0) {
    std::cerr << "Error. ¡La gramática necesita al menos una producción!"
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
  for (int i{0}; i < numero_de_producciones; ++i) {
    std::getline(fichero_gra, datos);
    std::istringstream iss_datos(datos);
    std::string no_terminal_str;
    iss_datos >> no_terminal_str;
    Simbolo no_terminal(no_terminal_str);
    // Se comprueba que el símbolo no terminal de la producción sea válido.
    if (!simbolos_no_terminales_.ComprobarSimbolo(no_terminal)) {
      std::cerr << "Error. ¡El símbolo no terminal " << no_terminal
                << " no está definido!" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    std::string produccion_str;
    iss_datos >> produccion_str;
    // producciones_[no_terminal].push_back(Simbolo(produccion_str));
    int iterador = 0;
    std::string produccion_str_aux = produccion_str;
    Cadena produccion_aux;
    // Se comprueban que todos los símbolos de la producción sean válidos.
    while (iterador < produccion_str.size()) {
      while (!simbolos_terminales_.ComprobarSimbolo(produccion_str_aux) &&
             !simbolos_no_terminales_.ComprobarSimbolo(produccion_str_aux) &&
             !produccion_str_aux.empty()) {
        produccion_str_aux.pop_back();
      }
      if (!produccion_str_aux.empty()) {
        produccion_aux.ConcatenarSimbolo(Simbolo(produccion_str_aux));
        iterador += produccion_str_aux.size();
        produccion_str_aux =
            produccion_str.substr(iterador, produccion_str.size() - 1);
      } else {
        std::cerr << "Error. ¡La combinación de símbolos " << produccion_str
                  << " contiene símbolos no reconocidos por la gramática!"
                  << std::endl;
        std::exit(EXIT_FAILURE);
      }
    }
    producciones_.insert(
        std::pair<Simbolo, Cadena>(no_terminal, produccion_aux));
    produccion_aux.Clear();
  }
  //   std::string produccion_str;
  //   iss_datos >> produccion_str;
  //   producciones_[no_terminal].push_back(Simbolo(produccion_str));
  //   int iterador = 0;
  //   std::string produccion_str_aux = produccion_str;
  //   // Se comprueban que todos los símbolos de la producción sean válidos.
  //   while (iterador < produccion_str.size()) {
  //     while (!simbolos_terminales_.ComprobarSimbolo(produccion_str_aux) &&
  //            !simbolos_no_terminales_.ComprobarSimbolo(produccion_str_aux) &&
  //            !produccion_str_aux.empty()) {
  //       produccion_str_aux.pop_back();
  //     }
  //     if (!produccion_str_aux.empty()) {
  //       iterador += produccion_str_aux.size();
  //       produccion_str_aux =
  //           produccion_str.substr(iterador, produccion_str.size() - 1);
  //     } else {
  //       std::cerr << "Error. ¡La combinación de símbolos " << produccion_str
  //                 << " contiene símbolos no reconocidos por la gramática!"
  //                 << std::endl;
  //       std::exit(EXIT_FAILURE);
  //     }
  //   }
  // }
}

/**
 * @brief Método de la clase Gramatica que comprueba si existen producciones
 * vacías.
 * @return Devuelve true si existen producciones vacías, false en caso
 * contrario.
 */
bool Gramatica::ExistenProduccionesVacias() {
  for (auto& produccion : producciones_) {
    if (produccion.first != simbolo_de_arranque_ &&
        produccion.second == Cadena("&"))
      return true;
  }
  return false;
}

/**
 * @brief Método de la clase Gramatica que comprueba si existen producciones
 * unitarias.
 * @return Devuelve true si existen producciones unitarias, false en caso
 * contrario.
 */
bool Gramatica::ExistenProduccionesUnitarias() {
  for (auto& produccion : producciones_) {
    if (produccion.second.getCadena().size() == 1 &&
        simbolos_no_terminales_.ComprobarSimbolo(
            produccion.second.getCadena()[0]))
      return true;
  }
  return false;
}

/**
 * @brief Método de la clase Gramatica que devuelve la gramatica en Forma
 * Normal de Chomsky. 
 * @return Devuelve la gramatica en Forma Normal de Chomsky. 
 */
Gramatica Gramatica::FormalNormalDeChomsky() {
  if (this->ExistenProduccionesVacias()) {
    std::cerr << "Error. ¡No se pudo realizar la conversión a FNC!\nLa "
                 "gramática contiene producciones vacías"
              << std::endl;
    std::exit(EXIT_FAILURE);
  } else if (this->ExistenProduccionesUnitarias()) {
    std::cerr << "Error. ¡No se pudo realizar la conversión a FNC!\nLa "
                 "gramática contiene producciones unitarias"
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
  Gramatica gramatica_fnc = *this;
  for (auto& produccion : gramatica_fnc.producciones_) {
    if (produccion.second.getCadena().size() >= 2) {
      for (auto& simbolo : produccion.second.getCadena()) {
        if (simbolos_terminales_.ComprobarSimbolo(simbolo)) {
          Simbolo simbolo_aux = Simbolo("C" + simbolo.getSimbolo());
          if (!gramatica_fnc.simbolos_no_terminales_.ComprobarSimbolo(
                  simbolo_aux)) {
            gramatica_fnc.simbolos_no_terminales_.InsertarSimbolo(simbolo_aux);
            gramatica_fnc.producciones_.insert(
                std::pair<Simbolo, Cadena>(simbolo_aux, Cadena(simbolo)));
          }
          simbolo = simbolo_aux;
        }
      }
    }
  }
  int iterador = 0;
  for (auto it = gramatica_fnc.producciones_.begin();
       it != gramatica_fnc.producciones_.end();) {
    if (it->second.getCadena().size() >= 3) {
      for (int i{0}; i < (it->second.getCadena().size() - 2); ++i) {
        char iterador_char = 'D' + iterador;
        std::string simbolo = iterador_char + std::to_string(i + 1);
        Simbolo simbolo_aux = Simbolo(simbolo);
        Simbolo simbolo_aux_anterior =
            Simbolo(("D" + iterador) + std::to_string(i));
        // out << "Simbolo aux: " << simbolo_aux << std::endl;
        if (!gramatica_fnc.simbolos_no_terminales_.ComprobarSimbolo(
                simbolo_aux)) {
          gramatica_fnc.simbolos_no_terminales_.InsertarSimbolo(simbolo_aux);
        }
        Cadena cadena_aux;
        cadena_aux.ConcatenarSimbolo(it->second.getCadena()[i]);
        cadena_aux.ConcatenarSimbolo(simbolo);
        if (i == 0) {
          gramatica_fnc.producciones_.insert(
              std::pair<Simbolo, Cadena>(it->first.getSimbolo(), cadena_aux));
        } else {
          gramatica_fnc.producciones_.insert(
              std::pair<Simbolo, Cadena>(simbolo_aux_anterior, cadena_aux));
        }
        if (i == (it->second.getCadena().size() - 3)) {
          cadena_aux.Clear();
          cadena_aux.ConcatenarSimbolo(it->second.getCadena()[i + 1]);
          cadena_aux.ConcatenarSimbolo(it->second.getCadena()[i + 2]);
          gramatica_fnc.producciones_.insert(
              std::pair<Simbolo, Cadena>(simbolo_aux, cadena_aux));
          it = gramatica_fnc.producciones_.erase(it);
        }
      }
      // produccion.second.getCadena().clear();
      iterador++;
    } else {
      ++it;
    }
  }
  return gramatica_fnc;
}

/**
 * @brief Sobrecarga del operador de inserción de flujo para imprimir un objeto
 * Gramatica en un flujo de salida.
 * @param out Flujo de salida en el que se imprimirá el objeto Gramatica.
 * @param gramatica Objeto Gramatica que se imprimirá en el flujo de salida.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Gramatica& gramatica) {
  // out << "Símbolos terminales: " << gramatica.simbolos_terminales_ <<
  // std::endl;
  out << gramatica.simbolos_terminales_.getAlfabeto().size() << std::endl;
  for (auto& simbolo : gramatica.simbolos_terminales_.getAlfabeto()) {
    out << simbolo << std::endl;
  }
  // out << "Símbolos no terminales: " << gramatica.simbolos_no_terminales_
  // << std::endl;
  out << gramatica.simbolos_no_terminales_.getAlfabeto().size() << std::endl;
  out << gramatica.simbolo_de_arranque_ << std::endl;
  for (auto& simbolo : gramatica.simbolos_no_terminales_.getAlfabeto()) {
    if (simbolo != gramatica.simbolo_de_arranque_)
      out << simbolo << std::endl;
  }
  // out << "Símbolo de arranque: " << gramatica.simbolo_de_arranque_ <<
  // std::endl; out << "Producciones: " << std::endl;
  out << gramatica.producciones_.size() << std::endl;
  auto range =
      gramatica.producciones_.equal_range(gramatica.simbolo_de_arranque_);
  for (auto i = range.first; i != range.second; ++i) {
    out << i->first << " ";
    for (auto& simbolo : i->second.getCadena()) {
      out << simbolo;
    }
    out << std::endl;
  }
  for (auto it = gramatica.producciones_.begin();
       it != gramatica.producciones_.end(); ++it) {
    if (it->first != gramatica.simbolo_de_arranque_) {
      out << it->first << " ";
      for (auto& simbolo : it->second.getCadena()) {
        out << simbolo;
      }
      out << std::endl;
    }
  }
  return out;
}