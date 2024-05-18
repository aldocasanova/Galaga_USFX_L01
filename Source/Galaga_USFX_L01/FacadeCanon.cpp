// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeCanon.h"

// Sets default values
AFacadeCanon::AFacadeCanon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Inicializar las coordenadas
    TopLeftCorner = FVector(-1000.f, -1000.f, 250.f);
    TopRightCorner = FVector(1000.f, -1000.f, 250.f);
    DownLeftCorner = FVector(-1000.f, 1000.f, 250.f);
    DownRightCorner = FVector(1000.f, 1000.f, 250.f);
}

// Called when the game starts or when spawned
void AFacadeCanon::BeginPlay()
{
	Super::BeginPlay();
	
    SpawnCanons();
}

void AFacadeCanon::SpawnCanons()
{
    SpawnCanon(ACanonBala::StaticClass(), TopLeftCorner);
    SpawnCanon(ACanonLazer::StaticClass(), TopRightCorner);
    SpawnCanon(ACanonBomba::StaticClass(), DownLeftCorner);
    SpawnCanon(ACanonHielo::StaticClass(), DownRightCorner);
}

// Called every frame
void AFacadeCanon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacadeCanon::SpawnCanon(TSubclassOf<AModeloCanon> CanonClass, FVector Location)
{
    if (GetWorld())
    {
        FActorSpawnParameters SpawnParams;
        GetWorld()->SpawnActor<AModeloCanon>(CanonClass, Location, FRotator::ZeroRotator, SpawnParams);
    }

}

