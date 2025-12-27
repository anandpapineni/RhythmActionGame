// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmSubsystem.h"

#include "RhythmClockActor.h"

void URhythmSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}


void URhythmSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void URhythmSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	RhythmClock = InWorld.SpawnActor<ARhythmClockActor>();
	SetBPM(120);
	SetTimeSignature(4, 4);
}

void URhythmSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void URhythmSubsystem::SetBPM(float BPM)
{
	RhythmClock->ClockComponent->SetDefaultTempo(BPM);
}

void URhythmSubsystem::SetTimeSignature(int32 NumBeats, int32 BeatValue)
{
	// Set time signature to 4/4 (4 beats per bar, quarter note)
	RhythmClock->ClockComponent->SetDefaultTimeSignatureNum(NumBeats);
	RhythmClock->ClockComponent->SetDefaultTimeSignatureDenom(BeatValue);		// Set BPM to 120 beats per minute
}

void URhythmSubsystem::StartClock()
{
	RhythmClock->ClockComponent->Start();
}

void URhythmSubsystem::ContinueClock()
{
	RhythmClock->ClockComponent->Continue();
}

void URhythmSubsystem::PauseClock()
{
	RhythmClock->ClockComponent->Pause();
}

void URhythmSubsystem::StopClock()
{
	RhythmClock->ClockComponent->Stop();
}

FBeatEvent& URhythmSubsystem::GetBeatEvent()
{
	return RhythmClock->ClockComponent->BeatEvent;
}
