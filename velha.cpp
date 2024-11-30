/**
 * \file  velha.cpp
 */

 
#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

int VerificaVelha( int velha[3][3] )
{
	// Verificando se o X pode vencer.

	// Verifica linhas.
	int i;
	for (i = 0; i < 3; ++i) {
		if (velha[i][0] == 1 && velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2]) {
			return 1;
		}
	}
	// Verifica colunas.
	int j;
	for (j = 0; j < 3; ++j) {
		if (velha[0][j] == 1 && velha[0][j] == velha[1][j] && velha[1][j] == velha[2][j]) {
			return 1;
		}
	}
	// Verificando diagonais (principal e secundária).
	if (velha[0][0] == 1 && velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) {
		return 1;
	}
	if (velha[0][2] == 1 && velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0]) {
		return 1;
	}
	return 0; 
}


