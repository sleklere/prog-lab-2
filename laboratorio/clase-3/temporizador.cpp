#include <iostream>
using namespace std;

class Temporizador
{
private:
  int _horas;
  int _minutos;
  int _segundos;

public:
  Temporizador(int horas, int minutos, int segundos);
  Temporizador();

  bool setHoras(int horas);
  bool setMinutos(int minutos);
  bool setSegundos(int segundos);
  int getHoras();
  int getMinutos();
  int getSegundos();
  void tic();
  void tac();
  void mostrar();
  int comparar(Temporizador temporizador);
};

bool Temporizador::setHoras(int horas)
{
  if (horas >= 0)
  {
    _horas = horas;
    return true;
  }
  else
  {
    return false;
  }
}

bool Temporizador::setMinutos(int minutos)
{
  if (minutos >= 0 && minutos < 60)
  {
    _minutos = minutos;
    return true;
  }
  else
  {
    return false;
  }
}

bool Temporizador::setSegundos(int segundos)
{
  if (segundos >= 0 && segundos < 60)
  {
    _segundos = segundos;
    return true;
  }
  else
  {
    return false;
  }
}

int Temporizador::getHoras()
{
  return _horas;
}

int Temporizador::getMinutos()
{
  return _minutos;
}

int Temporizador::getSegundos()
{
  return _segundos;
}

void Temporizador::tic()
{
  int horas = getHoras(), minutos = getMinutos(), segundos = getSegundos();

  if (segundos == 59)
  {
    setSegundos(0);
    if (minutos == 59)
    {
      setMinutos(0);
      setHoras(horas + 1);
    }
    else
    {
      setMinutos(minutos + 1);
    }
  }
  else
  {
    setSegundos(segundos + 1);
  }
}

void Temporizador::tac()
{
  tic();
}

void Temporizador::mostrar()
{
  // HH:MM:SS
  cout << _horas << ":" << _minutos << ":" << _segundos << endl;
}

int Temporizador::comparar(Temporizador temporizador)
{
  int horasComp = temporizador.getHoras();
  int minutosComp = temporizador.getMinutos();
  int segundosComp = temporizador.getSegundos();

  if (_horas == horasComp && _minutos == minutosComp && _segundos == segundosComp)
  {
    return 0;
  }
  else if (_horas > horasComp)
  {
    return 1;
  }
  else if (_minutos > minutosComp)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

Temporizador::Temporizador(int horas, int minutos, int segundos)
{
  if (!setHoras(horas) ||
      !setMinutos(minutos) ||
      !setSegundos(segundos))
  {
    // Temporizador();
    setHoras(0);
    setMinutos(0);
    setSegundos(0);
  }
}

Temporizador::Temporizador()
{
  setHoras(0);
  setMinutos(0);
  setSegundos(0);
}

int main()
{
  Temporizador temp1(1, 59, 58), temp2(1, 59, 59);

  temp1.mostrar();
  temp2.mostrar();

  cout << "Comparacion: " << temp1.comparar(temp2) << endl;
  // temp1.tic();
  // temp1.mostrar();

  return 0;
}