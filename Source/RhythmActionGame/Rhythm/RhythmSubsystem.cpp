// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmSubsystem.h"

#include "RhythmClockActor.h"

void URhythmSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	RhythmClock = NewObject<UMusicClockComponent>(this, UMusicClockComponent::StaticClass(), TEXT("WorldRhythmClock"));
	
}


void URhythmSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void OnWorldBeginPlay(UWorld& InWorld)
{
	ARhythmClockActor RhythmClock = ARhythmClockActor();
}

void URhythmSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TStatId URhythmSubsystem::GetStatId() const
{
	return Super::GetStatId();
}

void URhythmSubsystem::SetBPM(float BPM)
{
	RhythmClock->SetDefaultTempo(BPM);
}

void URhythmSubsystem::SetTimeSignature(int NumBeats, int BeatValue)
{
	RhythmClock->SetDefaultTimeSignatureNum(NumBeats);
	RhythmClock->SetDefaultTimeSignatureDenom(BeatValue);
}

void URhythmSubsystem::StartClock()
{
	RhythmClock->BeginPlay();
}
void URhythmSubsystem::PlayClock()
{
	//RhythmClock->PlayClock();
}

void URhythmSubsystem::PauseClock()
{
}

void URhythmSubsystem::StopClock()
{
}
