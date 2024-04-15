#include <iostream>
using namespace std;

class Articulo
{
private:
  char _codigo[5];
  char _descripcion[30];
  float _precio;
  int _stock;
  bool _estado;

public:
  // Constructor
  // Un constructor con parámetros por omisión
  Articulo(char codigo[5] = "ABC", char descripcion[30], float precio = 0, int stock = 0, bool estado = 0);
  // Un constructor para asignar valor sólo a la descripción
  Articulo(char descripcion[30]);
  // Getters
  char getCodigo();
  char getDescripcion();
  float getPrecio();
  int getStock();
  bool getEstado();
  // Setters
  void setCodigo(char codigo[5]);
  void setDescripcion(char descripcion[30]);
  void setPrecio(float precio);
  void setStock(int stock);
  void setEstado(bool estado);
};

char Articulo::getCodigo(){};
char Articulo::getDescripcion(){};
float Articulo::getPrecio(){};
int Articulo::getStock(){};
bool Articulo::getEstado(){};

void Articulo::setCodigo(char codigo[5]){};
void Articulo::setDescripcion(char descripcion[30]){};
void Articulo::setPrecio(float precio){};
void Articulo::setStock(int stock){};
void Articulo::setEstado(bool estado){};

Articulo::Articulo(char codigo[5] = "-----", char descripcion[30], float precio = 0, int stock = 0, bool estado = 0)
{
  setCodigo(codigo);
  setDescripcion(descripcion);
  setPrecio(precio);
  setStock(stock);
  setEstado(estado);
}

Articulo::Articulo(char descripcion[30])
{
  setDescripcion(descripcion);
}

int main()
{

  return 0;
}