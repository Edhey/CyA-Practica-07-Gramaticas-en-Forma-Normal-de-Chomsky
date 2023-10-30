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
 * @file alfabeto.h
 * @brief Declaración de los métodos de la clase Alfabeto
 * @bug No hay errores conocidos
 * @see https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#ifndef ALFABETO_H
#define ALFABETO_H

#include <fstream>
#include <iostream>
#include <map>
#include <set>

#include "cadena.h"
#include "simbolo.h"

class Cadena;  // Declaración adelantada de la clase Cadena para evitar
               // dependencia circular

/**
 * @brief Clase que define y trabaja con un alfabeto (conjunto de simbolos).
 */
class Alfabeto {
public:
  Alfabeto();
  Alfabeto(Simbolo simbolo);
  Alfabeto(Cadena cadena);
  bool ComprobarSimbolo(Simbolo simbolo);
  void InsertarSimbolo(const Simbolo simbolo_nuevo);
  friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto);
  std::set<Simbolo> getAlfabeto() const { return alfabeto_; }
private:
  std::set<Simbolo> alfabeto_;
};

#endif  // ALFABETO_H
