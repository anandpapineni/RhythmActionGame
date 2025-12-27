// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmClockActor.h"

#include "RhythmSubsystem.h"


// Sets default values
ARhythmClockActor::ARhythmClockActor()
{
	// Create Music Clock component and attach it
	ClockComponent = CreateDefaultSubobject<UMusicClockComponent>(TEXT("RhythmClock"));
}

// Called when the game starts or when spawned
void ARhythmClockActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetSubsystem<URhythmSubsystem>()->StartClock();
}

