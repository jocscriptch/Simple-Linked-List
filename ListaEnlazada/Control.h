#pragma once
#include "List.h";
#include <cstdlib>
#include <windows.h>

class Control
{
public:
	Control(); //Constructor
	int menu(); //metodo menu
	void controller(); //metodo controlador

	void listPerson(); //metodo listar personas
	void inputNewPerson(); //metodo ingresar personas
	void searchPerson(); //metodo buscar persona
	void deletePerson(); //metodo eliminar persona
	void modifyPerson(); //metodo modificar persona
	
	~Control();
private:
	List *Lis; //atributo de tipo lista
};

