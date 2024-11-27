// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Util.generated.h"

/**
 * 클래스를 따로 만들어서 정의해두기에는 수가 적거나 애매하고, 재사용 할 것 같기는 한 함수들을 모아놓습니다.
 */
UCLASS()
class QUACKTOHELL_API UUtil : public UObject
{
	GENERATED_BODY()
public:
	void ReadTextFile(FString& FilePath, FString& SaveInto);
private:

};
