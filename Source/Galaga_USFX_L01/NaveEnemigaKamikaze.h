// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaKamikaze.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaKamikaze : public ANaveEnemiga
{
	GENERATED_BODY()
	
private:
	//float
public:
	// Sets default values for this actor's properties
	ANaveEnemigaKamikaze();
		//FORCEINLINE int Get//metodo() const { return //metodo; }
		//FORCEINLINE void Set//(int _//) { rangoVision = _//; }
		virtual void Tick(float DeltaTime) override;
protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();

};
