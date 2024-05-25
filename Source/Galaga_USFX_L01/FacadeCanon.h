// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModeloCanon.h"
#include "FacadeCanon.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AFacadeCanon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeCanon();

	//métodos de spawn
	void SpawnCanons(int32 Nivel);
	void SpawnCanon(TSubclassOf<AModeloCanon> CanonClass, FVector Location);
	void IncreaseNivel();
	void CleanUpCanones();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	//ubicaciones en extremos
	FVector TopLeftCorner;
	FVector TopRightCorner;
	FVector DownLeftCorner;
	FVector DownRightCorner;

	int32 NivelInicial;
	float  IntervaloNivel;
	float TiempoSpawn;
	FTimerHandle  IntervaloNivelimerHandle;
	int32 MaxNivel;

	//TArray<AModeloCanon*> ExistingCanons;

};
