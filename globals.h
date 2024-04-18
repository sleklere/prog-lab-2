#include <iostream>
using namespace std;

void cargarCadena(char* cad, int tam) {
  int i;
  fflush(stdin);
  for (i = 0; i < tam; i++) {
    cad[i] = cin.get();
    if (cad[i] == '\n')
      break;
  }
  cad[i] = '\0';
  fflush(stdin);
}