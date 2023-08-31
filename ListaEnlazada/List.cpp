#include "List.h"

List::List() {
	firstNode = NULL; //inicializando en nulo al primer puntero
}

void List::inputPerson(Person *per) {
	
	/* El metodo de ingresar una persona recibe 2 tipos de parametros 
	   el primer parametro es la persona y el otro es el puntero siguiente
	   osea el nodo que esta adelante
	*/
	firstNode = new Node(per, firstNode); //enviando parametros
}

string List::toString() {

	stringstream s;
	Node* n = firstNode; //nodo para recorrer la lista es igual al nodo que esta de primero
	Person *Per; //auxiliar para acceder a los datos de la persona en cada nodo

	while (n != NULL) //mientras no sea vacio
	{
		Per = n->getPerson(); //obtener a la persona en el nodo actual n 
		s << Per->toString() << endl; //obtener informacion de la persona por toString()
		n = n->getNext(); //avanzar  al siguiente nodo
	}
	return s.str();

}


//metodo guardar datos 
void List::saveData() {

	Node* n = firstNode;  //puntero n que apunta al primer nodo
	Person* per;  //puntero para la persona
	ofstream Write("Personas.txt", ios::out); //abrir el archivo personas en modo escritura

	while (n!=NULL)
	{
		per = n->getPerson(); //obtener a la persona que esta en el nodo
		per->saveTxt(Write); //se guarda en el archivo
		n = n->getNext();	//se avanza al siguiende nodo
	}
	Write.close(); //cerrar archivo
}

//Cargar datos
void List::loadData() {

	ifstream Read("Personas.txt", ios::in); //leer en el archivo
	Person *Per; //puntero temporal para almacenar una persona
	Person aux; //auxiliar

	Per = aux.readTxt(Read); //leer la informacion de la primer persona del archivo

	while (!Read.eof()) // Mientras no se llegue al final del archivo
	{ 
		inputPerson(Per); //agregar la persona a la lista
		Per = aux.readTxt(Read); //leer la siguiente persona del archivo
	}
	Read.close();
}

//metodo para verificar que la persona ingresada tenga id unico
Person* List::listPeople(string id) {

	Person* aux;
	Node* n = firstNode;

	while (n!= NULL)  // Mientras no se llegue al final de la lista
	{
		aux = n->getPerson(); //obtener un puntero a la persona en el nodo actual
		if (aux->getId() == id) //comparar el id de la persona con el que se recibe por parametro
		{
			return aux; //si se encuentra coincidencia se devuelve la persona
		}
		n = n->getNext(); //avanzar al siguiente nodo

	}
	return NULL; //si la persona no existe dentro de la lista retorna nulo
}


//metodo eliminar persona de la lista recibe la cedula
Person* List::deletePer(string id) {

	Node* n = firstNode; //puntero n que apunta al primer nodo
	Node* aux = NULL; //puntero auxiliar que apunta a nulo
	bool found = false; //boolean encontrado en falso

	Person* Per;

	/* mientras no se llegue al final de la lista 
	y mientras no se haya encontrado a la persona*/
	while (n != NULL && !found) 
	{
		Per = n->getPerson(); //se obtiene el puntero de la persona actual
		if (Per->getId() == id) //compara el id de la persona con el que viene por parametro
		{
			found = true; //si se encuentrar pasa a verdadero
			deleteNode(aux, n); //se borra el nodo
			return Per;
		}
		aux = n; //actualizar aux al nodo actual 
		n = n->getNext(); //avanzar al siguiente nodo

	}
	return NULL; //si no existe la persona sale nulo

}

//borrar nodo de la lista
void List::deleteNode(Node* aux, Node* n) {

	/*Si aux es nulo, significa que el nodo a eliminar es el primer nodo. 
	En este caso, actualiza el puntero firstNode para apuntar al siguiente nodo
	y luego se borra el nodo actual*/
	if (aux == NULL)
	{
		firstNode = n->getNext();

	}
	/*Si aux no es nulo, actualiza el puntero del nodo anterior para que 
	salte el nodo que se va a eliminar, y luego se borra el nodo actual.*/
	else {
		aux->setNext(n->getNext());

	}
	delete n;
}



//Destructor para liberar la memoria
List::~List() {

	Node *n = firstNode; //puntero n que apunta al primer nodo
	Node *aux;	//nodo auxiliar

	while (n != NULL) {
		aux = n->getNext();  // guardar el puntero al siguiente nodo en aux
		delete n;  // se libera la memoria del nodo actual
		n = aux;   // avanzar al siguiente nodo
	}
	firstNode = NULL; //asegurar que el primer nodo se establece como nulo al final
}	
