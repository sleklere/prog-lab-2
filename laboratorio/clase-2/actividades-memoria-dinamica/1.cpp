#include <iostream>
using namespace std;

int main()
{
  int n, *vec;

  cout << "Ingrese un numero: ";
  cin >> n;

  // generar vector dinamico
  vec = new int[n];
  if (vec == NULL)
  {
    return 1;
  }

  // numeros random entre 1 y N
  for (int i = 0; i < n; i++)
  {
    vec[i] = rand() % 10 + 1;
  }

  for (int i = 0; i < n; i++)
  {
    cout << i << ": " << vec[i] << endl;
  }

  delete[] vec;

  return 0;
}