// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"

void APowerUp::GenerarPowerUp()
{

}

// Sets default values
APowerUp::APowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	// Create the mesh component
	mallaPowerUp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PowerUpMesh"));
	mallaPowerUp->SetupAttachment(RootComponent);
	RootComponent = mallaPowerUp;
}


// Called when the game starts or when spawned
void APowerUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

