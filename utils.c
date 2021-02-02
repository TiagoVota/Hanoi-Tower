#include <stdio.h>


// Função para mostrar o "estado atual" da torre
void print_tower(int n, int A[n], int B[n], int C[n]) {
	int i;

	// Printa "Nomes" das colunas
	printf("  A           B           C\n\n");
	// Printa a matriz que representa a torre de Hanói, com um espaço de três digitos (%3d) para as colunas ficarem melhor alinhadas
	for (i = 0; i < n; i++) {
		printf("%3d     |   %3d     |   %3d\n", A[i], B[i], C[i]);
	}
	printf("\n\n");
}


// Algoritmo para resolução da Torre de Hanói
void hanoi_tower(int n, int origem[n], int auxiliar[n], int destino[n], int first[n], int second[n], int third[n]) {
	/*
	Explicações dos parâmetros da Função:
	int n: Número de discos que será movidos. Também utilizado para inicializar a função, dando a quantidade total de discos que a torre possui;
	int origem[n]: vetor que repesenta a torre da qual serão movidos os n discos;
	int auxiliar[n]: vetor que repesenta a torre que será auxiliar para mover os discos;
	int destino[n]: vetor que repesenta a torre que receberá ao final os n discos;
	int first[n]: vetor que representa a torre que está na primeira posição (para a hora do print);
	int second[n]: vetor que representa a torre que está na segunda posição (para a hora do print);
	int third[n]: vetor que representa a torre que está na terceira posição (para a hora do print);
	*/

	/*
	Ideia do que é uma variável do tipo 'static':
	"Uma variável 'static' dentro de uma função mantêm seu valor entre as invocações"
	*/
	static int count = 0;  // "Variável estática" utilizada para contar a quantidades de movimentos realizados
	static int teste = 0, n_disc;  // Variáveis para guardar o número total de discos do problema
	int i;
	int temp;

	// Essa parte é utilizada para guardar a informação da quantidade total de discos do problema
	if (teste == 0) {
		n_disc = n;
		teste++;
	}

	// Critério de parada.
	if (n == 0) {
		return;
	}

	// Mostrar qual era a posição inicial das peças
	if (n == n_disc) {
		printf("Posição Inicial:\n");
		print_tower(n_disc, first, second, third);
	}

	if (n > 0) {
		// Move "a pilha" de n - 1 discos da coluna origem para a auxiliar
		hanoi_tower(n - 1, origem, destino, auxiliar, first, second, third);
		
		// Move a peça n da origem para o destino:
		// Busca, na coluna da origem, o primeiro valor que não é zero (0). Grava tal valor numa variável temporária e, em seguida, troca o valor daquela posição por zero (0)
		for (i = 0; i < n_disc; i++) {
			if (origem[i] != 0) {
				temp = origem[i];
				origem[i] = 0;
				break;
			}
		}
		// Busca o último valor que é zero da coluna do destino e coloca o valor da peça n no seu lugar
		for (i = 1; i < n_disc; i++) {
			if (destino[i] != 0) {
				destino[i - 1] = temp;
				break;
			}
			if (i == n_disc - 1) {
				destino[i] = temp;
			}
		}
		// Mostra em qual movimento estamo
		printf("%dº Movimento:\n", ++count);
		// Mostra como a torre está após esse movimento
		print_tower(n_disc, first, second, third);

		// Move "a pilha" de n-1 discos da coluna auxiliar para o destino
		hanoi_tower(n - 1, auxiliar, origem, destino, first, second, third);
	}
}
