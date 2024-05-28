// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANaveEnemigaManager::ANaveEnemigaManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    NavesEnemigasRestantes = 29; //por referencia
	NavesDesplegadas = false;
}

// Called when the game starts or when spawned
void ANaveEnemigaManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemigaManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    UpdateNaveCount(); //cada frame llam a update para que llame a ntify 
}

void ANaveEnemigaManager::AddObserver(INaveEnemigaObserver* Observer) //al spawnear
{
	Observers.Add(Observer);
}

void ANaveEnemigaManager::RemoveObserver(INaveEnemigaObserver* Observer) //al impactar 
{
	Observers.Remove(Observer);
}

void ANaveEnemigaManager::NotifyObservers()
{
  int NaveCount = NavesEnemigasRestantes;
    if (NaveCount < 20 && !NavesDesplegadas)
    {
        for (INaveEnemigaObserver* Observer : Observers)
        {
			Observer->OnNaveCountChanged(NaveCount); //llamo a la funcion de la interfaz uno [por uno
        }
		NavesDesplegadas = true;
    }
}

void ANaveEnemigaManager::UpdateNaveCount()
{
    // Actualiza el número de NavesEnemigas y notifica a los observadores si es necesario
    NotifyObservers();
}

