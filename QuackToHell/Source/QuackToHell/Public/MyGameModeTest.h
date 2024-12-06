// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameModeTest.generated.h"

/**
 * 
 */
UCLASS()
class QUACKTOHELL_API AMyGameModeTest : public AGameMode
{
	GENERATED_BODY()
public:
	UFUNCTION(Exec, Category = "Command")
	void CallChat(FString& SendTo, FString& SendMessage);
};
