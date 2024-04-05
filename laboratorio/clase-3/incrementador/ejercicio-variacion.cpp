#include <iostream>
#include "incrementador.h"
#include "incrementador.cpp"
using namespace std;

int main()
{
  Incrementador inc(100, 55), incB;
  inc.incrementar();

  cout << inc.getValorActual() << endl;

  return 0;
}