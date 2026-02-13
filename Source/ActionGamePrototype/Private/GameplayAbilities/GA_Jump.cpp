// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/GA_Jump.h"

#include "ActionGamePrototype/ActionGamePrototypeCharacter.h"

UGA_Jump::UGA_Jump(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

bool UGA_Jump::ExecuteCanActivateAbilityValidations(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags,
	const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	const AActionGamePrototypeCharacter* Character = CastChecked<AActionGamePrototypeCharacter>(ActorInfo->AvatarActor.Get(), ECastCheckedType::NullAllowed);
	return (Character && Character->CanJump());
}

void UGA_Jump::ExecuteActivation(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                      const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	AActionGamePrototypeCharacter* Character = CastChecked<AActionGamePrototypeCharacter>(ActorInfo->AvatarActor.Get());
	Character->Jump();
	
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UGA_Jump::ExecuteCancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	AActionGamePrototypeCharacter* Character = CastChecked<AActionGamePrototypeCharacter>(ActorInfo->AvatarActor.Get());
	Character->StopJumping();
}

