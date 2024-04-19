#include "claseTiempo.h"
#include <iostream>
using namespace std;

Tiempo::Tiempo(int hora, int minuto, int segundo) {
  setHora(hora);
  setMinuto(minuto);
  setSegundo(segundo);
}

int Tiempo::getHora() { return _hora; }

int Tiempo::getMinuto() { return _minuto; }

int Tiempo::getSegundo() { return _segundo; }

void Tiempo::setHora(int hora) {
  if (hora >= 0 && hora <= 24) {
    _hora = hora;
  }
}

void Tiempo::setMinuto(int minuto) {
  if (minuto >= 0 && minuto <= 60) {
    _minuto = minuto;
  }
}

void Tiempo::setSegundo(int segundo) {
  if (segundo >= 0 && segundo <= 60) {
    _segundo = segundo;
  }
}

Tiempo::Tiempo(int hora = 0, int minuto = 0, int segundo = 0) {
  _hora = hora;
  _minuto = minuto;
  _segundo = segundo;
}

void Tiempo::Cargar() {
  int hora, minutos, segundo;

  cout << "Ingrese hora: " << endl;
  cin >> hora;
  setHora(hora);
  cout << "Ingrese minutos: " << endl;
  cin >> minutos;
  setMinuto(hora);
  cout << "Ingrese segundos: " << endl;
  cin >> segundo;
  setSegundo(segundo);
}