// Header file

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "GameplayTagContainer.h"
#include "EnhancedInputComponent.h" // For ETriggerEvent
#include "Abilities/GameplayAbility.h"
#include "RhythmActionGameCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FAbilityInputTrigger
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* TriggerAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	ETriggerEvent TriggerEvent = ETriggerEvent::Started;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	FGameplayTag TriggerTag;
};
USTRUCT(BlueprintType)
struct FRhythmInputEvent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	float EventTime = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	FGameplayEventData EventData;
};


/**
 * Player character with movement input and gameplay tag-driven ability input system.
 */
UCLASS(abstract)
class ARhythmActionGameCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UAbilitySystemComponent* ASC;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UAudioComponent* AudioComponent;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action (e.g., right stick or mouse delta) */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;
	
	/** Array of input triggers mapping Input Actions to Gameplay Tags and TriggerEvent */
	UPROPERTY(EditAnywhere, Category="Input")
	TArray<FAbilityInputTrigger> AbilityInputTriggers;
	
	UPROPERTY(EditAnywhere, Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> Abilities;

public:
	ARhythmActionGameCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return ASC; }

protected:
	UFUNCTION()
	void FlushBufferedEvents(int BeatNumber, int BeatInBar);
	
	virtual void BeginPlay() override;
	void TriggerAbility(const FInputActionValue& Value, FGameplayTag GameplayTag);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);
	
	/** Called for camera look input */
	void Look(const FInputActionValue& Value);
	
	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	TArray<FRhythmInputEvent> BufferedInputs;
};