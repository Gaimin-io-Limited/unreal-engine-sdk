// Copyright 2023, Gaimin.io Limited, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IFetch.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "FetchRequest.generated.h"

UCLASS(BlueprintType)
class FETCH_API UFetchRequest : public UObject
{
    GENERATED_BODY()

public:
    UFetchRequest();
    void Process(FString URL, FFetchOptions Options);

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
        UFetchRequest* OnError(FFetchErrorDelegate Event);

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
        UFetchRequest* OnSuccess(FFetchSuccessDelegate Event);

private:
    UFetchResponse* FetchResponse;
    FString ResponseText;

    FFetchErrorDelegate OnErrorDelegate;
    FFetchSuccessDelegate OnSuccessDelegate;

    void OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);
    FString HttpMethodToString(FFetchOptionsMethod Method);
};

