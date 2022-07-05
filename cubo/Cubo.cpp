
#include "Cubo.h"
#include <iostream>
#include "Cara.h"

using namespace std;

Cubo::Cubo() {
	caras[0] = Cara();
	caras[1] = Cara();
	caras[2] = Cara();
	caras[3] = Cara();
	caras[4] = Cara();
	caras[5] = Cara();
	
}
/*void Cubo::setCara0() {
	string value;
	for (int i = 0; i < 3; i++ ) {
		for (int j = 0; j < 3; j++) {
			
			cin >> value;
			caras[0]->setCara(i, j, value);

		}
	}
}
void Cubo::setCara1() {
	string value;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			

			cin >> value;
			caras[1]->setCara(i, j, value);

		}
	}
}
void Cubo::setCara2() {
	string value;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			cin >> value;
			caras[2]->setCara(i,j,value);

		}
	}
}
void Cubo::setCara3() {
	string value;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			cin >> value;
			caras[3]->setCara(i, j, value);

		}
	}
}
void Cubo::setCara4() {
	string value;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			cin >> value;
			caras[4]->setCara(i, j, value);

		}
	}
}*/
void Cubo::setCaras(int num) {
	string value;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			cin >> value;
			caras[num].setCara(i, j, value);

		}
	}
}

void Cubo::mostrarCara(int cara) {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << caras[cara].getCara(i, j) << " ";
		}
		cout << endl;
	}cout << endl;
}
void Cubo::mostrarTodo() {
	Cubo::mostrarCara(0);
	Cubo::mostrarCara(1);
	Cubo::mostrarCara(2);
	Cubo::mostrarCara(3);
	Cubo::mostrarCara(4);
	Cubo::mostrarCara(5);
}

void Cubo::rotarDerecha(int caraAmover, int caraTope, int caraDer, int caraIzq, int caraFondo) {

	string auxT[3];
	string auxD[3];
	string auxI[3];
	string auxF[3];
	string auxM[3][3];

	for (int i = 0; i < 3; i++) {
		auxT[i] = caras[caraTope].getCara(2, i);//      caraTope[2][i];
		auxD[i] = caras[caraDer].getCara(i,0); //caraDer[i][0];
		auxF[i] = caras[caraFondo].getCara(0, i);//caraFondo[0][i];
		auxI[i] = caras[caraIzq].getCara(i, 2);//caraIzq[i][2];

	}

	for (int j = 0; j < 3; j++) {
		caras[caraTope].setCara(2, j, auxI[2 - j]); // [2] [j] = auxI[2 - j];
		caras[caraDer].setCara(j, 0, auxT[j]); //caraDer[j][0]=auxT[j];
		caras[caraFondo].setCara( 0, j, auxD[2 - j]); //caraFondo[0][j]=auxD[2-j];
		caras[caraIzq].setCara( j, 2, auxF[j]); //caraIzq[j][2]=auxF[j];
	}

	auxM[0][0] = caras[caraAmover].getCara(2,0);
	auxM[0][1] = caras[caraAmover].getCara(1, 0); //caraAmover[1][0];
	auxM[0][2] = caras[caraAmover].getCara(0, 0); //caraAmover[0][0];
	auxM[1][0] = caras[caraAmover].getCara(2, 1); //caraAmover[2][1];
	auxM[1][1] = caras[caraAmover].getCara(1, 1); //caraAmover[1][1];
	auxM[1][2] = caras[caraAmover].getCara(0, 1); //caraAmover[0][1];
	auxM[2][0] = caras[caraAmover].getCara(2, 2); //caraAmover[2][2];
	auxM[2][1] = caras[caraAmover].getCara(1, 2); //caraAmover[1][2];
	auxM[2][2] = caras[caraAmover].getCara(0, 2); //caraAmover[0][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			caras[caraAmover].setCara(i, j,auxM[i][j] ) ;
		}
	}
}

void Cubo::rotarIzquierda(int caraAmover, int caraTope, int caraDer, int caraIzq, int caraFondo) {

	string auxT[3];
	string auxD[3];
	string auxI[3];
	string auxF[3];
	string auxM[3][3];

	for (int i = 0; i < 3; i++) {
		/*auxT[i] = caraTope[2][i];
		auxD[i] = caraDer[i][0];
		auxF[i] = caraFondo[0][i];
		auxI[i] = caraIzq[i][2];*/

		auxT[i] = caras[caraTope].getCara(2, i);//      caraTope[2][i];
		auxD[i] = caras[caraDer].getCara(i, 0); //caraDer[i][0];
		auxF[i] = caras[caraFondo].getCara(0, i);//caraFondo[0][i];
		auxI[i] = caras[caraIzq].getCara(i, 2);//caraIzq[i][2];


	}

	for (int j = 0; j < 3; j++) {
		/*caraTope[2][j] = auxD[j];
		caraDer[j][0] = auxF[2-j];
		caraFondo[0][j] = auxI[j];
		caraIzq[j][2] = auxT[2-j];*/
	
		caras[caraTope].setCara(2, j, auxD[j]); // [2] [j] = auxI[2 - j];
		caras[caraDer].setCara(j, 0, auxF[2 - j]); //caraDer[j][0]=auxT[j];
		caras[caraFondo].setCara(0, j, auxI[j]); //caraFondo[0][j]=auxD[2-j];
		caras[caraIzq].setCara(j, 2, auxT[2 - j]); //caraIzq[j][2]=auxF[j];
	
	
	
	}
	/*auxM[0][0] = caraAmover[0][2];
	auxM[0][1] = caraAmover[1][2];
	auxM[0][2] = caraAmover[2][2];
	auxM[1][0] = caraAmover[0][1];
	auxM[1][1] = caraAmover[1][1];
	auxM[1][2] = caraAmover[2][1];
	auxM[2][0] = caraAmover[0][0];
	auxM[2][1] = caraAmover[1][0];
	auxM[2][2] = caraAmover[2][0];*/

	auxM[0][0] = caras[caraAmover].getCara(0, 2);
	auxM[0][1] = caras[caraAmover].getCara(1, 2); //caraAmover[1][0];
	auxM[0][2] = caras[caraAmover].getCara(2, 2); //caraAmover[0][0];
	auxM[1][0] = caras[caraAmover].getCara(0, 1); //caraAmover[2][1];
	auxM[1][1] = caras[caraAmover].getCara(1, 1); //caraAmover[1][1];
	auxM[1][2] = caras[caraAmover].getCara(2, 1); //caraAmover[0][1];
	auxM[2][0] = caras[caraAmover].getCara(0, 0); //caraAmover[2][2];
	auxM[2][1] = caras[caraAmover].getCara(1, 0); //caraAmover[1][2];
	auxM[2][2] = caras[caraAmover].getCara(2, 0); //caraAmover[0][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//caraAmover[i][j] = auxM[i][j];
			caras[caraAmover].setCara(i, j, auxM[i][j]);
		}
	}
}
