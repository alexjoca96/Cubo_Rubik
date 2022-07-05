#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int movs = 0;



class cubo {
	//atributos
public:
	char caras0[3][3];
	char caras1[3][3];
	char caras2[3][3];
	char caras3[3][3];
	char caras4[3][3];
	char caras5[3][3];
	//variables auxiliares
	int mejor, pos;
	int carass[25];
	int sentido[25];
	int solsentido[25];
	int solcaras[25];
	//metodos
public:
	void cubos() { //Constructor por defecto
		mejor = 0;
		pos = 0;
		movs = 0;
		for (int i = 0; i < 25; i++) {
			carass[i] = 0;
			sentido[i] = 0;
			solsentido[i] = 0;
			solcaras[i] = 0;

		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				caras0[i][j] = ' ';
				caras1[i][j] = ' ';
				caras2[i][j] = ' ';
				caras3[i][j] = ' ';
				caras4[i][j] = ' ';
				caras5[i][j] = ' ';
			}
		}


	}
	void rotar(int num_cara, int direccion) {
		char A, B, C, D, E, F, G, H, I, J, K, L;
		if (num_cara == 0 && direccion == 1) {
			A = caras0[0][0];
			B = caras0[0][2];
			C = caras0[2][2];
			D = caras0[2][0];
			caras0[0][2] = A;
			caras0[2][2] = B;
			caras0[2][0] = C;
			caras0[0][0] = D;
			A = caras0[0][1];
			B = caras0[1][0];
			C = caras0[2][1];
			D = caras0[1][2];
			caras0[1][2] = A;
			caras0[0][1] = B;
			caras0[1][0] = C;
			caras0[2][1] = D;
			A = caras1[0][2];
			B = caras1[0][1];
			C = caras1[0][0];
			D = caras4[0][2];
			E = caras4[0][1];
			F = caras4[0][0];
			G = caras3[0][2];
			H = caras3[0][1];
			I = caras3[0][0];
			J = caras2[0][2];
			K = caras2[0][1];
			L = caras2[0][0];
			caras4[0][2] = A;
			caras4[0][1] = B;
			caras4[0][0] = C;
			caras3[0][2] = D;
			caras3[0][1] = E;
			caras3[0][0] = F;
			caras2[0][2] = G;
			caras2[0][1] = H;
			caras2[0][0] = I;
			caras1[0][2] = J;
			caras1[0][1] = K;
			caras1[0][0] = L;
		}
		if (num_cara == 1 && direccion == 1) {
			A = caras1[0][0];
			B = caras1[0][2];
			C = caras1[2][2];
			D = caras1[2][0];
			caras1[0][2] = A;
			caras1[2][2] = B;
			caras1[2][0] = C;
			caras1[0][0] = D;
			A = caras1[0][1];
			B = caras1[1][0];
			C = caras1[2][1];
			D = caras1[1][2];
			caras1[1][2] = A;
			caras1[0][1] = B;
			caras1[1][0] = C;
			caras1[2][1] = D;
			A = caras5[0][2];
			B = caras5[0][1];
			C = caras5[0][0];
			D = caras4[2][2];
			E = caras4[1][2];
			F = caras4[0][2];
			G = caras0[2][0];
			H = caras0[2][1];
			I = caras0[2][2];
			J = caras2[0][0];
			K = caras2[1][0];
			L = caras2[2][0];
			caras4[2][2] = A;
			caras4[1][2] = B;
			caras4[0][2] = C;
			caras0[2][0] = D;
			caras0[2][1] = E;
			caras0[2][2] = F;
			caras2[0][0] = G;
			caras2[1][0] = H;
			caras2[2][0] = I;
			caras5[0][2] = J;
			caras5[0][1] = K;
			caras5[0][0] = L;
		}
		if (num_cara == 2 && direccion == 1) {
			A = caras2[0][0];
			B = caras2[0][2];
			C = caras2[2][2];
			D = caras2[2][0];
			caras2[0][2] = A;
			caras2[2][2] = B;
			caras2[2][0] = C;
			caras2[0][0] = D;
			A = caras2[0][1];
			B = caras2[1][0];
			C = caras2[2][1];
			D = caras2[1][2];
			caras2[1][2] = A;
			caras2[0][1] = B;
			caras2[1][0] = C;
			caras2[2][1] = D;
			A = caras5[2][2];
			B = caras5[1][2];
			C = caras5[0][2];
			D = caras1[2][2];
			E = caras1[1][2];
			F = caras1[0][2];
			G = caras0[2][2];
			H = caras0[1][2];
			I = caras0[0][2];
			J = caras3[0][0];
			K = caras3[1][0];
			L = caras3[2][0];
			caras1[2][2] = A;
			caras1[1][2] = B;
			caras1[0][2] = C;
			caras0[2][2] = D;
			caras0[1][2] = E;
			caras0[0][2] = F;
			caras3[0][0] = G;
			caras3[1][0] = H;
			caras3[2][0] = I;
			caras5[2][2] = J;
			caras5[1][2] = K;
			caras5[0][2] = L;
		}
		if (num_cara == 3 && direccion == 1) {
			A = caras3[0][0];
			B = caras3[0][2];
			C = caras3[2][2];
			D = caras3[2][0];
			caras3[0][2] = A;
			caras3[2][2] = B;
			caras3[2][0] = C;
			caras3[0][0] = D;
			A = caras3[0][1];
			B = caras3[1][0];
			C = caras3[2][1];
			D = caras3[1][2];
			caras3[1][2] = A;
			caras3[0][1] = B;
			caras3[1][0] = C;
			caras3[2][1] = D;
			A = caras5[2][0];
			B = caras5[2][1];
			C = caras5[2][2];
			D = caras2[2][2];
			E = caras2[1][2];
			F = caras2[0][2];
			G = caras0[0][2];
			H = caras0[0][1];
			I = caras0[0][0];
			J = caras4[0][0];
			K = caras4[1][0];
			L = caras4[2][0];
			caras2[2][2] = A;
			caras2[1][2] = B;
			caras2[0][2] = C;
			caras0[0][2] = D;
			caras0[0][1] = E;
			caras0[0][0] = F;
			caras4[0][0] = G;
			caras4[1][0] = H;
			caras4[2][0] = I;
			caras5[2][0] = J;
			caras5[2][1] = K;
			caras5[2][2] = L;
		}
		if (num_cara == 4 && direccion == 1) {
			A = caras4[0][0];
			B = caras4[0][2];
			C = caras4[2][2];
			D = caras4[2][0];
			caras4[0][2] = A;
			caras4[2][2] = B;
			caras4[2][0] = C;
			caras4[0][0] = D;
			A = caras4[0][1];
			B = caras4[1][0];
			C = caras4[2][1];
			D = caras4[1][2];
			caras4[1][2] = A;
			caras4[0][1] = B;
			caras4[1][0] = C;
			caras4[2][1] = D;
			A = caras5[0][0];
			B = caras5[1][0];
			C = caras5[2][0];
			D = caras3[2][2];
			E = caras3[1][2];
			F = caras3[0][2];
			G = caras0[0][0];
			H = caras0[1][0];
			I = caras0[2][0];
			J = caras1[0][0];
			K = caras1[1][0];
			L = caras1[2][0];
			caras3[2][2] = A;
			caras3[1][2] = B;
			caras3[0][2] = C;
			caras0[0][0] = D;
			caras0[1][0] = E;
			caras0[2][0] = F;
			caras1[0][0] = G;
			caras1[1][0] = H;
			caras1[2][0] = I;
			caras5[0][0] = J;
			caras5[1][0] = K;
			caras5[2][0] = L;
		}
		if (num_cara == 5 && direccion == 1) {

			A = caras5[0][0];
			B = caras5[0][2];
			C = caras5[2][2];
			D = caras5[2][0];
			caras5[0][2] = A;
			caras5[2][2] = B;
			caras5[2][0] = C;
			caras5[0][0] = D;
			A = caras5[0][1];
			B = caras5[1][0];
			C = caras5[2][1];
			D = caras5[1][2];
			caras5[1][2] = A;
			caras5[0][1] = B;
			caras5[1][0] = C;
			caras5[2][1] = D;
			A = caras3[2][0];
			B = caras3[2][1];
			C = caras3[2][2];
			D = caras4[2][0];
			E = caras4[2][1];
			F = caras4[2][2];
			G = caras1[2][0];
			H = caras1[2][1];
			I = caras1[2][2];
			J = caras2[2][0];
			K = caras2[2][1];
			L = caras2[2][2];
			caras4[2][0] = A;
			caras4[2][1] = B;
			caras4[2][2] = C;
			caras1[2][0] = D;
			caras1[2][1] = E;
			caras1[2][2] = F;
			caras2[2][0] = G;
			caras2[2][1] = H;
			caras2[2][2] = I;
			caras3[2][0] = J;
			caras3[2][1] = K;
			caras3[2][2] = L;
		}
		//empieza a girar en sentido antihorario
		if (num_cara == 0 && direccion == 0) {
			A = caras0[0][0];
			B = caras0[0][2];
			C = caras0[2][2];
			D = caras0[2][0];
			caras0[0][2] = C;
			caras0[2][2] = D;
			caras0[2][0] = A;
			caras0[0][0] = B;
			A = caras0[0][1];
			B = caras0[1][0];
			C = caras0[2][1];
			D = caras0[1][2];
			caras0[1][2] = C;
			caras0[0][1] = D;
			caras0[1][0] = A;
			caras0[2][1] = B;
			C = caras1[0][0];
			B = caras1[0][1];
			A = caras1[0][2];
			L = caras2[0][0];
			K = caras2[0][1];
			J = caras2[0][2];
			I = caras3[0][0];
			H = caras3[0][1];
			G = caras3[0][2];
			F = caras4[0][0];
			E = caras4[0][1];
			D = caras4[0][2];
			caras2[0][0] = C;
			caras2[0][1] = B;
			caras2[0][2] = A;
			caras3[0][0] = L;
			caras3[0][1] = K;
			caras3[0][2] = J;
			caras4[0][0] = I;
			caras4[0][1] = H;
			caras4[0][2] = G;
			caras1[0][0] = F;
			caras1[0][1] = E;
			caras1[0][2] = D;
		}
		if (num_cara == 1 && direccion == 0) {

			A = caras1[0][0];
			B = caras1[0][2];
			C = caras1[2][2];
			D = caras1[2][0];
			caras1[0][2] = C;
			caras1[2][2] = D;
			caras1[2][0] = A;
			caras1[0][0] = B;
			A = caras1[0][1];
			B = caras1[1][0];
			C = caras1[2][1];
			D = caras1[1][2];
			caras1[1][2] = C;
			caras1[0][1] = D;
			caras1[1][0] = A;
			caras1[2][1] = B;
			C = caras5[0][0];
			B = caras5[0][1];
			A = caras5[0][2];
			L = caras2[2][0];
			K = caras2[1][0];
			J = caras2[0][0];
			I = caras0[2][2];
			H = caras0[2][1];
			G = caras0[2][0];
			F = caras4[0][2];
			E = caras4[1][2];
			D = caras4[2][2];
			caras2[2][0] = C;
			caras2[1][0] = B;
			caras2[0][0] = A;
			caras0[2][2] = L;
			caras0[2][1] = K;
			caras0[2][0] = J;
			caras4[0][2] = I;
			caras4[1][2] = H;
			caras4[2][2] = G;
			caras5[0][0] = F;
			caras5[0][1] = E;
			caras5[0][2] = D;
		}
		if (num_cara == 2 && direccion == 0) {
			A = caras2[0][0];
			B = caras2[0][2];
			C = caras2[2][2];
			D = caras2[2][0];
			caras2[0][2] = C;
			caras2[2][2] = D;
			caras2[2][0] = A;
			caras2[0][0] = B;
			A = caras2[0][1];
			B = caras2[1][0];
			C = caras2[2][1];
			D = caras2[1][2];
			caras2[1][2] = C;
			caras2[0][1] = D;
			caras2[1][0] = A;
			caras2[2][1] = B;
			C = caras5[0][2];
			B = caras5[1][2];
			A = caras5[2][2];
			L = caras3[2][0];
			K = caras3[1][0];
			J = caras3[0][0];
			I = caras0[0][2];
			H = caras0[1][2];
			G = caras0[2][2];
			F = caras1[0][2];
			E = caras1[1][2];
			D = caras1[2][2];
			caras3[2][0] = C;
			caras3[1][0] = B;
			caras3[0][0] = A;
			caras0[0][2] = L;
			caras0[1][2] = K;
			caras0[2][2] = J;
			caras1[0][2] = I;
			caras1[1][2] = H;
			caras1[2][2] = G;
			caras5[0][2] = F;
			caras5[1][2] = E;
			caras5[2][2] = D;
		}
		if (num_cara == 3 && direccion == 0) {
			A = caras3[0][0];
			B = caras3[0][2];
			C = caras3[2][2];
			D = caras3[2][0];
			caras3[0][2] = C;
			caras3[2][2] = D;
			caras3[2][0] = A;
			caras3[0][0] = B;
			A = caras3[0][1];
			B = caras3[1][0];
			C = caras3[2][1];
			D = caras3[1][2];
			caras3[1][2] = C;
			caras3[0][1] = D;
			caras3[1][0] = A;
			caras3[2][1] = B;
			C = caras5[2][2];
			B = caras5[2][1];
			A = caras5[2][0];
			L = caras4[2][0];
			K = caras4[1][0];
			J = caras4[0][0];
			I = caras0[0][0];
			H = caras0[0][1];
			G = caras0[0][2];
			F = caras1[0][2];
			E = caras1[1][2];
			D = caras1[2][2];
			caras4[2][0] = C;
			caras4[1][0] = B;
			caras4[0][0] = A;
			caras0[0][0] = L;
			caras0[0][1] = K;
			caras0[0][2] = J;
			caras1[0][2] = I;
			caras1[1][2] = H;
			caras1[2][2] = G;
			caras5[2][2] = F;
			caras5[2][1] = E;
			caras5[2][0] = D;
		}
		if (num_cara == 4 && direccion == 0) {
			A = caras4[0][0];
			B = caras4[0][2];
			C = caras4[2][2];
			D = caras4[2][0];
			caras4[0][2] = C;
			caras4[2][2] = D;
			caras4[2][0] = A;
			caras4[0][0] = B;
			A = caras4[0][1];
			B = caras4[1][0];
			C = caras4[2][1];
			D = caras4[1][2];
			caras4[1][2] = C;
			caras4[0][1] = D;
			caras4[1][0] = A;
			caras4[2][1] = B;
			C = caras5[2][0];
			B = caras5[1][0];
			A = caras5[0][0];
			L = caras1[2][0];
			K = caras1[1][0];
			J = caras1[0][0];
			I = caras0[2][0];
			H = caras0[1][0];
			G = caras0[0][0];
			F = caras3[0][2];
			E = caras3[1][2];
			D = caras3[2][2];
			caras1[2][0] = C;
			caras1[1][0] = B;
			caras1[0][0] = A;
			caras0[2][0] = L;
			caras0[1][0] = K;
			caras0[0][0] = J;
			caras3[0][2] = I;
			caras3[1][2] = H;
			caras3[2][2] = G;
			caras5[2][0] = F;
			caras5[1][0] = E;
			caras5[0][0] = D;
		}
		if (num_cara == 5 && direccion == 0) {
			A = caras5[0][0];
			B = caras5[0][2];
			C = caras5[2][2];
			D = caras5[2][0];
			caras5[0][2] = C;
			caras5[2][2] = D;
			caras5[2][0] = A;
			caras5[0][0] = B;
			A = caras5[0][1];
			B = caras5[1][0];
			C = caras5[2][1];
			D = caras5[1][2];
			caras5[1][2] = C;
			caras5[0][1] = D;
			caras5[1][0] = A;
			caras5[2][1] = B;
			C = caras3[2][2];
			B = caras3[2][1];
			A = caras3[2][0];
			L = caras2[2][2];
			K = caras2[2][1];
			J = caras2[2][0];
			I = caras1[2][2];
			H = caras1[2][1];
			G = caras1[2][0];
			F = caras4[2][2];
			E = caras4[2][1];
			D = caras4[2][0];
			caras2[2][2] = C;
			caras2[2][1] = B;
			caras2[2][0] = A;
			caras1[2][2] = L;
			caras1[2][1] = K;
			caras1[2][0] = J;
			caras4[2][2] = I;
			caras4[2][1] = H;
			caras4[2][0] = G;
			caras3[2][2] = F;
			caras3[2][1] = E;
			caras3[2][0] = D;
		}

	}

	void setvalor(char c, int num_cara) {
		int i, j;
		if (num_cara == 0) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					caras0[i][j] = c;
				}
			}
		}

		if (num_cara == 1) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					caras1[i][j] = c;
				}
			}
		}

		if (num_cara == 2) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					caras2[i][j] = c;
				}
			}
		}

		if (num_cara == 3) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					caras3[i][j] = c;
				}
			}
		}

		if (num_cara == 4) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					caras4[i][j] = c;
				}
			}
		}

		if (num_cara == 5) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					caras5[i][j] = c;
				}
			}
		}

	}

	int bt(int movs) {

		if (movs > 25) { return 0xffffffff; }
		if (validarw() && validarr() && validarb() && validarg() && validaro() && validary()) {
			if (movs < mejor) {
				for (int i = 0; i < pos; i++) {
					solcaras[i] = carass[i];
					solsentido[i] = sentido[i];
				} mejor = movs;
			}

		}
		else {

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 2; j++) {

					carass[pos] = i;
					sentido[pos] = j;
					pos++;
					rotar(i, j);
					bt(movs + 1);
					rotar(i, !j);
					pos--;
				}
			}
		}
	}

	bool validarw() {

		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (caras0[i][j] != 'w') {
					return false;
				}
				else { return true; }


			}
		}
	}

	bool validarr() {

		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (caras1[i][j] != 'r') {
					return false;
				}
				else { return true; }

			}
		}


	}


	bool validarb() {

		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (caras2[i][j] != 'b') {
					return false;
				}
				else { return true; }

			}
		}


	}


	bool validarg() {

		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (caras4[i][j] != 'g') {
					return false;
				}
				else { return true; }

			}
		}


	}



	bool validaro() {

		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (caras3[i][j] != 'o') {
					return false;
				}
				else { return true; }

			}
		}


	}


	bool validary() {

		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (caras5[i][j] != 'y') {
					return false;
				}
				else { return true; }

			}
		}

	}



};













int main() {

	int  i, j;
	cubo* rubik;
	char c;
	rubik = new cubo;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> c;
			rubik->caras1[i][j] = c;
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> c;
			rubik->caras2[i][j] = c;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> c;
			rubik->caras4[i][j] = c;
		}
	}



	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> c;
			rubik->caras0[i][j] = c;
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> c;
			rubik->caras3[i][j] = c;
		}
	}



	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> c;
			rubik->caras5[i][j] = c;
		}
	}





	rubik->bt(movs);
	cout << rubik->mejor << endl;
	for (int i = 0; i < rubik->mejor; i++) {
		cout << rubik->solcaras[i] << " " << rubik->solsentido[i];
		cout << endl;


	}


}










