// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()
	
private:
	int NroEscudos;


	uint32 bCanFire : 1;
	float FireRate;
	int MaxShots;
	int ShotsFired;


	float AmplitudVertical;
	float VelocidadVertical;

	float Radio;	
	float VelocidadR;

	int codigoNave = 4;
public:
	// Sets default values for this actor's properties
	ANaveEnemigaNodriza();
	FORCEINLINE float GetNroEscudos() const { return NroEscudos; }
	FORCEINLINE void SetNroEscudos(int _NroEscudos) { NroEscudos = _NroEscudos; }
	virtual void Tick(float DeltaTime) override;
	virtual void ShotTimerExpired();

	FORCEINLINE int GetcodigoNave() const { return codigoNave; }
	FORCEINLINE void SetCodigoNave(int _codigoNave) { codigoNave = _codigoNave; }

	class USoundBase* FireSound;

protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Escapar();
	FTimerHandle TimerHandle_ShotTimerExpired;
	virtual void Desplazamiento(float DeltaTime);

};
