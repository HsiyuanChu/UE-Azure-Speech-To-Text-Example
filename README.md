# UE-Azure-Speech-To-Text-Example

## Description
Developed with Unreal Engine 5.3, this project demonstrates integration with [Azure Speech to Text service](https://azure.microsoft.com/en-us/products/ai-services/speech-to-text), utilizing microphone input.

## Instruction
Clone this repository. Open AzureSpeechToText.umap from the 'Level' folder, or create a new level and add the SpeechToTextManager Actor class to your scene. Once SpeechToTextManager is placed in the scene, you can call the following Blueprint functions:
  
- **SpeechRecognizerSetup**: Call this function before starting speech recognition to configure the recognizer with credentials obtained from the Azure service website.
- **StartRecognizing**: Initiates speech recognition from the microphone input.
- **StopRecognizing**: Stop the recognition process

In the AzureSpeechToText level, press '1' to start speech recognition and release to stop. The recognition status (blue) and the results of recognizing (white) or recognized text (red) will be displayed on screen. Subscribe to the RecognizingEvent or RecognizedEvent to access recognizing or recognized text. Refer to the Level Blueprint in AzureSpeechToText.umap to view my Blueprint setup.

## Screenshots
**Subscribe to RecognizingEvent/RecognizedEvent:**

![image](https://github.com/HsiyuanChu/UE-Azure-Speech-To-Text-Example/assets/137818387/223f9feb-c216-4009-9617-c320d2831bb3)


![image](https://github.com/HsiyuanChu/UE-Azure-Speech-To-Text-Example/assets/137818387/8992216c-133c-4509-b924-c53795952c72)


<br>
<br>

**Recognition status (blue), recognizing text (white), and recognized text (red) print out**

![image](https://github.com/HsiyuanChu/UE-Azure-Speech-To-Text-Example/assets/137818387/d5d0018e-db31-4f46-9011-a5315c454cfe)




