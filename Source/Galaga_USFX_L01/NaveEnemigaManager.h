// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//publisher
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaObserver.h"
#include "NaveEnemigaManager.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANaveEnemigaManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	TArray<INaveEnemigaObserver*> Observers;
	int NavesEnemigasRestantes;
	bool NavesDesplegadas;
public:
	void AddObserver(INaveEnemigaObserver* Observer);
	void RemoveObserver(INaveEnemigaObserver* Observer);
	void NotifyObservers();
	void UpdateNaveCount();

	FORCEINLINE int GetNavesEnemigasRestantes() const { return NavesEnemigasRestantes; }
	FORCEINLINE void SetNavesEnemigasRestantes(int _NavesEnemigasRestantes) { NavesEnemigasRestantes = _NavesEnemigasRestantes; }

};
