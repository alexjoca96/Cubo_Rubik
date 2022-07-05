#pragma once


#include "Cara.h"
class Cubo
{
public:
	Cara caras[6];
	

public:
	Cubo();

	void setCaras(int);
	//void setCara1();
	//void setCara2();
	//void setCara3();
	//void setCara4();
	//void setCara5();

	void mostrarTodo();
	void mostrarCara(int);
	void rotarDerecha(int caraAmover, int caraTope, int caraDer, int caraIzq, int caraFondo);
	void rotarIzquierda(int caraAmover, int caraTope, int caraDer, int caraIzq, int caraFondo);

	
};

