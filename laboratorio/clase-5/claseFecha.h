#include <iostream>
using namespace std;

class Fecha {
private:
  int _dia;
  int _mes;
  int _anio;

public:
  Fecha(int dia = 8, int mes = 4, int anio = 2024);
  // Getters
  int getDia();
  int getMes();
  int getAnio();
  // Setters (1 == argumento valido, 0 == invalido)
  bool setDia(int dia);
  bool setMes(int mes);
  bool setAnio(int anio);
  void Mostrar();
  void Cargar();
};