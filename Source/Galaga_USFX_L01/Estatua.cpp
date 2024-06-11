// Fill out your copyright notice in the Description page of Project Settings.


#include "Estatua.h"
#include "Engine/Engine.h"

// Sets default values
AEstatua::AEstatua()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Estatua(TEXT("StaticMesh'/Game/StarterContent/Props/Estatua.Estatua'"));
	// Create the mesh component
	mallaEstatua = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EstatuaMesh"));
	mallaEstatua->SetStaticMesh(Estatua.Object);
	mallaEstatua->SetupAttachment(RootComponent);
	RootComponent = mallaEstatua;

	mallaEstatua->SetRelativeScale3D(FVector(4.0f, 4.0f, 4.0f));
	Vida = 100;
}

// Called when the game starts or when spawned
void AEstatua::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstatua::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstatua::Spawn(UWorld* World, FVector SpawnLocation)
{
	SetActorLocation(SpawnLocation);
}

void AEstatua::RecibirDanio(int32 Danio)
{
	Vida -= Danio;
	if (Vida <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Has destruido patrimonio de las naves. "));
		Destroy();
	}
}

