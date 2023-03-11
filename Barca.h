/*
  Archivo: Barca.h
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

/**
  CLASE: Barca
  INTENCIÓN: Estoy modelando una barca que ES un Lugar con un nombre, en el cual puede haber individuos, y conoce 2 vecinos (otros lugares). Como ES un Lugar, se le puede pedir:
    - Que mire si entre los individuos que tiene ahí alguno puede comerse a otro
    - Puedo introducir los vecinos
    - Puedo pedirle que me retorne el valor de una posición
    - Puedo introducir un individuo
    - Que me diga cuantos individuos tiene
    - Que intercambie los 2 vecinos que conoce
    - Que mire si alguno de los individuos responde a cierta orden
    - Que mueva un individuo al vecino inmediato
    (las dos anteriores verifican si el individuo que se movió se cayó al agua)
    - Que me diga su nombre
    - Que me diga si hay un robot
  RELACIONES: ES un Lugar (y por ello, CONOCE Individuos, CONOCE Lugares)
*/

#include "Lugar.h"

#ifndef HH_BARCA
#define HH_BARCA

class Barca : public Lugar
{
  public:
  /**
  Constructor: Construye una barca que ES un lugar con un nombre, en el que pueden haber individuos y que puede conocer 2 vecinos (otros lugares). Como está recien fabricado, no hay individuos en el y no conoce ningún vecino.
  */
  Barca(string nombre);
  /**
  Destructor: No hace nada.
  */
  virtual ~Barca();
};

#else
class Barca;
#endif