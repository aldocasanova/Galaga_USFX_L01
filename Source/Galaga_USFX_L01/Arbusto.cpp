// Fill out your copyright notice in the Description page of Project Settings.


#include "Arbusto.h"

// Sets default values
AArbusto::AArbusto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Arbusto(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Bush.SM_Bush'"));
	// Create the mesh component
	mallaArbusto = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArbustoMesh"));
	mallaArbusto->SetStaticMesh(Arbusto.Object);
	mallaArbusto->SetupAttachment(RootComponent);
	RootComponent = mallaArbusto;

	Vida = 5000;
}

// Called when the game starts or when spawned
void AArbusto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArbusto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArbusto::Spawn(UWorld* World, FVector SpawnLocation)
{
	//World->SpawnActor<AArbusto>(AArbusto::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
	SetActorLocation(SpawnLocation);

}

void AArbusto::RecibirDanio(int32 Danio)
{
	Vida -= Danio;
	if (Vida <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Arbusto podado"));
		Destroy();
	}
}

