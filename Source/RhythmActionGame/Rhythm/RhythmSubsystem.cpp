// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmSubsystem.h"

#include "RhythmClockActor.h"

void URhythmSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	UE_LOG(LogTemp, Log, TEXT("BPM: %f"), BPM);
	UE_LOG(LogTemp, Log, TEXT("Time Signature: %d/%d"), TimeSigNum, TimeSigDenom);
}


void URhythmSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void URhythmSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	RhythmClock = InWorld.SpawnActor<ARhythmClockActor>();
	SetBPM(BPM);
	SetTimeSignature(TimeSigNum, TimeSigDenom);
}

void URhythmSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void URhythmSubsystem::SetBPM(float NewBPM)
{
	RhythmClock->ClockComponent->SetDefaultTempo(NewBPM);
}

void URhythmSubsystem::SetTimeSignature(int32 NumBeats, int32 BeatValue)
{
	// Set time signature to 4/4 (4 beats per bar, quarter note)
	RhythmClock->ClockComponent->SetDefaultTimeSignatureNum(NumBeats);
	RhythmClock->ClockComponent->SetDefaultTimeSignatureDenom(BeatValue);		
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