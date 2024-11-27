// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"
#include "ChatGPT/BaseService.h"
#include "ChatGPT/ChatGPT.h"
#include "FuncLib/OpenAIFuncLib.h"
#include "DefendantStoryService.generated.h"

/**
 * 
 */
UCLASS()
class QUACKTOHELL_API UDefendantStoryService : public UBaseService
{
    //GENERATED_BODY() 매크로가 클래스의 기본 생성자와 필수 메타데이터를 자동으로 생성
	GENERATED_BODY()
public:
    virtual bool Init(const OpenAI::ServiceSecrets& Secrets);

    void OnSendMessage(const FString& Input);


    void OnRequestCompleted();

    void OnRequestUpdated(const FMessage& Message, bool WasError);

    virtual FString Description() const;
    virtual FString FunctionName() const;
    virtual void Call(const TSharedPtr<FJsonObject>& Args, const FString& InToolID);

    virtual FString Name() const;
    virtual FString TooltipDescription() const;

protected:
    virtual FString MakeFunction() const;
    UPROPERTY()
    TObjectPtr<UChatGPT> ChatGPT;
    int32 MaxTokens = 2000 ;
};
