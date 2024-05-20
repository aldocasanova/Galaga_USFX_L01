// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NaveEnemiga.h"
#include "OmegaFieldBuilder.h"
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

	int TiempoTranscurrido = 0;
	AAndromedaDirector* Director;
	
	//AFacadeCanon* FormacionCanones;


};
