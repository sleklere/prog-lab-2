#include <iostream>
#include <string.h>

using namespace std;

// Sobrecarga de funciones
void mostrar(int n)
{
    cout << n;
}

void mostrar(char c)
{
    cout << c;
}

// Par�metros por referencia
void sumar(int &n, int n2)
{
    n += n2;
}

// Valores por omisi�n
int sumar(int n1, int n2 = 1)
{
    return n1 + n2;
}

// POO - Clases
// principio fundamental -> Encapsulamiento
// poner todas las propiedades como privadas
// public/private -> "especificador de acceso" (private por default)
// getters and setters
// convencion nombres propiedades, getters, setters:
// lower camelCase
// propiedad - _parametro (nombre - _nombre) o al rev�s

class Materia
{
private:
    int numero;
    char nombre[40];
    int cantidadAlumnos;
    int cantidadDocentes;
    char codigoCarrera[5];

public:
    void setNumero(int _numero) { numero = _numero; }
    void setNombre(const char *_nombre) { strcpy(nombre, _nombre); }
    void setCantidadAlumnos(int _cantidadAlumnos) { cantidadAlumnos = _cantidadAlumnos; }
    const char *getNombre() { return nombre; }
    void mostrar()
    {
        cout << "NUMERO: " << numero << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "CANTIDAD DE ALUMNOS: " << cantidadAlumnos << endl;
        cout << "CANTIDAD DE DOCENTES: " << cantidadDocentes << endl;
    }
    // se usar�a un setter si hubiera que validar el dato
    void cargar()
    {
        cout << "INGRESE EL NUMERO: ";
        cin >> numero;
        cout << "INGRESE EL NOMBRE: ";
        cin >> nombre;
        cout << "INGRESE LA CANTIDAD DE ALUMNOS: ";
        cin >> cantidadAlumnos;
        cout << "INGRESE LA CANTIDAD DE DOCENTES";
        cin >> cantidadDocentes;
    }
};

class Articulo
{
    char codigo[5];
    char descripcion[30];
    int stock;
    bool estado;

public:
    // Articulo() {}

    // Articulo(char _codigo[5], char _descripcion[30], bool _estado, int _stock = 0)
    // {
    //     setCodigo(_codigo);
    //     setDescripcion(_descripcion);
    //     setStock(_stock);
    //     setEstado(_estado);
    // }

    void cargar()
    {
        cout << "INGRESE EL CODIGO: ";
        cin >> codigo;
        cout << "INGRESE LA DESCRIPCION: ";
        cin >> descripcion;
        cout << "INGRESE EL STOCK: ";
        cin >> stock;
        cout << "INGRESE EL ESTADO: ";
        cin >> estado;
        cout << endl;
    }
    void mostrar()
    {
        cout << "CODIGO: " << codigo << endl;
        cout << "DESCRIPCION: " << descripcion << endl;
        cout << "STOCK: " << stock << endl;
        cout << "ESTADO: " << estado << endl;
    }
    // getters
    const char *getCodigo() { return codigo; }
    const char *getDescripcion() { return descripcion; }
    int getStock() { return stock; }
    bool getEstado() { return estado; }
    // setters
    void setCodigo(const char *_codigo) { strcpy(codigo, _codigo); }
    void setDescripcion(const char *_descripcion) { strcpy(descripcion, _descripcion); }
    void setStock(int _stock) { stock = _stock; }
    void setEstado(bool _estado) { estado = _estado; }
    // un constructor con parametros por omision
    // un constructor para asignar alor solo a la descripcion

    // a) cargar un vector de 10 articulos
};

int main()
{
    Articulo vecArticulos[10];

    for (int i = 0; i < 3; i++)
    {
        /*
        char *_codigo[5], *_descripcion[40];
        int _stock;
        bool _estado;

        cout << "INGRESE EL CODIGO: ";
        cin >> _codigo;
        cout << "INGRESE LA DESCRIPCION: ";
        cin >> _descripcion;
        cout << "INGRESE EL STOCK: ";
        cin >> _stock;
        cout << "INGRESE EL ESTADO: ";
        cin >> _estado;
        cout << endl; */
        // vecArticulos[i] = Articulo();
        vecArticulos[i].cargar();
    }

    for (int i = 0; i < 3; i++)
    {
        vecArticulos[i].mostrar();
    }

    return 0;
}
