#include "fecha.h"

#pragma once
class Persona {
private:
  int _dni;
  char _nombre[30];
  char _apellido[30];
  Fecha _fechaNacimiento;
  char _telefono[15];

public:
  // Getters

  int getDni();
  const char* getNombre();
  const char* getApellido();
  Fecha getFechaNacimiento();
  const char* getTelefono();
  // Setters

  void setDni(const int dni);
  void setNombre(const char* n);
  void setApellido(const char* n);
  void setFechaNacimiento(Fecha f);
  void setTelefono(const char* t);
  void Mostrar();
  void Cargar();
};

// : -> operador "scope"
class Alumno : public Persona {
private:
  int _legajo;

public:
  // Getters
  int getLegajo();
  // Setters
  void setLegajo(const int legajo);
};