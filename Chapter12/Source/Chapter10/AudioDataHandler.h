#pragma once

#include <string>
using namespace std;

class AudioDataHandler
{
public:
	AudioDataHandler();
	~AudioDataHandler();
	string GetAudio(int data) // Set one of the enum values here from the driver program
	{
		return Files[data];
	}

	enum AUDIO
	{
		NONE=0,
		BACKGROUND,
		BATTLE,
		UI
	};
private:
	string Files[] =
	{
		"",
		"Hello.wav",
		"Battlenn.wav",
		"Click.wav"
	}
		
	
};

