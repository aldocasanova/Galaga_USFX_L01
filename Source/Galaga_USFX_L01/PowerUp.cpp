// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
void APowerUp::GenerarPowerUp()
{
}

// Sets default values
APowerUp::APowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PowerUp(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim_90_Out.Shape_Trim_90_Out'"));
	// Create the mesh component
	mallaPowerUp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PowerUpMesh"));
	mallaPowerUp->SetStaticMesh(PowerUp.Object);
	mallaPowerUp->SetupAttachment(RootComponent);
	RootComponent = mallaPowerUp;

	LimiteVerticalPO = -1000.0f;
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
	Mover(DeltaTime);

}

void APowerUp::Mover(float DeltaTime)
{
	velocidad = 8; //1.5
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteVerticalPO) 
	{
		SetActorLocation(FVector(4000.0f, FMath::RandRange(-1000.0f, 1000.0f), 250.0f));
	}
}

