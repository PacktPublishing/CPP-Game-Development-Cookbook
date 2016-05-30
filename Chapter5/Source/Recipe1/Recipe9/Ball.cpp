// Library Includes

// Local Includes
#include "resource.h"
#include "Utilities.h"

// This Includes
#include "Ball.h"

// Static Variables

// Static Function Prototypes

// Implementation

CBall::CBall()
: m_fVelocityX(0.0f)
, m_fVelocityY(0.0f)
{

}

CBall::~CBall()
{

}

bool
CBall::Initialise(float _fPosX, float _fPosY, float _fVelocityX, float _fVelocityY)
{
	VALIDATE(CEntity::Initialise(IDB_BALLSPRITE, IDB_BALLMASK));

	m_fX = _fPosX;
	m_fY = _fPosY;

	m_fVelocityX = _fVelocityX;
	m_fVelocityY = _fVelocityY;

	return (true);
}

void
CBall::Draw()
{
	CEntity::Draw();
}

void
CBall::Process(float _fDeltaTick)
{
	m_fX += m_fVelocityX * _fDeltaTick;
	m_fY += m_fVelocityY * _fDeltaTick;

	CEntity::Process(_fDeltaTick);
}

float
CBall::GetVelocityX() const
{
	return (m_fVelocityX);
}

float
CBall::GetVelocityY() const
{
	return (m_fVelocityY);
}

void
CBall::SetVelocityX(float _fX)
{
	m_fVelocityX = _fX;
}

void
CBall::SetVelocityY(float _fY)
{
	m_fVelocityY = _fY;
}

float
CBall::GetRadius() const
{
	return (GetWidth() / 2.0f);
}
