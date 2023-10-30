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
    std::vector<Simbolo> produccion_aux;
    // Se comprueban que todos los símbolos de la producción sean válidos.
    while (iterador < produccion_str.size()) {
      while (!simbolos_terminales_.ComprobarSimbolo(produccion_str_aux) &&
             !simbolos_no_terminales_.ComprobarSimbolo(produccion_str_aux) &&
             !produccion_str_aux.empty()) {
        produccion_str_aux.pop_back();
      }
      if (!produccion_str_aux.empty()) {
        produccion_aux.push_back(Simbolo(produccion_str_aux));
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
        std::pair<Simbolo, std::vector<Simbolo>>(no_terminal, produccion_aux));
    produccion_aux.clear();
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
 * @brief Sobrecarga del operador de inserción de flujo para imprimir un objeto
 * Gramatica en un flujo de salida.
 * @param out Flujo de salida en el que se imprimirá el objeto Gramatica.
 * @param gramatica Objeto Gramatica que se imprimirá en el flujo de salida.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Gramatica& gramatica) {
  out << "Símbolos terminales: " << gramatica.simbolos_terminales_ << std::endl;
  out << "Símbolos no terminales: " << gramatica.simbolos_no_terminales_
      << std::endl;
  out << "Símbolo de arranque: " << gramatica.simbolo_de_arranque_ << std::endl;
  out << "Producciones: " << std::endl;
  for (auto it = gramatica.producciones_.begin();
       it != gramatica.producciones_.end(); ++it) {
    out << it->first << " -> ";
    for (auto& simbolo : it->second) {
      out << simbolo;
    }
    out << std::endl;
  }
  return out;
}