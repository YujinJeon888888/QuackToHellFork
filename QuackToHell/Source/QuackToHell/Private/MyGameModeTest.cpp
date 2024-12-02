// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeTest.h"
#include "Sample/APIOverview.h"
#include <Kismet/GameplayStatics.h>



void AMyGameModeTest::CallChat(FString& SendTo, FString& SendMessage)
{
    /*
    1. 해당 인게임에서 내가 원하는 액터를 찾는다.
    2. 그 액터의 createChatCompletion메소드를 호출한다.
        query는 인자로 넣는다.
    */

    TArray<AActor*> TaggedActors;

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(*SendTo), TaggedActors);
    for (AActor* Actor : TaggedActors)
    {
        AAPIOverview* APIActor = Cast<AAPIOverview>(Actor);
        if (APIActor)
        {
            // 해당 클래스의 메소드 호출
            APIActor->CreateChatCompletionRequest(SendMessage);
            UE_LOG(LogTemp, Log, TEXT("Called CreateChatCompletionRequest on Actor: %s"), *Actor->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Actor with tag '%s' is not of type AAPIOverview"), *SendTo);
        }
    }
}