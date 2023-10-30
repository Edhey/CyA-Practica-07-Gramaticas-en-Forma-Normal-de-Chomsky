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
 * @file simbolo.cc
 * @brief Definición de los métodos de la clase Simbolo
 * @bug No hay errores conocidos
 * @see https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#include "simbolo.h"

Simbolo::Simbolo() { simbolo_ = '&'; }

/**
 * @brief Getter para el atributo simbolo_.
 * @return Devuélve simbolo_.
 */
std::string Simbolo::getSimbolo() const { return simbolo_; }

/**
 * @brief Sobrecarga del operador< para los objetos Simbolo. La comparación se
 * realiza lexicográficamente.
 * @param nuevo_simbolo Es el simbolo que se compara según <.
 * @return Devuélve true si el objeto de la izquierda esta antes
 * (lexicográficamente) que el de la derecha, false en el caso contrario.
 */
bool Simbolo::operator<(const Simbolo& nuevo_simbolo) const {
  return this->getSimbolo() < nuevo_simbolo.getSimbolo();
}

/**
 * @brief Sobrecarga del operador + para Simbolos y char. Funciona como una
 * concatenación.
 * @param nuevo_simbolo Es el char a concatenar con el simbolo.
 * @return Devuélve el char concatenado al simbolo.
 */
Simbolo Simbolo::operator+(const char& nuevo_simbolo) const {
  return Simbolo(this->getSimbolo() + nuevo_simbolo);
}

/**
 * @brief Sobrecarga del operador + para Simbolos con Simbolos. Funciona como
 * una concatenación.
 * @param nuevo_simbolo Es el simbolo a concatenar con el simbolo previo.
 * @return Devuélve la concatenación de los simbolos.
 */
Simbolo Simbolo::operator+(const Simbolo& nuevo_simbolo) const {
  std::string simbolo_suma = this->getSimbolo() + nuevo_simbolo.getSimbolo();
  return Simbolo(simbolo_suma);
}

/**
 * @brief Sobrecarga del operador + para Simbolos y std::strings. Funciona como
 * una concatenación.
 * @param nuevo_simbolo Es la std::string a concatenar con el simbolo.
 * @return Devuélve la std::strings concatenada al simbolo.
 */
Simbolo Simbolo::operator+(const std::string& nuevo_simbolo) const {
  return Simbolo(this->getSimbolo() + nuevo_simbolo);
}

/**
 * @brief Sobrecarga del operador != para simbolos y strings. Este operador
 * compara que ambos sean distintos.
 * @param string_a_comparar Es la string a comparar.
 * @return Devuelve true si ambos son distintos, false en caso contrario.
 */
bool Simbolo::operator!=(const std::string& string_a_comparar) const {
  return (simbolo_ != string_a_comparar);
}

/**
 * @brief Sobrecarga del operador != para simbolos. Este operador compara que
 * ambos simbolos sean distintos.
 * @param simbolo_comparar Es el simbolo a comparar.
 * @return Devuelve true si ambos simbolos son distintos, false en caso
 * contrario.
 */
bool Simbolo::operator!=(const Simbolo simbolo_comparar) const {
  return (simbolo_ != simbolo_comparar.getSimbolo());
}

/**
 * @brief Sobrecarga del operador == para simbolos y strings. Este operador
 * compara que ambos sean iguales.
 * @param string_a_comparar Es la string a comparar.
 * @return Devuelve true si ambos son iguales, false en caso contrario.
 */
bool Simbolo::operator==(const std::string& string_a_comparar) const {
  return (simbolo_ == string_a_comparar);
}

/**
 * @brief Sobrecarga del operador == para simbolos. Este operador compara que
 * ambos simbolos sean iguales.
 * @param simbolo Es el simbolo a comparar.
 * @return Devuelve true si ambos simbolos son iguales, false en caso contrario.
 */
bool Simbolo::operator==(const Simbolo simbolo) const {
  return (simbolo_ == simbolo.getSimbolo());
}

/**
 * @brief Sobrecarga del operador = para simbolos. Este operador sustituye el
 * contenido del simbolo de la izquierda por el del de la derecha.
 * @param nuevo_simbolo Es el simbolo que suplantará el viejo.
 */
void Simbolo::operator=(const Simbolo& nuevo_simbolo) {
  this->simbolo_ = nuevo_simbolo.getSimbolo();
}

/**
 * @brief Sobrecarga del operador = para simbolos con strings. Este operador
 * sustituye el contenido del simbolo de la izquierda por la string de la
 * derecha.
 * @param nuevo_simbolo Es la string que suplantará el viejo simbolo.
 */
void Simbolo::operator=(const std::string& nuevo_simbolo) {
  this->simbolo_ = nuevo_simbolo;
}

/**
 * @brief Sobrecarga del operador = para simbolos y chars. Este operador
 * sustituye el contenido del simbolo de la izquierda por el char de la derecha.
 * @param nuevo_simbolo Es el char que suplantará el viejo simbolo.
 */
void Simbolo::operator=(const char& nuevo_simbolo) {
  this->simbolo_ = nuevo_simbolo;
}

/**
 * @brief Sobrecarga del operador de inserción de flujo para imprimir un objeto
 * Simbolo en un flujo de salida.
 * @param out Flujo de salida en el que se imprimirá el objeto Simbolo.
 * @param simbolo Objeto Simbolo que se imprimirá en el flujo de salida.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo) {
  out << simbolo.getSimbolo();
  return out;
}

/**
 * @brief Sobrecarga del operador de extracción de flujo para leer un objeto
 * Simbolo desde un flujo de entrada.
 * @param in Flujo de entrada desde el que se leerá el objeto Simbolo.
 * @param simbolo Objeto Simbolo en el que se almacenarán los valores
 * leídos desde el flujo de entrada.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& in, Simbolo& simbolo) {
  in >> simbolo.simbolo_;
  return in;
}
