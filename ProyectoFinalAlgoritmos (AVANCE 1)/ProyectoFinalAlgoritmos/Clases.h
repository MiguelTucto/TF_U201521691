#pragma once
#include <iostream>
#include<string>
#include <sstream>
#include <iomanip>
#include"Lista.h"
#include"ArbolAVL.h"
using namespace std;
using namespace System;

//datos aleatorios
string nombres[20] = { "Juan ","Paula ","Miguel " ,"Juben " ,"Johan " ,"Johanna " ,"Maria " ,"Alejandro " ,"Jose " ,"Cristina " ,"Nicole " ,"Sofia " ,"Josue " ,"Diego " ,"Ruben " ,"Milagros " ,"Diana " ,"Oscar " ,"Gabriel " ,"Einer " };
string apellidos[20] = { "Aguirre","Peralta","Gonzales","Padilla","Valenzuela","Pinto","Collao","Garcia","Rodriguez","Pilco","Uribe","Salazar","Huerta","Hablutzel","Fernandez","Flores","Figueroa","Ramirez","Miranda","Landa" };
string areas[7] = { "Administracion", "Gerencial", "Logistica", "Seguridad", "Informatica", "Contabilidad", "RRHH" };
//

class Empleado {
private:
	string nombre;
	string apellido;
	string area;
	short sueldo;
	short edad;
	short meses_trabajo;
	short cts;
	bool pers_indispensable;
public:
	Empleado(string nombre, string apellido,string area, short sueldo, short edad, short meses_trabajo, short cts,bool pers_indispensable )
		: nombre(nombre),apellido(apellido),area(area), sueldo(sueldo), edad(edad), meses_trabajo(meses_trabajo), cts(cts),pers_indispensable(pers_indispensable){}
	~Empleado() {}

	string getNombre() { return nombre; }
	string getApellido() {return apellido;}
	string getArea() { return area; }
	float getSueldo() { return sueldo; }
	short getEdad() { return edad; }
	short getMeses() { return meses_trabajo; }
	short getCts() { return cts; }
	string getIndis() { 
		if (pers_indispensable == true)
			return "SI";
		else
			return "NO";
	} 
	void mostrar()
	{
		cout << setw(15) << nombre 
			<< setw(15) << apellido
			<< setw(8) << edad
			<< setw(18) << area
			<< setw(12) << sueldo
			<< setw(18) << meses_trabajo
			<< setw(10) << cts
			<< setw(20) << pers_indispensable;
		cout << endl;
	}
};

class Empresa {
	DLCList<Empleado*>ListaEmpleados;
	arbolAVL<Empleado*,string>* idxNombre;
	arbolAVL<Empleado*, string>* idxApellido;
	arbolAVL<Empleado*, short>* idxEdad;
	arbolAVL<Empleado*, string>* idxArea;
	arbolAVL<Empleado*, short>* idxSueldo;
	arbolAVL<Empleado*, short>* idxMeses;
	arbolAVL<Empleado*, short>* idxCts;
	arbolAVL<Empleado*, string>* idxIndis;
	string nombreEmpresa;
public:
	Empresa(string nombreEmpresa){
		auto k1 = [](Empleado* e) {return e->getNombre(); };
		auto k2 = [](Empleado* e) {return e->getApellido(); };
		auto k3 = [](Empleado* e) {return e->getEdad(); };
		auto k4 = [](Empleado* e) {return e->getArea(); };
		auto k5 = [](Empleado* e) {return e->getSueldo(); };
		auto k6 = [](Empleado* e) {return e->getMeses(); };
		auto k7 = [](Empleado* e) {return e->getCts(); };
		auto k8 = [](Empleado* e) {return e->getIndis(); };
		idxNombre = new arbolAVL<Empleado*, string>(k1);
		idxApellido = new arbolAVL<Empleado*, string>(k2);
		idxEdad = new arbolAVL<Empleado*, short>(k3);
		idxArea = new arbolAVL<Empleado*, string>(k4);
		idxSueldo = new arbolAVL<Empleado*, short>(k5);
		idxMeses = new arbolAVL<Empleado*, short>(k6);
		idxCts = new arbolAVL<Empleado*, short>(k7);
		idxIndis = new arbolAVL<Empleado*, string>(k8);
		this->nombreEmpresa = nombreEmpresa;
	}
	~Empresa() {}

	void generarClientes(short n) {
		string nombre;
		string apellido;
		string area;
		short sueldo;
		short edad;
		short meses_trabajo;
		short cts;
		bool pers_indispensable;
		Random aleatorio;
		for (int i = 0; i < n; ++i)
		{
			nombre = nombres[aleatorio.Next(0, 20)];
			apellido = apellidos[aleatorio.Next(0, 20)];
			area = areas[aleatorio.Next(0, 7)];
			edad = aleatorio.Next(25, 60);
			meses_trabajo = aleatorio.Next(1, 120);
			if (area == "Gerencial") {
				sueldo = 7500;
				pers_indispensable = true;
			}
			else if (area == "Administracion") {
				sueldo = 6700;
				pers_indispensable = true;
			}
			else if (area == "Logistica") {
				sueldo = 6200;
				pers_indispensable = true;
			}
			else if (area == "Contabilidad") {
				sueldo = 6000;
				pers_indispensable = true;
			}
			else if (area == "Informatica") {
				sueldo = 5800;
				pers_indispensable = true;
			}
			else if (area == "RRHH") {
				sueldo = 5300;
				pers_indispensable = false;
			}
			else if (area == "Seguridad") {
				sueldo = 3900;
				pers_indispensable = false;
			}
			cts = ((sueldo + (sueldo / 6)) / 360)*(meses_trabajo);
			//AGREGAR DATOS A LA LISTA
			ListaEmpleados.addPos(new Empleado(nombre,apellido,area,sueldo,edad,meses_trabajo,cts,pers_indispensable), i);
		}

	}

	void mostrarLista() {
		if (ListaEmpleados.size() > 0) 
		{
			for (int i = 0; i < ListaEmpleados.size(); ++i) 
			{
				cout <<
					left << setw(15) << ListaEmpleados.getPos(i)->getNombre() <<
					left << setw(15) << ListaEmpleados.getPos(i)->getApellido() <<
					left << setw(8) << ListaEmpleados.getPos(i)->getEdad() <<
					left << setw(18) << ListaEmpleados.getPos(i)->getArea() <<
					left << setw(12) << ListaEmpleados.getPos(i)->getSueldo() <<
					left << setw(18) << ListaEmpleados.getPos(i)->getMeses() <<
					left << setw(10) << ListaEmpleados.getPos(i)->getCts() <<
					left << setw(20) << ListaEmpleados.getPos(i)->getIndis();
				cout << endl;
			}
		}
		else
			cout << "No se encontraron trabajadores para la empresa indicada..." << endl;

	}

	void pasarArbol()
	{
		for (auto e : ListaEmpleados)
		{
			idxNombre->add(e);
			idxApellido->add(e);
			idxArea->add(e);
			idxCts->add(e);
			idxEdad->add(e);
			idxMeses->add(e);
			idxSueldo->add(e);
			idxIndis->add(e);

		}
		
	}
	void mostrarArbol()
	{
		for (auto e : ListaEmpleados)
		{
			e->mostrar();
		};
	}
	void ordenarNombre()
	{
		auto print = [](Empleado* e) {return e->mostrar(); };
		idxNombre->inOrder(print);
	}
	void ordenarTipo()
	{
		int opc;
		cout << "ingresar por que odenar: "; cin >> opc;
		auto print = [](Empleado* e) {return e->mostrar(); };
		if (opc == 1)
		{
			idxNombre->inOrder(print);
		}
		else if (opc == 2)
		{
			idxApellido->inOrder(print);
		}
		else if (opc == 3)
		{
			idxArea->inOrder(print);
		}
		else if (opc == 4)
		{
			idxCts->inOrder(print);
		}
		else if (opc == 5)
		{
			idxEdad->inOrder(print);
		}
		else if (opc == 6)
		{
			idxMeses->inOrder(print);
		}
		else if (opc == 7)
		{
			idxSueldo->inOrder(print);
		}
		else if (opc == 8)
		{
			idxIndis->inOrder(print);
		}
		else
		{
			cout << "Indique un valor correcto.";
		}
	}
	void buscar()
	{
		int opc;
		string nombre;
		string apellido;
		string area;
		short sueldo;
		short edad;
		short meses;
		short cts;
		bool pers_indispensable;
		cout << "�En que columna quieres bucar? "; cin >> opc;
		auto print = [](Empleado* e) {return e->mostrar(); };
		switch (opc)
		{
		case 1:
			cout << "Ingresa el nombre a buscar: "; cin >> nombre;
			print(idxNombre->find(nombre));
			break;
		case 2:
			cout << "Ingresa el apellido a buscar: "; cin >> apellido;
			print(idxApellido->find(apellido));
			break;
		case 3:
			cout << "Ingrese la edad a buscar: "; cin >> edad;
			print(idxEdad->find(edad));
			break;
		case 4:
			cout << "Ingrese el area a buscar: "; cin >> area;
			print(idxArea->find(area));
			break;
		case 5:
			cout << "Ingrese sueldo a buscar: "; cin >> sueldo;
			print(idxSueldo->find(sueldo));
			break;
		case 6:
			cout << "Ingrese meses: "; cin >> meses;
			print(idxMeses->find(meses));
			break;
		case 7:
			cout << "Ingrese la edad a buscar: "; cin >> cts;
			print(idxEdad->find(cts));
			break;
		default:
			break;
		}
		/*
		if (opc == 1)
		{
			string nombre;
			cout << "Ingresa el nombre a buscar: "; cin >> nombre;
			print(idxNombre->find(nombre));
		}
		else if (opc == 2)
		{
			string apellido;
			cout << "Ingresa el apellido a buscar: "; cin >> apellido;
			print(idxApellido->find(apellido));
		}
		else if (opc == 3)
		{
			int edad;
			cout << "Ingrese la edad a buscar: "; cin >> edad;
			print(idxEdad->find(edad));
		
		}
		else if (opc == 4)
		{
			string area;
			cout << "Ingrese el area a buscar: "; cin >> area;
			print(idxArea->find(area));

		}
		else if (opc == 5)
		{
			int sueldo;
			cout << "Ingrese sueldo a buscar: "; cin >> sueldo;
			print(idxSueldo->find(sueldo));
		}
		else if (opc == 6)
		{
			int meses;
			cout << "Ingrese meses: "; cin >> meses;
			print(idxMeses->find(meses));
		}
		else if (opc == 7)
		{
			short cts;
			cout << "Ingrese la edad a buscar: "; cin >> cts;
			print(idxEdad->find(cts));
		}
		else if (opc == 8)
		{
			
		}
		else
		{
			cout << "Ingrese una opcion correcta.";
		}
		*/
	}
};