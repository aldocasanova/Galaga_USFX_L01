// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaPiccolo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaPiccolo : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	int ResistenciaBalas;

	float AmplitudP;
	float VelocidadP;

	int codigoNave = 5;
public:
	// Sets default values for this actor's properties
	ANaveEnemigaPiccolo();
	FORCEINLINE float GetResistenciaBalas() const { return ResistenciaBalas; }
	FORCEINLINE void SetResistenciaBalas(int _ResistenciaBalas) { ResistenciaBalas = _ResistenciaBalas; }

	FORCEINLINE int GetcodigoNave() const { return codigoNave; }
	FORCEINLINE void SetCodigoNave(int _codigoNave) { codigoNave = _codigoNave; }
	virtual void Tick(float DeltaTime) override;

	virtual void RecibirDanio() override;

	virtual void Mover(float DeltaTime) override;
	virtual void Disparar() override {};
	virtual void Desplazamiento(float DeltaTime) override;
protected:
	

};
