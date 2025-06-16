// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Aura_Control.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class AURA_API AAura_Control : public APlayerController
{
	GENERATED_BODY()
public:
	AAura_Control();
protected:
	virtual void BeginPlay() override;
	virtual	void SetupInputComponent() override;

	void Move(const FInputActionValue& InputActionValue);
private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext>AuraMapping;
	UPROPERTY(EditAnywhere,Category="input")
	TObjectPtr<UInputAction>MoveAction;
};