#pragma once

class Tiempo {
private:
  int _hora;
  int _minuto;
  int _segundo;

public:
  Tiempo(int hora = 0, int minuto = 0, int segundo = 0);
  // getter
  int getHora();
  int getMinuto();
  int getSegundo();
  // setter
  void setHora(int hora);
  void setMinuto(int minuto);
  void setSegundo(int segundo);
  // cargar
  void Cargar();
};
