// Fill out your copyright notice in the Description page of Project Settings.


#include "DefendantStoryService.h"
#include "FuncLib/JsonFuncLib.h"
#include "FuncLib/OpenAIFuncLib.h"
#include "Engine/Engine.h"
#include "ChatGPT/ChatGPT.h"

#include "Logging/StructuredLog.h"

//초기화 함수
bool UDefendantStoryService::Init(const OpenAI::ServiceSecrets& Secrets)
{
	UE_LOG(LogTemp, Display, TEXT("UDefendantStoryService Init"));
	
	//인증 절차
	const auto Auth = UOpenAIFuncLib::LoadAPITokensFromFile(FPaths::ProjectDir().Append("OpenAIAuth.ini"));
	ChatGPT = NewObject<UChatGPT>();
	//객체생성에 문제가 있으면 강종
	check(ChatGPT);
	ChatGPT->SetAuth(Auth);
	ChatGPT->SetModel(TEXT("gpt-4"));
	ChatGPT->SetMaxTokens(MaxTokens);

	//요청이 성공적으로 처리되었을 때 어떤 함수를 불러올 것인지. (콜백등록). ChatGPT객체의 해당 함수를 부를 때 다음 함수도 같이 부르라는 뜻이다.
	ChatGPT->OnRequestCompleted().AddUObject(this, &ThisClass::OnRequestCompleted);
	//요청이 업데이트(처리) 중일 때 어떤 함수를 불러올 것인지. (콜백등록)
	ChatGPT->OnRequestUpdated().AddUObject(this, &ThisClass::OnRequestUpdated);

	return true;
}

//gpt에게 요청을 보낸다.
void UDefendantStoryService::OnSendMessage(const FString& Input) {
		
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, TEXT("Processing your input..."));
	}

	// OpenAI에 보낼 메시지 생성
	FMessage Message;
	Message.Role = UOpenAIFuncLib::OpenAIRoleToString(ERole::User); //role이 user면 요청을 보낸다는 뜻임.
	Message.Content = Input;
	ChatGPT->AddMessage(Message);

	// OpenAI 요청 실행
	ChatGPT->MakeRequest();

	UE_LOG(LogTemp, Display, TEXT("Message sent to OpenAI: %s"), *Input);
}




void UDefendantStoryService::OnRequestCompleted()
{
	UE_LOG(LogTemp, Display, TEXT("요청이 성공적으로 완료되었습니다."));
}


void UDefendantStoryService::OnRequestUpdated(const FMessage& Message, bool WasError)
{
	UE_LOG(LogTemp, Display, TEXT("요청을 처리중입니다."));
}

//해당 서비스에 대한 간략 설명
FString UDefendantStoryService::Description() const
{
	return "generation about ramdom story of defendant.";
}

//function의 이름
FString UDefendantStoryService::FunctionName() const
{
	return "GenerateDefendantStory";
}

//call함수: OpenAI요청 처리
void UDefendantStoryService::Call(const TSharedPtr<FJsonObject>& Args, const FString& InToolID)
{
	Super::Call(Args, InToolID);

	//Args 유효성 검사 : Json schema가 유효한 형태인가? 
	if (!Args.IsValid()) {
		UE_LOG(LogTemp, Display, TEXT("유효하지 않은 Json Schema"));
		ServiceDataError.Broadcast("Error: Invalid JSON arguments");
		return;
	}

	//필드 추출
	FString DefendantName;
	//인자 설명:	bool TryGetStringField(FAnsiStringView FieldName, FString& OutString) const<- Json객체에서 특정 필드값을 읽어오는 데 사용되는 함수이다. 이 함수는 지정된 필드 이름으로 값을 검색하고, 해당 값이 문자열인 경우 두 번째 인자로 값을 반환한다. 
	//name필드가 없거나 문자열이 아닌 경우이다.  
	if (!Args->TryGetStringField("name", DefendantName))
	{
		UE_LOG(LogTemp, Display, TEXT("Required field 'name' is missing. "));
		ServiceDataError.Broadcast("Error: 'name' field is required.");
		return;
	}

	//스토리 프롬프트 생성: Prompt변수에 Printf 문자열이 대입된다. (Printf는 출력만을 위한 함수가 아니다. 문자열을 생성하고 반환하는 기능도 된다. ) 
	FString Prompt = FString::Printf(TEXT(
		"Create a story about %s, who is neither fully virtuous nor completely sinful."
		"The story should emphasized moral ambiguity."), *DefendantName);
	
	//OpenAI에게 프롬프트를 전달함&응답 받아옴. 
	ServiceDataRecieved.Broadcast(MakeMessage(Prompt));
}

//서비스 이름 반환
FString UDefendantStoryService::Name() const
{
	return "DefendantStory";
}

//ToolTip 설명 반환
FString UDefendantStoryService::TooltipDescription() const
{
	return "generation about morally obscure ramdom story of defendant";
}

//Function 만들기: Json 스키마 생성
FString UDefendantStoryService::MakeFunction() const
{
	//해당 스키마를 C++코드로 옮길 것이다. (Json: Key-Value 쌍)
	/*{
		"type": "object",
		"properties" : {
			"name": {
				"type": "string",
				"description": "Name of the defendant."
			}
		},
		"required": ["name"]
	}*/


	//Json 객체 생성
	TSharedPtr<FJsonObject> MainObj = MakeShareable(new FJsonObject());
	//인자 설명: void SetStringField(const FString& FieldName, const FString& StringValue);<- 첫번째 인자: Json필드의 이름정의. 두 번째 인자: Json필드에 저장될 값
	MainObj->SetStringField("type", "object");

	//properties 객체 생성
	TSharedPtr<FJsonObject> Props = MakeShareable(new FJsonObject());

	//"name" 필드 정의
	TSharedPtr<FJsonObject> NameObj = MakeShareable(new FJsonObject());
	//해당 필드 내의 하위항목들 지정
	NameObj->SetStringField("type", "string");
	//* description은 openai에서 공식 지원하는 필드는 아니고, 사용자가 직접 지정한 필드이다. 그러나 openai는 이를 유연하게 이해하고 사용할 수 있다. 
	NameObj->SetStringField("description", "Name of the defendant.");
	//인자 설명: void SetObjectField(const FString& FieldName, const TSharedPtr<FJsonObject>& JsonObject); <- 첫 번째 인자: 필드 이름, 두 번째 인자: 필드에 들어갈 값을 정의한 Json객체
	Props->SetObjectField("name", NameObj);

	//properties를 mainobj에 추가
	MainObj->SetObjectField("properties", Props);

	//필수 필드 정의
	//JSON배열을 표현하기 위해 UnrealEngine에서 이용하는 TArray객체
	//이 배열은 필수필드이름을 담는다. 
	TArray<TSharedPtr<FJsonValue>> RequiredArray;
	//이름은 필수인자여야만 한다. 따라서 배열에 add
	RequiredArray.Add(MakeShareable(new FJsonValueString("name")));
	//인자 설명: void FJsonObject::SetArrayField(FString&& FieldName, const TArray<TSharedPtr<FJsonValue>>& Array)<- 첫 번째 인자: 필드이름, 두 번째 인자: 어레이(필드의 값인데, 어레이형식). 
	//required는, openai의 표준 필드이다. 필수 인자를 정의하는 데 사용된다. 
	MainObj->SetArrayField("required", RequiredArray);

	//Json 스키마를 문자열로 반환
	return UJsonFuncLib::MakeFunctionsString(MainObj);
}
