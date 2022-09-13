// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CLM_AIController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTLIKEME_API ACLM_AIController : public AAIController
{
	GENERATED_BODY()
public:
	ACLM_AIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	

	FVector GetFocalPointOnActor(const AActor* Actor) const override;

};
