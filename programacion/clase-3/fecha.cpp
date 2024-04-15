#include <iostream>
using namespace std;
#include "fecha.h"

int Fecha::getDia() { return _dia; };
int Fecha::getMes() { return _mes; };
int Fecha::getAnio() { return _anio; };
bool Fecha::setDia(int dia) {
  if (dia > 0 && dia <= 31) {
    _dia = dia;
    return true;
  } else {
    return false;
  }
};
bool Fecha::setMes(int mes) {
  if (mes > 0 && mes <= 12) {
    _mes = mes;
    return true;
  } else {
    return false;
  }
};
bool Fecha::setAnio(int anio) {
  if (anio > 1900 && anio <= 2024) {
    _anio = anio;
    return true;
  } else {
    return false;
  }
};
void Fecha::Mostrar() {
  cout << "Fecha [DD/MM/AA]: " << _dia << "/" << _mes << "/" << _anio;
}
void Fecha::Cargar() {
  int dia, mes, anio;
  bool bD = 0, bM = 0, bA = 0;
  while (!bD) {
    cout << "Dia: ";
    cin >> dia;
    if (setDia(dia)) {
      bD = 1;
    } else {
      cout << "Dia invalido." << endl;
    }
  }
  while (!bM) {
    cout << "Mes: ";
    cin >> mes;
    if (setMes(mes)) {
      bM = 1;
    } else {
      cout << "Mes invalido." << endl;
    }
  }
  while (!bA) {
    cout << "Anio: ";
    cin >> anio;
    if (setAnio(anio)) {
      bA = 1;
    } else {
      cout << "Anio invalido." << endl;
    }
  }
}

// Constructor predeterminado. Elegí que cree el objeto con la fecha actual.
Fecha::Fecha(int dia, int mes, int anio) {
  setDia(dia);
  setMes(mes);
  setAnio(anio);
};

// int main()
// {
//   Fecha fecha1;

//   cout << endl;
//   fecha1.Cargar();
//   fecha1.Mostrar();
//   cout << endl;

//   return 0;
// }