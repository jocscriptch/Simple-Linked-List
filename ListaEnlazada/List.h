#pragma once
#include "Node.h";

class List
{
public:

	List();
	void inputPerson(Person *); //recibe una persona por puntero
	string toString();

	
	void saveData(); //metodo guardar datos
	void loadData(); //metodo cargar datos

	Person* listPeople(string); //metodo para verificar la lista de personas

	Person* deletePer(string); //eliminar persona de la lista

	void deleteNode(Node*, Node*);


	~List();

private:
	Node *firstNode; //atributo nodo puntero primero




};

