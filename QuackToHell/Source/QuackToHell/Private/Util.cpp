// Fill out your copyright notice in the Description page of Project Settings.


#include "Util.h"

void UUtil::ReadTextFile(FString& FilePath, FString& SaveInto)
{
    FString FileContent;
    if (FFileHelper::LoadFileToString(FileContent, *FilePath))
    {
        // 파일 읽기 성공
        UE_LOG(LogTemp, Log, TEXT("File content: %s"), *FileContent);
        SaveInto = FileContent;
    }
    else
    {
        // 파일 읽기 실패
        UE_LOG(LogTemp, Error, TEXT("Failed to read the file at: %s"), *FilePath);
    }
}
