#include <iostream>
#include <cstring>

using namespace std;

void cargarCadena(char *pal, int tam)
{
	int i;
	fflush(stdin); /// limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
	for (i = 0; i < tam; i++)
	{
		pal[i] = cin.get();
		if (pal[i] == '\n')
			break;
	}
	pal[i] = '\0';
	fflush(stdin); /// vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

/**
Alta: agregar un registro al archivo
Empresa obj;
FILE *p;
p=fopen("empresas.dat","ab");
if(p==nullptr){
	return;
}
fwrite(&obj, sizeof (Empresa), 1, p);
fclose(p);

Baja: eliminaci�n de un registro del archivo
(puede ser f�sica o l�gica).
-Baja l�gica:
-Pedir al usuario que ingrese el n�mero
de empresa a modificar.
-Abro el archivo.
-Leo registro por registro hasta que coincide
el n�mero de empresa con el ingresado.

Modificaci�n: modificaci�n de la informaci�n
de un registro:
-Pedir al usuario que ingrese el n�mero
de empresa a modificar.
-Abro el archivo.
-Leo registro por registro hasta que coincide
el n�mero de empresa con el ingresado.
-Pedir al usuario la nueva categor�a.
-Modifico el registro con la nueva categor�a.
rb+
ab+
wb+
-Me posiciono en la posici�n que ocupa el
registro a modificar en el archivo.
fseek(p, desplazamiento, desdeDonde );
fseek(p, 0, 2);
0 - SEEK_SET
1 - SEEK_CUR
2 - SEEK_END
eof.
-Escribo el registro modificado en el archivo.
-Cierro el archivo.

ftell(p): la cantidad de bytes que hay desde
el principio del archivo hasta donde estoy
parado actualmente.

Listado: mostrar uno, varios o todos los
registros del archivo.
void Articulo::Mostrar(){
	if(estado){
		cout<<"CODIGO: "<<codigo<<endl;
		cout<<"NOMBRE: "<<nombre<<endl;
		cout<<"STOCK: "<<stock<<endl;
		cout<<"PRECIO: "<<precio<<endl;
	}
}


while(fread(&objArt, sizeof (Articulo), 1, p)==1){
	if(obj.getEstado()){
		objArt.Mostrar();
		cout<<endl;
	}
}

*/
/**
Empresas.dat
N�mero de empresa (N�mero entero. No se repite en el archivo. Es �nico para cada empresa)
Nombre (char[30])
Cantidad de empleados
Categor�a (1 a 80)
N�mero de municipio al que pertenece (1 a 135)
Estado (bool)
*/

class Empresa
{
private:
	int numero;
	char nombre[30];
	int cantidadEmpleados;
	int categoria;
	int numeroMunicipio;
	bool estado;

public:
	Empresa() { estado = false; }
	void setNumero(int n)
	{
		numero = n;
	}
	void setCategoria(int c) { categoria = c; }
	void setEstado(bool e) { estado = e; }
	int getNumero() { return numero; }
	bool getEstado() { return estado; }
	void Cargar()
	{
		cout << "NUMERO: ";
		cin >> numero;
		cout << "NOMBRE: ";
		cargarCadena(nombre, 29);
		cout << "CANTIDAD DE EMPLEADOS: ";
		cin >> cantidadEmpleados;
		cout << "CATEGORIA: ";
		cin >> categoria;
		cout << "NUMERO DE MUNICIPIO: ";
		cin >> numeroMunicipio;
		estado = true;
	}
	void Mostrar()
	{
		if (estado)
		{
			cout << "NUMERO: " << numero << endl;
			cout << "NOMBRE: " << nombre << endl;
			cout << "CANTIDAD DE EMPLEADOS: " << cantidadEmpleados << endl;
			cout << "CATEGORIA: " << categoria << endl;
			cout << "NUMERO DE MUNICIPIO: " << numeroMunicipio << endl;
			cout << endl;
		}
	}
};

class ArchivoEmpresas
{
private:
	char _nombre[30];

public:
	ArchivoEmpresas(const char *nombre = "empresas.dat")
	{
		setNombre(nombre);
	}
	const char *getNombre() { return _nombre; };
	void setNombre(const char *nombre)
	{
		strcpy(_nombre, nombre);
	};
	Empresa leerRegistro(int pos);
	void grabarRegistro(Empresa obj);
	void modificarRegistro(Empresa obj, int pos); // modificacion Y baja - podria devolver booleano en base a si fue exitoso
	void listarRegistros();						  // "discutible si va aca"
	int buscarRegistro(int numRegistro);		  // devuelve la pos del registro en el archivo
	int contarRegistros();
};

Empresa ArchivoEmpresas::leerRegistro(int pos)
{
	Empresa obj;
	obj.setNumero(-1);
	FILE *p;
	p = fopen("empresas.dat", "rb");
	if (p == nullptr)
	{
		cout << "ERROR DE ARCHIVO" << endl;
		obj.setNumero(-2);
		return obj;
	}
	fseek(p, pos * sizeof obj, 0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
};
void ArchivoEmpresas::grabarRegistro(Empresa obj)
{
	FILE *p;
	p = fopen(this->getNombre(), "ab");
	if (p == nullptr)
	{
		cout << "ERROR DE ARCHIVO" << endl;
		return;
	}
	fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
};
void ArchivoEmpresas::modificarRegistro(Empresa obj, int pos){};
void ArchivoEmpresas::listarRegistros()
{
	Empresa obj;
	int cant = this->contarRegistros(); // el this es opcional.

	for (int i = 0; i < cant; i++)
	{
		obj = this->leerRegistro(i);
		obj.Mostrar();
	}
};
int ArchivoEmpresas::buscarRegistro(int numRegistro)
{
	Empresa obj;
	int cant = this->contarRegistros();

	for (int i = 0; i < cant; i++)
	{
		obj = this->leerRegistro(i);

		if (obj.getNumero() == numRegistro)
		{
			return i;
		}
	}
	return -1;
}
int ArchivoEmpresas::contarRegistros()
{
	FILE *p;
	Empresa obj;

	p = fopen(this->getNombre(), "rb");
	if (p == nullptr)
	{
		cout << "ERROR DE ARCHIVO" << endl;
		return;
	}

	int tamArchivo = ftell(p);
	int tamEmpresa = sizeof obj;

	fclose(p);

	return tamArchivo / tamEmpresa;
}

void altaEmpresa()
{
	Empresa obj;
	ArchivoEmpresas archEmp; // si no tiene valores por omision -> archEmp("nombre_archivo.dat")

	obj.Cargar();

	if (archEmp.buscarRegistro(obj.getNumero()) >= 0)
	{
		cout << "Ya existe una empresa con ese numero en el archivo." << endl;
		return;
	}

	if (obj.getEstado())
	{
		archEmp.grabarRegistro(obj);
	}
}

void bajaEmpresa()
{
	int num;
	ArchivoEmpresas archEmp;

	cout << "INGRESE EL NUMERO DE EMPRESA A DAR DE BAJA: ";
	cin >> num;
	int pos = archEmp.buscarRegistro(num);
	if (pos < 0)
	{
		cout << "NO EXISTE EL NUMERO DE EMPRESA EN EL ARCHIVO" << endl;
		return;
	}
	Empresa obj;
	obj = archEmp.leerRegistro(pos);
	obj.setEstado(false);
	archEmp.modificarRegistro(obj, pos);
}

void modificarCategoria()
{
	int num, pos, categoria;
	ArchivoEmpresas archEmp;
	Empresa obj;

	cout << "Ingrese el numero de la empresa a modificar: ";
	cin >> num;

	pos = archEmp.buscarRegistro(num);

	if (pos < 0)
	{
		cout << "No existe ese numero en el archivo." << endl;
		return;
	}

	obj = archEmp.leerRegistro(pos);

	if (!obj.getEstado())
	{
		cout << "El registro que quiere modificar esta dado de baja." << endl;
		return;
	}

	cout << "Ingresar la nueva categoria: ";
	cin >> categoria;
	obj.setCategoria(categoria);

	archEmp.modificarRegistro(obj, pos);
}

void listarEmpresas()
{
	ArchivoEmpresas archEmp;
	archEmp.listarRegistros();
}

void listarPorNumero()
{
	int num;

	cout << "Ingrese el numero de la empresa: ";
	cin >> num;

	ArchivoEmpresas archEmp;

	int pos = archEmp.buscarRegistro(num);

	if (pos < 0)
	{
		cout << "No existe una empresa con ese numero" << endl;
		return;
	}
	Empresa obj;
	// obj = archEmp.leerRegistro(pos);
	// obj.Mostrar();
	archEmp.leerRegistro(pos).Mostrar();
}
// void listarEmpresas()
// {
// 	Empresa obj;
// 	FILE *p;
// 	p = fopen("empresas.dat", "rb");
// 	if (p == nullptr)
// 	{
// 		cout << "ERROR DE ARCHIVO" << endl;
// 		return;
// 	}
// 	while (fread(&obj, sizeof obj, 1, p) == 1)
// 	{
// 		obj.Mostrar();
// 		if (obj.getEstado())
// 			cout << endl;
// 	}
// }

// void grabarRegistro(Empresa obj)
// {
// 	FILE *p;
// 	p = fopen("empresas.dat", "ab");
// 	if (p == nullptr)
// 	{
// 		cout << "ERROR DE ARCHIVO" << endl;
// 		return;
// 	}
// 	fwrite(&obj, sizeof obj, 1, p);
// 	fclose(p);
// }

// void altaEmpresa()
// {
// 	Empresa obj;
// 	obj.Cargar();
// 	if (obj.getEstado())
// 	{
// 		grabarRegistro(obj);
// 	}
// 	else
// 	{
// 		cout << "SE CANCELO LA CARGA DEL REGISTRO EN EL ARCHIVO" << endl;
// 	}
// }
/**
1
Empresa 1
1
1
1
2
Empresa 2
2
2
2
3
Empresa 3
3
3
3
4
Empresa 4
4
4
4
5
Empresa 5
5
5
5
*/

// int buscarRegistro(int num)
// {
// 	Empresa obj;
// 	FILE *p;
// 	p = fopen("empresas.dat", "rb");
// 	if (p == nullptr)
// 	{
// 		return -2;
// 	}
// 	int pos = 0;
// 	while (fread(&obj, sizeof obj, 1, p) == 1)
// 	{
// 		if (obj.getNumero() == num)
// 		{
// 			fclose(p);
// 			return pos;
// 		}
// 		pos++;
// 	}
// 	fclose(p);
// 	return -1;
// }

// void modificarRegistro(Empresa obj, int pos)
// {
// 	FILE *p;
// 	p = fopen("empresas.dat", "rb+");
// 	if (p == nullptr)
// 	{
// 		return;
// 	}
// 	fseek(p, pos * sizeof obj, 0);
// 	fwrite(&obj, sizeof obj, 1, p);
// 	fclose(p);
// }

// Empresa leerRegistro(int pos)
// {
// 	Empresa obj;
// 	obj.setNumero(-1);
// 	FILE *p;
// 	p = fopen("empresas.dat", "rb");
// 	if (p == nullptr)
// 	{
// 		cout << "ERROR DE ARCHIVO" << endl;
// 		obj.setNumero(-2);
// 		return obj;
// 	}
// 	fseek(p, pos * sizeof obj, 0);
// 	fread(&obj, sizeof obj, 1, p);
// 	fclose(p);
// 	return obj;
// }

// void bajaEmpresa()
// {
// 	int num;
// 	cout << "INGRESE EL NUMERO DE EMPRESA A DAR DE BAJA: ";
// 	cin >> num;
// 	int pos = buscarRegistro(num);
// 	if (pos < 0)
// 	{
// 		cout << "NO EXISTE EL NUMERO DE EMPRESA EN EL ARCHIVO" << endl;
// 		return;
// 	}
// 	Empresa obj;
// 	obj = leerRegistro(pos);
// 	obj.setEstado(false);
// 	modificarRegistro(obj, pos);
// }

// void modificarCategoria()
// {
// 	int num;
// 	cout << "INGRESE EL NUMERO DE EMPRESA A DAR DE BAJA: ";
// 	cin >> num;
// 	int pos = buscarRegistro(num);
// 	if (pos < 0)
// 	{
// 		cout << "NO EXISTE EL NUMERO DE EMPRESA EN EL ARCHIVO" << endl;
// 		return;
// 	}
// 	Empresa obj;
// 	obj = leerRegistro(pos);
// 	int cat;
// 	cout << "INGRESE LA NUEVA CATEGORIA: ";
// 	cin >> cat;
// 	obj.setCategoria(cat);
// 	modificarRegistro(obj, pos);
// }

void menuPrincipal()
{
	int opc;
	while (true)
	{
		system("cls");
		cout << "MENU PRINCIPAL" << endl;
		cout << "--------------" << endl;
		cout << "1 - ALTA" << endl;
		cout << "2 - BAJA LOGICA" << endl;
		cout << "3 - MODIFICAR CATEGORIA" << endl;
		cout << "4 - LISTAR ARCHIVO" << endl;
		cout << "0 - SALIR" << endl;
		cout << "-------------------" << endl;
		cout << "INGRESE UNA OPCION: ";
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:
			altaEmpresa();
			break;
		case 2:
			bajaEmpresa();
			break;
		case 3:
			modificarCategoria();
			break;
		case 4:
			listarEmpresas();
			break;
		case 0:
			return;
		default:
			cout << "OPCION INCORRECTA" << endl;
			break;
		}
		system("pause");
	}
}

int main()
{
	menuPrincipal();
	return 0;
}
