// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefendantStoryService.h"//스토리 자동화를 위한 클래스를 불러온다.
#include "AutoStoryGenerator.generated.h"

UCLASS()
class QUACKTOHELL_API AAutoStoryGenerator : public AActor
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//DefendantStoryService에 대한 참조
	UPROPERTY()
	TObjectPtr<UDefendantStoryService> StoryService;
	// Sets default values for this actor's properties
	AAutoStoryGenerator();

	// 텍스트 파일에서 문자열을 읽어오는 함수
	void ReadInputFromFile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
