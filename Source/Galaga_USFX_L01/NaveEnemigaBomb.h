// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaBomb.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaBomb : public ANaveEnemiga
{
	GENERATED_BODY()
protected:
	int NBombas;

	uint32 bCanFire : 1;
	float FireRate;


	int MaxBombs;
	int BombsFired;

	int direccion = 1;

	float velocidad = 8;
public:
	ANaveEnemigaBomb();

	//virtual void BeginPlay() override;

	FORCEINLINE int GetCantidadBombas() const { return NBombas; }
	FORCEINLINE void SetCantidadBombas(int _NBombas) { NBombas = _NBombas; }


	virtual void Tick(float DeltaTime) override;
	virtual void ShotTimerExpired();
	virtual void RecibirDanio() override;
protected:
	virtual void Mover(float DeltaTime);
	virtual void Soltar();
	virtual void ResetFire();	

	FTimerHandle TimerHandle_ShotTimerExpired;
	virtual void Desplazamiento(float DeltaTime);

};
