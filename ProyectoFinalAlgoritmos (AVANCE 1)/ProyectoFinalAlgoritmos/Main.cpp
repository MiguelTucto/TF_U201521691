#include "Clases.h"
#include "Lista.h"
#include <conio.h>

using namespace std;

int main()
{
	string nombreEmpresa = "DELOSI SA";
	Empresa *listaTrabajadores = new Empresa(nombreEmpresa);
	cout << left << setw(15) << "NOMBRES" << left << setw(15) << "APELLIDOS" << left << setw(8) << "EDAD" << left << setw(18) << "AREA DE TRABAJO"
		<< left << setw(12) << "SUELDO(S/.)" << left << setw(18) << "MESES DE TRABAJO" << left << setw(10) << "CTS(S/.)"
		<< left << setw(20) << "PERSONAL NECESARIO" << endl;
	listaTrabajadores->generarClientes(25);
	listaTrabajadores->pasarArbol();
	listaTrabajadores->mostrarArbol();
	//listaTrabajadores->ordenarNombre();
	//listaTrabajadores->ordenarTipo();
	listaTrabajadores->buscar();
	listaTrabajadores->buscar();


	_getch();
	return 0;
}