#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Types.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "FetchResponse.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class FETCH_API UFetchResponse : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Gaimin");
	int32 StatusCode;

	UPROPERTY(BlueprintReadOnly, Category = "Gaimin");
	FString ResponseText;

	UPROPERTY(BlueprintReadOnly, Category = "Gaimin");
	TArray<FFetchHeader> Headers;

private:
	FHttpResponsePtr Original;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gaimin")
		FString GetHeader(FString Key);

	static UFetchResponse* Get(FHttpResponsePtr Response);
};
