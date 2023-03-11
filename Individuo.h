/*
  Archivo: Individuo.h
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

/**
  CLASE: Individuo
  INTENCIÓN: Estoy modelando un individuo con un nombre, una orden a la que responde y que puede tener la capacidad de comerse a otro(s) en especifico. Se le puede pedir:
    - Que introduzca un individuo que le paso a su lista de individuos que puede comerse
    - Que me diga su nombre
    - Que me diga si se come cierto individuo que le paso
    - Que me diga si responde a cierta orden que le paso
  RELACIONES: conoce Individuos
*/

#include <string>
#include <vector>

using namespace std;

#ifndef HH_INDIVIDUO
#define HH_INDIVIDUO

class Individuo
{
  private:
  string nombre;
  string orden_a_responder;
  vector<Individuo *> individuos_que_puede_comer;

  public:
  /**
  Constructor: Construye un Individuo con un nombre, con una orden a la cual responde y que quizá puede comerse a otro(s). Como está recién fabricado, aún no puede comerse a nadie (en caso de que lo vaya a hacer).
  */
  Individuo(string nombre, string orden_a_responder);
  /**
  Destructor: Pone cada uno de los punteros del vector de individuos que puede comer a nullptr, para al final borrar los elementos del vector (con clear).
  */
  virtual ~Individuo();
  /**
  Recibe un puntero a un invididuo que puede comerse y lo introduce al vector de punteros a individuos que se puede comer con push_back.
  */
  virtual void introducir_individuo_comestible(Individuo *individuo_comestible);
  /**
  Retorna el nombre.
  */
  virtual string que_eres();
  /**
  Recibe un puntero a un Individuo y mira si se lo come (si está en su vector de individuos que puede comer) y retorna: true = se lo come, false = no se lo come
  */
  virtual bool dime_si_te_lo_comes(Individuo *un_individuo);
  /**
  Recibe una orden y mira si es la orden a la que responde y retorna: true = responde a esa orden, false = no responde a esa orden
  */
  virtual bool dime_si_es_tu_orden(string una_orden);
};

#else
class Individuo;
#endif