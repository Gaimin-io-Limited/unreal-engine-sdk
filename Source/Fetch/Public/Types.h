#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Json.h"
#include "SimpleJsonObject.h"
#include "SimpleJsonValue.h"
#include "Types.generated.h"

UENUM(BlueprintType)
enum FFetchOptionsMethod
{
	GET,
	POST,
	PUT,
	DELETE
};

USTRUCT(BlueprintType)
struct FETCH_API FFetchHeader
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaimin")
		FString Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaimin")
		FString Value;
};

USTRUCT(BlueprintType)
struct FETCH_API FFetchOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaimin")
		TEnumAsByte<FFetchOptionsMethod> Method = FFetchOptionsMethod::GET;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaimin")
		FString Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaimin")
		TArray<FFetchHeader> Headers;
};

UCLASS()
class FETCH_API UTypes : public UObject
{
	GENERATED_BODY()
};
