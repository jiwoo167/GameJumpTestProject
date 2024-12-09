// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/AIInterface.h"
#include "AICharacterBase.generated.h"

UCLASS()
class GAMEJUMPTESTPROJECT_API AAICharacterBase : public ACharacter, public IAIInterface
{
	GENERATED_BODY()

public:
	AAICharacterBase();
	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	virtual void AIJump() override;
	virtual void AIBackToStart() override;
	virtual void AIMoveStart() override;
	virtual void AIMoveEnd() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAIMovementDataAsset> BaseStat;

private:
	UPROPERTY()
	TObjectPtr<class UCharacterMovementComponent> Movement;

// Move Section
	FVector StartPosition;
	bool bMoveing;
	void MoveForward();

// Jump Section
	bool bIsJumping;
	float JumpStartZPos;
	void JumpSequence(uint8 Type);
};
