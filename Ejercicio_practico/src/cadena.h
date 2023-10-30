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
 * @file cadena.h
 * @brief Declaración de los métodos de la clase Cadena
 * @bug No hay errores conocidos
 * @see https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#ifndef CADENA_H
#define CADENA_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "alfabeto.h"
#include "simbolo.h"

class Alfabeto;  // Declaración adelantada de la clase Alfabeto para evitar
                 // dependencia circular

// struct ComparacionPorLonguitud {
//   bool operator()(const Simbolo& simbolo_1, const Simbolo& simbolo_2) const {
//     if (simbolo_1.getSimbolo().size() < simbolo_2.getSimbolo().size() ||
//         simbolo_1.getSimbolo() == "&")
//       return true;
//     return false;
//   }
// };

/**
 * @brief Clase que define y trabaja con cadenas(Secuencias de simbolos).
 */
class Cadena {
public:
  Cadena();
  Cadena(char simbolo) : cadena_(1, simbolo) {}
  Cadena(Simbolo simbolo) : cadena_(1, simbolo) {}
  Cadena(std::string cadena);
  Cadena(std::vector<Simbolo> vector_cadena) : cadena_(vector_cadena) {}
  std::vector<Simbolo> getCadena();
  void ConcatenarSimbolo(const Simbolo& simbolo);
  int Longuitud();
  Cadena Inversa();
  void Prefijos(std::string nombre_archivo_de_salida);
  // std::set<Simbolo, ComparacionPorLonguitud> Prefijos();
  void Sufijos(std::string nombre_archivo_de_salida);
  // std::set<Simbolo, ComparacionPorLonguitud> Sufijos();
  friend std::ostream& operator<<(std::ostream& out, const Cadena& cadena);
  friend std::istream& operator>>(std::istream& in, Cadena& cadena);
private:
  std::vector<Simbolo> cadena_;
};

#endif  // CADENA_H
