/**
 * \file  velha.cpp
 */

 
#include "velha.hpp"

/** 
 * @brief Verifica situação do jogo da velha.  
 * @author João Carlos.
 * @param  velha Tabuleiro do jogo da velha (matriz 3x3).
 * 
 * Diferentes retornos:
 * - 1 se o X venceu.
 * - 2 se o O venceu.
 * - 0 se o jogo está empatado.
 * - -1 se o jogo está indefinido.
 */ 


bool vence_diagonal(int num_jogador, int velha[3][3]) {
  if (
    velha[0][0] == num_jogador &&
    velha[0][0] == velha[1][1] &&
    velha[1][1] == velha[2][2]) {
    return true;
  }
  if (
    velha[0][2] == num_jogador &&
    velha[0][2] == velha[1][1] &&
    velha[1][1] == velha[2][0]) {
    return true;
  }
  return false;
}

bool vence_coluna(int num_jogador, int velha[3][3]) {
  int j;
  for (j = 0; j < 3; ++j) {
    if (
      velha[0][j] == num_jogador &&
      velha[0][j] == velha[1][j] &&
      velha[1][j] == velha[2][j]) {
      return true;
    }
  }
  return false;
}

bool vence_linha(int num_jogador, int velha[3][3]) {
  int i;
  for (i = 0; i < 3; ++i) {
    if (
      velha[i][0] == num_jogador &&
      velha[i][0] == velha[i][1] &&
      velha[i][1] == velha[i][2]) {
      return true;
    }
  }
  return false;
}

bool verifica_vencedor(int num_jogador, int velha[3][3]) {
  return (
    vence_linha(num_jogador, velha) ||
    vence_coluna(num_jogador, velha) ||
    vence_diagonal(num_jogador, velha));
}

int VerificaVelha(int velha[3][3]) {
  // Verificando se o X pode vencer.
  // Verifica linhas, colunas e diagonais.

  if (verifica_vencedor(1, velha) == true) {
	return 1;
  }

  return 0;
}


