// Copyright 2023, Gaimin.io Limited, All Rights Reserved

#include "FetchRequest.h"

UFetchRequest::UFetchRequest()
{

}

void UFetchRequest::Process(FString Url, FFetchOptions Options)
{
    FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(Url);
    Request->SetVerb(HttpMethodToString(Options.Method));

    for (int lc = 0; lc < Options.Headers.Num(); lc++) {
        FFetchHeader Header = Options.Headers[lc];
        Request->SetHeader(Header.Key, Header.Value);
    }

    Request->OnProcessRequestComplete().BindUObject(this, &UFetchRequest::OnResponse);
    Request->ProcessRequest();
}

void UFetchRequest::OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    if (!bSuccess) {
        FString msg = Response.IsValid()
                ? "Request Failed with an error: " + Response->GetContentAsString()
                : "Request failed without making a request";

        OnErrorDelegate.ExecuteIfBound(msg);
        return;
    }

    FetchResponse = UFetchResponse::Get(Response);

    TSharedPtr<FJsonValue> ParsedJSON;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FetchResponse->ResponseText);

    if (OnSuccessDelegate.IsBound()) {
        if (FJsonSerializer::Deserialize(Reader, ParsedJSON)) {
            OnSuccessDelegate.ExecuteIfBound(USimpleJsonValue::Get(ParsedJSON), FetchResponse);
        } else {
            OnErrorDelegate.ExecuteIfBound("Invalid JSON as the response");
        }
    }
}

FString UFetchRequest::HttpMethodToString(FFetchOptionsMethod Method)
{
    switch (Method) {
        case GET:    return "GET";
        case POST:   return "POST";
        case PUT:    return "PUT";
        case DELETE: return "DELETE";
        default:     return "";
    }
}

UFetchRequest* UFetchRequest::OnError(FFetchErrorDelegate Event)
{
    OnErrorDelegate = Event;
    return this;
}

UFetchRequest* UFetchRequest::OnSuccess(FFetchSuccessDelegate Event)
{
    OnSuccessDelegate = Event;
    return this;
}
