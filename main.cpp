/*
  Archivo: main.cpp
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

/**
  HISTORIA: hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los individuos, además del robot. El problema es que si el robot deja solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. El jugador debe controlar que órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos. Las órdenes que puede dar el jugador son (usando el teclado): B la Barca se mueve a la otra orilla - R el Robot salta de/a la barca - Z el Zorro salta de/a la barca - C el Conejo salta de/a la barca - L la Lechuga salta de/a la barca. Como este es un añadido para el premio, se añade otro conejo que responde al comando C2 y se añade otro robot que responde al comando R2.
*/

#include "Barca.h"
#include "Individuo.h"
#include "Jugador.h"
#include "Lugar.h"
#include "Orilla.h"

#include <string>
using namespace std;

int main()
{
  Orilla orilla_izquierda("IZQUIERDA");
  Barca barca("BARCA");
  Orilla orilla_derecha("DERECHA");
  orilla_izquierda.introducir_vecinos(&barca, nullptr);
  barca.introducir_vecinos(&orilla_izquierda, &orilla_derecha);
  orilla_derecha.introducir_vecinos(nullptr, &barca);

  Jugador jugador({&orilla_izquierda, &barca, &orilla_derecha});

  Individuo robot("Robot", "R");
  Individuo conejo("Conejo", "C");
  Individuo zorro("Zorro", "Z");
  Individuo lechuga("Lechuga", "L");
  Individuo conejo_2("Conejo_2", "C2");
  Individuo robot_2("Robot_2", "R2");
  orilla_izquierda.introducir_un_individuo(&robot);
  orilla_izquierda.introducir_un_individuo(&conejo);
  orilla_izquierda.introducir_un_individuo(&zorro);
  orilla_izquierda.introducir_un_individuo(&lechuga);
  orilla_izquierda.introducir_un_individuo(&conejo_2);
  orilla_izquierda.introducir_un_individuo(&robot_2);

  conejo.introducir_individuo_comestible(&lechuga);
  conejo_2.introducir_individuo_comestible(&lechuga);
  zorro.introducir_individuo_comestible(&conejo);
  zorro.introducir_individuo_comestible(&conejo_2);

  jugador.jugar();

  return 0;
}