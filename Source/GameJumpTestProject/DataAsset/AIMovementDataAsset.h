// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AIMovementDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJUMPTESTPROJECT_API UAIMovementDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UAIMovementDataAsset();

	UPROPERTY(EditAnywhere, Category = "Jump", Meta = (ToolTip = "JumpPower"))
	float JumpPower;

	UPROPERTY(EditAnywhere, Category = "Jump", Meta = (ToolTip = "Base GravityScale"))
	float OriginalGravityScale;

	UPROPERTY(EditAnywhere, Category = "Jump", Meta = (ToolTip = "GravityScale At Over Threshold"))
	float ManipulatedGravityScale;

	UPROPERTY(EditAnywhere, Category = "Jump", Meta = (ToolTip = "GravityScale Change Threshold"))
	float HeightThreshold;

	UPROPERTY(EditAnywhere, Category = "Jump", Meta = (ToolTip = "0 = Default Jump / 1 = Change GravityScale At One TIme"))
	uint8 GravityChangeType;

};
