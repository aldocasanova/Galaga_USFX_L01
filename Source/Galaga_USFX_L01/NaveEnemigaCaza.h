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

	int codigoNave = 1;
	
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

	FORCEINLINE int GetcodigoNave() const { return codigoNave; }
	FORCEINLINE void SetCodigoNave(int _codigoNave) { codigoNave = _codigoNave; }

	virtual void Tick(float DeltaTime) override;
	virtual void ShotTimerExpired();

protected:
	virtual void Mover(float DeltaTime) override;
	virtual void Disparar() override;
	virtual void Destruirse() override;

	FTimerHandle TimerHandle_ShotTimerExpired;
	virtual void Desplazamiento(float DeltaTime) override;

	void StartFly();

private:
	


	
	/** Handle for efficient management of ShotTimerExpired timer */
	//FTimerHandle TimerHandle_ShotTimerExpired;
};
