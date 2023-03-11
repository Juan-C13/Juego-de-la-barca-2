/*
  Archivo: Lugar.cpp
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

#include "Lugar.h"


Lugar::Lugar(string nombre)
  : nombre(nombre)
{
  // No hay que hacer nada
}


Lugar::~Lugar()
{
  vecino_inmediato = nullptr;
  vecino_alternativo = nullptr;
  for(int cual_individuo = 0; cual_individuo < individuos_en_el_sitio.size(); cual_individuo++)
    individuos_en_el_sitio.at(cual_individuo) = nullptr;
  individuos_en_el_sitio.clear();
}


bool Lugar::mirar_estado()
{
  bool alguien_fue_comido = false;
  int quien_fue_comido = -1;
  bool hay_un_robot = dime_si_hay_un_robot();
  if(not hay_un_robot)
  {
    for(int quien_comeria = 0; quien_comeria < individuos_en_el_sitio.size(); quien_comeria++)
    {
      for(int cual_posible_presa = 0; cual_posible_presa < individuos_en_el_sitio.size(); cual_posible_presa++)
      {
        if(individuos_en_el_sitio.at(quien_comeria)->dime_si_te_lo_comes(individuos_en_el_sitio.at(cual_posible_presa)))
        {
          alguien_fue_comido = true;
          quien_fue_comido = cual_posible_presa;
        }
      }
    }
    if(alguien_fue_comido)
      individuos_en_el_sitio.erase(individuos_en_el_sitio.begin()+quien_fue_comido);
  }
  return alguien_fue_comido;
}


void Lugar::introducir_vecinos(Lugar *un_vecino_inmediato, Lugar *un_vecino_alternativo)
{
  vecino_inmediato = un_vecino_inmediato;
  vecino_alternativo = un_vecino_alternativo;
}


string Lugar::imprimir_una_posicion(int una_posicion)
{
  string auxiliar = "";
  if((individuos_en_el_sitio.size()!=0)and(una_posicion<individuos_en_el_sitio.size()))
    auxiliar = individuos_en_el_sitio.at(una_posicion)->que_eres();

  return auxiliar;
}


void Lugar::introducir_un_individuo(Individuo *individuo)
{
  individuos_en_el_sitio.push_back(individuo);
}


int Lugar::cuantos_individuos_tienes()
{
  return individuos_en_el_sitio.size();
}


void Lugar::intercambiar_vecinos()
{
  Lugar* auxiliar = nullptr;
  auxiliar = vecino_inmediato;
  vecino_inmediato = vecino_alternativo;
  vecino_alternativo = auxiliar;
  auxiliar = nullptr;
}


int Lugar::dar_una_orden(string una_orden)
{
  int resultado = 0;
  for(int cual_individuo = 0; cual_individuo < individuos_en_el_sitio.size(); cual_individuo++)
  {
    if(individuos_en_el_sitio.at(cual_individuo)->dime_si_es_tu_orden(una_orden))
      resultado = mover_individuo(cual_individuo);
  }
  return resultado;
}


int Lugar::mover_individuo(int cual_individuo)
{
  int resultado = 1;
  if(vecino_inmediato)
  {
    if(((vecino_inmediato->cuantos_individuos_tienes() < 2) and (vecino_inmediato->dime_que_eres() == "BARCA"))or(vecino_inmediato->dime_que_eres()!="BARCA"))
    {
      vecino_inmediato->introducir_un_individuo(individuos_en_el_sitio.at(cual_individuo));
      individuos_en_el_sitio.erase(individuos_en_el_sitio.begin()+cual_individuo);
    }
  }
  else
  {
    resultado = 2;
    individuos_en_el_sitio.erase(individuos_en_el_sitio.begin()+cual_individuo);
  }
  return resultado;
}


string Lugar::dime_que_eres()
{
  return nombre;
}


bool Lugar::dime_si_hay_un_robot()
{
  bool hay_un_robot = false;
  int contador = 0;
  string identificador_de_robot = "Robot";
  for(int cual_individuo = 0; cual_individuo < individuos_en_el_sitio.size(); cual_individuo++)
  {
    contador = 0;
    for(int cual_caracter = 0; cual_caracter < 5; cual_caracter++)
    {
      if(individuos_en_el_sitio.at(cual_individuo)->que_eres()[cual_caracter] == identificador_de_robot[cual_caracter])
        contador++;
    }
    if(contador == 5)
      hay_un_robot = true;
  }
  return hay_un_robot;
}