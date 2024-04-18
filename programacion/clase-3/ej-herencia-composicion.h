#pragma once
#include "fecha.h"
#include "persona.h"

class Empleado : public Persona {
private:
  int _categoria;
  float _sueldo;
  Fecha _fechaIngreso;

public:
  Empleado(int categoria = 1, float sueldo = 0,
           const Fecha fechaIngreso = Fecha(15, 4, 2024));
};

class Proveedor : public Persona {
private:
  char _CUIL[11];
  int _tipoProducto;
  char _condicionPago;

public:
  Proveedor(const char* CUIL, int tipoProducto, char condicion);
  const char* getCUIL();
  int getTipoProducto();
  char getCondicionPago();
  bool setCUIL(const char* CUIL);
  bool setTipoProducto(int tipoProducto);
  bool setCondicionPago(char condicionPago);
  void Cargar();
  void Mostrar();
};

class Docente : public Persona {
private:
  char _legajo[10];
  char _cargo[15];
  Fecha _fechaIngreso;

public:
  Docente(const char* _legajo = "123123", const char* _cargo = "Profesor",
          Fecha _fechaIngreso = Fecha(15, 4, 2024));
};