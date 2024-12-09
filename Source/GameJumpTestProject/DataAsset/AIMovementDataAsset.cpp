// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/AIMovementDataAsset.h"

UAIMovementDataAsset::UAIMovementDataAsset()
{
	JumpPower = 1600.0f;
	OriginalGravityScale = 6.0f;
	ManipulatedGravityScale = 3.0f;
	HeightThreshold = 160.0f;
	GravityChangeType = 0;
}
