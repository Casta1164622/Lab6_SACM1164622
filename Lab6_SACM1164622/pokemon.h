#pragma once
#include <string>
using namespace std;
class pokemon
{
	string nombre;
	int generacion;
	int nationalNumber;

public:
	pokemon() {}
	pokemon(string nombre, int generacion, int nationalNumber) 
	{
		this->nombre = nombre;
		this->generacion = generacion;
		this->nationalNumber = nationalNumber;
	}

	string GetNombre() 
	{
		return nombre;
	}
	int getGeneracion() 
	{
		return generacion;
	}
	int getNationalNumber()
	{
		return nationalNumber;
	}
};

