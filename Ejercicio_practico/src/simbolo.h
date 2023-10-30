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
 * @file simbolo.h
 * @brief Declaración de los métodos de la clase Simbolo
 * @bug No hay errores conocidos
 * @see https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>

/**
 * @brief Clase que define un simbolo y proporciona herramientas para su uso.
 */
class Simbolo {
public:
  Simbolo();
  Simbolo(char simbolo) : simbolo_(1, simbolo) {};
  Simbolo(std::string simbolo) : simbolo_(simbolo) {};
  std::string getSimbolo() const;
  bool operator<(const Simbolo& nuevo_simbolo) const;
  Simbolo operator+(const char& nuevo_simbolo) const;
  Simbolo operator+(const Simbolo& nuevo_simbolo) const;
  Simbolo operator+(const std::string& nuevo_simbolo) const;
  bool operator==(const std::string& string_a_comparar) const;
  bool operator==(const Simbolo simbolo) const;
  bool operator!=(const std::string& string_a_comparar) const;
  bool operator!=(const Simbolo simbolo_comparar) const;
  void operator=(const Simbolo& nuevo_simbolo);
  void operator=(const std::string& nuevo_simbolo);
  void operator=(const char& nuevo_simbolo);
  friend std::istream& operator>>(std::istream& in, Simbolo& simbolo);
private:
  std::string simbolo_;
};

std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo);


#endif // SIMBOLO_H