// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

private:
	int rangoVision;
public:	
	// Sets default values for this actor's properties
	ANaveEnemigaEspia();
	FORCEINLINE int GetRangoVision() const { return rangoVision; }
	FORCEINLINE void SetRangoVision(int _rangoVision) { rangoVision = _rangoVision; }
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void Mover(float DeltaTime);
	virtual void Destruirse();
	

};
