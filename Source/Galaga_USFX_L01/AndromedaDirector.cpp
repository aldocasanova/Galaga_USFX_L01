// Fill out your copyright notice in the Description page of Project Settings.


#include "AndromedaDirector.h"
#include "OmegaFieldBuilder.h"
#include "IGalacticFieldBuilder.h"

// Sets default values
AAndromedaDirector::AAndromedaDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAndromedaDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAndromedaDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AGalacticField* AAndromedaDirector::ConstructGalacticField(IIGalacticFieldBuilder* Builder)
{
	if (Builder)
	{
		Builder->BuildObstacles(); //accedo a métodos por el puntero
		Builder->BuildEnemies();
		Builder->BuildPowerUps();

		return Builder->GetGalacticField();
	}
	else
	{
		// Manejar el caso de que el constructor sea nulo (error)
		return nullptr;
	}
}



//se usan las felchas de la interfaz para acceder a los metodos de la interfaz
//por qué no con .? porque se ejeuta y se elimina 