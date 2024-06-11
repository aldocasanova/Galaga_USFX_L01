// Fill out your copyright notice in the Description page of Project Settings.


#include "DeltaFieldBuilder.h"
#include "Jungla.h"
#include "Pilar.h"
#include "Arbusto.h"
#include "Roca.h"
#include "Arbol.h"
#include "Suelo.h"

// Sets default values
ADeltaFieldBuilder::ADeltaFieldBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeltaFieldBuilder::BeginPlay()
{
	Super::BeginPlay();
	
	/*FormacionCanones = GetWorld()->SpawnActor<AFacadeCanon>();
	FormacionCanones->SpawnCanons(1);*/

	ASuelo* SueloDelta = GetWorld()->SpawnActor<ASuelo>(FVector(-4000.0f, -4000.0f, 160.0f), FRotator::ZeroRotator);
	UStaticMesh* MeshAlfa = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Architecture/SueloDelta.SueloDelta'"));
	SueloDelta->SetMesh(MeshAlfa);

	// Elemetnos Delta
	AJungla* ElementosDelta = GetWorld()->SpawnActor<AJungla>();
	BuildElements(ElementosDelta);
	ElementosDelta->Spawn(GetWorld(), FVector::ZeroVector);
}

void ADeltaFieldBuilder::BuildElements(AJungla* ElementosDelta)
{
	// Agrego muchos arboles y arbustos, y 2 rocas 
	for (int i = 0; i < 10; i++) {
		ElementosDelta->AgregarElemento(GetWorld()->SpawnActor<AArbol>(), FVector(FMath::RandRange(-1800.0f, -1000.0f), FMath::RandRange(-1800.0f, 1800.0f), 205.0f));
		ElementosDelta->AgregarElemento(GetWorld()->SpawnActor<AArbusto>(), FVector(FMath::RandRange(-2500.0f, -1500.0f), FMath::RandRange(-1800.0f, 1800.0f), 205.0f));
	}

	ElementosDelta->AgregarElemento(GetWorld()->SpawnActor<ARoca>(), FVector(FMath::RandRange(-2500.0f, -1800.0f), FMath::RandRange(-1300.0f, 1300.0f), 205.0f));
	ElementosDelta->AgregarElemento(GetWorld()->SpawnActor<ARoca>(), FVector(1600.0f, -200.0f, 200.0f));
}

// Called every frame
void ADeltaFieldBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



void ADeltaFieldBuilder::BuildEnemies()
{

	for (int i = 0; i < 30; i++) {
		FVector SpawnLocation = FVector(FMath::RandRange(400.0f, 1600.0f), FMath::RandRange(-1600.0f, 1600.0f), 215.0f);		
		x = 1 + rand() % (5);
		switch (x) {
		case 1:
		{
			ANaveEnemigaEspia* NaveEnemigaEspiaNv1Temporal = GetWorld()->SpawnActor<ANaveEnemigaEspia>(ANaveEnemigaEspia::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaEspiaNv1Temporal);
			break;
		}
		case 2:
		{
			ANaveEnemigaCaza* NaveEnemigaCazaXTemporal = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaCazaXTemporal);
			break;
		}
		case 3:
		{
			ANaveEnemigaTransporte* NaveEnemigaTATemporal = GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaTATemporal);
			break;
		}
		case 4:
		{
			ANaveEnemigaReabastecimiento* NaveEnemigaRBATemporal = GetWorld()->SpawnActor<ANaveEnemigaReabastecimiento>(ANaveEnemigaReabastecimiento::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaRBATemporal);
			break;
		}
		case 5:
		{
			ANaveEnemigaKamikaze* NaveEnemigaKATemporal = GetWorld()->SpawnActor<ANaveEnemigaKamikaze>(ANaveEnemigaKamikaze::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaKATemporal);
			break;
		}
		}
	}
}

void ADeltaFieldBuilder::BuildPowerUps()
{
	/*x = 1 + rand() % (2);
	for (int i = 0; i < x; i++)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-400.0f, 0.0f), FMath::RandRange(-1000.0f, 1000.0f), 215.0f);
		APowerUp* NewObstacle = GetWorld()->SpawnActor<APowerUp>(APowerUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}*/
}

void ADeltaFieldBuilder::BuildObstacles()
{
	/*x = 1 + rand() % (4);
	for (int i = 0; i < x; i++)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-1600.0f, 1000.0f), FMath::RandRange(-1400.0f, 1400.0f), 215.0f);
		AObstaculo* NewObstacle = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}*/

}

AGalacticField* ADeltaFieldBuilder::GetGalacticField() const
{
	AGalacticField * GalacticField = NewObject<AGalacticField>();
	return GalacticField;
}

