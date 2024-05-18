// Fill out your copyright notice in the Description page of Project Settings.


#include "ModeloCanon.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AModeloCanon::AModeloCanon()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CanonMesh(TEXT("StaticMesh'/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02'"));
	// Create the mesh component
	mallaCanon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CanonMesh"));
	mallaCanon->SetupAttachment(RootComponent);
	RootComponent = mallaCanon;
	mallaCanon->SetStaticMesh(CanonMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AModeloCanon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AModeloCanon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

