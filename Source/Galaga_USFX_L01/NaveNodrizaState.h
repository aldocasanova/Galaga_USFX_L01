// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NaveNodrizaState.generated.h"
//contexto
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNaveNodrizaState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API INaveNodrizaState
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public: 
	float TiempoDisparo;
	//Establecemos a la Nave Nodriza
	virtual void SetNaveNodriza(class ANaveEnemigaNodriza* NaveNodriza) = 0;

	//Funciones que compartiran con los estados y la nave nodriza
	virtual void Mover(float DeltaTime) = 0;
	virtual void Disparar() = 0;
	virtual void CrearEscudo() = 0;
	//virtual void DestruirEscudos() = 0;
};
