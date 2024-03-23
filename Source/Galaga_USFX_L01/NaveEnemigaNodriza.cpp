// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
#include "ProyectilEnemigo.h"
#include "Kismet/GameplayStatics.h"




// Sets default values
ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    FireRate = rand() % 11 + 1; // Intervalo de tiempo entre disparos en segundos, formula 

    MaxShots = 2; // Cantidad máxima de disparos
    ShotsFired = 0; // Inicializar contador de disparos

    bCanFire = true; // Permitir disparos al principio
}

// Called every frame
void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Disparar();
}

void ANaveEnemigaNodriza::ShotTimerExpired()
{
		bCanFire = true;
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
	velocidad = 0.35; //0.25
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) {

		SetActorLocation(FVector(600.0f, GetActorLocation().Y, 250.0f));

	}

}


void ANaveEnemigaNodriza::Disparar()
{
    FVector SpawnLocation = GetActorLocation() + -(GetActorForwardVector() * 1);


    if (bCanFire == true && ShotsFired < MaxShots)
    {
        UWorld* World = GetWorld();
        if (World)
        {
            AProyectilEnemigo* NewProjectile = World->SpawnActor<AProyectilEnemigo>(SpawnLocation, FRotator::ZeroRotator);
        }
        World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigaNodriza::ShotTimerExpired, FireRate);
        bCanFire = false; //no todas las balas se disparan seguidas

        ShotsFired++;
        if (ShotsFired >= MaxShots)
        {
            bCanFire = false;
            GetWorldTimerManager().ClearTimer(TimerHandle_ShotTimerExpired);
        }
        if (FireSound != nullptr)
        {
            UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
        }
        // If we are pressing fire stick in a direction

    }
}

void ANaveEnemigaNodriza::Destruirse()
{
}

void ANaveEnemigaNodriza::Escapar()
{
}


