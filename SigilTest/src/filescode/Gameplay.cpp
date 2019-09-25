#include "../headers/Gameplay.h"

#include "sl.h"

#include "../headers/Vectors.h"
#include "../headers/Rectangles.h"
#include "../headers/Game.h"
#include "../headers/GlobalComponents.h"
#include "../headers/Ball.h"
#include "../headers/Palette.h"

int pointsP1 = 0;
int pointsP2 = 0;
int startPointsP1 = 0;
int startPointsP2 = 0;
int player1Wins;
int player2Wins;
int winPoints = 5;

void Game()
{
	slSetForeColor(0.1, 0.9, 0.2, 0.4);

	ballPosition.x -= ballSpeed.x;
	ballPosition.y += ballSpeed.y;

	if (slGetKey('W') && player1.y <= screenHeight - player1.height / 2) player1.y += 5.0f;
	if (slGetKey('S') && player1.y >= 0 + player1.height / 2) player1.y -= 5.0f;
	if (slGetKey(SL_KEY_UP) && player2.y <= screenHeight - player2.height / 2) player2.y += 5.0f;
	if (slGetKey(SL_KEY_DOWN) && player2.y >= 0 + player2.height / 2) player2.y -= 5.0f;
	//ballPosition.y = player2.y;

	slRectangleFill(player1.x, player1.y, player1.width, player1.height);
	slRectangleFill(player2.x, player2.y, player2.width, player2.height);

	slCircleFill(ballPosition.x, ballPosition.y, ballRadius, ballVertices);

	BallCollision();

	PlayerGetPoints();

	if (pointsP1 >= winPoints || pointsP2 >= winPoints)
	{
		stateGame = State::Lose;
	}

	slSetBackColor(0, 0, 0);

	slSetFontSize(14);

	slRender();
}