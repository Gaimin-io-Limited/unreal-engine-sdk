// Copyright 2023, Gaimin.io Limited, All Rights Reserved

#pragma once

#include "CoreMinimal.h"

#include "FetchRequest.h"
#include "Components/SceneComponent.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "IFetch.h"
#include "FetchAPI.generated.h"

UCLASS()
class FETCH_API UFetchAPI : public UObject
{
	GENERATED_BODY()

public:
	UFetchAPI();

public:

	UFUNCTION(BlueprintCallable, Category = "Gaimin")
		static UFetchRequest* PublicKey();

	UFUNCTION(BlueprintCallable, Category = "Gaimin")
		static UFetchRequest* PlayerToken(FString BearerToken);

	UFUNCTION(BlueprintCallable, Category = "Gaimin")
		static UFetchRequest* PlayerBalance(FString PlayerToken);

	UFUNCTION(BlueprintCallable, Category = "Gaimin")
		static UFetchRequest* PlayerTokens(FString ApiKey, FString PlayerToken);

	UFUNCTION(BlueprintCallable, Category = "Gaimin")
		static UFetchRequest* PlayerTokensRaw(FString ApiKey, FString PlayerToken);

private:

		static UFetchRequest* Fetch(FString Url, FFetchOptions Options);

};
