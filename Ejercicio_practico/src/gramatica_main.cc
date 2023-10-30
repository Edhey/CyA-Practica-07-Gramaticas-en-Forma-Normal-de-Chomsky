/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 5: Simulador autómatas finitos
 * @author Himar Edhey Hernández Alonso
 * Correo: alu0101552392@ull.edu.es
 * @date Oct 15 2023
 * @file simulador_automatas_main.cc: programa cliente.
 * @brief Programa que
 * @bug No hay errores conocidos
 * @see
 * https://github.com/Edhey/CyA-Practica-06-Algoritmo-de-construccion-de-subconjuntos
 * * Historial de revisiones:
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "gramatica.h"
#include "tools.h"

/**
 * @brief Función main
 */
int main(int argc, char* argv[]) {
  int numero_de_parametros{2};
  if (!CompruebaParametrosCorrectos(argc, argv, numero_de_parametros)) {
    return 1;
  }
  std::string fichero_gramatica{argv[1]};
  Gramatica gramatica(fichero_gramatica);
  std::cout << "Gramatica: " << std::endl << gramatica;
  Gramatica formal_normal_de_chomsky = gramatica.FormalNormalDeChomsky();
  std::cout << "Forma normal de Chomsky: " << std::endl
            << formal_normal_de_chomsky;
  return 0;
}