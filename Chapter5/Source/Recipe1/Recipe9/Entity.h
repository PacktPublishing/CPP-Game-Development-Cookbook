#pragma once

#if !defined(__ENTITY_H__)
#define __ENTITY_H__

// Library Includes

// Local Includes

// Types

// Constants

// Prototypes
class CSprite;

class CEntity
{
	// Member Functions
public:
	CEntity();
	virtual ~CEntity();

	virtual bool Initialise(const int _kiSpriteID, const int _kiMaskID);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	void SetX(float _f);
	void SetY(float _f);

	float GetX() const;
	float GetY() const;

	float GetHeight() const;
	float GetWidth() const;

protected:

private:
	CEntity(const CEntity& _kr);
	CEntity& operator= (const CEntity& _kr);

	// Member Variables
public:

protected:
	CSprite* m_pSprite;

	float m_fX;
	float m_fY;

private:

};

#endif    // __ENTITY_H__
