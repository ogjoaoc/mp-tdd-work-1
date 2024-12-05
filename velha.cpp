/**
 * \file  velha.cpp
 */

#include "velha.hpp"

/**
 * @brief Verifica se há espaços vazios no tabuleiro.
 * @author João Carlos
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se houver espaço vazio, false caso contrário.
 */

bool tem_espaco_vazio(int velha[3][3]) {
  int index_linha, index_coluna;
  for (index_linha = 0; index_linha < 3; ++index_linha) {
    for (index_coluna = 0; index_coluna < 3; ++index_coluna) {
      if (velha[index_linha][index_coluna] == 0) {
        return true;
      }
    }
  }
  return false;
}

/**
 * @brief Verifica se o jogador venceu em uma das diagonais.
 * @author João Carlos
 * @param num_jogador Número identificador do jogador (1 para X, 2 para O).
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogador venceu em uma diagonal, false caso contrário.
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

/**
 * @brief Verifica se o jogador venceu em alguma coluna.
 * @author João Carlos
 * @param num_jogador Número identificador do jogador (1 para X, 2 para O).
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogador venceu em uma coluna, false caso contrário.
 */

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

/**
 * @brief Verifica se o jogador venceu em alguma linha.
 * @author João Carlos
 * @param num_jogador Número identificador do jogador (1 para X, 2 para O).
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogador venceu em uma linha, false caso contrário.
 */

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

/**
 * @brief Verifica se o jogador venceu o jogo.
 * @author João Carlos
 * @param num_jogador Número identificador do jogador (1 para X, 2 para O).
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogador venceu, false caso contrário.
 */

bool verifica_vencedor(int num_jogador, int velha[3][3]) {
  return (
    vence_linha(num_jogador, velha) ||
    vence_coluna(num_jogador, velha) ||
    vence_diagonal(num_jogador, velha));
}

/**
 * @brief Verifica se o jogador X venceu.
 * @author João Carlos
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogador X venceu, false caso contrário.
 */

bool x_venceu(int velha[3][3]) {
  return verifica_vencedor(1, velha) == true;
}

/**
 * @brief Verifica se o jogador O venceu.
 * @author João Carlos
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogador O venceu, false caso contrário.
 */

bool o_venceu(int velha[3][3]) {
  return verifica_vencedor(2, velha) == true;
}

/**
 * @brief Verifica se não há vencedores.
 * @author João Carlos
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se não há vencedores, false caso contrário.
 */

bool sem_vencedores(int velha[3][3]) {
  return x_venceu(velha) == false && o_venceu(velha) == false;
}

/**
 * @brief Verifica se o jogo está empatado.
 * @author João Carlos
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogo está empatado, false caso contrário.
 */

bool verifica_empate(int velha[3][3]) {
  if (tem_espaco_vazio(velha)) {
    return false;
  }
  return sem_vencedores(velha);
}

/**
 * @brief Verifica se o jogo está indefinido.
 * @author João Carlos
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogo está indefinido, false caso contrário.
 */

bool jogo_indefinido(int velha[3][3]) {
  if (tem_espaco_vazio(velha) == false) {
    return false;
  }
  return sem_vencedores(velha);
}

/**
 * @brief Verifica se o jogo está em uma situação impossível.
 * @author João Carlos
 * @param velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return true se o jogo está em situação impossível, false caso contrário.
 */

bool jogo_impossivel(int velha[3][3]) {
  int quantidade_x = 0, quantidade_o = 0;
  int index_linha, index_coluna;
  for (index_linha = 0; index_linha < 3; ++index_linha) {
    for (index_coluna = 0; index_coluna < 3; ++index_coluna) {
      if (velha[index_linha][index_coluna] == 1) {
        quantidade_x += 1;
      } else if (velha[index_linha][index_coluna] == 2) {
        quantidade_o += 1;
      }
    }
  }
  if (quantidade_o > quantidade_x || (quantidade_x - quantidade_o) > 1) {
    return true;
  }
  if (x_venceu(velha) && o_venceu(velha)) {
    return true;
  }
  return false;
}

/** 
 * @brief Verifica situação do jogo da velha.  
 * @author João Carlos
 * @param  velha Tabuleiro do jogo da velha (matriz 3x3).
 * @return Inteiro representando o estado do jogo:
 * - 1 se o X venceu.
 * - 2 se o O venceu.
 * - 0 se o jogo está empatado.
 * - -1 se o jogo está indefinido.
 * - -2 se o jogo é impossível.
 */ 

int VerificaVelha(int velha[3][3]) {
  if (jogo_impossivel(velha)) {
    return -2;
  } else if (x_venceu(velha)) {
    return 1;
  } else if (o_venceu(velha)) {
    return 2;
  } else if (verifica_empate(velha)) {
    return 0;
  } else if (jogo_indefinido(velha)) {
    return -1;
  }
  return -1;
}
