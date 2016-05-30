// Library Includes

// Local Includes
#include "resource.h"
#include "Utilities.h"

// This Include
#include "Paddle.h"

// Static Variables

// Static Function Prototypes

// Implementation

CPaddle::CPaddle()
{

}

CPaddle::~CPaddle()
{

}

bool
CPaddle::Initialise()
{
	VALIDATE(CEntity::Initialise(IDB_PADDLESPRITE, IDB_PADDLEMASK));

	return (true);
}

void
CPaddle::Draw()
{
	CEntity::Draw();
}

void
CPaddle::Process(float _fDeltaTick)
{
	CEntity::Process(_fDeltaTick);
}
