// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeechToTxtManager.h"

RecognitionEventHandler RecognizingHandler;
RecognitionEventHandler RecognizedHandler;
RecognitionCancelHandler RecognizingCancelHandler;

// Sets default values
ASpeechToTxtManager::ASpeechToTxtManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASpeechToTxtManager::BeginPlay()
{
	Super::BeginPlay();	

	RecognizingHandler = [this](const MicrosoftSpeech::SpeechRecognitionEventArgs& e) {
		FString recognizingText = FString((e.Result->Text).c_str());
		RecognizingEvent.Broadcast(recognizingText);
	};

	RecognizedHandler = [this](const MicrosoftSpeech::SpeechRecognitionEventArgs& e) {
		FString recognizedText = FString((e.Result->Text).c_str());
		RecognizedEvent.Broadcast(recognizedText);
	};

	RecognizingCancelHandler = [](const MicrosoftSpeech::SpeechRecognitionCanceledEventArgs& e) {
		int cancelReason = (int)e.Reason;

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Cancel Reason: %d"), cancelReason));

		if (e.Reason == MicrosoftSpeech::CancellationReason::Error) {
			int errorCode = (int)e.ErrorCode;
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ErrorCode: %d"), errorCode));
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ErrorDetails: %s"), *FString(e.ErrorDetails.c_str())));
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Check key and region setup")));
		}
	};	
}

void ASpeechToTxtManager::StartRecognizing() {

	GEngine->AddOnScreenDebugMessage(-1, 6.0f, FColor::Blue, FString::Printf(TEXT("Start Recognizing")));

	speechRecognizer->StartContinuousRecognitionAsync().get();

	speechRecognizer->Recognizing += RecognizingHandler;
	speechRecognizer->Recognized += RecognizedHandler;
	speechRecognizer->Canceled += RecognizingCancelHandler;

}

void ASpeechToTxtManager::StopRecognizing() {

	FTimerHandle timerHandle;

	//Delay one second to make sure every word is captured after the button is released
	GetWorld()->GetTimerManager().SetTimer(timerHandle, [this]() {
		speechRecognizer->StopContinuousRecognitionAsync().get();

		speechRecognizer->Recognizing -= RecognizingHandler;
		speechRecognizer->Recognized -= RecognizedHandler;
		speechRecognizer->Canceled -= RecognizingCancelHandler;

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Stop Recognizing")));
	}, 1, false);
	
}

//return false if any of the config settings is missing
bool ASpeechToTxtManager::SpeechRecognizerSetup(FString key, FString region, FString language) {

	if (key.IsEmpty() || region.IsEmpty() || language.IsEmpty()) {
		UE_LOG(LogTemp, Error, TEXT("Check your config setting!"));
		return false;
	}

	SpeechConfigPtr speechConfig = MicrosoftSpeech::SpeechConfig::FromSubscription(TCHAR_TO_UTF8(*key), TCHAR_TO_UTF8(*region));
	speechConfig->SetSpeechRecognitionLanguage(TCHAR_TO_UTF8(*language));
	AudioConfigPtr audioConfig = MicrosoftAudio::AudioConfig::FromDefaultMicrophoneInput();
	speechRecognizer = MicrosoftSpeech::SpeechRecognizer::FromConfig(speechConfig, audioConfig);
	return true;

}

