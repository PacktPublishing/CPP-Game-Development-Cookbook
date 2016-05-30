#pragma once

#if !defined(__SPRITE_H__)
#define __SPRITE_H__

// Library Includes
#include "windows.h"

// Local Includes

// Types

// Constants

// Prototypes
class CSprite
{
	// Member Functions
public:
	CSprite();
	~CSprite();

	bool Initialise(int _iResourceID, int _iMaskResourceID);

	void Draw();
	void Process(float _fDeltaTick);

	int GetWidth() const;
	int GetHeight() const;

	int GetX() const;
	int GetY() const;
	void SetX(int _i);
	void SetY(int _i);

	void TranslateRelative(int _iX, int _iY);
	void TranslateAbsolute(int _iX, int _iY);

protected:

private:
	CSprite(const CSprite& _kr);
	CSprite& operator= (const CSprite& _kr);

	// Member Variables
public:

protected:
	//Center handle
	int m_iX;
	int m_iY;

	HBITMAP m_hSprite;
	HBITMAP m_hMask;

	BITMAP m_bitmapSprite;
	BITMAP m_bitmapMask;

	static HDC s_hSharedSpriteDC;
	static int s_iRefCount;

private:

};

#endif    // __SPRITE_H__
