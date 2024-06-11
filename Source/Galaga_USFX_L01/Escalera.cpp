// Fill out your copyright notice in the Description page of Project Settings.


#include "Escalera.h"

// Sets default values
AEscalera::AEscalera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Escalera(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Stairs.SM_Stairs'"));
	// Create the mesh component
	mallaEscalera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EscaleraMesh"));
	mallaEscalera->SetStaticMesh(Escalera.Object);
	mallaEscalera->SetupAttachment(RootComponent);
	RootComponent = mallaEscalera;

	mallaEscalera->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	// Set the rotation
	FRotator InitialRotation = FRotator(0.0f, 90.0f, 0.0f); // Example rotation
	mallaEscalera->SetRelativeRotation(InitialRotation);
	Vida = 5000;
}

// Called when the game starts or when spawned
void AEscalera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscalera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscalera::Spawn(UWorld* World, FVector SpawnLocation)
{
	SetActorLocation(SpawnLocation);
}

void AEscalera::RecibirDanio(int32 Danio)
{
	Vida -= Danio;
	if (Vida <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Escalera destruida"));
		Destroy();
	}
}

