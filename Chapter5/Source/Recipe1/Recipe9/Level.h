
#pragma once

#if !defined(__LEVEL_H__)
#define __LEVEL_H__

// Library Includes
#include <vector>
#include <string>

// Local Includes

// Types

// Constants

// Prototypes
class CBall;
class CPaddle;
class CBrick;

class CLevel
{
	// Member Functions
public:
	CLevel();
	virtual ~CLevel();

	virtual bool Initialise(int _iWidth, int _iHeight);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	CPaddle* GetPaddle() const;

	int GetBricksRemaining() const;

protected:
	void ProcessBallWallCollision();
	void ProcessBallPaddleCollision();
	void ProcessBallBrickCollision();

	void ProcessCheckForWin();

	void ProcessBallBounds();

	void UpdateScoreText();
	void DrawScore();

	void SetBricksRemaining(int _i);

private:
	CLevel(const CLevel& _kr);
	CLevel& operator= (const CLevel& _kr);

	// Member Variables
public:

protected:
	CBall* m_pBall;
	CPaddle* m_pPaddle;
	std::vector<CBrick*> m_vecBricks;

	int m_iWidth;
	int m_iHeight;

	int m_iBricksRemaining;

	std::string m_strScore;

private:

};

#endif    // __LEVEL_H__
