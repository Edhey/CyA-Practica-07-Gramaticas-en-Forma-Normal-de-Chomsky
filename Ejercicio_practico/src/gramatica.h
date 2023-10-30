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
 * @file gramatica.h
 * @brief Declaración de los métodos de la clase Gramatica
 * @bug No hay errores conocidos
 * @see https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "alfabeto.h"

#include <map>
#include <vector>
#include <sstream>

/**
 * @brief Clase que define y trabaja con una gramática.
 */
class Gramatica {
 public:
  Gramatica();
  Gramatica(std::string nombre_archivo_de_entrada);
  friend std::ostream& operator<<(std::ostream& out, const Gramatica& gramatica);
 private:
  Alfabeto simbolos_terminales_;
  Alfabeto simbolos_no_terminales_;
  Simbolo simbolo_de_arranque_;
  std::multimap<Simbolo, std::vector<Simbolo>> producciones_;
};

#endif  // GRAMATICA_H

