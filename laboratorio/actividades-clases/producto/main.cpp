#include <iostream>
using namespace std;
#include "producto.h"

// comando que funciona para compilar
// g++ -Wall -Wextra -g3 main.cpp producto.cpp -o outputProgramName

int main() {
  Producto prod1;

  prod1 = cargarProducto();
  system("pause");
  // prod1.Mostrar();
  mostrarProducto(prod1);

  return 0;
}