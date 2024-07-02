// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AzSpeech/Runnables/Recognition/Bases/AzSpeechRecognitionRunnableBase.h"
#include "SpeechToTxtManager.generated.h"

namespace MicrosoftSpeech = Microsoft::CognitiveServices::Speech;
namespace MicrosoftAudio = MicrosoftSpeech::Audio;

using RecognitionEventHandler = std::function<void(const MicrosoftSpeech::SpeechRecognitionEventArgs&)>;
using RecognitionCancelHandler = std::function<void(const MicrosoftSpeech::SpeechRecognitionCanceledEventArgs&)>;

using SpeechRecognizerPtr = std::shared_ptr<MicrosoftSpeech::SpeechRecognizer>;
using SpeechConfigPtr = std::shared_ptr<MicrosoftSpeech::SpeechConfig>;
using AudioConfigPtr = std::shared_ptr<MicrosoftAudio::AudioConfig>;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecognizingText, FString, recognizingText);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecognizedText, FString, recognizedText);


UCLASS()
class AZURESPEECHTOTXT_API ASpeechToTxtManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeechToTxtManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	SpeechRecognizerPtr speechRecognizer;

public:
	UFUNCTION(BlueprintCallable, Category = "AzureSpeechToText")
	bool SpeechRecognizerSetup(FString key, FString region, FString language);

	UFUNCTION(BlueprintCallable, Category = "AzureSpeechToText")
	void StartRecognizing();

	UFUNCTION(BlueprintCallable, Category = "AzureSpeechToText")
	void StopRecognizing();

	UPROPERTY(BlueprintAssignable, Category = "AzureSpeechToText")
	FRecognizingText RecognizingEvent;

	UPROPERTY(BlueprintAssignable, Category = "AzureSpeechToText")
	FRecognizedText RecognizedEvent;

};
