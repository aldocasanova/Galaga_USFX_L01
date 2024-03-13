// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"//cambio 7/03
#include "NaveEnemigaCaza.h"//entonces en el GameMode debo añadir la librería de cada Nave que haga
//include resto de naves
AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

	//NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing
	float x = 1200;
	float y = -1000;

	FVector ubicacionNave01 = FVector(-1000.0f, 500.0f, 250.0f);
	FVector ubicacionNave02 = FVector(-500.0f, -500.0f, 250.0f);
	//resto de ubicaciones de nave
	
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		//NaveEnemiga01 = World->SpawnActor<ANaveEnemiga>(ubicacionNave, rotacionNave);
		NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNave01, rotacionNave);
		NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNave02, rotacionNave);
		//resto de spawners de naves
	}

	//NaveEnemiga01->SetPosicion(FVector(2000.0f, 0.0f, 120.0f));
	// se quitó la NaveEnemiga genérica al pasar a ser clase abstracta
	NaveEnemigaCaza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f)); //?
	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));

}
