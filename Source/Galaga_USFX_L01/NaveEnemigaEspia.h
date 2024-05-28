// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

private:
	int rangoVision;

	float AmplitudE;
	float VelocidadE;
	
	int codigoNave = 2;
public:	
	// Sets default values for this actor's properties
	ANaveEnemigaEspia();
	FORCEINLINE int GetRangoVision() const { return rangoVision; }
	FORCEINLINE void SetRangoVision(int _rangoVision) { rangoVision = _rangoVision; }

	FORCEINLINE int GetcodigoNave() const { return codigoNave; }
	FORCEINLINE void SetCodigoNave(int _codigoNave) { codigoNave = _codigoNave; }
	virtual void Tick(float DeltaTime) override;

	//class USoundBase* FireSound;
	virtual void RecibirDanio() override;
protected:
	virtual void Mover(float DeltaTime) override;
	virtual void Destruirse() override;
	//virtual void Escapar() override;
	virtual void Desplazamiento(float DeltaTime) override;


};
