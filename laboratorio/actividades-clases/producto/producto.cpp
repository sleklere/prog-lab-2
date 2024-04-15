#include "producto.h"
#include <iostream>
#include <string.h>
using namespace std;

// Getters
const char* Producto::getNombre() { return _nombre; };
float Producto::getPrecio() { return _precio; };
int Producto::getStock() { return _stock; };
int Producto::getMinStock() { return _minStock; };
int Producto::getTipo() { return _tipo; };
// Setters
void Producto::setNombre(const char* nombre) { strcpy(_nombre, nombre); };
void Producto::setPrecio(float precio) {
  if (precio > 0) {
    _precio = precio;
  }
};
void Producto::setStock(int stock) {
  if (stock >= 0) {
    _stock = stock;
  }
};
void Producto::setMinStock(int minStock) {
  if (minStock >= 0) {
    _minStock = minStock;
  }
};
void Producto::setTipo(int tipo) {
  if (tipo > 0 && tipo < 3) {
    _tipo = tipo;
  }
};

void Producto::Mostrar() {
  cout << "Nombre: " << _nombre << endl;
  cout << "Precio: " << _precio << endl;
  cout << "Stock: " << _stock << endl;
  cout << "Minimo stock: " << _minStock << endl;
  cout << "Tipo de producto: " << _tipo << endl;
};
void Producto::Cargar() {
  cout << "Nombre: ";
  cin >> _nombre;
  cout << "Precio: ";
  cin >> _precio;
  cout << "Stock: ";
  cin >> _stock;
  cout << "Minimo stock: ";
  cin >> _minStock;
  cout << "Tipo de producto: ";
  cin >> _tipo;
};

void mostrarProducto(Producto prod) {
  int stock = prod.getStock(), minStock = prod.getMinStock(),
      tipo = prod.getTipo();
  float precio = prod.getPrecio();

  cout << "Nombre: " << prod.getNombre() << endl;
  cout << "Precio: " << precio << endl;
  if (stock <= minStock && tipo == 1) {
    cout << "Hay que reponer el stock del producto" << endl;
  }
  cout << "Stock: " << stock << endl;
  cout << "Minimo stock: " << minStock << endl;
  cout << "Tipo de producto: " << tipo << endl;

  if (tipo == 1) {
    cout << "Valuacion del stock: " << stock * precio << endl;
  } else {
    cout << "Valuacion del stock: 0" << endl;
  }
  cout << endl;
};

Producto cargarProducto() {
  char nombre[20];
  float precio;
  int stock, minStock, tipo;

  cout << "Nombre: ";
  cin >> nombre;
  cout << "Precio: ";
  cin >> precio;
  cout << "Stock: ";
  cin >> stock;
  cout << "Minimo stock: ";
  cin >> minStock;
  cout << "Tipo de producto: ";
  cin >> tipo;
  cout << endl;

  Producto nuevoProducto(nombre, precio, stock, minStock, tipo);

  return nuevoProducto;
};

Producto::Producto(const char* nombre = "", float precio = 0, int stock = 0,
                   int minStock = 0, int tipo = 2) {
  strcpy(_nombre, nombre);
  _precio = precio;
  _stock = stock;
  _minStock = minStock;
  _tipo = tipo;
};
Producto::Producto(){};