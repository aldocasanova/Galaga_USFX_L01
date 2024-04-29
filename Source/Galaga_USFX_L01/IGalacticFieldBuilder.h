// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GalacticField.h"
#include "IGalacticFieldBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIGalacticFieldBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IIGalacticFieldBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void BuildObstacles() = 0;
	virtual void BuildEnemies() = 0;
	virtual void BuildPowerUps() = 0;
	virtual AGalacticField* GetGalacticField() const = 0;


	//TMap<FVector, AActor*> TMObstaclesAndPowerUps;
};
