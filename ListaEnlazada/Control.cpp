#include "Control.h"

Control::Control() {
	Lis = new List;
}

int Control::menu() {

	int option;
	do {
		system("CLS"); 
		cout << "-------------------------------" << endl;
		cout << "----------- PERSONAS ----------" << endl;
		cout << "-------------------------------" << endl;
		cout << "[1]-Ver lista de personas" << endl;
		cout << "[2]-Agregar nueva persona" << endl;
		cout << "[3]-Buscar una persona" << endl;
		cout << "[4]-Eliminar una persona" << endl;
		cout << "[5]-Modificar una persona" << endl;
		cout << "[6]-Salir" << endl;
		cout << "Opcion: ";
		cin >> option;

		if (cin.fail()) //si se ingresan caracteres 
		{
			cin.clear(); //limpiar carecteres
			cin.ignore(1024, '\n'); //ignorar
			cout << "Ingrese solo valores numericos"<<endl;
			Sleep(1000);
			option = menu();
		}

		if (option > 6 || option < 1)
		{
			cout << "Ingrese solo valores entre [1-5]" << endl; 
			Sleep(1000);
			option = menu();
		}

		switch (option)
		{
		case 1: listPerson();
				break;

		case 2: inputNewPerson();
				break;

		case 3: searchPerson();
				break;

		case 4: deletePerson();
				break;

		case 5: modifyPerson();
				break;
		default:
			break;
		}

	} while (option !=6);
	
	return option;
}


void Control::controller() {

	Lis->loadData();
	menu();
	Lis->saveData();
}

//metodo listar personas que estan en el archivoTXT
void Control::listPerson() {

	system("CLS");
	cout << Lis->toString() << endl;
	system("PAUSE");
}

//metodo insertar nuevas personas por id unico
void Control::inputNewPerson() {
	
	system("CLS");
	string name, lst, id;
	int age;

	Person* Per;
	
	cout << "Ingrese el nombre: ";
	cin >> name;
	cout << "Ingrese su apellido: ";
	cin >> lst;
	cout << "Ingrese la cedula: ";
	cin >> id;
	cout << "Ingrese la edad: ";
	cin >> age;

	Per = Lis->listPeople(id);

	if (Per == NULL) //Si es nula, es decir esa persona no existe en la lista
	{
		//se le manda los parametros para crearla
		Lis->inputPerson(new Person(name, lst, id, age));
	
	}
	else {//Si existe
		cout << "Ya existe esta persona!" << endl;
		Sleep(1500);
	}

}

//metodo buscar persona
void Control::searchPerson() {

	system("CLS");
	string id;
	Person* Per;

	cout << "Ingrese la cedula: ";
	cin >> id;

	Per = Lis->listPeople(id);

	if (Per != NULL) //Si no esta vacia, que muestre esa persona
	{
		system("CLS");
		cout << Per->toString() << endl;
		system("PAUSE");
	
	}
	else {//No existe la persona con esa cedula
		cout << "No existe esa persona!" << endl;
		Sleep(1500);
	}

}

//metodo eliminar persona
void Control::deletePerson() {
	
	system("CLS");
	string id;
	Person* Per;

	cout << Lis->toString();
	cout << "Ingrese la cedula de la persona a eliminar: ";
	cin >> id;

	Per = Lis->deletePer(id); //se envia el id a eliminar

	if (Per != NULL) //Si la lista no esta vacia, es porque se encontro ese id a eliminar
	{
		delete Per; //se borra
		cout << "**** Persona Eliminada ****" << endl;
		Sleep(1500);

	}
	else {//Sino es porque no existe ese id en la lista
		cout << "No existe esa persona en la lista!" << endl;
		Sleep(1500);
	}
}

void Control::modifyPerson() {

	system("CLS");
	Person *aux;
	string id, newName;

	cout << Lis->toString();

	cout << "Ingrese la cedula de la persona a modificar: ";
	cin >> id;
	aux = Lis->listPeople(id);

	if (aux != NULL)
	{
		cout << "Ingrese el nuevo nombre: ";
		cin >> newName;
		aux->setName(newName);
	
	}
	else {
		cout << "No existe esa persona!"<<endl;
		Sleep(1500);
	}
}


Control::~Control() {

}