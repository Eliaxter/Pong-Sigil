#include "sl.h"
#include "../headers/Game.h"

int pointsP1 = 0;
int pointsP2 = 0;
int startPointsP1 = 0;
int startPointsP2 = 0;
int player1Wins;
int player2Wins;
int winPoints = 5;

void Game() //Gameplay
{
	// background glow
	slSetForeColor(0.1, 0.9, 0.2, 0.4);

	Initialize();

	if (slGetKey('W') && player1.y <= screenHeight - player1.height / 2) player1.y += 5.0f;
	if (slGetKey('S') && player1.y >= 0 + player1.height / 2) player1.y -= 5.0f;
	if (slGetKey(SL_KEY_UP) && player2.y <= screenHeight - player2.height / 2) player2.y += 5.0f;
	if (slGetKey(SL_KEY_DOWN) && player2.y >= 0 + player2.height / 2) player2.y -= 5.0f;
	//ballPosition.y = player2.y;

	// large text and fat line
	slRectangleFill(player1.x, player1.y, player1.width, player1.height);
	slRectangleFill(player2.x, player2.y, player2.width, player2.height);

	slCircleFill(ballPosition.x, ballPosition.y, ballRadius, ballVertices);

	BallCollision();

	if (pointsP1 >= winPoints || pointsP2 >= winPoints)
	{
		stateGame = State::Lose;
	}

	slSetBackColor(0, 0, 0);

	// smaller subtext
	slSetFontSize(14);

	slRender();
}