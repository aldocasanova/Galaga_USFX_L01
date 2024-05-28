// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaObserver.h"
#include "NaveEnemigaManager.h"
#include "NaveEnemigaTransporte.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTransporte : public ANaveEnemiga, public INaveEnemigaObserver
{
	GENERATED_BODY()
private:
	float capacidadCargaPeso;
	float capacidadCargaVolumen;

	float AmplitudT;
	float VelocidadT;

	int codigoNave = 7;


public:
	ANaveEnemigaTransporte();
	FORCEINLINE float GetCapacidadCargaPeso() const { return capacidadCargaPeso; }
	FORCEINLINE void SetCapacidadCargaPeso(float capacidad) { capacidadCargaPeso = capacidad; }
	FORCEINLINE float GetCapacidadCargaVolumen() const { return capacidadCargaVolumen; }
	FORCEINLINE void SetCapacidadCargaVolumen(float capacidad) { capacidadCargaVolumen = capacidad; }

	FORCEINLINE int GetcodigoNave() const { return codigoNave; }
	FORCEINLINE void SetCodigoNave(int _codigoNave) { codigoNave = _codigoNave; }
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	//interfaz
	virtual void OnNaveCountChanged(int NewCount) override;
	void SpawnNaveEnemigaCaza();
	ANaveEnemigaManager* NaveManager;
	ANaveEnemigaTransporte* EnemyTransport = this;

	virtual void RecibirDanio() override;

protected:
	virtual void Mover(float DeltaTime);// no tengo que poner el overribe si no estoy sobreesbribiendo nada
	virtual void  Disparar();
	virtual void  Destruirse();
	virtual void  Escapar();

	virtual void Desplazamiento(float DeltaTime);
};
