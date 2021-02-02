#include <stdio.h>


// Função para mostrar o "estado atual" da torre
void print_tower(int n, int A[n], int B[n], int C[n]);
// Algoritmo para resolução da Torre de Hanói
void hanoi_tower(int n, int origem[n], int auxiliar[n], int destino[n], int first[n], int second[n], int third[n]);


int main(void) {
	
	int n;
	n = 5;  // Número total de discos
	int A[n], B[n], C[n];  // Vetores que representam as colunas da Torre de Hanói


	// Adicionando configuração inicial das torres
	int i;
	for (i = 0; i < n; i++) {
		A[i] = i + 1;
		B[i] = 0;
		C[i] = 0;
	}


	// Rodando algoritmo que resolve a Torre de Hanói
	hanoi_tower(n, A, B, C, A, B, C);


	return 0;
}
