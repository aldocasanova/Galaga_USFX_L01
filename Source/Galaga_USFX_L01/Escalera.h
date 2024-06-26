// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FieldElement.h"
#include "GameFramework/Actor.h"
#include "Escalera.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AEscalera : public AActor, public IFieldElement
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscalera();
	UStaticMeshComponent* mallaEscalera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Spawn(UWorld* World, FVector SpawnLocation) override;
	virtual void RecibirDanio(int32 Danio) override;
private:
	int32 Vida;
};
