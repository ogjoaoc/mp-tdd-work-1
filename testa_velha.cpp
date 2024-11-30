
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Teste 1 : Verifica se o X venceu.") {

    int teste_1[3][3] = { { 2, 0, 1 }, 
  	                      { 2, 0, 1 },
						  { 0, 2, 1 } 
                      };
    REQUIRE(VerificaVelha(teste_1) == 1);
} 			

TEST_CASE("Teste 2 : Verifica se o O venceu.") {

	int teste_2[3][3] = { { 1, 0, 2 },
	                      { 1, 2, 1 },
						  { 2, 0, 0 }
					  };
    REQUIRE(VerificaVelha(teste_2) == 2);
}

TEST_CASE("Teste 3 : Verifica se o jogo empatou.") {

	int teste_3[3][3] = { { 1, 1, 2 },
	                      { 2, 2, 1 },
						  { 1, 2, 1 }
					  };
    REQUIRE(VerificaVelha(teste_3) == 0);
}

TEST_CASE("Teste 4 : Verifica jogo indefinido.") {

	int teste_4[3][3] = { { 0, 0, 0 },
	                      { 0, 1, 0 },
						  { 0, 0, 0 }
					  };
    REQUIRE(VerificaVelha(teste_4) == -1);
}
