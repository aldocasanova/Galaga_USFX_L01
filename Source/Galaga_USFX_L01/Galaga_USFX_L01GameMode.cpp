// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaKamikaze.h"
#include "MyNaveEnemigaCazaX.h"
#include "MyNaveEnemigaCazaY.h"
#include "NaveEnemigaTransporteAttack.h"
#include "NaveEnemigaTransporteSupport.h"
#include "MyNaveEnemigaEspiaNv1.h"
#include "MyNaveEnemigaEspiaNv2.h"
#include "MyNaveEnemigaNodrizaPacheco.h"
#include "MyNaveEnemigaNodrizaCoca.h"
#include "MyNaveEnemigaReabastecimientoBal.h"
#include "MyNaveEnemigaReabastecimientoBom.h"
#include "MyNaveEnemigaKamikazeA.h"
#include "MyNaveEnemigaKamikazeB.h"
#include "NaveEnemigaPiccolo.h"
#include "NaveEnemigaPiccoloZ.h"
#include "NaveEnemigaPiccoloAF.h"

#include "Obstaculo.h"
#include "PowerUp.h"
#include "Bomb.h"
#include "NaveEnemigaBomb.h"

#include "NaveEnemigaFactory.h"


AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing
	//fila de adelante
	FVector ubicacionInicioNavesEnemigasEspiaNv1 = FVector(400.0f, -1100.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasEspiaNv2 = FVector(400.0f, -900.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasCazaX = FVector(400.0f, -700.0f, 250.0f); 
	FVector ubicacionInicioNavesEnemigasCazaY = FVector(400.0f, -500.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasKamikazeA = FVector(400.0f, -300.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasKamikazeB = FVector(400.0f, -100.0f, 250.0f);
	//fila de atrás
	FVector ubicacionInicioNavesEnemigasReabastecimientoBal = FVector(600.0f, -1100.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasReabastecimientoBom = FVector(600.0f, -900.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasTransporteAttack = FVector(600.0f, -700.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasTransporteSupport = FVector(600.0f, -500.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasNodrizaPacheco = FVector(600.0f, -300.0f, 250.0f); 
	FVector ubicacionInicioNavesEnemigasNodrizaCoca = FVector(600.0f, -100.0f, 250.0f); 

	FVector ubicacionInicioNavesEnemigasPiccoloZ = FVector(200.0f, -500.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasPiccoloAF = FVector(200.0f, 100.0f, 250.0f);

	FVector ubicacionInicioNavesEnemigasBomb = FVector(800.0f, -500.0f, 250.0f);

		FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
		FRotator rotacionObstaculoPowerUp = FRotator(0.0f, 0.0f, 0.0f);

	//Generador de naves: 
	UWorld* const World = GetWorld();

	if (World != nullptr)
	{
		for (int i = 0; i < 20; i++)
		{
			FVector Position = FVector(1500.0f, -1500.0f + i * 150, 250.0f);
			if (FMath::RandBool())
			{
				ANaveEnemiga* NuevaNaveCaza = ANaveEnemigaFactory::CrearNaveEnemiga("Caza", World, Position, FRotator::ZeroRotator);
			}
			else
			{
				ANaveEnemiga* NuevaNaveTransporte = ANaveEnemigaFactory::CrearNaveEnemiga("Transporte", World, Position, FRotator::ZeroRotator);
			}
		}

		//fila de adelante
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasEspiaNv1.X, ubicacionInicioNavesEnemigasEspiaNv1.Y + i * 2200, ubicacionInicioNavesEnemigasEspiaNv1.Z);
			ANaveEnemigaEspia* NaveEnemigaEspiaTemporal = World->SpawnActor<ANaveEnemigaEspia>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaEspiaTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasEspiaNv2.X, ubicacionInicioNavesEnemigasEspiaNv2.Y + i * 1800, ubicacionInicioNavesEnemigasEspiaNv2.Z);
			ANaveEnemigaEspia* NaveEnemigaEspiaTemporal = World->SpawnActor<ANaveEnemigaEspia>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaEspiaTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasCazaX.X, ubicacionInicioNavesEnemigasCazaX.Y + i * 1400, ubicacionInicioNavesEnemigasCazaX.Z);
			ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaCazaTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasCazaY.X, ubicacionInicioNavesEnemigasCazaY.Y + i * 1000, ubicacionInicioNavesEnemigasCazaY.Z);
			ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaCazaTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasKamikazeA.X, ubicacionInicioNavesEnemigasKamikazeA.Y + i * 600, ubicacionInicioNavesEnemigasKamikazeA.Z);
			ANaveEnemigaKamikaze* NaveEnemigaKamikazeTemporal = World->SpawnActor<ANaveEnemigaKamikaze>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaKamikazeTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasKamikazeB.X, ubicacionInicioNavesEnemigasKamikazeB.Y + i * 200, ubicacionInicioNavesEnemigasKamikazeB.Z);
			ANaveEnemigaKamikaze* NaveEnemigaKamikazeTemporal = World->SpawnActor<ANaveEnemigaKamikaze>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaKamikazeTemporal);
		}

		//fila de atrás
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasReabastecimientoBal.X, ubicacionInicioNavesEnemigasReabastecimientoBal.Y +i*2200, ubicacionInicioNavesEnemigasReabastecimientoBal.Z);
			ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimientoTemporal = World->SpawnActor<ANaveEnemigaReabastecimiento>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaReabastecimientoTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasReabastecimientoBom.X, ubicacionInicioNavesEnemigasReabastecimientoBom.Y + i * 1800, ubicacionInicioNavesEnemigasReabastecimientoBom.Z);
			ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimientoTemporal = World->SpawnActor<ANaveEnemigaReabastecimiento>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaReabastecimientoTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasTransporteAttack.X, ubicacionInicioNavesEnemigasTransporteAttack.Y + i * 1400, ubicacionInicioNavesEnemigasTransporteAttack.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaTransporteTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasTransporteSupport.X, ubicacionInicioNavesEnemigasTransporteSupport.Y + i * 1000, ubicacionInicioNavesEnemigasTransporteSupport.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaTransporteTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasNodrizaPacheco.X, ubicacionInicioNavesEnemigasNodrizaPacheco.Y + i * 600, ubicacionInicioNavesEnemigasNodrizaPacheco.Z);
			ANaveEnemigaNodriza* NaveEnemigaNodrizaTemporal = World->SpawnActor<ANaveEnemigaNodriza>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaNodrizaTemporal);
		}
		for (int i = 0; i < 2; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasNodrizaCoca.X, ubicacionInicioNavesEnemigasNodrizaCoca.Y + i * 200, ubicacionInicioNavesEnemigasNodrizaCoca.Z);
			ANaveEnemigaNodriza* NaveEnemigaNodrizaTemporal = World->SpawnActor<ANaveEnemigaNodriza>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaNodrizaTemporal);
		}
		//nuevas naves
		for (int i = 0; i < 3; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasPiccoloZ.X, ubicacionInicioNavesEnemigasPiccoloZ.Y + i * 200, ubicacionInicioNavesEnemigasPiccoloZ.Z);
			ANaveEnemigaPiccolo* NaveEnemigaPiccoloTemporal = World->SpawnActor<ANaveEnemigaPiccolo>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaPiccoloTemporal);
		}
		for (int i = 0; i < 3; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasPiccoloAF.X, ubicacionInicioNavesEnemigasPiccoloAF.Y + i * 200, ubicacionInicioNavesEnemigasPiccoloAF.Z);
			ANaveEnemigaPiccolo* NaveEnemigaPiccoloTemporal = World->SpawnActor<ANaveEnemigaPiccolo>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaPiccoloTemporal);
		}		
	
		for (int i = 0; i < 1; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasBomb.X, ubicacionInicioNavesEnemigasBomb.Y, ubicacionInicioNavesEnemigasBomb.Z);
			ANaveEnemigaBomb* NaveEnemigaNodrizaTemporal = World->SpawnActor<ANaveEnemigaBomb>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaNodrizaTemporal);
		}
		//Laboratorio Grupal
		for (int i = 0; i < 1; i++)
		{
			FVector SpawnLocation = FVector((-600.0f), FMath::RandRange(-1000.0f, 1000.0f), 250.0f); 
			AObstaculo* NewObstacle = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
		}
		// Crear e insertar power-ups en el TMap
		for (int i = 0; i < 2; i++)
		{
			FVector SpawnLocation = FVector(FMath::RandRange(-400.0f, 0.0f), FMath::RandRange(-1000.0f, 1000.0f), 250.0f);
			APowerUp* NewObstacle = GetWorld()->SpawnActor<APowerUp>(APowerUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
		}
		for (int i = 0; i < 6; i++)
		{
			FVector SpawnLocation = FVector(-600.0f, -1000.0f + i* 400 , 250.0f);
			AObstaculo* NewObstacle = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
		}
	}
		TiempoTranscurrido = 0;
}
void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoTranscurrido++;

	/*if (TiempoTranscurrido >= 100)
	{
		int numeroEnemigo = FMath::RandRange(0, 9);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Hola estoy aqui")));


			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Entero: %d"), numeroEnemigo));

		}
		//TANavesEnemigas[numeroEnemigo]->PrimaryActorTick.bCanEverTick = false;
		TANavesEnemigas[numeroEnemigo]->SetVelocidad(0);
	}*/
}