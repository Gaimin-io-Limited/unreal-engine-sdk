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
	return Fetch("https://api.qa.gaimin.gg/api/public/v1/public-key", Options);
}

UFetchRequest* UFetchAPI::PlayerToken(FString BearerToken)
{
	FFetchOptions Options;
	Options.Headers.Add({ "Content-Type", "application/json" });
	Options.Headers.Add({ "Accept", "application/json" });
	Options.Headers.Add({ "Authorization", "Bearer " + BearerToken });

	return Fetch("https://api.qa.gaimin.gg/api/public/v1/player/token", Options);
}

UFetchRequest* UFetchAPI::PlayerBalance(FString PlayerToken)
{
	FFetchOptions Options;
	Options.Headers.Add({ "Content-Type", "application/json" });
	Options.Headers.Add({ "Accept", "application/json" });
	return Fetch("https://api.qa.gaimin.gg/api/public/v1/player/balance?playerToken=" + PlayerToken, Options);
}

UFetchRequest* UFetchAPI::PlayerTokens(FString ApiKey, FString PlayerToken)
{
	FFetchOptions Options;
	Options.Headers.Add({ "Content-Type", "application/json" });
	Options.Headers.Add({ "Accept", "application/json" });
	Options.Headers.Add({ "X-Api-Key", ApiKey });
	return Fetch("https://api.qa.gaimin.gg/api/public/v1/player/tokens?playerToken=" + PlayerToken + "&chains", Options);
}

UFetchRequest* UFetchAPI::PlayerTokensRaw(FString ApiKey, FString PlayerToken)
{
	FFetchOptions Options;
	Options.Headers.Add({ "Content-Type", "application/json" });
	Options.Headers.Add({ "Accept", "application/json" });
	Options.Headers.Add({ "X-Api-Key", ApiKey });
	return Fetch("https://api.qa.gaimin.gg/api/public/v1/player/tokens/raw?playerToken=" + PlayerToken + "&chains", Options);
}