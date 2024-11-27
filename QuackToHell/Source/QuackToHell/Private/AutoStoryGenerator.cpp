// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoStoryGenerator.h"
#include "Misc/FileHelper.h" // 텍스트 파일 읽기용
#include "Misc/Paths.h" // 파일 경로 관련

// Sets default values
AAutoStoryGenerator::AAutoStoryGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//StoryService 초기화
	// DefendantStoryService 객체 생성 및 초기화
	StoryService = NewObject<UDefendantStoryService>();
	if (StoryService)
	{
		StoryService->Init(OpenAI::ServiceSecrets()); // 필요한 Secret 정보 전달
		UE_LOG(LogTemp, Display, TEXT("Defendant Story Service initialized."));
	}

}



// Called when the game starts or when spawned
void AAutoStoryGenerator::BeginPlay()
{
	Super::BeginPlay();
	// StoryService 초기화
	if (!StoryService)
	{
		StoryService = NewObject<UDefendantStoryService>(this); // Outer를 명시적으로 설정
		if (StoryService)
		{
			if (StoryService->Init(OpenAI::ServiceSecrets()))
			{
				UE_LOG(LogTemp, Display, TEXT("Defendant Story Service initialized in BeginPlay."));
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Defendant Story Service Init failed."));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create Defendant Story Service in BeginPlay."));
		}
	}

	// 텍스트 파일에서 입력 읽기
	ReadInputFromFile();

}


void AAutoStoryGenerator::ReadInputFromFile()
{
	FString FilePath = FPaths::ProjectContentDir() + TEXT("InputText.txt");
	FString FileContent;

	if (FFileHelper::LoadFileToString(FileContent, *FilePath))
	{
		UE_LOG(LogTemp, Display, TEXT("File Content: %s"), *FileContent);

		if (StoryService)
		{
			StoryService->OnSendMessage(FileContent);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("StoryService is nullptr."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load file from path: %s"), *FilePath);
	}

}


// Called every frame
void AAutoStoryGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

