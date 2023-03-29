// Copyright 2023, Gaimin.io Limited, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleJsonObject.h"
#include "Json.h"
#include "SimpleJsonValue.generated.h"

UCLASS(BlueprintType)
class FETCH_API USimpleJsonValue : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    float AsNumber();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    float AsNumberSync()
    {
        return AsNumber();
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    FString AsString();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    FString AsStringSync()
    {
        return AsString();
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    bool AsBool();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    bool AsBoolSync()
    {
        return AsBool();
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    USimpleJsonObject* AsObject();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    USimpleJsonObject* AsObjectSync()
    {
        return AsObject();
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    TArray<USimpleJsonValue*> AsArray();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
        TArray<USimpleJsonValue*> AsArraySync()
    {
        return AsArray();
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    bool IsNull();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    bool IsNullSync()
    {
        return IsNull();
    }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
    bool IsValid();

    UFUNCTION(BlueprintCallable, Category = "Gaimin")
    bool IsValidSync()
    {
        return IsValid();
    }

    static USimpleJsonValue* Get(TSharedPtr<FJsonValue> JsonValue);

public:
    TSharedPtr<FJsonValue> Original;
    bool InvalidJson = false;
};
