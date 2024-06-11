// Fill out your copyright notice in the Description page of Project Settings.


#include "Roca.h"

// Sets default values
ARoca::ARoca()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Roca(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'"));
	// Create the mesh component
	mallaRoca = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RocaMesh"));
	mallaRoca->SetStaticMesh(Roca.Object);
	mallaRoca->SetupAttachment(RootComponent);
	RootComponent = mallaRoca;

	Vida = 100;
}

// Called when the game starts or when spawned
void ARoca::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoca::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoca::Spawn(UWorld* World, FVector SpawnLocation)
{
	//World->SpawnActor<ARoca>(ARoca::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
	SetActorLocation(SpawnLocation);
}

void ARoca::RecibirDanio(int32 Danio)
{
	Vida -= Danio;
	if (Vida <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Rota roca :)"));
		Destroy();
	}
}

