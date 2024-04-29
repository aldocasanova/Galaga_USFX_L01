// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GalacticField.h"
#include "IGalacticFieldBuilder.h"
#include "AndromedaDirector.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AAndromedaDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAndromedaDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AGalacticField* ConstructGalacticField(IIGalacticFieldBuilder* Builder);

};

