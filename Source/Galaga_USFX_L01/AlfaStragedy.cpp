// Fill out your copyright notice in the Description page of Project Settings.


#include "AlfaStragedy.h"
#include "NaveEnemiga.h"
// Sets default values
AAlfaStragedy::AAlfaStragedy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAlfaStragedy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlfaStragedy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAlfaStragedy::Mover(ANaveEnemiga* NaveEnemiga, float DeltaTime)
{
	FVector NewPosition = NaveEnemiga->GetActorLocation();
	NewPosition.X -= DeltaTime * NaveEnemiga->GetVelocidad();
	NaveEnemiga->SetActorLocation(NewPosition);
}

void AAlfaStragedy::Disparar(ANaveEnemiga* NaveEnemiga)
{
	 // Ejemplo: Disparo en ráfaga
	if (NaveEnemiga->GetWorld()->GetTimeSeconds() - NaveEnemiga->GetLastFireTime() > NaveEnemiga->GetTiempoDisparo() / 3)
	{
		NaveEnemiga->FireProjectile();
		NaveEnemiga->SetLastFireTime(NaveEnemiga->GetWorld()->GetTimeSeconds());
	}
}






