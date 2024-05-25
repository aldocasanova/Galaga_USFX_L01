// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveNodrizaState.h"
#include "EstadoOfensivo.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AEstadoOfensivo : public AActor, public INaveNodrizaState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoOfensivo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EstadoOfensivo() override;
	virtual void EstadoDefensivo() override;
	virtual void EstadoDebil() override;

	virtual void SetNaveNodrizaState(class NaveNodriza* NaveNodriza) override;
};
