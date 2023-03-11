/*
  Archivo: Jugador.cpp
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

#include "Jugador.h"


Jugador::Jugador(vector <Lugar *> lugares_en_el_juego)
  : lugares_en_el_juego(lugares_en_el_juego)
{
  // No hay que hacer nada
}


Jugador::~Jugador()
{
  for(int cual_lugar = 0; cual_lugar < lugares_en_el_juego.size(); cual_lugar++)
    lugares_en_el_juego.at(cual_lugar) = nullptr;
  lugares_en_el_juego.clear();
}


void Jugador::jugar()
{
  cout << "Eres un Robot, y tu misión es llevar todos los individuos a la otra orilla, usando la barca. Pero no puedes dejar solo al zorro con el conejo, ni al conejo con la lechuga, porque el primero se deboraría al segundo. En la barca solo caben dos individuos, y uno de ellos deber ser tú, para pilotarla. Las órdenes que puedes dar son:" << endl << endl << "  - Q para rendirte" << endl << "  - R para mover Robot" << endl << "  - Z para mover Zorro" << endl << "  - C para mover Conejo" << endl << "  - L para mover Lechuga" << endl;

  cout  << imprimir_estado_total();

  while(not juego_terminado)
  {
    string auxiliar = "";
    cout << endl << "¿Qué deseas hacer? ";
    getline(cin, auxiliar);
    
    ejecutar_un_comando(auxiliar);
    cout << endl << imprimir_estado_total();
  }
  cout << endl << mensaje_final << endl;
}


void Jugador::ejecutar_un_comando(string un_comando)
{
  if(un_comando == "Q")
    fin_del_juego("TE RENDISTE\nPERDISTE");
  else
  {
    if(un_comando == "B")
      mover_barca();
    else
      pasar_un_comando(un_comando);
  }
}


void Jugador::fin_del_juego(string un_mensaje)
{
  juego_terminado = true;
  mensaje_final = un_mensaje;
}


void Jugador::mover_barca()
{
  if(lugares_en_el_juego.at(1)->dime_si_hay_un_robot())
  {
    for(int cual_lugar = 0; cual_lugar < lugares_en_el_juego.size(); cual_lugar++)
      lugares_en_el_juego.at(cual_lugar)->intercambiar_vecinos();
    if(barca_en_la_izquierda)
      barca_en_la_izquierda = false;
    else
      barca_en_la_izquierda = true;
  }
}


void Jugador::pasar_un_comando(string un_comando)
{
  int resultado_del_comando = 0;
  for(int cual_lugar = 0; cual_lugar < lugares_en_el_juego.size(); cual_lugar++)
  {
    if(resultado_del_comando == 0)
      resultado_del_comando = lugares_en_el_juego.at(cual_lugar)->dar_una_orden(un_comando);

    if(resultado_del_comando == 2)
      fin_del_juego("Alguien se cayó al agua\nPERDISTE");
  }
}


void Jugador::mira_si_alguien_fue_comido()
{
  for(int cual_lugar = 0; cual_lugar < lugares_en_el_juego.size(); cual_lugar++)
  {
    if(lugares_en_el_juego.at(cual_lugar)->mirar_estado())
      fin_del_juego("Alguien fue devorado \nPERDISTE");
  }
}


void Jugador::mira_si_ganaste()
{
  if(lugares_en_el_juego.at(2)->cuantos_individuos_tienes() == cuantos_individuos_hay_en_el_juego())
    fin_del_juego("GANASTE");
}


int Jugador::cuantos_individuos_hay_en_el_juego()
{
  return lugares_en_el_juego.at(0)->cuantos_individuos_tienes()+lugares_en_el_juego.at(1)->cuantos_individuos_tienes()+lugares_en_el_juego.at(2)->cuantos_individuos_tienes();
}


string Jugador::comprobar_texto(string &un_texto)
{
  int const espacios_entre_casillas = 10;
  if(espacios_entre_casillas > un_texto.size())
  {
    for(int cual_caracter = un_texto.size(); cual_caracter < espacios_entre_casillas; cual_caracter++)
      un_texto += " ";
  }
  return un_texto;
}


string Jugador::imprimir_estado_total()
{
  mira_si_alguien_fue_comido();
  mira_si_ganaste();

  string resultado = "";
  string hueco_izquierdo = "";
  string hueco_derecho = "";

  vector <string> partes_del_resultado;
  string *informacion_barca = nullptr;

  if(barca_en_la_izquierda)
    informacion_barca = &hueco_izquierdo;
  else
    informacion_barca = &hueco_derecho;

  *informacion_barca = lugares_en_el_juego.at(1)->dime_que_eres();
  partes_del_resultado.push_back(lugares_en_el_juego.at(0)->dime_que_eres());
  partes_del_resultado.push_back(hueco_izquierdo);
  partes_del_resultado.push_back(hueco_derecho);
  partes_del_resultado.push_back(lugares_en_el_juego.at(2)->dime_que_eres());

  for(int veces = 0; veces < cuantos_individuos_hay_en_el_juego(); veces++)
  {
    *informacion_barca = lugares_en_el_juego.at(1)->imprimir_una_posicion(veces);
    partes_del_resultado.push_back(lugares_en_el_juego.at(0)->imprimir_una_posicion(veces));
    partes_del_resultado.push_back(hueco_izquierdo);
    partes_del_resultado.push_back(hueco_derecho);
    partes_del_resultado.push_back(lugares_en_el_juego.at(2)->imprimir_una_posicion(veces));
  }

  for(int veces = 0; veces < partes_del_resultado.size()*0.25; veces++)
  {
    for(int veces_2 = 0; veces_2 < 4; veces_2++)
    {
      comprobar_texto(partes_del_resultado.at(veces_2+(4*veces)));
      resultado += "| " + partes_del_resultado.at(veces_2+(4*veces));
    }
    resultado += "|\n";
  }
  informacion_barca = nullptr;
  return resultado;
}