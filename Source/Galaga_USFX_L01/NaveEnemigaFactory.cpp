// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaFactory.h"
#include "MyNaveEnemigaCazaY.h"
#include "NaveEnemigaTransporteAttack.h"
#include "MyNaveEnemigaKamikazeA.h"
#include "MyNaveEnemigaEspiaNv2.h"
#include "MyNaveEnemigaNodrizaCoca.h"
#include "MyNaveEnemigaReabastecimientoBom.h"
#include "NaveEnemigaBomb.h"

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
        AMyNaveEnemigaCazaY* NuevaNave = World->SpawnActor<AMyNaveEnemigaCazaY>(SpawnLocationAdjusted, SpawnRotation);
        return NuevaNave;
    }
    else if (tipoNave == "Kamikaze")
    {
        AMyNaveEnemigaKamikazeA* NuevaNave = World->SpawnActor<AMyNaveEnemigaKamikazeA>(SpawnLocationAdjusted, SpawnRotation);
        return NuevaNave;
	}
	else if (tipoNave == "Nodriza")
	{
		AMyNaveEnemigaNodrizaCoca* NuevaNave = World->SpawnActor<AMyNaveEnemigaNodrizaCoca>(SpawnLocationAdjusted, SpawnRotation);
		return NuevaNave;
	}
	else if (tipoNave == "Reabastecimiento")
	{
		AMyNaveEnemigaReabastecimientoBom* NuevaNave = World->SpawnActor<AMyNaveEnemigaReabastecimientoBom>(SpawnLocationAdjusted, SpawnRotation);
		return NuevaNave;
	}
	else if (tipoNave == "Bomb")
	{
		ANaveEnemigaBomb* NuevaNave = World->SpawnActor<ANaveEnemigaBomb>(SpawnLocationAdjusted, SpawnRotation);
		return NuevaNave;
	}
    else if (tipoNave == "Transporte")
    {
        ANaveEnemigaTransporteAttack* NuevaNave = World->SpawnActor<ANaveEnemigaTransporteAttack>(SpawnLocationAdjusted, SpawnRotation);
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

/*ANaveEnemigaFactory::ANaveEnemigaFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}*/