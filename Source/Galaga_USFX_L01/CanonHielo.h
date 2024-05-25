// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModeloCanon.h"
#include "CanonHielo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ACanonHielo : public AModeloCanon
{
	GENERATED_BODY()
public:
	ACanonHielo();
	virtual void Tick(float DeltaTime) override;
	virtual void Disparar() override;
	virtual void ResetFire() override;

	int MaxProjectile;

	int NumberFired;
	bool bCanFire;

	float TiempoDisparo;

	FVector UltimaPosicionJugador; // Nueva variable para almacenar la �ltima posici�n del jugadord
protected:
	virtual void BeginPlay() override;

};
