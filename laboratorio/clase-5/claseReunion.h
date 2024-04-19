#pragma once
#include "claseFecha.h"
#include "clasePersona.h"
#include "claseTiempo.h"
#include <string>
using namespace std;

class Reunion {
private:
  Fecha _fechaReunion;
  Tiempo _horarioReunion;
  string _lugar;
  string _tema;
  int _duracion;
  Persona _participantes[5];
  int _cantidadParticipantes;

public:
  // Constructor/es
  Reunion(int cantidadParticipantes = 0);
  // Getters
  Persona getParticipante(int indice);
  int getCantParticipantes();
  // Persona* getParticipantes();
  // Setters
  void addParticipante(Persona participante);
  void setFechaReunion(Fecha fechaReunion);
  void setHorarioReunion(Tiempo horarioReunion);
  void setLugar(string lugar);
  void setTema(string tema);
  void setDuracion(int duracion);
  // Mostrar y Cargar
  void Mostrar();
  void Cargar();
  // Otros métodos
};
