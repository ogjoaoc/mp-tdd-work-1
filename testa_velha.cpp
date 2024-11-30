
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE( "Teste 1 : Verifica se o X venceu." ) {
	
	int teste1[3][3]= {   { 2, 0, 1 }, 
	                      { 2, 0, 1 },
						  { 0, 2, 1 }
					  };
    REQUIRE( VerificaVelha(teste1) == 1 );

} 			
 
