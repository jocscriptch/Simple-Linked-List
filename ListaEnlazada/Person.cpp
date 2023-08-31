#include "Person.h"

Person::Person(){ //Constructor para inicializar atributos

	Name = "";
	Lastname = "";
	Id = "";
	Age = 0;

}

//Constructor que recibe parametros
Person::Person(string name, string lastname, string id, int age) {

	this->Name = name;
	this->Lastname = lastname;
	this->Id = id;
	this->Age = age;
}

//metodo toString para mostrar los valores
string Person::toString() {

	stringstream s;
	s << "---------- PERSONAS -----------" << endl;
	s << "Nombre ----------------: " << Name<<endl;
	s << "Apellido --------------: " << Lastname << endl;
	s << "Cedula-----------------: " << Id << endl;
	s << "Edad ------------------: " << Age << endl;

	return s.str();
}

//Metodo para guardar en archivoTXT
void Person::saveTxt(ofstream &Write) {

	Write << Name << "\n"; //escribir el nombre en el archivo
	Write << Lastname << "\n";
	Write << Id << "\n";
	Write << Age << "\n";
}

//Metodo leer en archivoTXT
Person *Person::readTxt(ifstream &Read) {

	string name, lst, id;
	int age;

	Read >> name; // Lee el nombre desde el archivo
	Read >> lst;
	Read >> id;
	Read >> age;

	return (new Person(name, lst, id, age)); // Crea y devuelve un nuevo objeto persona
}

//metodo que retorna la cedula
string Person::getId() {

	return Id;
}

//metodo set para el nombre
void Person::setName(string name) {

	Name = name;
}

Person::~Person(){}