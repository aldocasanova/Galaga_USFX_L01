// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaReabastecimiento.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaReabastecimiento : public ANaveEnemiga
{
	GENERATED_BODY()
	
private:
	int capacidadBalas;
	int capacidadBombas;
	int capacidadEscudos;

	float AmplitudR;
	float VelocidadR;

	int codigoNave = 6;
public:
	// Sets default values for this actor's properties
	ANaveEnemigaReabastecimiento();
		FORCEINLINE int GetCapacidadBalas() const { return capacidadBalas; }
		FORCEINLINE void SetCapacidadBalas(int _capacidadBalas) { capacidadBalas = _capacidadBalas; }
		FORCEINLINE int GetCapacidadBombas() const { return capacidadBombas; }
		FORCEINLINE void SetCapacidadBombas(int _capacidadBombas) { capacidadBombas = _capacidadBombas; }
		FORCEINLINE int GetCapacidadEscudos() const { return capacidadEscudos; }
		FORCEINLINE void SetCapacidadEsudos(int _capacidadEscudos) { capacidadEscudos = _capacidadEscudos; }
		virtual void Tick(float DeltaTime) override;

		FORCEINLINE int GetcodigoNave() const { return codigoNave; }
		FORCEINLINE void SetCodigoNave(int _codigoNave) { codigoNave = _codigoNave; }
protected:
	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	virtual void Escapar();

	virtual void Desplazamiento();
};
