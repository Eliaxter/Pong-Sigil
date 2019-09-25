#include "../headers/Ball.h"

#include "sl.h"

#include <iostream>
#include <time.h>

#include "../headers/Vectors.h"
#include "../headers/Rectangles.h"
#include "../headers/GlobalComponents.h"
#include "../headers/Gameplay.h"

const float initBallPosX = 400.0f;
const float initBallPosY = 260.0f;
const float initPowerBallX = rand() % 200 + 400;
const float initPowerBallY = rand() % 160 + 260;
const int ballRadius = 20;
const int powerBallRadius = 10;
const int ballVertices = 100;
const int powerBallVertices = 100;
const float speedInX = 7.0f;
const float speedInY = 7.0f;
float negativeSpeed = -1.0f;

Vector2 powerBallPosition;

void InitBall() 
{
	ballSpeed.x = speedInX;
	ballSpeed.y = speedInY;
}

void InitPowerBall() 
{
	powerBallPosition.x = initPowerBallX;
	powerBallPosition.y = initPowerBallY;
}

void BallCollision()
{
	if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius))
	{
		ballSpeed.y *= negativeSpeed;
	}

	if ((ballPosition.x - ballRadius) <= (player1.x + player1.width / 2) &&
		(ballPosition.x + ballRadius) >= (player1.x - player1.width / 2) &&
		(ballPosition.y + ballRadius) >= (player1.y - player1.height / 2) &&
		(ballPosition.y - ballRadius) <= (player1.y + player1.height / 2))
	{
		ballSpeed.x *= negativeSpeed;
	}

	if ((ballPosition.x - ballRadius) <= (player2.x + player2.width / 2) &&
		(ballPosition.x + ballRadius) >= (player2.x - player2.width / 2) &&
		(ballPosition.y + ballRadius) >= (player2.y - player2.height / 2) &&
		(ballPosition.y - ballRadius) <= (player2.y + player2.height / 2))
	{
		ballSpeed.x *= negativeSpeed;
	}
}