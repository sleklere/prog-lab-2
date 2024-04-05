/*
Problema 3
Un profesor desea poder cargar la cantidad de alumnos que tiene en su materia y que un programa le solicite el Apellido y Nombres de cada uno de ellos así como también sus correspondientes notas finales del semestre.
De ese procesamiento de datos desea poder conocer:
La cantidad de alumnos que hayan obtenido un puntaje final que exceda el promedio general del curso.
Un listado con los apellidos y nombres de aquellos alumnos cuya puntaje final exceda el promedio general de los aprobados (se aprueba con nota final mayor a 6).

*/

#include <iostream>
using namespace std;

struct InfoAlumno
{
  char apellido[20];
  char nombre[20];
  int notaFinal;
};

int main()
{
  int cantidadAlumnos;
  InfoAlumno *alumnos;

  cout << "Ingrese la cantidad de alumnos: ";
  cin >> cantidadAlumnos;

  alumnos = new InfoAlumno[cantidadAlumnos];

  int promedioNotas = 0;
  int promedioNotasAprobados = 0;
  int cantidadAprobados = 0;

  for (int i = 0; i < cantidadAlumnos; i++)
  {
    int notaFinal;

    cout << "Alumno N°" << i + 1 << endl;
    cout << "Apellido: ";
    cin >> alumnos[i].apellido;
    cout << "Nombre: ";
    cin >> alumnos[i].nombre;
    cout << "Nota final: ";
    cin >> notaFinal;
    alumnos[i].notaFinal = notaFinal;

    promedioNotas += notaFinal;
    if (notaFinal > 6)
    {
      cantidadAprobados++;
      promedioNotasAprobados += notaFinal;
    }
  }

  // cantidad de alumnos notaFinal > promedio
  promedioNotas /= cantidadAlumnos;
  promedioNotasAprobados /= cantidadAprobados;

  int cantAlumnosArribaPromedio = 0;

  for (int i = 0; i < cantidadAlumnos; i++)
  {
    if (alumnos[i].notaFinal > promedioNotas)
    {
      cantAlumnosArribaPromedio++;
    }
  }

  cout << "Cantidad de alumnos con nota mayor al promedio: " << cantAlumnosArribaPromedio << endl;

  cout << "Apellidos y nombres de alumnos con nota final mayor al promedio de aprobados: " << endl;
  // apellidos y nombres alumnos notaFinal > promedio aprobados
  for (int i = 0; i < cantidadAlumnos; i++)
  {
    if (alumnos[i].notaFinal > promedioNotasAprobados)
    {
      cout << alumnos[i].apellido << ", " << alumnos[i].nombre << endl;
    }
  }

  return 0;
}