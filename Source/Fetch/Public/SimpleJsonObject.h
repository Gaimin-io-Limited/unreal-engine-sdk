#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Json.h"

#include "SimpleJsonObject.generated.h"

class USimpleJsonValue;
/**
 *
 */
UCLASS(BlueprintType)
class FETCH_API USimpleJsonObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	USimpleJsonObject* GetObject(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	USimpleJsonObject* GetObjectSync(FString Field)
	{
		return GetObject(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	float GetNumber(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	float GetNumberSync(FString Field)
	{
		return GetNumber(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	FString GetString(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	FString GetStringSync(FString Field)
	{
		return GetString(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	bool GetBool(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	bool GetBoolSync(FString Field)
	{
		return GetBool(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	TArray<USimpleJsonValue*> GetArray(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	TArray<USimpleJsonValue*> GetArraySync(FString Field)
	{
		return GetArray(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	bool IsNull(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	bool IsNullSync(FString Field)
	{
		return IsNull(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	bool IsNone(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	bool IsNoneSync(FString Field)
	{
		return IsNone(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	bool IsEmpty(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	bool IsEmptySync(FString Field)
	{
		return IsEmpty(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	bool HasKey(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	bool HasKeySync(FString Field)
	{
		return HasKey(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	USimpleJsonObject* SetNumber(FString Field, float Value);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	USimpleJsonObject* SetNumberSync(FString Field, float Value)
	{
		return SetNumber(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	USimpleJsonObject* SetString(FString Field, FString Value);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	USimpleJsonObject* SetStringSync(FString Field, FString Value)
	{
		return SetString(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	USimpleJsonObject* SetBool(FString Field, bool Value);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	USimpleJsonObject* SetBoolSync(FString Field, bool Value)
	{
		return SetBool(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	USimpleJsonObject* SetObject(FString Field, USimpleJsonObject* JsonObjet);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	USimpleJsonObject* SetObjectSync(FString Field, USimpleJsonObject* JsonObjet)
	{
		return SetObject(Field, JsonObjet);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	USimpleJsonObject* SetArray(FString Field, TArray<USimpleJsonValue*> Value);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	USimpleJsonObject* SetArraySync(FString Field, TArray<USimpleJsonValue*> Value)
	{
		return SetArray(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	FString Stringify(bool pretty = false);
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	FString StringifySync(bool pretty = false)
	{
		return Stringify(pretty);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	USimpleJsonValue* AsValue();
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	USimpleJsonValue* AsValueSync()
	{
		return AsValue();
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
	bool IsValidObject();
	UFUNCTION(BlueprintCallable, Category = "Gaimin")
	bool IsValidObjectSync()
	{
		return IsValidObject();
	}

	static USimpleJsonObject* Get(TSharedPtr<FJsonObject> Json);
	static USimpleJsonObject* GetInvalid();

public:
	TSharedPtr<FJsonObject> Original;
	bool invalidJson = false;
};
