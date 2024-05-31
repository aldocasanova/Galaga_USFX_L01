// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaKamikaze.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaKamikaze : public ANaveEnemiga
{
	GENERATED_BODY()
	
private:
	//float
	float AmplitudK;
	float VelocidadK;

	int codigoNave = 3;
public:
	// Sets default values for this actor's properties
	ANaveEnemigaKamikaze();

	FORCEINLINE int GetcodigoNave() const { return codigoNave; }
	FORCEINLINE void SetCodigoNave(int _codigoNave) { codigoNave = _codigoNave; }
	virtual void Tick(float DeltaTime) override;
	class USoundBase* FireSound;
	virtual void RecibirDanio() override;

	virtual void Mover(float DeltaTime) override;
	FTimerHandle TimerHandle_ShotTimerExpired;
	virtual void Desplazamiento(float DeltaTime) override;
	virtual void Disparar() override;
protected:
	
};
