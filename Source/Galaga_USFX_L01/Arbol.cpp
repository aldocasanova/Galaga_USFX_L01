// Fill out your copyright notice in the Description page of Project Settings.


#include "Arbol.h"

// Sets default values
AArbol::AArbol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Arbol(TEXT("StaticMesh'/Game/StarterContent/Architecture/Arbol.Arbol'"));
	// Create the mesh component
	mallaArbol = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArbolMesh"));
	mallaArbol->SetStaticMesh(Arbol.Object);
	mallaArbol->SetupAttachment(RootComponent);
	RootComponent = mallaArbol;

}

// Called when the game starts or when spawned
void AArbol::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArbol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArbol::Spawn(UWorld* World, FVector SpawnLocation)
{
	SetActorLocation(SpawnLocation);
}

void AArbol::RecibirDanio(int32 Danio)
{
	Vida -= Danio;
	if (Vida <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Intenta apuntar a las naves ._."));
		Destroy();
	}
}

