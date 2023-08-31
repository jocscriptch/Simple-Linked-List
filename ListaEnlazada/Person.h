#pragma once
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
using namespace std;

class Person
{
public:
	Person();
	Person(string, string, string, int);
	string toString();

	//metodo para guardar en archivo.txt
	void saveTxt(ofstream &); //recibe un objeto por referencia

	Person *readTxt(ifstream &); //leer archivo recibe un objeto por referencia

	string getId(); //metodo para obtener el id "cedula"

	void setName(string); //metodo para setear el nombre

	~Person();
private:
	string Name;
	string Lastname;
	string Id;
	int Age;
};

