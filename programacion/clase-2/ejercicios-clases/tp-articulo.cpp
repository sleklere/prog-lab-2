#include <cstring>
#include <iostream>
using namespace std;

class Articulo {
private:
  char _codigo[5];
  char _descripcion[30];
  float _precio;
  int _stock;
  bool _estado;

public:
  // Constructor
  // Un constructor con parámetros por omisión
  Articulo(const char* codigo, const char* descripcion, float precio, int stock,
           bool estado);
  // Un constructor para asignar valor sólo a la descripción
  Articulo(char descripcion[30]);
  // Getters
  const char* getCodigo();
  const char* getDescripcion();
  float getPrecio();
  int getStock();
  bool getEstado();
  // Setters
  void setCodigo(const char* codigo);
  void setDescripcion(const char* descripcion);
  void setPrecio(float precio);
  void setStock(int stock);
  void setEstado(bool estado);
  // Cargar y mostrar
  void Cargar();
  void Mostrar();
};

void Articulo::Cargar() {
  char codigo[5], descripcion[30];
  float precio;
  int stock;
  bool estado;

  cout << "Codigo: ";
  cin >> codigo;
  setCodigo(codigo);
  cout << "Descripcion: ";
  cin >> descripcion;
  setDescripcion(descripcion);
  cout << "Precio: ";
  cin >> precio;
  setPrecio(precio);
  cout << "Stock: ";
  cin >> stock;
  setStock(stock);
  cout << "Estado (bool): ";
  cin >> estado;
  setEstado(estado);
}

void Articulo::Mostrar() {
  cout << "Codigo: " << _codigo;
  cout << "Descripcion: ";
  cout << "Precio: ";
  cout << "Stock: ";
  cout << "Estado (bool): ";
}

const char* Articulo::getCodigo() { return _codigo; };
const char* Articulo::getDescripcion() { return _descripcion; };
float Articulo::getPrecio() { return _precio; };
int Articulo::getStock() { return _stock; };
bool Articulo::getEstado() { return _estado; };

void Articulo::setCodigo(const char* codigo) { strcpy(_codigo, codigo); };
void Articulo::setDescripcion(const char* descripcion) {
  strcpy(_descripcion, descripcion);
};
void Articulo::setPrecio(float precio) {
  if (precio > 0) {
    _precio = precio;
  }
};
void Articulo::setStock(int stock) {
  if (stock > 0) {
    _stock = stock;
  }
};
void Articulo::setEstado(bool estado) {
  if (estado > 0 && estado < 2) {
    _estado = estado;
  }
};

Articulo::Articulo(const char* codigo = "-----",
                   const char* descripcion = "Sin descripcion.",
                   float precio = 0, int stock = 0, bool estado = 0) {
  setCodigo(codigo);
  setDescripcion(descripcion);
  setPrecio(precio);
  setStock(stock);
  setEstado(estado);
}

Articulo::Articulo(char descripcion[30]) { setDescripcion(descripcion); }

int main() {
  Articulo vec[10];

  for (int i = 0; i < 10; i++) {
    cout << "Articulo numero " << i + 1 << ": " << endl;
    vec[i].Cargar();
    cout << endl;
  }

  system("pause");

  for (int i = 0; i < 10; i++) {
    cout << "Articulo numero " << i + 1 << ": " << endl;
    vec[i].Mostrar();
    cout << endl;
  }

  return 0;
}