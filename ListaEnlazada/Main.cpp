#include <iostream>
#include <fstream>
#include "Control.h";
using namespace std;

int main()
{ 
    Control* Con = new Control; //crear un nuevo control

    Con->controller();
    
    delete Con; //liberar memoria

    
}
