// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
//*
#include "PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
//*/

void ACharacterControllerBase::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// Store reference to player pawn
	PlayerCharacter = Cast<APlayerCharacter>(aPawn);
	checkf(PlayerCharacter, TEXT("ACharacterControllerBase derived classes hsould only possess APlayerCharacterBase derived pawns"));

	// Get reference to EnhancedInputComponent
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	checkf(EnhancedInputComponent, TEXT("Unable to get reference to the EnhancedInputComponent"));

	// Get the local Player subsystem
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	checkf(InputSubsystem, TEXT("Unable to get reference to the EnhancedInputLocalPlayerSubsystem"));

	// Wipe existing mappings and replace it with our own
	checkf(InputMappingContent, TEXT("Unable to get reference to the EnhancedInputLocalPlayerSubsystem"));
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(InputMappingContent, 0);

	// Bind input actions
	// Only attempt to bind if a valid value was provided
	if (ActionMove) 
	{
		EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, 
			&ACharacterControllerBase::HandleMove);
	}
	if (ActionLook) 
	{
		EnhancedInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered, this, 
			&ACharacterControllerBase::HandleLook);
	}
	if (ActionJump) 
	{
		EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Triggered, this, 
			&ACharacterControllerBase::HandleJump);
	}
	if (ActionPsiBlast)
	{
		EnhancedInputComponent->BindAction(ActionPsiBlast, ETriggerEvent::Triggered, this,
			&ACharacterControllerBase::HandlePsiBlast);
	}
	if (ActionToggleCrouch)
	{
		EnhancedInputComponent->BindAction(ActionToggleCrouch, ETriggerEvent::Triggered, this,
			&ACharacterControllerBase::HandleToggleCrouch);
	}
	if (ActionToggleSprint)
	{
		EnhancedInputComponent->BindAction(ActionToggleSprint, ETriggerEvent::Triggered, this,
			&ACharacterControllerBase::HandleToggleSprint);
	}
	if (ActionCycleUImode)
	{
		EnhancedInputComponent->BindAction(ActionCycleUImode, ETriggerEvent::Triggered, this,
			&ACharacterControllerBase::HandleCycleUIMode);
	}
}

void ACharacterControllerBase::OnUnPossess()
{
	// Unbind input actions
	EnhancedInputComponent->ClearActionBindings();

	// Call parent
	Super::OnUnPossess();
}

void ACharacterControllerBase::HandleLook(const FInputActionValue& InputActionValue)
{
	const FVector2d LookAxisVector = InputActionValue.Get<FVector2D>();

	// Add yaw and pitch input to controller
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void ACharacterControllerBase::HandleMove(const FInputActionValue& InputActionValue)
{
	// Value is a Vector2D
	const FVector2d MovementVector = InputActionValue.Get<FVector2D>();

	// Add movement to player's character pawn
	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), MovementVector.Y);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
	}
}

void ACharacterControllerBase::HandleJump()
{
	// Input is digital - no value

	// Make player character jump. Disable crouch if active
	if (PlayerCharacter)
	{
		PlayerCharacter->UnCrouch();
		PlayerCharacter->Jump();
	}
}

void ACharacterControllerBase::HandleToggleCrouch()
{
	if (PlayerCharacter && PlayerCharacter->bIsCrouched)
		PlayerCharacter->UnCrouch();
	else
		PlayerCharacter->Crouch();
}

void ACharacterControllerBase::HandleToggleSprint()
{
	if (PlayerCharacter) PlayerCharacter->ToggleRunning();
}

void ACharacterControllerBase::HandlePsiBlast()
{
	if (PlayerCharacter) PlayerCharacter->PsiBlast();
}

void ACharacterControllerBase::HandleCycleUIMode()
{
	if (PlayerHud)
	{
		//PlayerHud->CycleToNextViewMode();
	}

}
