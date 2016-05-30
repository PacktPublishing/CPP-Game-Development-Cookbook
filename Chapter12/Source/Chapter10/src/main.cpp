

#include <iostream>
#include "../AudioDataHandler.h"

#include "../lib/SDL2/include/SDL2/SDL.h"

#include "iaudiodevice.hpp"
#include "iaudiocontext.hpp"
#include "audioobject.hpp"

#include "sdl/sdlaudiodevice.hpp"
#include "sdl/sdlaudiocontext.hpp"

#define FILE_PATH "./res/audio/testClip.wav"

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_AUDIO);

	IAudioDevice* device = new SDLAudioDevice();
	IAudioContext* context = new SDLAudioContext();

	IAudioData* data = device->CreateAudioFromFile(FILE_PATH);

	SampleInfo info;
	info.volume = 1.0;
	info.pitch = 0.7298149802137;

	AudioObject sound(info, data);
	sound.SetPos(0.0);

	char in = 0;
	while(in != 'q')
	{
		std::cin >> in;
		switch(in)
		{
			case 'a':
				context->PlayAudio(sound);
				break;
			case 's':
				context->PauseAudio(sound);
				break;
			case 'd':
				context->StopAudio(sound);
				break;
		}
	}

	device->ReleaseAudio(data);
	delete context;
	delete device;

	SDL_Quit();
	return 0;
}

int main()
{
	AudioDataHandler _audioData;
	cout<<_audioData.GetAudio(AudioDataHandler::BACKGROUND);
}
