// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GJTP_AIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJUMPTESTPROJECT_API AGJTP_AIControllerBase : public AAIController
{
	GENERATED_BODY()
public:
	AGJTP_AIControllerBase();

	void RunAI();
	void StopAI();
	void StopBehaviorTree();


protected:
	virtual void OnPossess(APawn* InPawn) override;

protected:
	UPROPERTY()
	TObjectPtr<class UBlackboardData> BBAsset;

	UPROPERTY()
	TObjectPtr<class UBehaviorTree> BTAsset;
};
