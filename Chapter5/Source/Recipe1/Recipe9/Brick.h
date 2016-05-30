#pragma once

#if !defined(__BRICK_H__)
#define __BRICK_H__

// Library Includes

// Local Includes
#include "entity.h"

// Types

// Constants

// Prototypes

class CBrick : public CEntity
{
	// Member Functions
public:
	CBrick();
	virtual ~CBrick();

	virtual bool Initialise();

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	void SetHit(bool _b);
	bool IsHit() const;

protected:

private:
	CBrick(const CBrick& _kr);
	CBrick& operator= (const CBrick& _kr);

	// Member Variables
public:

protected:
	bool m_bHit;

private:

};

#endif    // __BRICK_H__
