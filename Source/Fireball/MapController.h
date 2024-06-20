// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MapController.generated.h"

/**
 * 
 */
UCLASS()
class FIREBALL_API UMapController : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	//UPROPERTY(VisibleAnywhere)

public:

	UFUNCTION(BlueprintCallable)
	static FString getPointlessMessage();

private:
	
	
};
