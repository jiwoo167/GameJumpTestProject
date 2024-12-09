// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GJTP_AIControllerBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GJTP_AI.h"

AGJTP_AIControllerBase::AGJTP_AIControllerBase()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTAssetRef(TEXT("/Script/AIModule.BehaviorTree'/Game/AI/BT_AI.BT_AI'"));
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBAssetRef(TEXT("/Script/AIModule.BlackboardData'/Game/AI/BB_AI.BB_AI'"));

	if (BTAssetRef.Object)
	{
		BTAsset = BTAssetRef.Object;
	}
	if (BBAssetRef.Object)
	{
		BBAsset = BBAssetRef.Object;
	}
}

void AGJTP_AIControllerBase::RunAI()
{



	UBlackboardComponent* BlackboardPtr = Blackboard.Get();
	if (UseBlackboard(BBAsset, BlackboardPtr))
	{
		 Blackboard->SetValueAsVector(BBKEY_STARTPOS, GetPawn()->GetActorLocation());
		bool RunResult = RunBehaviorTree(BTAsset);
		ensure(RunResult);
	}
}

void AGJTP_AIControllerBase::StopAI()
{
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}


void AGJTP_AIControllerBase::StopBehaviorTree()
{
	if (UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent))
	{
		BTComponent->StopTree(EBTStopMode::Safe);
	}
}

void AGJTP_AIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	RunAI();
}
