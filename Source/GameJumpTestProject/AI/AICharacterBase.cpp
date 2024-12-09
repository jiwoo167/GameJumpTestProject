// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DataAsset/AIMovementDataAsset.h"
#include "AI/GJTP_AIControllerBase.h"

// Sets default values
AAICharacterBase::AAICharacterBase()
{
	AIControllerClass = AGJTP_AIControllerBase::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	//GetCapsuleComponent()->SetCollisionProfileName();
	// 
	
	// Mesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	if (CharacterMeshRef.Object)
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassRef(TEXT("/Game/Characters/Mannequins/Animations/ABP_Manny.ABP_Manny_C"));
	if (AnimInstanceClassRef.Class)
	{
		GetMesh()->SetAnimInstanceClass(AnimInstanceClassRef.Class);
	}

	static ConstructorHelpers::FObjectFinder<UAIMovementDataAsset> StatDataRef(TEXT("/Game/Characters/Mannequins/Animations/ABP_Manny.ABP_Manny_C"));
	if (StatDataRef.Object)
	{
		BaseStat = StatDataRef.Object;
	}
}

void AAICharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// Movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->MaxWalkSpeed = 450.0f;
	GetCharacterMovement()->GravityScale = BaseStat->OriginalGravityScale;

	// GetCharacterMovement()->JumpZVelocity = StatComponent->GetStatData()->JumpZVelocity;
	// GetCharacterMovement()->AirControl = StatComponent->GetStatData()->AirControl;
}

// Called when the game starts or when spawned
void AAICharacterBase::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation();
	Movement = GetCharacterMovement();
}

// Called every frame
void AAICharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bMoveing)
	{
		MoveForward();
	}

	if (bIsJumping )
	{
		JumpSequence(BaseStat->GravityChangeType);
		






		// ĳ���Ͱ� �ٽ� �ȱ� ���°� �ȴٸ�
		if (GetCharacterMovement()->MovementMode == MOVE_Walking)
		{
			// ���� ���� �ʱ�ȭ
			bIsJumping = false;
			Movement->GravityScale = BaseStat->OriginalGravityScale;
		}
	}
}


void AAICharacterBase::AIJump()
{
	bIsJumping = true;
	LaunchCharacter(GetActorUpVector() * BaseStat->JumpPower, false, false);
}

void AAICharacterBase::AIBackToStart()
{
	SetActorLocation(StartPosition, false);
}

void AAICharacterBase::AIMoveStart()
{
	bMoveing = true;
}

void AAICharacterBase::AIMoveEnd()
{
	bMoveing = false;
}

void AAICharacterBase::MoveForward()
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, 50.0f);
}

void AAICharacterBase::JumpSequence(uint8 Type)
{
	switch (Type)
	{
		case 0:
		break;
		case 1:
		{
			// ���� ������ ��ġ�� ���� �󸶳� ���� �ö󰬴��� z�� ���
			float CurrentZValue = GetActorLocation().Z - JumpStartZPos;

			// z���� �Ӱ�ġ���� Ŀ�� ���
			if (CurrentZValue > BaseStat->HeightThreshold)
			{
				// �߷°� ����
				Movement->GravityScale = BaseStat->ManipulatedGravityScale;
			}
			// z���� �Ӱ�ġ���� �۾��� ���
			else
			{
				// ���� �߷°����� ����
				Movement->GravityScale = BaseStat->OriginalGravityScale;
			}
		}
		break;
		case 2:
		{



		}
		break;
	default:
		break;
	}
}
