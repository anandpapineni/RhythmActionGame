// Source file

#include "RhythmActionGameCharacter.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "AbilitySystemComponent.h"
#include "InputAction.h"
#include "Attributes/CombatAttributes.h"

ARhythmActionGameCharacter::ARhythmActionGameCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);

	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void ARhythmActionGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	ASC->AddAttributeSetSubobject(NewObject<UCombatAttributes>(ASC));
	for (TSubclassOf<UGameplayAbility>& Ability : Abilities)
	{
		FGameplayAbilitySpec AbilitySpec;
		AbilitySpec = ASC->BuildAbilitySpecFromClass(Ability);
		ASC->GiveAbility(AbilitySpec);
	}
}

void ARhythmActionGameCharacter::TriggerAbility(const FInputActionValue& Value, FGameplayTag GameplayTag)
{
	FGameplayEventData EventData;
	EventData.EventMagnitude = Value.GetMagnitude();
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(this, GameplayTag, EventData);
}

void ARhythmActionGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInput)
	{
		UE_LOG(LogTemp, Error, TEXT("EnhancedInputComponent not found on PlayerInputComponent!"));
		return;
	}

	// Bind movement input
	if (MoveAction)
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARhythmActionGameCharacter::Move);
	}
	
	// Bind look input
	if (LookAction)
	{
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARhythmActionGameCharacter::Look);
	}
 

	// Bind ability input triggers with custom TriggerEvent
	for (const FAbilityInputTrigger& Trigger : AbilityInputTriggers)
	{
		if (Trigger.TriggerAction)
		{
			UInputAction* InputAction = Trigger.TriggerAction;
			ETriggerEvent TriggerEvent = Trigger.TriggerEvent;

			EnhancedInput->BindAction(InputAction, TriggerEvent, this, &ARhythmActionGameCharacter::TriggerAbility, Trigger.TriggerTag);
		}
	}
}

void ARhythmActionGameCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller && !MovementVector.IsNearlyZero())
	{
		if (MovementVector.Y != 0.f)
		{
			AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		}
		if (MovementVector.X != 0.f)
		{
			AddMovementInput(GetActorRightVector(), MovementVector.X);
		}
	}
}

void ARhythmActionGameCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ARhythmActionGameCharacter::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void ARhythmActionGameCharacter::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}