class Empresa {
private:
  int _num;
  char _nombre[30];
  int _cantEmpleados;
  int _categoria;
  int _numMunicipio;
  bool _estado;

public:
  Empresa(int num = 0, const char* nombre = "", int cantEmpleados = 0,
          int categoria = 0, int numMunicipio = 0, bool estado = false);
}