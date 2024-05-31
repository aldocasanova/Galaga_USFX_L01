// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaFactory.h"
#include "NaveEnemigaBomb.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaKamikaze.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaTransporte.h"

// Sets default values
/*ANaveEnemigaFactory::ANaveEnemigaFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}*/
// Called when the game starts or when spawned

ANaveEnemiga* ANaveEnemigaFactory::CrearNaveEnemiga(FString tipoNave, UWorld* World, FVector SpawnLocation, FRotator SpawnRotation)
{
    FVector SpawnLocationAdjusted = SpawnLocation;

    if (tipoNave == "Caza")
    {
        ANaveEnemigaCaza* NuevaNave = World->SpawnActor<ANaveEnemigaCaza>(SpawnLocationAdjusted, SpawnRotation);
        return NuevaNave;
    }
    else if (tipoNave == "Kamikaze")
    {
        ANaveEnemigaKamikaze* NuevaNave = World->SpawnActor<ANaveEnemigaKamikaze>(SpawnLocationAdjusted, SpawnRotation);
        return NuevaNave;
	}
	else if (tipoNave == "Nodriza")
	{
		ANaveEnemigaNodriza* NuevaNave = World->SpawnActor<ANaveEnemigaNodriza>(SpawnLocationAdjusted, SpawnRotation);
		return NuevaNave;
	}
	else if (tipoNave == "Reabastecimiento")
	{
		ANaveEnemigaReabastecimiento* NuevaNave = World->SpawnActor<ANaveEnemigaReabastecimiento>(SpawnLocationAdjusted, SpawnRotation);
		return NuevaNave;
	}
	else if (tipoNave == "Bomb")
	{
		ANaveEnemigaBomb* NuevaNave = World->SpawnActor<ANaveEnemigaBomb>(SpawnLocationAdjusted, SpawnRotation);
		return NuevaNave;
	}
    else if (tipoNave == "Transporte")
    {
        ANaveEnemigaTransporte* NuevaNave = World->SpawnActor<ANaveEnemigaTransporte>(SpawnLocationAdjusted, SpawnRotation);
        return NuevaNave;
    }
    
	return nullptr;
}

void ANaveEnemigaFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemigaFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

