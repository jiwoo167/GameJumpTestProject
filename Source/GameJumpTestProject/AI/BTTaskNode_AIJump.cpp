// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTaskNode_AIJump.h"
#include "AIController.h"
#include "Interface/AIInterface.h"
#include "GJTP_AI.h"


UBTTaskNode_AIJump::UBTTaskNode_AIJump()
{
}

EBTNodeResult::Type UBTTaskNode_AIJump::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	APawn* ControllingPawn = Cast<APawn>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ControllingPawn)
	{
		return EBTNodeResult::Failed;
	}

	IAIInterface* AiPawn = Cast<IAIInterface>(ControllingPawn);
	if (nullptr == AiPawn)
	{
		return EBTNodeResult::Failed;
	}
	AiPawn->AIJump();

	return EBTNodeResult::Succeeded;

}