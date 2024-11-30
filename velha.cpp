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

bool verifica_jogo_indefinido(int velha[3][3]) {
	return false;
}

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
  int index_coluna;
  for (index_coluna = 0; index_coluna < 3; ++index_coluna) {
    if (
      velha[0][index_coluna] == num_jogador &&
      velha[0][index_coluna] == velha[1][index_coluna] &&
      velha[1][index_coluna] == velha[2][index_coluna]) {
      return true;
    }
  }
  return false;
}

bool vence_linha(int num_jogador, int velha[3][3]) {
  int index_linha;
  for (index_linha = 0; index_linha < 3; ++index_linha) {
    if (
      velha[index_linha][0] == num_jogador &&
      velha[index_linha][0] == velha[index_linha][1] &&
      velha[index_linha][1] == velha[index_linha][2]) {
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

bool verifica_empate(int velha[3][3]) {
  bool x_venceu = verifica_vencedor(1, velha);
  bool o_venceu = verifica_vencedor(2, velha);
  if (x_venceu || o_venceu) {
    return false;
  }
  return true;
}

int VerificaVelha(int velha[3][3]) {
  // Verifica se o jogo está indefinido, caso contrário, busca um empate.
  // Verifica se ocorreu um empate, caso contrário, procura o vencedor.
  // Verifica o vencedor (X ou O) pelas linhas, colunas e diagonais.

  if (verifica_jogo_indefinido(velha) == true) {
    return -1;
  }
  if (verifica_empate(velha) == true) {
    return 0;
  } else if (verifica_vencedor(1, velha) == true) {
    return 1;
  } else if (verifica_vencedor(2, velha) == true) {
    return 2;
  }

  return -3;
}


