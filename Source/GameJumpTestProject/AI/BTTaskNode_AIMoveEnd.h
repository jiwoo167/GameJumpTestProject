// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_AIMoveEnd.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJUMPTESTPROJECT_API UBTTaskNode_AIMoveEnd : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTaskNode_AIMoveEnd();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;
};
