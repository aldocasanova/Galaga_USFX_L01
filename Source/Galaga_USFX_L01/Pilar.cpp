// Fill out your copyright notice in the Description page of Project Settings.


#include "Pilar.h"

// Sets default values
APilar::APilar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Pilar(TEXT("StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));
	// Create the mesh component
	mallaPilar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PilarMesh"));
	mallaPilar->SetStaticMesh(Pilar.Object);
	mallaPilar->SetupAttachment(RootComponent);
	RootComponent = mallaPilar;

}

// Called when the game starts or when spawned
void APilar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APilar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APilar::Spawn(UWorld* World, FVector SpawnLocation)
{
	SetActorLocation(SpawnLocation);
}

void APilar::RecibirDanio(int32 Danio)
{
	Vida -= Danio;
	if (Vida <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Nave Nodriza: No rompas propiedad privada!"));
		Destroy();
	}
}

