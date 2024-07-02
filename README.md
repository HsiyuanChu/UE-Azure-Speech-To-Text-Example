# UE-Azure-Speech-To-Text-Example

## Description
Developed with Unreal Engine 5.3, this project demonstrates integration with [Azure Speech to Text service](https://azure.microsoft.com/en-us/products/ai-services/speech-to-text) using the Vilas-Bôas Plugin (2024), utilizing microphone input.

## Instruction
Clone this repository. Open AzureSpeechToText.umap from the 'Level' folder, or create a new level and add the SpeechToTextManager Actor class to your scene. Once SpeechToTextManager is placed in the scene, you can call the following Blueprint functions:
  
- **SpeechRecognizerSetup**: Call this function before starting speech recognition to configure the recognizer with credentials obtained from the Azure service website.
- **StartRecognizing**: Initiates speech recognition from the microphone input.
- **StopRecognizing**: Stop the recognition process

In the AzureSpeechToText level, press '1' to start speech recognition and release to stop. The recognition status (blue) and the results of recognizing (white) or recognized text (red) will be displayed on screen. Subscribe to the RecognizingEvent or RecognizedEvent to access recognizing or recognized text. Refer to the Level Blueprint in AzureSpeechToText.umap to view my Blueprint setup.

## Screenshots
**Subscribe to RecognizingEvent/RecognizedEvent:**

![image](https://github.com/HsiyuanChu/UE-Azure-Speech-To-Text-Example/assets/137818387/8d632726-6cb8-47c3-81d3-c17f7dc920a2)

![image](https://github.com/HsiyuanChu/UE-Azure-Speech-To-Text-Example/assets/137818387/322fb014-6a18-429e-a986-fb19cbd6aee3)


<br>
<br>

**Recognition status (blue), recognizing text (white), and recognized text (red) print out**

![image](https://github.com/HsiyuanChu/UE-Azure-Speech-To-Text-Example/assets/137818387/d7d166af-cc78-4d40-910a-f96e72e740c3)



## Reference:

Vilas-Bôas, L. (2024). UEAzSpeech (Version 1.6.19) [Source code]. GitHub. https://github.com/lucoiso/UEAzSpeech
