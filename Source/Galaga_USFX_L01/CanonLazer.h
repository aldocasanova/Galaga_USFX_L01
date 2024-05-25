// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModeloCanon.h"
#include "CanonLazer.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ACanonLazer : public AModeloCanon
{
	GENERATED_BODY()

public:
	ACanonLazer();
	virtual void Disparar() override;
	virtual void ResetFire() override;
	virtual void Tick(float DeltaTime) override;


	int MaxProjectile;

	int NumberFired;
	bool bCanFire;

	float TiempoDisparo;
	FVector UltimaPosicionJugador; // Nueva variable para almacenar la última posición del jugadord

};
