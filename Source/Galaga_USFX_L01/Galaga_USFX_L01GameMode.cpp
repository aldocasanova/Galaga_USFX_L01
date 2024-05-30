// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "OmegaFieldBuilder.h"
#include "AlfaFieldBuilder.h"
#include "DeltaFieldBuilder.h"
#include "AndromedaDirector.h"
#include "GalacticField.h"
#include "EngineUtils.h"
#include "OmegaStragedy.h"
#include "AlfaStragedy.h"
#include "DeltaStragedy.h"
#include "IGalacticFieldBuilder.h"
#include "Kismet/GameplayStatics.h"



#//include "AndromedaDirector.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();

    Director = GetWorld()->SpawnActor<AAndromedaDirector>();

    IIGalacticFieldBuilder* FieldBuilder = nullptr;
	int FormationType = FMath::RandRange(1, 3);
	switch (FormationType) // puedo cambair esto on una variable que se pueda cambiar en el editor, FMath::RandRange(1, 3)
    {
    case 1:
        FieldBuilder = GetWorld()->SpawnActor<AOmegaFieldBuilder>(); 
        break;
    case 2:
        FieldBuilder = GetWorld()->SpawnActor<AAlfaFieldBuilder>();
        break;
    case 3:
        FieldBuilder = GetWorld()->SpawnActor<ADeltaFieldBuilder>();
        break;
    }
    AGalacticField* GalacticField = Director->ConstructGalacticField(FieldBuilder);
    // Asigna la estrategia correspondiente
    SetCurrentFieldStrategy(FormationType);

    // Asignar la estrategia a todas las Naves Enemigas
    for (TActorIterator<ANaveEnemiga> It(GetWorld()); It; ++It)
    {
        ANaveEnemiga* NaveEnemiga = *It;
        if (NaveEnemiga)
        {
            NaveEnemiga->SetFieldStrategy(CurrentFieldStrategy);
        }
    }
    // Aquí puedes hacer algo con el campo galáctico, como asignarlo a una variable del GameMode o pasarlo a otros sistemas.
	TiempoTranscurrido = 0;


}

void AGalaga_USFX_L01GameMode::SetCurrentFieldStrategy(int FormationType)
{
    switch (FormationType)
    {
    case 1:
        CurrentFieldStrategy = NewObject<AOmegaStragedy>();
        break;
    case 2:
        CurrentFieldStrategy = NewObject<AAlfaStragedy>();
        break;
    case 3:
        CurrentFieldStrategy = NewObject<ADeltaStragedy>();
        break;
    }
}

void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoTranscurrido += DeltaTime;
}