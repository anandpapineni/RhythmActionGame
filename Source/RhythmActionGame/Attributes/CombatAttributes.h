// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CombatAttributes.generated.h"

/**
 * 
 */
UCLASS()
class RHYTHMACTIONGAME_API UCombatAttributes : public UAttributeSet
{
	GENERATED_BODY()
	
		 
public:
	UCombatAttributes();
 
	// Health Attribute
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	FGameplayAttributeData Health;
 
	// AttackPower Attribute
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	FGameplayAttributeData AttackPower;
};
