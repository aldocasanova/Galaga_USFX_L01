// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaStragedy.h"
#include "NaveEnemiga.h"
#include "ProyectilEnemigo.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AOmegaStragedy::AOmegaStragedy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOmegaStragedy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AOmegaStragedy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AOmegaStragedy::Mover(ANaveEnemiga* NaveEnemiga, float DeltaTime)
{
	FVector NewPosition = NaveEnemiga->GetActorLocation();
	NewPosition.X -= DeltaTime * NaveEnemiga->GetVelocidad();
	NaveEnemiga->SetActorLocation(NewPosition);
}
void AOmegaStragedy::Disparar(ANaveEnemiga* NaveEnemiga)
{
	//continuo
	if (NaveEnemiga->GetWorld()->GetTimeSeconds() - NaveEnemiga->GetLastFireTime() > NaveEnemiga->GetTiempoDisparo())
	{
		NaveEnemiga->FireProjectile();
		NaveEnemiga->SetLastFireTime(NaveEnemiga->GetWorld()->GetTimeSeconds());
	}
}

void AOmegaStragedy::Desplazamiento(ANaveEnemiga* NaveEnemiga, float DeltaTime)
{
	float AmplitudZigzag = 1.20f;
	float VelocidadZigzag = 0.2f;

	FVector NewLocation = NaveEnemiga->GetActorLocation();
	NewLocation.Y += AmplitudZigzag * FMath::Sin(VelocidadZigzag * NaveEnemiga->GetWorld()->GetTimeSeconds());
	NaveEnemiga->SetActorLocation(NewLocation);
}


