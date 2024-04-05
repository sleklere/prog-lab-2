#pragma once

class Incrementador
{
private:
  int _valorInicial;
  int _valorIncremento;
  int _cantidadIncrementos;
  int _valor;
  void setValorInicial(int valorInicial);

public:
  Incrementador(int valorInicial, int valorIncremento);
  Incrementador();

  void setValorIncremento(int valorIncremento);
  int getValorInicial();
  int getValorIncremento();
  int getValorActual();
  int incrementar();
  void reset();
};