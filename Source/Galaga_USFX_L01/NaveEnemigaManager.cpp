// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANaveEnemigaManager::ANaveEnemigaManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    NavesEnemigasRestantes = 29;
	//NavesDesplegadas = false;
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
    UpdateNaveCount(); 
}

void ANaveEnemigaManager::AddObserver(INaveEnemigaObserver* Observer)
{
	Observers.Add(Observer);
}

void ANaveEnemigaManager::RemoveObserver(INaveEnemigaObserver* Observer)
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
			Observer->OnNaveCountChanged(NaveCount); //llamo a la funcion de la interfaz
        }
        NavesEnemigasRestantes += 20;
		NavesDesplegadas = true;
    }
    //for (INaveEnemigaObserver* Observer : Observers)
    //{
    //    Observer->OnNaveCountChanged(NavesEnemigasRestantes); // Notify each observer
    //}
}

void ANaveEnemigaManager::UpdateNaveCount()
{
    // Actualiza el número de NavesEnemigas y notifica a los observadores si es necesario
    NotifyObservers();
}

void ANaveEnemigaManager::AddNaveEnemiga(ANaveEnemiga* Nave)
{
    NavesEnemigas.Add(Nave);
    UpdateNaveCount();
    
}

void ANaveEnemigaManager::RemoveNaveEnemiga(ANaveEnemiga* Nave)
{
   /* NavesEnemigas.Remove(Nave);
    UpdateNaveCount();*/
    NavesEnemigas.Remove(Nave);
    NavesEnemigasRestantes--;

    if (NavesEnemigasRestantes < 20 && !NavesDesplegadas)
    {
        NotifyObservers();
        NavesEnemigasRestantes += 20;
        NavesDesplegadas = true;
    }
}


