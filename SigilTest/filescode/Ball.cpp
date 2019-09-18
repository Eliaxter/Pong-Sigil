#include "../headers/Ball.h"
#include "../headers/Game.h"

const int initBallPosX = 400;
const int initBallPosY = 260;
const int ballRadius = 20;
const int ballVertices = 100;

void InitBall() 
{
	ballPosition.x -= ballSpeed.x;
	ballPosition.y += ballSpeed.y;

	ballPosition.x = initBallPosX;
	ballPosition.y = initBallPosY;

	ballSpeed.x = speedInX;
	ballSpeed.y = speedInY;
	slCircleFill(ballPosition.x, ballPosition.y, ballRadius, ballVertices);
}

void BallCollision()
{
	if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius))
	{
		ballSpeed.y *= -1.0f;
	}

	if ((ballPosition.x - ballRadius) <= (player1.x + player1.width / 2) &&
		(ballPosition.x + ballRadius) >= (player1.x - player1.width / 2) &&
		(ballPosition.y + ballRadius) >= (player1.y - player1.height / 2) &&
		(ballPosition.y - ballRadius) <= (player1.y + player1.height / 2))
	{
		ballSpeed.x *= -1.0f;
	}

	if ((ballPosition.x - ballRadius) <= (player2.x + player2.width / 2) &&
		(ballPosition.x + ballRadius) >= (player2.x - player2.width / 2) &&
		(ballPosition.y + ballRadius) >= (player2.y - player2.height / 2) &&
		(ballPosition.y - ballRadius) <= (player2.y + player2.height / 2))
	{
		ballSpeed.x *= -1.0f;
	}

	if (ballPosition.x > screenWidth)
	{
		ballPosition.x = initBallPosX;
		pointsP1++;
		player1Wins++;
	}
	if (ballPosition.x < minScreenWidth)
	{
		ballPosition.x = initBallPosX;
		pointsP2++;
		player2Wins++;
	}
}