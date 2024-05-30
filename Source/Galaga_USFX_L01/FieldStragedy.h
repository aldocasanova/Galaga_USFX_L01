// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FieldStragedy.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFieldStragedy : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IFieldStragedy
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Mover(class ANaveEnemiga* NaveEnemiga, float DeltaTime) = 0;
	virtual void Disparar(class ANaveEnemiga* NaveEnemiga) = 0;
	virtual void Desplazamiento(class ANaveEnemiga* NaveEnemiga, float DeltaTime) = 0;
};
