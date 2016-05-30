// Library Includes

// Local Includes
#include "Game.h"
#include "Paddle.h"
#include "Brick.h"
#include "Ball.h"
#include "Utilities.h"
#include "backbuffer.h"

// This Include
#include "Level.h"

// Static Variables

// Static Function Prototypes

// Implementation

#define CHEAT_BOUNCE_ON_BACK_WALL

CLevel::CLevel()
: m_iBricksRemaining(0)
, m_pPaddle(0)
, m_pBall(0)
, m_iWidth(0)
, m_iHeight(0)
{

}

CLevel::~CLevel()
{
	while (m_vecBricks.size() > 0)
	{
		CBrick* pBrick = m_vecBricks[m_vecBricks.size() - 1];

		m_vecBricks.pop_back();

		delete pBrick;
	}

	delete m_pPaddle;
	m_pPaddle = 0;

	delete m_pBall;
	m_pBall = 0;
}

bool
CLevel::Initialise(int _iWidth, int _iHeight)
{
	m_iWidth = _iWidth;
	m_iHeight = _iHeight;

	const float fBallVelX = 200.0f;
	const float fBallVelY = 75.0f;

	m_pBall = new CBall();
	VALIDATE(m_pBall->Initialise(m_iWidth / 2.0f, m_iHeight / 2.0f, fBallVelX, fBallVelY));

	m_pPaddle = new CPaddle();
	VALIDATE(m_pPaddle->Initialise());

	// Set the paddle's position to be centered on the x, 
	// and a little bit up from the bottom of the window.
	m_pPaddle->SetX(_iWidth / 2.0f);
	m_pPaddle->SetY(_iHeight - (4 * m_pPaddle->GetHeight()));

	const int kiNumBricks = 36;
	const int kiStartX = 20;
	const int kiGap = 5;

	int iCurrentX = kiStartX;
	int iCurrentY = kiStartX;

	for (int i = 0; i < kiNumBricks; ++i)
	{
		CBrick* pBrick = new CBrick();
		VALIDATE(pBrick->Initialise());

		pBrick->SetX(static_cast<float>(iCurrentX));
		pBrick->SetY(static_cast<float>(iCurrentY));

		iCurrentX += static_cast<int>(pBrick->GetWidth()) + kiGap;

		if (iCurrentX > _iWidth)
		{
			iCurrentX = kiStartX;
			iCurrentY += 20;
		}

		m_vecBricks.push_back(pBrick);
	}

	SetBricksRemaining(kiNumBricks);

	return (true);
}

void
CLevel::Draw()
{
	for (unsigned int i = 0; i < m_vecBricks.size(); ++i)
	{
		m_vecBricks[i]->Draw();
	}

	m_pPaddle->Draw();
	m_pBall->Draw();

	DrawScore();
}

void
CLevel::Process(float _fDeltaTick)
{
	ProcessBallWallCollision();
	ProcessBallPaddleCollision();
	ProcessBallBrickCollision();

	ProcessCheckForWin();

	ProcessBallBounds();

	for (unsigned int i = 0; i < m_vecBricks.size(); ++i)
	{
		m_vecBricks[i]->Process(_fDeltaTick);
	}
	m_pPaddle->Process(_fDeltaTick);
	m_pBall->Process(_fDeltaTick);
}

CPaddle*
CLevel::GetPaddle() const
{
	return (m_pPaddle);
}

void
CLevel::ProcessBallWallCollision()
{
	float fBallX = m_pBall->GetX();
	float fBallY = m_pBall->GetY();
	float fBallW = m_pBall->GetWidth();
	float fBallH = m_pBall->GetHeight();

	float fHalfBallW = fBallW / 2;

	if (fBallX < fHalfBallW)
	{
		m_pBall->SetVelocityX(m_pBall->GetVelocityX() * -1);
	}
	else if (fBallX > m_iWidth - fHalfBallW)
	{
		m_pBall->SetVelocityX(m_pBall->GetVelocityX() * -1);
	}

	if (fBallY < 0)
	{
		m_pBall->SetVelocityY(m_pBall->GetVelocityY() * -1);
	}

#ifdef CHEAT_BOUNCE_ON_BACK_WALL
	if (fBallY > m_iHeight - fBallH)
	{
		m_pBall->SetVelocityY(m_pBall->GetVelocityY() * -1);
	}
#endif //CHEAT_BOUNCE_ON_BACK_WALL
}

void
CLevel::ProcessBallPaddleCollision()
{
	float fBallR = m_pBall->GetRadius();

	float fBallX = m_pBall->GetX();
	float fBallY = m_pBall->GetY();

	float fPaddleX = m_pPaddle->GetX();
	float fPaddleY = m_pPaddle->GetY();

	float fPaddleH = m_pPaddle->GetHeight();
	float fPaddleW = m_pPaddle->GetWidth();

	if ((fBallX + fBallR > fPaddleX - fPaddleW / 2) &&
		(fBallX - fBallR < fPaddleX + fPaddleW / 2) &&
		(fBallY + fBallR > fPaddleY - fPaddleH / 2) &&
		(fBallY - fBallR < fPaddleY + fPaddleH / 2))
	{
		m_pBall->SetY((fPaddleY - fPaddleH / 2) - fBallR);
		m_pBall->SetVelocityY(m_pBall->GetVelocityY() * -1);
	}
}

void
CLevel::ProcessBallBrickCollision()
{
	for (unsigned int i = 0; i < m_vecBricks.size(); ++i)
	{
		if (!m_vecBricks[i]->IsHit())
		{
			float fBallR = m_pBall->GetRadius();

			float fBallX = m_pBall->GetX();
			float fBallY = m_pBall->GetY();

			float fBrickX = m_vecBricks[i]->GetX();
			float fBrickY = m_vecBricks[i]->GetY();

			float fBrickH = m_vecBricks[i]->GetHeight();
			float fBrickW = m_vecBricks[i]->GetWidth();

			if ((fBallX + fBallR > fBrickX - fBrickW / 2) &&
				(fBallX - fBallR < fBrickX + fBrickW / 2) &&
				(fBallY + fBallR > fBrickY - fBrickH / 2) &&
				(fBallY - fBallR < fBrickY + fBrickH / 2))
			{
				//Hit the front side of the brick...
				m_pBall->SetY((fBrickY + fBrickH / 2.0f) + fBallR);
				m_pBall->SetVelocityY(m_pBall->GetVelocityY() * -1);
				m_vecBricks[i]->SetHit(true);

				SetBricksRemaining(GetBricksRemaining() - 1);
			}
		}
	}
}

void
CLevel::ProcessCheckForWin()
{
	for (unsigned int i = 0; i < m_vecBricks.size(); ++i)
	{
		if (!m_vecBricks[i]->IsHit())
		{
			return;
		}
	}

	CGame::GetInstance().GameOverWon();
}

void
CLevel::ProcessBallBounds()
{
	if (m_pBall->GetX() < 0)
	{
		m_pBall->SetX(0);
	}
	else if (m_pBall->GetX() > m_iWidth)
	{
		m_pBall->SetX(static_cast<float>(m_iWidth));
	}

	if (m_pBall->GetY() < 0)
	{
		m_pBall->SetY(0.0f);
	}
	else if (m_pBall->GetY() > m_iHeight)
	{
		CGame::GetInstance().GameOverLost();
		//m_pBall->SetY(m_iHeight);
	}
}

int
CLevel::GetBricksRemaining() const
{
	return (m_iBricksRemaining);
}

void
CLevel::SetBricksRemaining(int _i)
{
	m_iBricksRemaining = _i;
	UpdateScoreText();
}

void
CLevel::DrawScore()
{
	HDC hdc = CGame::GetInstance().GetBackBuffer()->GetBFDC();

	const int kiX = 0;
	const int kiY = m_iHeight - 50;

	TextOut(hdc, kiX, kiY, m_strScore.c_str(), static_cast<int>(m_strScore.size()));
}

void
CLevel::UpdateScoreText()
{
	m_strScore = "Bricks Remaining: ";

	m_strScore += ToString(GetBricksRemaining());
}
