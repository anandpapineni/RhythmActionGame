// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmSubsystem.h"

void URhythmSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	RhythmClock = NewObject<UMusicClockComponent>(this, UMusicClockComponent::StaticClass(), TEXT("WorldRhythmClock"));
	
}

void URhythmSubsystem::