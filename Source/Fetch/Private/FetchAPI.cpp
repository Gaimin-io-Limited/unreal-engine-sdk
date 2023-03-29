// Copyright 2023, Gaimin.io Limited, All Rights Reserved

#include "FetchAPI.h"
#include "FetchRequest.h"
#include "Misc/Base64.h"

UFetchAPI::UFetchAPI()
{

}

UFetchRequest* UFetchAPI::Fetch(FString Url, FFetchOptions Options)
{
    UFetchRequest* Request = NewObject<UFetchRequest>();
    Request->Process(Url, Options);

    return Request;
}

UFetchRequest* UFetchAPI::PublicKey()
{
    FFetchOptions Options;
    Options.Headers.Add({ "Content-Type", "application/json" });
    Options.Headers.Add({ "Accept", "application/json" });
    return Fetch("https://api.gaimin.gg/api/public/v1/public-key", Options);
}

UFetchRequest* UFetchAPI::PlayerToken(FString BearerToken)
{
    FFetchOptions Options;
    Options.Headers.Add({ "Content-Type", "application/json" });
    Options.Headers.Add({ "Accept", "application/json" });
    Options.Headers.Add({ "Authorization", "Bearer " + BearerToken });

    return Fetch("https://api.gaimin.gg/api/public/v1/player/token", Options);
}

UFetchRequest* UFetchAPI::PlayerDetails(FString PlayerToken)
{
    FFetchOptions Options;
    Options.Headers.Add({ "Content-Type", "application/json" });
    Options.Headers.Add({ "Accept", "application/json" });
    return Fetch("https://api.gaimin.gg/api/public/v1/player/details?playerToken=" + PlayerToken, Options);
}

UFetchRequest* UFetchAPI::PlayerTokens(FString ProductId, FString PlayerToken, FString Chains)
{
    FFetchOptions Options;
    Options.Headers.Add({ "Content-Type", "application/json" });
    Options.Headers.Add({ "Accept", "application/json" });
    return Fetch("https://api.gaimin.gg/api/public/v1/player/tokens?productId=" + ProductId + "&playerToken=" + PlayerToken + "&chainDtos=" + Chains, Options);
}

UFetchRequest* UFetchAPI::PlayerTokensRaw(FString ProductId, FString PlayerToken, FString Chains)
{
    FFetchOptions Options;
    Options.Headers.Add({ "Content-Type", "application/json" });
    Options.Headers.Add({ "Accept", "application/json" });
    return Fetch("https://api.gaimin.gg/api/public/v1/player/tokens/raw?productId=" + ProductId + "&playerToken=" + PlayerToken + "&chainDtos=" + Chains, Options);
}