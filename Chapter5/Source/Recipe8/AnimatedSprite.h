#pragma once

#ifndef __ANIMATEDSPRITE_H__
#define __ANIMATEDSPRITE_H__

// Library Includes
#include <vector>
#include "windows.h"

// Local Includes
#include "sprite.h"

// Types

// Constants

// Prototypes
class CAnimatedSprite : public CSprite
{
	// Member Variables
public:

protected:
	std::vector<int> m_vectorFrames;

	int m_iCurrentSprite;

	int m_iFrameWidth;

	float m_fFrameSpeed;
	float m_fTimeElapsed;

private:

	// Member Functions
public:
	CAnimatedSprite();
	~CAnimatedSprite();

	bool Deinitialise();
	bool Initialise(int _iResourceID, int _iMaskResourceID);

	void Draw();
	void Process(float _fDeltaTick);

	void AddFrame(int _iX);
	void SetSpeed(float _fSpeed);

	void SetWidth(int _iW);
	int GetFrameWidth();

protected:

private:

};

#endif    // __ANIMATEDSPRITE_H__
