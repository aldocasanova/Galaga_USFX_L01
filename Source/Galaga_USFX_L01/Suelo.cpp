// Fill out your copyright notice in the Description page of Project Settings.


#include "Suelo.h"

// Sets default values
ASuelo::ASuelo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaSuelo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SueloMesh"));
	RootComponent = MallaSuelo;
}

// Called when the game starts or when spawned
void ASuelo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASuelo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASuelo::SetMesh(UStaticMesh* NewMesh)
{
	if (MallaSuelo && NewMesh)
	{
		MallaSuelo->SetStaticMesh(NewMesh);
	}
}

