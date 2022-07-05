#include "Cara.h"
#include <iostream>
#include <string>


Cara::Cara() {
/*	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {*/
			this->cara[0][0] = "def";
			this->cara[0][1] = "def";
			this->cara[0][2] = "def";
			this->cara[1][0] = "def";
			this->cara[1][1] = "def";
			this->cara[1][2] = "def";
			this->cara[2][0] = "def";
			this->cara[2][1] = "def";
			this->cara[2][2] = "def";
		/*}
	}*/
}

void Cara::setCara(int fila, int col,std::string value) {
	
	cara[fila][col]=value;

}
std::string Cara::getCara(int fila,int col) {
	return cara[fila][col];
}
