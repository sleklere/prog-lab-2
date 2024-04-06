#include <iostream>
using namespace std;

/*
Hacer una función llamada Delta que reciba un vector de enteros llamado Alfa y su tamaño y un vector de enteros llamado Beta y su tamaño. El programa debe generar un vector de enteros llamado Gamma (de manera dinámica) y almacenar secuencialmente en él los elementos que se encuentran en ambos vectores (los que están en Alfa y en Beta).

Luego, mostrar el vector Gamma, si es que contiene datos, con las siguientes variantes:
A) Mostrarlo dentro de la función Delta
B) Mostrarlo desde main haciendo uso del vector generado dinámicamente en la función Delta.
C) ¿Existe sólo una manera de resolver el punto B?

*/

int delta(int *Alfa, int tamAlfa, int *Beta, int tamBeta, int *&Gamma)
{
  int tamGamma = tamAlfa + tamBeta;
  Gamma = new int[tamGamma];

  for (int i = 0; i < tamGamma; i++)
  {
    if (i < tamAlfa)
    {
      Gamma[i] = Alfa[i];
    }
    else
    {
      Gamma[i] = Beta[i - 5];
    }
  }

  cout << "Vector Gamma (desde funcion delta): " << endl;
  for (int i = 0; i < tamGamma; i++)
  {
    cout << Gamma[i] << endl;
  }
  cout << endl;

  return tamGamma;
}

int main()
{
  int tamAlfa = 5, tamBeta = 6;
  int *Gamma = nullptr, Alfa[tamAlfa] = {452, 34, 0, 35, 3}, Beta[tamBeta] = {1, 4, 23, 56, 21, 98};

  int tamGamma = delta(Alfa, tamAlfa, Beta, tamBeta, Gamma);

  cout << "Vector Gamma (desde main): " << endl;
  for (int i = 0; i < tamGamma; i++)
  {
    cout << Gamma[i] << endl;
  }
  cout << endl;

  delete[] Gamma;

  return 0;
}