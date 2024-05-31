// Fill out your copyright notice in the Description page of Project Settings.


#include "DeltaStragedy.h"
#include "NaveEnemiga.h"
// Sets default values
ADeltaStragedy::ADeltaStragedy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeltaStragedy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeltaStragedy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeltaStragedy::Mover(ANaveEnemiga* NaveEnemiga, float DeltaTime)
{
    // Radio del círculo
    float Radio = 3.0f;

    // Velocidad angular (en radianes por segundo)
    float VelocidadAngular = NaveEnemiga->GetVelocidadDelta()/5;

    // Calcular el nuevo ángulo basado en el tiempo transcurrido
    float TiempoTotal = NaveEnemiga->GetWorld()->GetTimeSeconds();
    float NuevoAngulo = VelocidadAngular * TiempoTotal;

    // Calcular la nueva posición en círculo en el plano XY
    FVector NuevaPosicion;
    NuevaPosicion.X = NaveEnemiga->GetActorLocation().X + Radio * FMath::Cos(NuevoAngulo);
    NuevaPosicion.Y = NaveEnemiga->GetActorLocation().Y + Radio * FMath::Sin(NuevoAngulo);
    NuevaPosicion.Z = NaveEnemiga->GetActorLocation().Z; // Mantener Z constante

    // Establecer la nueva posición
    NaveEnemiga->SetActorLocation(NuevaPosicion);
}

void ADeltaStragedy::Disparar(ANaveEnemiga* NaveEnemiga)
{
	// Ejemplo: Disparo en ráfaga lenta
	if (NaveEnemiga->GetWorld()->GetTimeSeconds() - NaveEnemiga->GetLastFireTime() > NaveEnemiga->GetTiempoDisparo() * 2)
	{
		NaveEnemiga->FireProjectile();
		NaveEnemiga->SetLastFireTime(NaveEnemiga->GetWorld()->GetTimeSeconds());
	}

}

void ADeltaStragedy::Desplazamiento(ANaveEnemiga* NaveEnemiga, float DeltaTime)
{
    FVector NewPosition = NaveEnemiga->GetActorLocation();
    NewPosition.X -= DeltaTime * NaveEnemiga->GetVelocidadAlfa()/4;
    NaveEnemiga->SetActorLocation(NewPosition);
}


