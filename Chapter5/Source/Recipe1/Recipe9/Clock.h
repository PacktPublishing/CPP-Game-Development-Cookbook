#pragma once

#if !defined(__CLOCK_H__)
#define __CLOCK_H__

// Library Includes

// Local Includes

// Types

// Constants

// Prototypes
class CClock
{
	// Member Functions
public:
	CClock();
	~CClock();

	bool Initialise();

	void Process();

	float GetDeltaTick();

protected:

private:
	CClock(const CClock& _kr);
	CClock& operator= (const CClock& _kr);

	// Member Variables
public:

protected:
	float m_fTimeElapsed;
	float m_fDeltaTime;
	float m_fLastTime;
	float m_fCurrentTime;

private:

};

#endif    // __CLOCK_H__
