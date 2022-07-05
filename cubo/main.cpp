#include <iostream>
#include <string>
#include <fstream>
#include "Cubo.h"
using namespace std;



int main() {
	int cara;
	string  rotacion="";
	Cubo* rubik= new Cubo();

	rubik->setCaras(0);
	rubik->setCaras(1);
	rubik->setCaras(2);
	rubik->setCaras(3);
	rubik->setCaras(4);
	rubik->setCaras(5);
	
	do{

	cout << "Introduzca el numero de cara a mover" << endl;
	cin >> cara;
	cout << "Que rotacion desea: izq o der" << endl;
	cin >> rotacion;

	if (rotacion.compare("izq")==0) {
		switch (cara)
		{
		case 0: 
			rubik->rotarIzquierda(0, 3, 2, 4, 1);

			break;
		case 1:
			rubik->rotarIzquierda(1, 0, 2, 4, 5);
			break;
		case 2:
			rubik->rotarIzquierda(2, 0, 3, 1, 5);
			break;
		case 3:
			rubik->rotarIzquierda(3, 0, 4, 2, 5);
			break;
		case 4:
			rubik->rotarIzquierda(4, 0, 1, 3, 5);
			break;
		case 5:
			rubik->rotarIzquierda(5, 1, 2, 4, 3);
			break;
		default:
			break;
		}
	}
	else if(rotacion.compare("der") == 0) {
		
		switch (cara)
		{
		case 0:
			rubik->rotarDerecha(0, 3, 2, 4, 1);

			break;
		case 1:
			rubik->rotarDerecha(1, 0, 2, 4, 5);
			break;
		case 2:
			rubik->rotarDerecha(2, 0, 3, 1, 5);
			break;
		case 3:
			rubik->rotarDerecha(3, 0, 4, 2, 5);
			break;
		case 4:
			rubik->rotarDerecha(4, 0, 1, 3, 5);
			break;
		case 5:
			rubik->rotarDerecha(5, 1, 2, 4, 3);
			break;
		default:
			break;
		}
	}
	else if(rotacion.compare("mostrar") == 0){
		rubik->mostrarTodo();
	}
		

	} while (rotacion.compare("fin")!=0);
	


	rubik->mostrarTodo();


}



