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
 * @file tools.cc
 * @brief Definición de las funciones Introduccion y
 * CompruebaParametrosCorrectos
 * @bug No hay errores conocidos
 * @see
 * https://github.com/Edhey/CyA-Practica-07-Gramaticas-en-Forma-Normal-de-Chomsky
 * Historial de revisiones:
 */

#include "tools.h"

/**
 * @brief Función que imprime el propósito del programa
 */
void Introduccion() {
  std::cout
      << "Este programa lee desde un fichero con extensión .gra las "
         "especificaciones de una gramática independiente del contexto y, a "
         "continuación, y genera otro fichero .gra en el que se especifica una "
         "gramática equivalente (L(Gin) = L(Gout)) a la de entrada, pero en "
         "este caso, escrita en forma normal de Chomsky. Los ficheros de "
         "especificación de gramáticas son ficheros de texto plano con "
         "extensión .gra que contienen los elementos definitorios de la "
         "gramática G ≡ (Σ, V, S, P) en este orden: símbolos terminales, "
         "símbolos no terminales, símbolo de arranque y producciones. El "
         "formato de cada uno de estos elementos en el fichero es el "
         "siguiente: \n1. Símbolos terminales (alfabeto): una línea que "
         "contiene N, el número de símbolos en el alfabeto seguida de N "
         "líneas, cada una de las cuales contiene un símbolo del alfabeto. "
         "Cada símbolo del alfabeto debe ser un único caracter "
         "imprimible.\n2. Símbolos no terminales: una línea que contiene V , "
         "el número de símbolos no terminales, seguida de V líneas, cada "
         "una de las cuales contiene una cadena alfanumérica sin espacios. Se "
         "asumirá que el primero de los símbolos no terminales de esta lista "
         "será el símbolo de arranque.\n3. Producciones: una línea que "
         "contiene P, el número de producciones de la gramática, seguida por "
         "P líneas cada una de las cuales contiene una producción en el "
         "formato:A α siendo α ∈ (Σ ∪ V )∗, es decir una secuencia de "
         "símbolos terminales y no terminales. La cadena vacía, ϵ se "
         "representa mediante el carácter &. "
      << std::endl;
}

/**
 * @brief Función que comprueba si el número de parámetros introducido es
 * correcto.
 * @param[in] argc: Número de parámetros en la línea de comando.
 * @param[in] argv: Vector contenedor (char*) de parámetros.
 * @param[in] kParametrosCorrectos: Número de parámetros que debería haber.
 * @return verdadero si el número de parámetros es correcto.
 *         falso si no lo es.
 */
bool CompruebaParametrosCorrectos(const int argc, char *argv[],
                                  const int kParametrosCorrectos) {
  if (argc == 2 && (!strcmp(argv[1], "--help"))) {
    Introduccion();
    return false;
  } else if (argc != kParametrosCorrectos + 1) {
    std::cerr << "Error. Número de parámetros incorrecto" << std::endl;
    std::cerr << "Este programa ha de ser llamado " << argv[0] << " Parámetro1 "
              << "Parámetro2" << std::endl;
    std::cerr << "Parámetro1: input.gra" << std::endl;
    std::cerr << "Parámetro2: output.gra" << std::endl;
    std::cerr << "Pruebe " << argv[0] << " --help para más información"
              << std::endl;
    return false;
  }
  return true;
}