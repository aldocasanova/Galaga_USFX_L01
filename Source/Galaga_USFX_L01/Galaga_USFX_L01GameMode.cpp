// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "OmegaFieldBuilder.h"
#include "AlfaFieldBuilder.h"
#include "DeltaFieldBuilder.h"
#include "IGalacticFieldBuilder.h"


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
	switch (FMath::RandRange(1, 3)) // puedo cambair esto on una variable que se pueda cambiar en el editor
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

    // Aquí puedes hacer algo con el campo galáctico, como asignarlo a una variable del GameMode o pasarlo a otros sistemas.
	TiempoTranscurrido = 0;

}
void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoTranscurrido += DeltaTime;
}