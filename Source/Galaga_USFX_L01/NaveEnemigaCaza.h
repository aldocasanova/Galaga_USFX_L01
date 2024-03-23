// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.generated.h"
/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCaza : public ANaveEnemiga
{

	GENERATED_BODY()
protected:
	int cantidadBombas;

	uint32 bCanFire : 1;
	float FireRate;

	float AmplitudZigzag;
	float VelocidadZigzag;
	

	int MaxShots;
	int ShotsFired;
public:
	class USoundBase* FireSound;
	//...
public:
	ANaveEnemigaCaza();

	//virtual void BeginPlay() override;

	FORCEINLINE int GetCantidadBombas() const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
	
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }

	FORCEINLINE float GetVelocidadZigzag() const { return VelocidadZigzag; }
	FORCEINLINE void SetVelocidadZigzag(float _VelocidadZigzag) { VelocidadZigzag = _VelocidadZigzag; }

	virtual void Tick(float DeltaTime) override;
	virtual void ShotTimerExpired();

protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	FTimerHandle TimerHandle_ShotTimerExpired;


	virtual void Desplazamiento();

private:
	


	
	/** Handle for efficient management of ShotTimerExpired timer */
	//FTimerHandle TimerHandle_ShotTimerExpired;
};
