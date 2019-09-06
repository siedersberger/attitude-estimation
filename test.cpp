#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"
#include "accelerometersample.h"
#include <sstream>

// teste utilizando os angulos calculados na 'application note' (equacoes 33 e 34).
TEST_CASE("TestRollPitchAppNote") 
{
	AccelerometerSample a;
	stringstream sample("1; 461.105; 82.198; -887.432");
	sample >> a;
	REQUIRE((a.getRoll() >= 174.7 && a.getRoll() <= 174.8)); 
	REQUIRE((a.getPitch() >= -27.4 && a.getPitch() <= -27.3));
}

// teste para verificar os angulos de rotacao para Roll
TEST_CASE("TestRollLimits") 
{
	AccelerometerSample a, b;
	stringstream sample_a("1; 0; 0; 1000");	//sem inclinacao
	stringstream sample_b("1; 0; 1000; 0");	//inclinacao maxima no roll
	sample_a >> a;
	sample_b >> b;
	REQUIRE((a.getRoll() - 180) < 0.1); 
	REQUIRE((b.getRoll() - 90) < 0.1);
}

// teste para verificar os angulos de rotacao para Pitch
TEST_CASE("TestPitchLimits") 
{
	AccelerometerSample a, b;
	stringstream sample_a("1; 0; 0; 1000");	//sem inclinacao
	stringstream sample_b("1; 1000; 0; 0");	//inclinacao maxima no picth
	sample_a >> a;
	sample_b >> b;
	REQUIRE((a.getPitch() - 180) < 0.1); 
	REQUIRE((b.getPitch() - 90) < 0.1);
}

// teste para verificar se a amostra obedece a restrição das somas 
//	dos quadrados de Gx, Gy e Gz, que deve ser igual ao quadrado de g
TEST_CASE("TestConstraints") 
{
	AccelerometerSample a, b;
	stringstream sample_a("1; 0; 0; 1000");	//restricoes obedecidas
	stringstream sample_b("1; 1000; 1000; 0");	//restricoes nao obedecidas
	sample_a >> a;
	sample_b >> b;
	REQUIRE(a.verifyConstraint()); 
	REQUIRE(!b.verifyConstraint());
}