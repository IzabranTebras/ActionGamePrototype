// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/GA_Dash.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ActionGamePrototype/ActionGamePrototypeCharacter.h"

class UCharacterMovementComponent;

UGA_Dash::UGA_Dash(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGA_Dash::ExecuteActivation(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	AActionGamePrototypeCharacter* Character = CastChecked<AActionGamePrototypeCharacter>(ActorInfo->AvatarActor.Get());
	FVector DashDirection = Character->GetLastMovementInputVector();
	if (DashDirection.IsNearlyZero())
	{
		DashDirection = Character->GetActorForwardVector();
	}

	Character->GetCharacterMovement()->MovementMode = EMovementMode::MOVE_Custom;
	Character->LaunchCharacter(DashDirection.GetSafeNormal() * DashDistance, true, true);
	
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UGA_Dash::ExecuteCancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	AActionGamePrototypeCharacter* Character = CastChecked<AActionGamePrototypeCharacter>(ActorInfo->AvatarActor.Get());
	Character->GetCharacterMovement()->StopActiveMovement();
}
