// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMetasound/Components/MusicClockComponent.h"
#include "HarmonixMetasound/DataTypes/MusicTransport.h"
#include "Subsystems/WorldSubsystem.h"
#include "RhythmSubsystem.generated.h"


/**
 * 
 */
UCLASS()
class RHYTHMACTIONGAME_API URhythmSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
	
	
	public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;
 
	 virtual void Tick(float DeltaTime) override;
	 virtual TStatId GetStatId() const override;
	 virtual bool IsTickable() const override { return true; }
	
	 UFUNCTION(BlueprintCallable, Category = "RhythmSubsystem")
	 void SetBPM(float BPM);
	
	 UFUNCTION(BlueprintCallable, Category = "RhythmSubsystem")
	 void SetTimeSignature(int NumBeats, int BeatValue);
	
	 UFUNCTION(BlueprintCallable, Category = "RhythmSubsystem")
	 void PlayClock();
	
	 UFUNCTION(BlueprintCallable, Category = "RhythmSubsystem")
	 void PauseClock();
	
	UFUNCTION(BlueprintCallable, Category = "RhythmSubsystem")
	void StartClock();
	
	 UFUNCTION(BlueprintCallable, Category = "RhythmSubsystem")
	 void StopClock();
    
	TObjectPtr<UMusicClockComponent> GetRhythmClock() const {return RhythmClock;}
	
    private:
	UPROPERTY()
	TObjectPtr<UMusicClockComponent> RhythmClock;
		
};

