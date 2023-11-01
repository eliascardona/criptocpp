#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Este práctinca interesante de informática me mantendra entrenenido
// a lo largo de mi aburrida carrera convencional de informática,
// por otro lado sería perfecto como un proyecto final de la carrera,
// y en fin, cosas muy interesantes y productivas para hacer en la escuela.
// --------------------- OBJETIVO PRINCIPAL --------------------------------
//  Factorizar un número primo N muy grande que sea factor matemático de  dos números primos
//  A continuación los pasos a seguir:
//
//	1. Eleguir un número al azar que pueda quedar dentro del número `N`.
//	2. Encontrar el valor de `r`, para que `g^r = multiploDeN+1`.
//	3. Si r es par, calcular `g^r/2+1` y `g^r/2-1`.
//	4. Si `r` es impar, volver al paso 1 y escoger un número distinto.
//	5. Utilizar el algoritmo de Euclides para hallar el divisor común más grande.
int r10(int &N, int &g);
int step2p1(int rf1, int g2);
int step2p2(int rf1, int g2);
int euclides(int a, int b);

int main() {
	int N=0;
	int g=0;
	int gr = 0;
	int st2 = 0;
	int st3 = 0;

	printf("----------- HORA DE FACTORIZAR ----------\n\n");
	printf("Ingresa un numero primo: ");
	scanf("%d", &N);
	printf("\n");
	printf("Ingresa un numero cualuiera, menor al numero ingresado: ");
	scanf("%d", &g);

	gr = r10(N, g);
	printf("--- %d ---\n\n", gr);
	// ------------
	st2 = step2p1(gr, g);
	st3 = step2p2(gr, g);

	printf("step 2: %d | step 3: %d \n\n", st2, st3);

	int MCD1 = euclides(st2, N);
	int MCD2 = euclides(st3, N);

	printf("\n--- MCD entre step 2 y N: %d ---\n\n", MCD1);
	printf("\n--- MCD entre step 3 y N: %d ---\n\n", MCD2);



	system("pause");
}


int step2p1(int rf1, int g2) {
	int halfPow = rf1/2;
	double powS=0.0;
	double res1=0.0;
	int intRes1=0;
	// -------------
	powS = pow(g2, halfPow);
	// -------------
	res1 = powS+1;
	// -------------
	intRes1 = (int)res1;
	// -------------
	return intRes1;
}


int step2p2(int rf1, int g2) {
	int halfPow = rf1/2;
	double powS=0.0;
	double res2=0.0;
	int intRes2=0;
	// -------------
	powS = pow(g2, halfPow);
	// -------------
	res2 = powS-1;
	// -------------
	intRes2 = (int)res2;
	// -------------
	return intRes2;
}


int r10(int &N1, int &g1) {
	int i=0, auxInt1=0;
	double gX=0.0;
	double N_div_gX=0.0;
	int rf=90;

	for(i=0; i<50; i++) {
		// -------------
		gX = pow(g1, i+1);
		auxInt1 = (int)gX;

		// -------------
		N_div_gX = auxInt1 % N1;
		// -------------
		if(i%10 == 0)
			printf("\ncargando... \n");
		// -------------
		if(N_div_gX == 1) {
			rf = i+1;
			return rf;
		}
		//
		// -------------
	}
}


int euclides(int a, int b) {
	int temp;
	while(b != 0) {
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}




