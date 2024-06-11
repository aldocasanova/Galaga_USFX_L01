// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NaveEnemiga.h"
#include "OmegaFieldBuilder.h"
#include "AlfaFieldBuilder.h"
#include "DeltaFieldBuilder.h"
#include "OmegaStragedy.h"
#include "AlfaStragedy.h"
#include "DeltaStragedy.h"
#include "AndromedaDirector.h"
#include "GalacticField.h"
#include "IGalacticFieldBuilder.h"
#include "FacadeCanon.h"
#include "Galaga_USFX_L01Pawn.h"

#include "Galaga_USFX_L01GameMode.generated.h"

//#include "AndromedaDirector.h"

UCLASS(MinimalAPI)
class AGalaga_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_L01GameMode();
	void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 
private:
	TScriptInterface<IFieldStragedy> CurrentFieldStrategy;
	void SetCurrentFieldStrategy(int FormationType);
	int TiempoTranscurrido = 0;
	AAndromedaDirector* Director;

	AOmegaStragedy* OmegaStrategy;
	AAlfaStragedy* AlfaStrategy;
	ADeltaStragedy* DeltaStrategy;
	FTimerHandle StrategyTimerHandle;
	//void ChangeStrategy();
	
};
