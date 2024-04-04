#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void mostrarVector(int *vec, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    cout << i << ": " << vec[i] << endl;
  }
}

int buscarPosMaximo(int *vec, int tam)
{
  int pos, max = 0;

  for (int i = 0; i < tam; i++)
  {
    if (vec[i] > max)
    {
      pos = i;
      max = vec[i];
    }
  }

  return pos;
}

int buscarCantMaximos(int *numeros, int *repeticiones, int tam, int posMax)
{
  int cantidad = 1; // como quiero saber si hay mas de un numero con el mayor numero de repeticiones, ya arranco contando el primer max encontrado

  for (int i = 0; i < tam; i++)
  {
    // si el numero repetido evaluado no es el mismo que el maximo encontrado en buscarPosMaximo se pasa a evaluar si se repetio la misma cantidad de veces
    cout << "numeros[i]: " << numeros[i] << endl;

    if (numeros[i] != numeros[posMax])
    {
      cout << "repeticiones[i]: " << repeticiones[i] << endl;
      cout << "repeticiones[posMax]: " << repeticiones[posMax] << endl;
      if (repeticiones[i] == repeticiones[posMax])
      {

        cantidad += repeticiones[i] / repeticiones[i]; // tener en cuenta que se va a volver a iterar por el mismo numero
      }
    }
  }

  return cantidad;
}

int main()
{
  int n, *vec, *nRep;

  cout << "Ingrese un numero: ";
  cin >> n;

  // generar vector dinamico
  vec = new int[n];
  nRep = new int[n]{};
  if (vec == NULL || nRep == NULL)
  {
    return 1;
  }

  srand((int)time(0));
  // numeros random entre 1 y N
  for (int i = 0; i < n; i++)
  {
    vec[i] = rand() % 10 + 1;
  }

  // contar repeticiones de numeros del 1 a n
  for (int i = 0; i < n; i++)
  {
    nRep[vec[i] - 1]++;
  }

  // buscar maxima cantidad de repeticiones
  int maxRep = 0;

  for (int i = 0; i < n; i++)
  {
    if (nRep[i] > maxRep)
    {
      maxRep = nRep[i];
    }
  }

  cout << "Max rep: " << maxRep << endl;

  cout << "Los numeros repetidos son: " << endl;

  for (int i = 0; i < n; i++)
  {
    if (nRep[i] == maxRep)
    {
      cout << i + 1 << endl; // se muestra el numero si las veces que se repitio es igual a la maxima
    }
  }

  ////////////////////////////////////////////////

  // volver a iterar y calcular y guardar numero/s con mayores repeticiones
  // int posNumMayRep = buscarPosMaximo(nRep, n);
  // int cantNumMaxRep = buscarCantMaximos(vec, nRep, n, posNumMayRep);

  mostrarVector(vec, n);
  // cout << "El numero con mayores repeticiones es: " << vec[repeticiones[0]] << " (" << repeticiones[1] << " repeticiones)" << endl;

  // cout << "Los numeros repetidos son: ";
  // for (int i = 0; i < n; i++)
  // {
  //   if (nRep[i] == nRep[posNumMayRep] && vec[i] != vec[posNumMayRep])
  //   {
  //     cout << vec[i] << ", ";
  //   }
  // }
  // cout << vec[posNumMayRep] << "." << endl;

  // cout << "El numero con mayores repeticiones es: " << vec[posNumMayRep] << " (" << nRep[posNumMayRep] << " repeticiones)" << endl;
  // cout << "El numero con mayores repeticiones es: " << vec[posNumMayRep] << endl;

  delete[] vec;
  delete[] nRep;

  return 0;
}

// crear vector con numeros al azar
// buscar si hay repetidos y cuantas veces cada uno
