/*
  Archivo: Lugar.h
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

/**
  CLASE: Lugar
  INTENCIÓN: Estoy modelando un Lugar con un nombre, en el cual puede haber individuos, y conoce 2 vecinos (otros lugares). Le puedo pedir:
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
  RELACIONES: conoce Individuos, conoce Lugares
*/

#include "Individuo.h"
#include <string>
#include <vector>

#ifndef HH_LUGAR
#define HH_LUGAR

class Lugar
{
  protected:
  string nombre;
  vector<Individuo *> individuos_en_el_sitio;

  Lugar *vecino_inmediato = nullptr;
  Lugar *vecino_alternativo = nullptr;

  public:
  /**
  Constructor: Construye un lugar con un nombre, en el que pueden haber individuos y que puede conocer 2 vecinos (otros lugares). Como está recien fabricado, no hay individuos en el y no conoce ningún vecino.
  */
  Lugar(string nombre);
  /**
  Destructor: Pone cada uno de sus vecinos como nullptr, y los punteros del vector de individuos tambíen a nullptr, para al final borrar los elementos del vector (con clear).
  */
  virtual ~Lugar();
  /**
  Mira si entre los individuos que estén en el lugar alguno puede comerse a otro, si sucede (retorna true), el o los comidos desaparecen, el jugador pierde, y hace que el juego acabe. true = alguien fue comido, false = nadie fue comido
  */
  virtual bool mirar_estado();
  /**
  Se introduce el puntero al vecino inmediato primero, y luego el puntero al vecino alternativo, que serán los lugares que están al lado (son vecinos) del lugar actual.
  */
  virtual void introducir_vecinos(Lugar *un_vecino_inmediato,Lugar *un_vecino_alternativo);
  /**
  Renorna el valor que haya en el vector de individuos en la posicion indicada, si no hay nada en el vector, o si la posicion indicada es un número igual o mayor a la cantidad de individuos en el vector, se retorna un string vacio "".
  */
  virtual string imprimir_una_posicion(int posicion);
  /**
  Recibe un puntero a individuo y lo introduce en el vector con push_back.
  */
  virtual void introducir_un_individuo(Individuo *un_individuo);
  /**
  Retorna la cantidad de individuos que hay en el lugar.
  */
  virtual int cuantos_individuos_tienes();
  /**
  Intercambia el puntero del vecino inmediato con el del vecino alternativo (para cuando la barca se mueva).
  */
  virtual void intercambiar_vecinos();
  /**
  El lugar recibe una orden y le pregunta a cada uno de los individuos que esté ahí si la orden recibida corresponde a la orden a la que ellos responden, si alguno responde a la orden, la función llama a otra para mover el individuo que respondió, al final retorna un resultado con base en lo que suceda: 0 = nadie respondió a la orden, 1 = alguien respondió a la orden, 2 = alguien respondió a la orden pero se cayó al agua
  */
  virtual int dar_una_orden(string una_orden);
  /**
  Recibe la ubicación de un individuo que esté en el lugar, luego revisa si tiene un vecino (si su vecino inmediato no es nullptr), si no lo hay, saca al individuo del lugar pero se cae al agua. Si hay un vecino, revisa que en caso de ser la barca, haya menos de 2 individuos en ella (porque estaría llena), y entonces mueve al individuo, si no es la barca simplemente saca el individuo y se lo pasa al vecino para que lo introduzca. Al final retorna un resultado con base en lo que suceda: 1 = había un vecino, 2 = no había un vecino y el individuo cayó al agua
  */
  virtual int mover_individuo(int cual_individuo);
  /**
  Retorna el nombre del lugar.
  */
  virtual string dime_que_eres();
  /**
  Dice si hay un robot en el lugar. true = sí, false = no
  */
  virtual bool dime_si_hay_un_robot();
};

#else
class Lugar;
#endif