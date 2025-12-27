// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HarmonixMetasound/Components/MusicClockComponent.h"
#include "HarmonixMidi/BarMap.h"
#include "HarmonixMetasound/DataTypes/MusicTransport.h"
#include "RhythmClockActor.generated.h"

UCLASS()
class RHYTHMACTIONGAME_API ARhythmClockActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARhythmClockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	friend class URhythmSubsystem;
	
	UPROPERTY(VisibleAnywhere, Category="Music")
	TObjectPtr<UMusicClockComponent> ClockComponent;
};
