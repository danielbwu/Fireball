// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Hud.h"
#include "CharacterHud.generated.h"

class APlayerCharacter;
class UMinimalLayoutBase;
class UModerateLayoutBase;
class UOverloadLayoutBase;

UENUM(BlueprintType)
enum class EHudViewMode : uint8
{
	CleanAndPristine UMETA(Tooltip = "Get that mess outta my face!"),
	Minimal UMETA(Tooltip = "Just the facts, maam."),
	Moderate UMETA(Tooltip = "Keep me well informed"),
	SensoryOverload UMETA(Tooltip = "My other UI is a derivatives trading screen")
};

/**
 * 
 */
UCLASS()
class FIREBALL_API ACharacterHud : public AHUD
{
	GENERATED_BODY()

public:
	
protected:

private:
	// Determines what UI elements should be displayed.
	UPROPERTY(EditAnywhere)
	EHudViewMode CurrentViewMode = EHudViewMode::Moderate;

};
