// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"


// Sets default values
AObstaculo::AObstaculo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Obstaculo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	// Create the mesh componentq
	mallaObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstaculo"));
	mallaObstaculo->SetStaticMesh(Obstaculo.Object);
	mallaObstaculo->SetupAttachment(RootComponent);
	RootComponent = mallaObstaculo;

	LimiteLateralOX = -1000.0f;
}
void AObstaculo::GenerarObstaculo()
{
}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

}

void AObstaculo::Mover(float DeltaTime)
{
	velocidad = 0.45;
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y - velocidad, GetActorLocation().Z));

	if (GetActorLocation().Y < LimiteLateralOX) {

		SetActorLocation(FVector(GetActorLocation().X, 1000.0f, 250.0f));

	}
}

