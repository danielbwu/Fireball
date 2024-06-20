// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
/**
#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerCharacter.h"
#include "CharacterController.generated.h"

//class UInputMappingContext;
//class UEnhancedInputComponent;
//class APlayerCharacter;
//*/

//**
#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "CharacterHud.h"
#include "CharacterController.generated.h"

//#include "EnhancedInputComponent.h"
//#include "EnhancedInputSubsystems.h"

// Forward Declarations
class UEnhancedInputComponent;
class APlayerCharacter;
class UInputMappingContext;
// */
UCLASS(Abstract)
class FIREBALL_API ACharacterControllerBase : public APlayerController
{	
	
public:
	// Input Action to to map to movement
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Character Movement")
	//UInputAction* ActionMove = nullptr;
	TObjectPtr<UInputAction> ActionMove = nullptr;

	// Look action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Character Movement")
	//UInputAction* ActionLook = nullptr;
	TObjectPtr<UInputAction> ActionLook = nullptr;

	// Jump action
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Character Movement")
	//UInputAction* ActionJump = nullptr;
	TObjectPtr<UInputAction> ActionJump = nullptr;

	// The Input Action to map to crouching.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionToggleCrouch = nullptr;

	// The Input Action to map to sprinting.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionToggleSprint = nullptr;

	// The Input Action to map to psi blast.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionPsiBlast = nullptr;

	// Input to cycle UI display
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|UI")
	TObjectPtr<UInputAction> ActionCycleUImode = nullptr;

	// Input Mapping context
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input|Character Movement")
	TObjectPtr<UInputMappingContext> InputMappingContent = nullptr;
	

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	void HandleLook(const FInputActionValue& InputActionValue);
	void HandleMove(const FInputActionValue& InputActionValue);
	void HandleJump();
	void HandleToggleCrouch();
	void HandleToggleSprint();
	void HandlePsiBlast();

	void HandleCycleUIMode();

private:
	// Used to store reference to InputComponent cast to an EnhancedInput
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

	// Stores reference to the pawn we are controlling
	UPROPERTY()
	APlayerCharacter* PlayerCharacter = nullptr;

	// Stores a refernce to the UI HUD
	UPROPERTY()
	TObjectPtr<ACharacterHud> PlayerHud = nullptr;

	GENERATED_BODY()

};
