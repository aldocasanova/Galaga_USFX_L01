// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNaveEnemigaCazaY.h"

void AMyNaveEnemigaCazaY::Tick(float DeltaTime)
{
}

AMyNaveEnemigaCazaY::AMyNaveEnemigaCazaY()
{
	posicion = FVector(1200, -1000 + 200, 250);
}

void AMyNaveEnemigaCazaY::Mover(float DeltaTime)
{
	ANaveEnemigaCaza::Mover(DeltaTime);
	/*velocidad = 3;
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y - velocidad, GetActorLocation().Z));
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}*/
}

void AMyNaveEnemigaCazaY::Disparar()
{
}

void AMyNaveEnemigaCazaY::Destruirse()
{
}
