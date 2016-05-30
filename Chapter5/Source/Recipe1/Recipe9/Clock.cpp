
// Library Includes
#include <windows.h>

// Local Includes
#include "Clock.h"

// Static Variables

// Static Function Prototypes

// Implementation

CClock::CClock()
: m_fTimeElapsed(0.0f)
, m_fDeltaTime(0.0f)
, m_fLastTime(0.0f)
, m_fCurrentTime(0.0f)
{

}

CClock::~CClock()
{

}

bool
CClock::Initialise()
{
	return (true);
}

void
CClock::Process()
{
	m_fLastTime = m_fCurrentTime;

	m_fCurrentTime = static_cast<float>(timeGetTime());

	if (m_fLastTime == 0.0f)
	{
		m_fLastTime = m_fCurrentTime;
	}

	m_fDeltaTime = m_fCurrentTime - m_fLastTime;

	m_fTimeElapsed += m_fDeltaTime;
}

float
CClock::GetDeltaTick()
{
	return (m_fDeltaTime / 1000.0f);
}
