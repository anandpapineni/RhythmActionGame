// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmClockActor.h"


// Sets default values
ARhythmClockActor::ARhythmClockActor()
{
	// Create Music Clock component and attach it
	RhythmClock = CreateDefaultSubobject<UMusicClockComponent>(TEXT("RhythmClock"));
}

// Called when the game starts or when spawned
void ARhythmClockActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetupClock();
	StartClock();
}

void ARhythmClockActor::SetupClock()
{
	if (RhythmClock)
	{
		// Set BPM to 120 beats per minute
		RhythmClock->SetDefaultTempo(120.0f);
 
		// Set time signature to 4/4 (4 beats per bar, quarter note)
		RhythmClock->SetDefaultTimeSignatureNum(4);
		RhythmClock->SetDefaultTimeSignatureDenom(4);
	}
}

void ARhythmClockActor::StartClock()
{
	if (RhythmClock)
	{
		RhythmClock->Start();
	}
}

void ARhythmClockActor::PlayClock()
{
	if (RhythmClock)
	{
		RhythmClock->Continue();
	}
}

void ARhythmClockActor::PauseClock()
{
	if (RhythmClock)
	{
		RhythmClock->Pause();
	}
}

void ARhythmClockActor::StopClock()
{
	if (RhythmClock)
	{
		RhythmClock->Deactivate();
	}
}

