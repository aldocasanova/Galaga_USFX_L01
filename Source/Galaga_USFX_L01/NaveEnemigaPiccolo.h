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
public:
	// Sets default values for this actor's properties
	ANaveEnemigaPiccolo();
	FORCEINLINE float GetResistenciaBalas() const { return ResistenciaBalas; }
	FORCEINLINE void SetResistenciaBalas(int _ResistenciaBalas) { ResistenciaBalas = _ResistenciaBalas; }
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void Mover(float DeltaTime);
	virtual void Destruirse();

};
