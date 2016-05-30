#pragma once
#include <iostream>
#include "../lib/SDL2/include/SDL2/SDL.h"

#include "iaudiodevice.hpp"
#include "iaudiocontext.hpp"
#include "audioobject.hpp"

#include "sdl/sdlaudiodevice.hpp"
#include "sdl/sdlaudiocontext.hpp"

#define FILE_PATH "./res/audio/testClip.wav"

class GlobalAudioClass
{
private:

	AudioObject* _audObj;
	IAudioDevice* device = new SDLAudioDevice();
	IAudioContext* context = new SDLAudioContext();

	IAudioData* data = device->CreateAudioFromFile(FILE_PATH);

	SampleInfo info;


	static GlobalAudioClass *s_instance;

	GlobalAudioClass()
	{
		info.volume = 1.0;
		info.pitch = 0.7298149802137;
		_audObj = new AudioObject(info,data);
	}
	~GlobalAudioClass()
	{
		//Delete all the pointers here
	}
public:
	AudioObject* get_value()
	{
		return _audObj;
	}
	void set_value(AudioObject* obj)
	{
		_audObj = obj;
	}
	static GlobalAudioClass *instance()
	{
		if (!s_instance)
			s_instance = new GlobalAudioClass();
		return s_instance;
	}
};

// Allocating and initializing GlobalAudioClass's
// static data member.  The pointer is being
// allocated - not the object inself.
GlobalAudioClass *GlobalAudioClass::s_instance = 0;
