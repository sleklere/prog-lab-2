#pragma once

class Producto {
private:
  char _nombre[20];
  float _precio;
  int _stock;
  int _minStock;
  int _tipo;

public:
  Producto(const char* nombre, float precio, int stock, int minStock, int tipo);
  Producto();
  // Getters
  const char* getNombre();
  float getPrecio();
  int getStock();
  int getMinStock();
  int getTipo();
  // Setters
  void setNombre(const char* nombre);
  void setPrecio(float precio);
  void setStock(int stock);
  void setMinStock(int minStock);
  void setTipo(int tipo);

  void Mostrar();
  void Cargar();
};

void mostrarProducto(Producto prod);
Producto cargarProducto();