/*
  Archivo: Individuo.cpp
  Autor: Juan Esteban Clavijo García
  Email: juan.esteban.clavijo@correounivalle.edu.co
  Fecha creación: 2023-01-05
  Fecha última modificación: 2023-01-11
  Versión: 0.2
*/

#include "Individuo.h"


Individuo::Individuo(string nombre, string orden_a_responder)
  : nombre(nombre), orden_a_responder(orden_a_responder)
{
  // No hay que hacer nada
}


Individuo::~Individuo()
{
  for(int cual_presa = 0; cual_presa < individuos_que_puede_comer.size(); cual_presa++)
    individuos_que_puede_comer.at(cual_presa) = nullptr;
  individuos_que_puede_comer.clear();
}


void Individuo::introducir_individuo_comestible(Individuo *individuo_comestible)
{
  individuos_que_puede_comer.push_back(individuo_comestible);
}


string Individuo::que_eres()
{
  return nombre;
}


bool Individuo::dime_si_te_lo_comes(Individuo *un_individuo)
{
  bool auxiliar = false;
  for(int cual_presa = 0; cual_presa < individuos_que_puede_comer.size(); cual_presa++)
  {
    if(individuos_que_puede_comer.at(cual_presa) == un_individuo)
      auxiliar = true;
  }
  return auxiliar;
}


bool Individuo::dime_si_es_tu_orden(string una_orden)
{
  if(orden_a_responder == una_orden)
    return true;
  else
    return false;
}