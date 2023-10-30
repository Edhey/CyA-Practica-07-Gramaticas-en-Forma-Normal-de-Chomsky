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
 * @file tools.h
 * @brief Declaración de las funciones Introduccion y
 * CompruebaParametrosCorrectos
 * @bug No hay errores conocidos
 * @see https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#ifndef TOOLS_H
#define TOOLS_H

#include <cstring>
#include <iostream>

void Introduccion();
bool CompruebaParametrosCorrectos(const int argc, char *argv[],
                                  const int kParametrosCorrectos);

#endif