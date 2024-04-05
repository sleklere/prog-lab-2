#include "incrementador.h"

void Incrementador::setValorInicial(int valorInicial)
{
  _valorInicial = valorInicial;
  _valor = valorInicial;
}
int Incrementador::getValorInicial()
{
  return _valorInicial;
}
void Incrementador::setValorIncremento(int valorIncremento)
{
  _valorIncremento = valorIncremento;
}
int Incrementador::getValorIncremento()
{
  return _valorIncremento;
}
int Incrementador::getValorActual()
{
  return _valor;
}
int Incrementador::incrementar()
{
  _cantidadIncrementos++;
  return _valor += _valorIncremento;
}
void Incrementador::reset()
{
  _valorInicial = 0;
  _valorIncremento = 1;
  _cantidadIncrementos = 0;
}

Incrementador::Incrementador(int valorInicial, int valorIncremento)
{
  setValorInicial(valorInicial);
  _valorIncremento = valorIncremento;
  _cantidadIncrementos = 0;
}
Incrementador::Incrementador()
{
  setValorInicial(0);
  _valorIncremento = 1;
  _cantidadIncrementos = 0;
}