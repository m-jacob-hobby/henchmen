#pragma once

//#include "Components/Image.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "MainMenuWidget.generated.h"

class UWebBrowser;
class UButton;
class UTextBlock;
class UImage;
/**
 *
 */
UCLASS()
class HENCHMEN_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UMainMenuWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
		FTimerHandle SetAveragePlayerLatencyHandle;

	UPROPERTY()
		FTimerHandle PollMatchmakingHandle;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	FHttpModule* HttpModule;

	UPROPERTY()
		FString LoginUrl;

	UPROPERTY()
		FString ApiUrl;

	UPROPERTY()
		FString CallbackUrl;

	UPROPERTY()
		FString RegionCode;

	UPROPERTY()
		UWebBrowser* WebBrowser;

	UPROPERTY()
		UButton* MatchmakingButton;

	UPROPERTY()
		UButton* HowToPlayButton;

	UPROPERTY()
		UButton* QuitButton;

	UPROPERTY()
		UTextBlock* WinsTextBlock;

	UPROPERTY()
		UTextBlock* LossesTextBlock;

	UPROPERTY()
		UTextBlock* PingTextBlock;

	UPROPERTY()
		UTextBlock* MatchmakingEventTextBlock;

	UPROPERTY()
		UImage* LogoImage;

	UPROPERTY()
		float AveragePlayerLatency;

	UPROPERTY()
		bool SearchingForGame;

	UFUNCTION()
		void HandleLoginUrlChange();

	UFUNCTION()
		void SetAveragePlayerLatency();

	UFUNCTION()
		void OnMatchmakingButtonClicked();

	UFUNCTION()
		void PollMatchmaking();

	void OnExchangeCodeForTokensResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnGetPlayerDataResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnStartMatchmakingResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnStopMatchmakingResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnPollMatchmakingResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};