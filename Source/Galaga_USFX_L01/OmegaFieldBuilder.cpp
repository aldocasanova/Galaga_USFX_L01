// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaFieldBuilder.h"

// Sets default values
AOmegaFieldBuilder::AOmegaFieldBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOmegaFieldBuilder::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AOmegaFieldBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}//uwu

void AOmegaFieldBuilder::BuildObstacles()
{
	for (int i = 0; i < 6; i++)
	{
		FVector SpawnLocation = FVector(-600.0f, -1000.0f + i * 400, 250.0f);
		AObstaculo* NewObstacle = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}
}

void AOmegaFieldBuilder::BuildEnemies()
{
	
	//fila de adelante
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -1100.0f + i*2200, 250.0f);
		AMyNaveEnemigaEspiaNv1* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaEspiaNv1>(AMyNaveEnemigaEspiaNv1::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -900.0f+i*1800, 250.0f);
		AMyNaveEnemigaEspiaNv1* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaEspiaNv1>(AMyNaveEnemigaEspiaNv1::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -700.0f + i * 1400, 250.0f);
		AMyNaveEnemigaCazaX* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaCazaX>(AMyNaveEnemigaCazaX::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -500.0f + i * 1000, 250.0f);
		AMyNaveEnemigaCazaX* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaCazaX>(AMyNaveEnemigaCazaX::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}

	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, -100.0f + i * 600, 250.0f);
		AMyNaveEnemigaKamikazeB* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaKamikazeB>(AMyNaveEnemigaKamikazeB::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(400.0f, 100.0f + i * 200, 250.0f);	
		AMyNaveEnemigaKamikazeB* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaKamikazeB>(AMyNaveEnemigaKamikazeB::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	//fila de atr�s
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(600.0f, -1100.0f + i * 2200, 250.0f);
		AMyNaveEnemigaReabastecimientoBal* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaReabastecimientoBal>(AMyNaveEnemigaReabastecimientoBal::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(600.0f, -900.0f + i * 1800, 250.0f);
		AMyNaveEnemigaReabastecimientoBal* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaReabastecimientoBal>(AMyNaveEnemigaReabastecimientoBal::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}

	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(600.0f, -700.0f + i * 1400, 250.0f);
		ANaveEnemigaTransporteSupport* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaTransporteSupport>(ANaveEnemigaTransporteSupport::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(600.0f, -500.0f + i * 1000, 250.0f);
		ANaveEnemigaTransporteSupport* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaTransporteSupport>(ANaveEnemigaTransporteSupport::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}


	for (int i = 0; i < 1; i++)
	{
		FVector SpawnLocation = FVector(600.0f, -200.0f, 250.0f);
		AMyNaveEnemigaNodrizaPacheco* NewEnemy = GetWorld()->SpawnActor<AMyNaveEnemigaNodrizaPacheco>(AMyNaveEnemigaNodrizaPacheco::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}


	//protectores 
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(200.0f, -500.0f, 250.0f);
		ANaveEnemigaPiccoloZ* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaPiccoloZ>(ANaveEnemigaPiccoloZ::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(200.0f, 100.0f, 250.0f);
		ANaveEnemigaPiccoloAF* NewEnemy = GetWorld()->SpawnActor<ANaveEnemigaPiccoloAF>(ANaveEnemigaPiccoloAF::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMNavesEnemigas.Add(SpawnLocation, NewEnemy);
	}

}

void AOmegaFieldBuilder::BuildPowerUps()
{
	for (int i = 0; i < 2; i++)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-400.0f, 0.0f), FMath::RandRange(-1000.0f, 1000.0f), 250.0f);
		APowerUp* NewObstacle = GetWorld()->SpawnActor<APowerUp>(APowerUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}
}

AGalacticField* AOmegaFieldBuilder::GetGalacticField() const
{
	AGalacticField* GalacticField = NewObject<AGalacticField>();
	return GalacticField;
}