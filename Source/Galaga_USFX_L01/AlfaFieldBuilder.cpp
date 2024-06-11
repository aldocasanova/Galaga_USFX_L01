// Fill out your copyright notice in the Description page of Project Settings.


#include "AlfaFieldBuilder.h"
#include "Coliseo.h"
#include "Estatua.h"
#include "Escalera.h"
#include "Roca.h"
#include "Pilar.h"
#include "Suelo.h"


// Sets default values
AAlfaFieldBuilder::AAlfaFieldBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAlfaFieldBuilder::BeginPlay()
{
	Super::BeginPlay();

	ASuelo* SueloAlfa = GetWorld()->SpawnActor<ASuelo>(FVector(-4000.0f, -4000.0f, 160.0f), FRotator::ZeroRotator);
	UStaticMesh* MeshAlfa = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Architecture/SueloAlfa.SueloAlfa'"));
	SueloAlfa->SetMesh(MeshAlfa);

	// elemetnos de alfa
	AColiseo* ElementosAlfa = GetWorld()->SpawnActor<AColiseo>();
	BuildElements(ElementosAlfa);
	ElementosAlfa->Spawn(GetWorld(), FVector::ZeroVector);
}

void AAlfaFieldBuilder::BuildElements(AColiseo* ElementosAlfa)
{
	// Agregar 2 estatuas, 1 escalera y 1 roca 
	ElementosAlfa->AgregarElemento(GetWorld()->SpawnActor<AEstatua>(), FVector(0.0f, 1800.0f, 215.0f));
	ElementosAlfa->AgregarElemento(GetWorld()->SpawnActor<AEstatua>(), FVector(1050.0f, 1800.0f, 215.0f));
	ElementosAlfa->AgregarElemento(GetWorld()->SpawnActor<AEscalera>(), FVector(200.0f, -2000.0f, 200.0f));

	ElementosAlfa->AgregarElemento(GetWorld()->SpawnActor<ARoca>(), FVector(FMath::RandRange(-1500.0f, -2000.0f), FMath::RandRange(-1300.0f, 1300.0f), 200.0f));
	for (int i = 0; i < 2; i++) {
		ElementosAlfa->AgregarElemento(GetWorld()->SpawnActor<APilar>(), FVector(1900.0f, -1700.0f + i * 3000, 205.0f));
	}
	for (int i = 0; i < 2; i++) {
		ElementosAlfa->AgregarElemento(GetWorld()->SpawnActor<APilar>(), FVector(-1300.0f, -1700.0f + i * 3000, 205.0f));
	}
}

// Called every frame
void AAlfaFieldBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoSpawn += GetWorld()->DeltaTimeSeconds;
}

void AAlfaFieldBuilder::BuildEnemies()
{
	UWorld* const World = GetWorld();
	//Caza,reabastecimiento, tr kamikaze; nodriza; bomba 
	for (int i = 0; i < 20; i++)
	{
		FVector Position = FVector(1300.0f, -1500.0f + i * 150, 215.0f); //aqui le da la posicion a la nave
		if (FMath::RandBool())
		{
			ANaveEnemiga* NuevaNaveCaza = ANaveEnemigaFactory::CrearNaveEnemiga("Caza", World, Position, FRotator::ZeroRotator);
		}
		else
		{
			ANaveEnemiga* NuevaNaveTransporte = ANaveEnemigaFactory::CrearNaveEnemiga("Kamikaze", World, Position, FRotator::ZeroRotator);
		}
	}
	for (int i = 0; i < 20; i++)
	{
		FVector Position = FVector(1500.0f, -1500.0f + i * 150, 215.0f); //aqui le da la posicion a la nave
		if (FMath::RandBool())
		{
			ANaveEnemiga* NuevaNaveCaza = ANaveEnemigaFactory::CrearNaveEnemiga("Reabastecimiento", World, Position, FRotator::ZeroRotator);
		}
		else
		{
			ANaveEnemiga* NuevaNaveTransporte = ANaveEnemigaFactory::CrearNaveEnemiga("Transporte", World, Position, FRotator::ZeroRotator);
		}
	}

	for (int i = 0; i < 1; i++)
	{
		FVector Position = FVector(1650.0f, -500.0f, 215.0f); //aqui le da la posicion a la nave
		ANaveEnemiga* NuevaNaveCaza = ANaveEnemigaFactory::CrearNaveEnemiga("Bomb", World, Position, FRotator::ZeroRotator);
	}

	for (int i = 0; i < 2; i++)
	{
		FVector Position = FVector(1750.0f, -900.0f + i*1800, 215.0f); //aqui le da la posicion a la nave
		ANaveEnemiga* NuevaNaveCaza = ANaveEnemigaFactory::CrearNaveEnemiga("Nodriza", World, Position, FRotator::ZeroRotator);
	}
	
}

void AAlfaFieldBuilder::BuildPowerUps()
{
	/*for (int i = 0; i < 4; i++)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-400.0f, 0.0f), FMath::RandRange(-1000.0f, 1000.0f), 215.0f);
		APowerUp* NewObstacle = GetWorld()->SpawnActor<APowerUp>(APowerUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}*/
}


AGalacticField* AAlfaFieldBuilder::GetGalacticField() const
{
	AGalacticField* GalacticField = NewObject<AGalacticField>();
	return GalacticField;

}

