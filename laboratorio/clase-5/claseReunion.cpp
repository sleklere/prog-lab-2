#include "claseReunion.h"
#include "claseFecha.h"
#include <iostream>
#include <stdexcept>
#include <string.h>
using namespace std;

Reunion::Reunion(int cantidadParticipantes) {
  _cantidadParticipantes = cantidadParticipantes;
}

Persona Reunion::getParticipante(int indice) {
  if (indice > 0 && indice < 5) {
    return _participantes[indice];
  } else {
    // cout << "Numero de indice invalido.";
    throw std::out_of_range("Numero de indice invalido.");
  }
}

int Reunion::getCantParticipantes() { return _cantidadParticipantes; }

void Reunion::addParticipante(Persona participante) {
  if (_cantidadParticipantes == 5) {
    cout << "El grupo esta lleno" << endl;
  } else {
    _participantes[_cantidadParticipantes] = participante;
    _cantidadParticipantes++;
  }
}

void Reunion::setFechaReunion(Fecha fechaReunion) {
  _fechaReunion = fechaReunion;
}

void Reunion::setHorarioReunion(Tiempo horarioReunion) {
  _horarioReunion = horarioReunion;
}

void Reunion::setLugar(string lugar) { _lugar = lugar; }

void Reunion::setTema(string tema) { _tema = tema; }

void Reunion::setDuracion(int duracion) { _duracion = duracion; }

void Reunion::Mostrar() {
  _fechaReunion.Mostrar();
  cout << "Horario: " << _horarioReunion.getHora() << ":"
       << _horarioReunion.getMinuto() << endl;
  cout << "Lugar: " << _lugar << endl;
  cout << "Tema: " << _tema << endl;
  cout << "Duracion: " << _duracion << endl;
  cout << "Participantes: ";
  for (int i = 0; i < getCantParticipantes(); i++) {
    cout << "Participante " << i + 1 << ": " << _participantes[i].getNombre()
         << " " << _participantes[i].getApellido() << endl;
  }
}
void Reunion::Cargar() {
  Fecha fecha;
  Tiempo horario;
  cout << "Fecha: ";
  fecha.Cargar();
  _fechaReunion = fecha;
  cout << "Horario: ";
  horario.Cargar();
  _horarioReunion = horario;
  cout << "Lugar: ";
  cin >> _lugar;
  cout << "Tema: ";
  cin >> _tema;
  cout << "Duracion: ";
  cin >> _duracion;
  cout << "Cantidad de participantes";
  cin >> _cantidadParticipantes;
  cout << "Participantes: " << endl;
  for (int i = 0; i < _cantidadParticipantes; i++) {
    cout << "Participante " << i + 1 << ": ";
    _participantes[i].Cargar();
  }
}