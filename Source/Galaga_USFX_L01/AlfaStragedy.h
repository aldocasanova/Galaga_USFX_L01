// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FieldStragedy.h"
#include "AlfaStragedy.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AAlfaStragedy : public AActor, public IFieldStragedy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlfaStragedy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/*virtual void Mover(float DeltaTime) override;
	virtual void Disparar() override;*/
	virtual void Mover(ANaveEnemiga* NaveEnemiga, float DeltaTime) override;
	virtual void Disparar(ANaveEnemiga* NaveEnemiga) override;
	virtual void Desplazamiento(class ANaveEnemiga* NaveEnemiga, float DeltaTime) override {};
};
