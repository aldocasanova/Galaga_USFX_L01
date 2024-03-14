// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "MyNaveEnemigaCazaX.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AMyNaveEnemigaCazaX : public ANaveEnemigaCaza
{
	GENERATED_BODY()
private:
	int cantidadBombas;
public:
	virtual void Tick(float DeltaTime) override;
	AMyNaveEnemigaCazaX();
	FORCEINLINE int GetCantidadBombas()const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
protected:
	virtual void Mover(float DeltaTime) override;
	virtual void Disparar();
	virtual void Destruirse();
};