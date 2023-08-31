#pragma once
#include "Person.h";

class Node
{
public:
	Node(Person *, Node *);	//Constructor que recibe un objeto persona y un nodo
	
	void setPerson(Person *); //metodo para setear a la persona
	
	Person *getPerson(); //para obtener a la persona
	
	void setNext(Node*); //metodo para setear al nodo
	
	Node *getNext();
	
	~Node(); //Destructor
private:

	//Un nodo esta formado de dos partes el objeto y 
	// el puntero siguiente al enlace al otro nodo

	Person *person; //objeto persona
	Node *next;    //puntero siguiente

};

