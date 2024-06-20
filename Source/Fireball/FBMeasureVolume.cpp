// Fill out your copyright notice in the Description page of Project Settings.


#include "FBMeasureVolume.h"
//include "ConstructorHelpers"

// Sets default values
AFBMeasureVolume::AFBMeasureVolume()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

   // Attach default visual mesh
   VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
   VisualMesh->SetupAttachment(RootComponent);

   static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

   if (CubeVisualAsset.Succeeded())
   {
      VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
      VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
   }

}

// Called when the game starts or when spawned
void AFBMeasureVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFBMeasureVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFBMeasureVolume::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

