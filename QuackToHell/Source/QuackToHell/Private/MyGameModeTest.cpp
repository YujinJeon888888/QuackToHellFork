// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeTest.h"
#include "Sample/APIOverview.h"
#include <Kismet/GameplayStatics.h>



void AMyGameModeTest::CallChat(FString& SendTo, FString& SendMessage)
{
    /*
    1. �ش� �ΰ��ӿ��� ���� ���ϴ� ���͸� ã�´�.
    2. �� ������ createChatCompletion�޼ҵ带 ȣ���Ѵ�.
        query�� ���ڷ� �ִ´�.
    */

    TArray<AActor*> TaggedActors;

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(*SendTo), TaggedActors);
    for (AActor* Actor : TaggedActors)
    {
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            // �ش� Ŭ������ �޼ҵ� ȣ��
            APIActor->CreateChatCompletionRequest(SendMessage);
            UE_LOG(LogTemp, Log, TEXT("Called CreateChatCompletionRequest on Actor: %s"), *Actor->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Actor with tag '%s' is not of type AAPIOverview"), *SendTo);
        }
    }
}