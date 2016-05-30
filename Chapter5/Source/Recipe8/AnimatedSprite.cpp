// This include
#include "AnimatedSprite.h"

// Static Variables

// Static Function Prototypes

// Implementation

CAnimatedSprite::CAnimatedSprite()
: m_fFrameSpeed(0.0f)
, m_fTimeElapsed(0.0f)
, m_iCurrentSprite(0)
{

}

CAnimatedSprite::~CAnimatedSprite()
{
	Deinitialise();
}

bool
CAnimatedSprite::Deinitialise()
{
	return (CSprite::Deinitialise());
}

bool
CAnimatedSprite::Initialise(int _iSpriteResourceID, int _iMaskResourceID)
{
	return (CSprite::Initialise(_iSpriteResourceID, _iMaskResourceID));
}

void
CAnimatedSprite::Draw()
{
	int iTopLeftX = m_vectorFrames[m_iCurrentSprite];
	int iTopLeftY = 0;

	int iW = GetFrameWidth();
	int iH = GetHeight();

	int iX = m_iX - (iW / 2);
	int iY = m_iY - (iH / 2);

	HDC hSpriteDC = hSharedSpriteDC;

	HGDIOBJ hOldObj = SelectObject(hSpriteDC, m_hMask);

	BitBlt(CGame::GetInstance().GetBackBuffer()->GetBFDC(), iX, iY, iW, iH, hSpriteDC, iTopLeftX, iTopLeftY, SRCAND);

	SelectObject(hSpriteDC, m_hSprite);

	BitBlt(CGame::GetInstance().GetBackBuffer()->GetBFDC(), iX, iY, iW, iH, hSpriteDC, iTopLeftX, iTopLeftY, SRCPAINT);

	SelectObject(hSpriteDC, hOldObj);
}

void
CAnimatedSprite::Process(float _fDeltaTick)
{
	m_fTimeElapsed += _fDeltaTick;

	if (m_fTimeElapsed >= m_fFrameSpeed &&
		m_fFrameSpeed != 0.0f)
	{
		m_fTimeElapsed = 0.0f;
		++m_iCurrentSprite;

		if (m_iCurrentSprite >= m_vectorFrames.size())
		{
			m_iCurrentSprite = 0;
		}
	}

	CSprite::Process(_fDeltaTick);
}

void
CAnimatedSprite::AddFrame(int _iX)
{
	m_vectorFrames.push_back(_iX);
}

void
CAnimatedSprite::SetSpeed(float _fSpeed)
{
	m_fFrameSpeed = _fSpeed;
}

void
CAnimatedSprite::SetWidth(int _iW)
{
	m_iFrameWidth = _iW;
}

int
CAnimatedSprite::GetFrameWidth()
{
	return (m_iFrameWidth);
}
