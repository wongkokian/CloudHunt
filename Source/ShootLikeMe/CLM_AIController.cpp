// Fill out your copyright notice in the Description page of Project Settings.


#include "CLM_AIController.h"
#include "Navigation/CrowdFollowingComponent.h"

ACLM_AIController::ACLM_AIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{

}

FVector ACLM_AIController::GetFocalPointOnActor(const AActor* Actor) const
{
	return Actor != nullptr ? Actor->GetActorLocation() + FVector(0,0,40.f) : FAISystem::InvalidLocation;
}
