// Copyright 2023, Gaimin.io Limited, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SimpleJsonValue.h"
#include "UObject/NoExportTypes.h"
#include "SimpleJson.generated.h"

UCLASS()
class FETCH_API USimpleJson : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    static USimpleJsonValue* MakeJson(FString InputJson);

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonSync(FString InputJson)
    {
        return MakeJson(InputJson);
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonNumber(float Number);

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonNumberSync(float Number)
    {
        return MakeJsonNumber(Number);
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonBool(bool Value);

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonBoolSync(bool Value)
    {
        return MakeJsonBool(Value);
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonString(FString Value);

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonStringSync(FString Value)
    {
        return MakeJsonString(Value);
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonNull();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    static USimpleJsonValue* MakeJsonNullSync()
    {
        return MakeJsonNull();
    }
};
