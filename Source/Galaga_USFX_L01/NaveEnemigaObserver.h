// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NaveEnemigaObserver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNaveEnemigaObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API INaveEnemigaObserver
{
	GENERATED_BODY()
public:
	virtual void OnNaveCountChanged(int NewCount) = 0;	
};
