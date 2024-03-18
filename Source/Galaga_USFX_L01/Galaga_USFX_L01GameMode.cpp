// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"//cambio 7/03
#include "NaveEnemigaCaza.h"//entonces en el GameMode debo añadir la librería de cada Nave que haga
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

#include "Obstaculo.h"
#include "PowerUp.h"


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
	/*FVector ubicacionInicioNavesEnemigasCaza = FVector(300.0f, -600.0f, 250.0f); //estaba 200 en y
	FVector ubicacionInicioNavesEnemigasTransporte = FVector(200.0f, -600.0f, 250.0f); //estaba en 200 en y

	FVector ubicacionInicioNavesEnemigasEspia = FVector(100.0f, -600.0f, 250.0f); //estaba en 300 en y*/

	//fila de adelante
	FVector ubicacionInicioNavesEnemigasEspiaNv1 = FVector(-300.0f, -1200.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasEspiaNv2 = FVector(-300.0f, -1000.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasCazaX = FVector(-300.0f, -800.0f, 250.0f); 
	FVector ubicacionInicioNavesEnemigasCazaY = FVector(-300.0f, -600.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasKamikazeA = FVector(-300.0f, -400.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasKamikazeB = FVector(-300.0f, -200.0f, 250.0f);
	//fila de atrás
	FVector ubicacionInicioNavesEnemigasReabastecimientoBal = FVector(-100.0f, -1200.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasReabastecimientoBom = FVector(-100.0f, -1000.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasTransporteAttack = FVector(-100.0f, -800.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasTransporteSupport = FVector(-100.0f, -600.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasNodrizaPacheco = FVector(-100.0f, -400.0f, 250.0f); 
	FVector ubicacionInicioNavesEnemigasNodrizaCoca = FVector(-100.0f, -200.0f, 250.0f); 
	

		//...float x = 1200;
		//...float y = -1000;
		//...FVector ubicacionNave01 = FVector(-1000.0f, 500.0f, 250.0f);
		//...FVector ubicacionNave02 = FVector(-500.0f, -500.0f, 250.0f);
		//...
		//FVector ubicacionNave03 = FVector(-700.0f, 500.0f, 250.0f);
		//FVector ubicacionNave04 = FVector(-200.0f, 500.0f, 250.0f);
		/*
		FVector ubicacionNave05 = FVector(-500.0f, -500.0f, 250.0f);
		FVector ubicacionNave06 = FVector(-500.0f, -500.0f, 250.0f);

		...*/
		//resto de ubicaciones de nave

		FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
	//Generador de naves: 

		//practlab
		for (int i = 0; i < 5; ++i)
		{
			FVector SpawnLocation = FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 0.f);
			AObstaculo* NewObstacle = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			ObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
		}

		// Crear e insertar power-ups en el TMap
		for (int i = 0; i < 3; ++i)
		{
			FVector SpawnLocation = FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 0.f);
			APowerUp* NewPowerUp = GetWorld()->SpawnActor<APowerUp>(APowerUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			ObstaclesAndPowerUps.Add(SpawnLocation, NewPowerUp);
		}
}



	UWorld* const World = GetWorld();
	/*
	if (World != nullptr)
	{
		for (int i = 0; i < 5; i++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasCaza.X, ubicacionInicioNavesEnemigasCaza.Y + i * 300, ubicacionInicioNavesEnemigasCaza.Z);
			ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaCazaTemporal);
		}

		float nuevaposicionXT = ubicacionInicioNavesEnemigasTransporte.X; //- 300.0f;
		for (int j = 0; j < 5; j++) {
			FVector PosicionNaveActual = FVector(nuevaposicionXT, ubicacionInicioNavesEnemigasTransporte.Y + j * 300, ubicacionInicioNavesEnemigasTransporte.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaTransporteTemporal);
		}
		//ok, entonces no conviene esto de usar varias variables aux
		float nuevaposicionXE = ubicacionInicioNavesEnemigasEspia.X; //- 300.0f;
		for (int j = 0; j < 5; j++) {
			FVector PosicionNaveActual = FVector(nuevaposicionXE, ubicacionInicioNavesEnemigasEspia.Y + j * 300, ubicacionInicioNavesEnemigasEspia.Z);
			ANaveEnemigaEspia* NaveEnemigaEspiaTemporal = World->SpawnActor<ANaveEnemigaEspia>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaEspiaTemporal);
		} 
		*/
	if (World != nullptr)
	{
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
	}
		//NaveEnemiga01 = World->SpawnActor<ANaveEnemiga>(ubicacionNave, rotacionNave);
		
		/*
		NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNave01, rotacionNave);
		NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNave02, rotacionNave);
		
		NaveEnemigaCazaX01 = World->SpawnActor<AMyNaveEnemigaCazaX>(ubicacionNave03, rotacionNave);
		NaveEnemigaCazaY01 = World->SpawnActor<AMyNaveEnemigaCazaY>(ubicacionNave04, rotacionNave); */

		TiempoTranscurrido = 0;

	//}
	/*
	//NaveEnemiga01->SetPosicion(FVector(2000.0f, 0.0f, 120.0f));
	// se quitó la NaveEnemiga genérica al pasar a ser clase abstracta
	NaveEnemigaCaza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f)); 
	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));
	//...
	//MyNaveEnemigaCazaX01->SetPosicion(FVector(700.0f, 500.0f, 200.0f));
	//MyNaveEnemigaCazaY01->SetPosicion(FVector(200.0f, 500.0f, 200.0f)); lo comento dice no hace nada
	
	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));
	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f)); */

}
void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoTranscurrido++;

	if (TiempoTranscurrido >= 100)
	{
		int numeroEnemigo = FMath::RandRange(0, 9);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Hola estoy aqui")));


			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Entero: %d"), numeroEnemigo));

		}
		//TANavesEnemigas[numeroEnemigo]->PrimaryActorTick.bCanEverTick = false;
		TANavesEnemigas[numeroEnemigo]->SetVelocidad(0);
	}
}