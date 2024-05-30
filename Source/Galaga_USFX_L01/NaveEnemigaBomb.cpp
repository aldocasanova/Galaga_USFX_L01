// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaBomb.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"
#include "Bomb.h"
#include "Kismet/GameplayStatics.h"
ANaveEnemigaBomb::ANaveEnemigaBomb()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A'"));
    mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

    PrimaryActorTick.bCanEverTick = true;

    //FireRate = rand() % 4 + 1;

    MaxBombs = 4; 
    BombsFired = 0; 

    bCanFire = true; // Permitir disparos al principio

    Vida = 30;

}

void ANaveEnemigaBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Soltar();
    Desplazamiento(DeltaTime);
}

void ANaveEnemigaBomb::ShotTimerExpired()
{
}

void ANaveEnemigaBomb::Mover(float DeltaTime)
{
	//velocidad = 0.35; 
	//SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	//if (GetActorLocation().X < LimiteInferiorX)
	//{
	//	//SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, 250.0f));
	//	SetActorLocation(FVector(800.0f, GetActorLocation().Y, 250.0f));
	//}
}

void ANaveEnemigaBomb::RecibirDanio()
{
    Vida -= 5;
    if (Vida <= 0)
    {
        Destroy();
    }
}

void ANaveEnemigaBomb::Soltar()
{
    if (bCanFire && BombsFired < MaxBombs)
    {
        bCanFire = false;  // Prevenir nuevos disparos hasta que el temporizador expire

        // creador de bombas
        UWorld* const World = GetWorld();
        if (World != NULL)
        {
            FVector Location = GetActorLocation();
            FRotator Rotation = GetActorRotation();
            World->SpawnActor<ABomb>(Location, Rotation);
            BombsFired++;

            // Establecer el temporizador para el próximo disparo
            FTimerHandle TimerHandle;
            GetWorldTimerManager().SetTimer(TimerHandle, this, &ANaveEnemigaBomb::ResetFire, rand() % 6 + 1, false);
        }
    }
}

void ANaveEnemigaBomb::ResetFire()
{
    if (BombsFired < MaxBombs)
    {
        bCanFire = true;  // Permitir el siguiente disparo
        Soltar();         // Disparar automáticamente la siguiente bomba
    }
    else
    {
        BombsFired = 0;   // Reiniciar el contador de bombas para el próximo ciclo de disparos reabastecido
        bCanFire = false;  
    }
}

void ANaveEnemigaBomb::Desplazamiento(float DeltaTime)
{
	if (GetActorLocation().Y < LimiteInferiorY)
	{
		direccion = 1;
	}
	else if (GetActorLocation().Y > LimiteSuperiorY)
	{
		direccion = -1;
	}

	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y + (direccion * velocidad), GetActorLocation().Z));
}
