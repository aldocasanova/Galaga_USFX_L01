// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaFieldBuilder.h"
#include "Kismet/GameplayStatics.h"
#include "GalacticField.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaKamikaze.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaPiccolo.h"

// Sets default values
AOmegaFieldBuilder::AOmegaFieldBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CantidadNaves = 0;
}

// Called when the game starts or when spawned
void AOmegaFieldBuilder::BeginPlay()
{
	Super::BeginPlay();

	//trabajo 3
	FormacionCanones = GetWorld()->SpawnActor<AFacadeCanon>();
	FormacionCanones->SpawnCanons(1);
	//trabajo 4
	NaveManager = GetWorld()->SpawnActor<ANaveEnemigaManager>();
}

// Called every frame
void AOmegaFieldBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CantidadNaves = NaveManager->GetNavesEnemigasRestantes();

	//FString mensaje = FString::Printf(TEXT("las naves restantes son: %d"), CantidadNaves);
	//const int32 MessageKey = 0;  // Puedes elegir cualquier número que desees para el MessageKey

	//// Imprimir el mensaje en pantalla, reemplazando cualquier mensaje anterior con la misma clave
	/*GEngine->AddOnScreenDebugMessage(MessageKey, 5.f, FColor::Yellow, mensaje);*/
}//uwu

void AOmegaFieldBuilder::BuildObstacles()
{
	for (int i = 0; i < 6; i++)
	{
		FVector SpawnLocation = FVector(-600.0f, -1000.0f + i * 400, 215.0f);
		AObstaculo* NewObstacle = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}
}

void AOmegaFieldBuilder::BuildEnemies()
{
	
	//fila de adelante
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -1100.0f + i*2200, 215.0f);
		ANaveEnemigaEspia* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaEspia>(ANaveEnemigaEspia::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -900.0f+i*1800, 215.0f);
		ANaveEnemigaEspia* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaEspia>(ANaveEnemigaEspia::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -700.0f + i * 1400, 215.0f);
		ANaveEnemigaCaza* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -500.0f + i * 1000, 215.0f);
		ANaveEnemigaCaza* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}

	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(200.0f, -300.0f + i * 600, 215.0f);
		ANaveEnemigaKamikaze* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaKamikaze>(ANaveEnemigaKamikaze::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(200.0f, -100.0f + i * 200, 215.0f);	
		ANaveEnemigaKamikaze* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaKamikaze>(ANaveEnemigaKamikaze::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	//fila de atrás
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(500.0f, -1100.0f + i * 2200, 215.0f);
		ANaveEnemigaReabastecimiento* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaReabastecimiento>(ANaveEnemigaReabastecimiento::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(500.0f, -900.0f + i * 1800, 215.0f);
		ANaveEnemigaReabastecimiento* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaReabastecimiento>(ANaveEnemigaReabastecimiento::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}

	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(600.0f, -700.0f + i * 1400, 215.0f);
		ANaveEnemigaTransporte* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);

		if (NaveManager) //antes no tenía los &&
		{
			NaveManager->AddObserver(NewEnemy);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(600.0f, -500.0f + i * 1000, 215.0f);
		ANaveEnemigaTransporte* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
		if (NaveManager)
		{
			NaveManager->AddObserver(NewEnemy);
		}
	}


	for (int i = 0; i < 1; i++)
	{
		FVector SpawnLocation = FVector(600.0f, 0.0f, 215.0f);
		ANaveEnemigaNodriza* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaNodriza>(ANaveEnemigaNodriza::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}


	//protectores 
	for (int i = 0; i < 4; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -300.0f + i * 100, 215.0f);
		ANaveEnemigaPiccolo* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaPiccolo>(ANaveEnemigaPiccolo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 4; i++)
	{
		FVector SpawnLocation = FVector(400.0f, 0.0f + i * 100, 215.0f);
		ANaveEnemigaPiccolo* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaPiccolo>(ANaveEnemigaPiccolo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}

}

void AOmegaFieldBuilder::BuildPowerUps()
{
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-400.0f, 0.0f), FMath::RandRange(-1000.0f, 1000.0f), 215.0f);
		APowerUp* NewObstacle = GetWorld()->SpawnActor<APowerUp>(APowerUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}
}

AGalacticField* AOmegaFieldBuilder::GetGalacticField() const
{
	AGalacticField* GalacticField = NewObject<AGalacticField>();
	return GalacticField;
}
