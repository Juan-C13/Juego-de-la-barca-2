/*
  Archivo: Jugador.h
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

/**
  CLASE: Jugador
  INTENCIÓN: Estoy modelando un jugador que conoce los 3 lugares del juego, que sabe si la barca está en la izquierda y que puede terminar el juego. Se le puede pedir:
    - Que inicie el juego
    - Que reciba un comando y ejecute una acción con base en él
    - Que termine el juego
    - Que mueva la barca
    - Que le pase un comando a los lugares
    - Que mire si alguien fue comido
    - Que mire si ganó
    - Que mire cuántos individuos hay en el juego
    - Pasarle un texto y que compruebe que está bien en cuanto a cantidad de carácteres
    - Que imprima el estado total del juego
  RELACIONES: conoce Lugares
*/

#include "Individuo.h"
#include "Lugar.h"
#include <string>

#include <iostream>
using namespace std;

#ifndef HH_JUGADOR
#define HH_JUGADOR

class Jugador
{
  private:
  bool juego_terminado = false;
  string mensaje_final = "";
  bool barca_en_la_izquierda = true;
  vector<Lugar *> lugares_en_el_juego;

  public:
  /**
  Constructor: Construye un jugador que contiene todos los lugares del juego.
  */
  Jugador(vector <Lugar *> lugares_en_el_juego);
  /**
  Destructor: Pone cada uno de los punteros del vector de lugares a nullptr, para al final borrar los elementos del vector (con clear).
  */
  virtual ~Jugador();
  /**
  Inicia el juego, imprimiendo el mensaje inicial y el estado inicial. Hasta que el juego no acabe, preguntará al usuario qué desea hacer, para que este introduzca comandos a ejecutar. Una vez el juego acabe, imprime un mensaje final.
  */
  virtual void jugar();
  /**
  Recibe un comando y lo ejecuta (si es posible) con base en lo que se escriba, y si lo escrito no corresponde a nada, le pasa el comando a cada lugar para que lo ejecuten (si es posible).
  */
  virtual void ejecutar_un_comando(string un_comando);
  /**
  Se acaba el juego y expresa en el mensaje final porqué (si el jugador ganó o perdió).
  */
  virtual void fin_del_juego(string un_mensaje);
  /**
  Le pregunta a la barca si tiene un robot, y si lo tiene entonces ordena que se intercambien los vecinos que conoce cada lugar, además de cambiar la posición que se conoce de la barca.
  */
  virtual void mover_barca();
  /**
  Recibe un comando y se lo pasa a cada uno de los lugares para que miren si alguien responde y le retornan un resultado. Cuando alguien responda, la función dejará de pasar el comando. El resultado que recibe la función puede ser: 0 = nadie ha respondido y siguen mirando, 1 = alguien respondio y dejan de mirar, 2 = alguien respondió pero se cayó al agua entonces se acaba el juego
  */
  virtual void pasar_un_comando(string un_comando);
  /**
  Le pregunta a cada lugar cuál es su estado, para ver si algún individuo fue comido. Si alguien fue comido, se acaba el juego.
  */
  virtual void mira_si_alguien_fue_comido();
  /**
  Le pregunta a la orilla derecha cuantos individuos tiene, y si están todos los individuos del juego ahí, se acaba el juego.
  */
  virtual void mira_si_ganaste();
  /**
  Le pregunta a cada lugar cuántos individuos tiene y retorna la suma de esas cantidades.
  */
  virtual int cuantos_individuos_hay_en_el_juego();
  /**
  Recibe un texto, y con base en una constante, mira si el valor de la constante es mayor que el número de carácteres que tiene el texto. Si es mayor, entonces rellena el texto con espacios (" ") al frente hasta que la cantidad de carácteres sea igual al valor de la constante, al final retorna este mismo texto. (Esta función es para hacer que al imprimir el juego todas las casillas (|          |) se vean alineadas y organizadas).
  */
  virtual string comprobar_texto(string &un_texto);
  /**
  Hace un chequeo del juego y luego lo imprime en 4 columnas, arriba el nombre del lugar, y debajo los individuos que tenga. En la primer columna estará la orilla Izquierda. Si la barca está en la izquierda su información se imprimirá en la segunda columna, si no lo está, se imprime en la tercer columna. La columna en la que no esté la barca estará vacía. Por último, en la cuarta columna estará la orilla Derecha.
  */
  virtual string imprimir_estado_total();
};

#else
class Jugador;
#endif