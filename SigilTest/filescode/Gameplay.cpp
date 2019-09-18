#include "../headers/Game.h"

void Game() //Gameplay
{
	// background glow
	slSetForeColor(0.1, 0.9, 0.2, 0.4);

	ballPosition.x -= ballSpeed.x;
	ballPosition.y += ballSpeed.y;

	if (slGetKey('W') && player1.y <= screenHeight - player1.height / 2) player1.y += 5.0f;
	if (slGetKey('S') && player1.y >= 0 + player1.height / 2) player1.y -= 5.0f;
	if (slGetKey(SL_KEY_UP) && player2.y <= screenHeight - player2.height / 2) player2.y += 5.0f;
	if (slGetKey(SL_KEY_DOWN) && player2.y >= 0 + player2.height / 2) player2.y -= 5.0f;
	//ballPosition.y = player2.y;

	// large text and fat line
	slRectangleFill(player1.x, player1.y, player1.width, player1.height);
	slRectangleFill(player2.x, player2.y, player2.width, player2.height);

	slCircleFill(ballPosition.x, ballPosition.y, ballRadius, ballVertices);

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

	if (pointsP1 >= winPoints || pointsP2 >= winPoints)
	{
		stateGame = State::Lose;
	}

	slSetBackColor(0, 0, 0);

	// smaller subtext
	slSetFontSize(14);

	slRender();
}