#include "sl.h"
#include <iostream>
#include "../headers/GlobalComponents.h"
#include "../headers/Ball.h"
#include "../headers/Palette.h"
#include "../headers/GamePlay.h"
#include "../headers/Menu.h"

int main(int args, char *argv[])
{
	InitializeGame();
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE) && true) //Game (loop)
	{
		if (stateGame == State::StateMenu)
		{
			Menu();
		}
		if (stateGame == State::Playing)
		{
			Game();
		}
		if (stateGame == State::Lose)
		{
			FinalMenu();
		}
	}
	slClose();
	return 0;
}



void Game()
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

void InitializeGame() 
{
	// set up our window and a few resources we need
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetTextAlign(SL_ALIGN_CENTER);

	player1.x = initialPlayer1PosX;
	player1.y = initialPlayer1PosY;
	player1.width = player1Width;
	player1.height = player1Height;

	player2.x = initialPlayer2PosX;
	player2.y = initialPlayer2PosY;
	player2.width = player2Width;
	player2.height = player2Height;

	ballPosition.x = initBallPosX;
	ballPosition.y = initBallPosY;
	ballSpeed.x = speedInX;
	ballSpeed.y = speedInY;
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
}

void FinalMenu()
{
	if (slGetKey('M'))
	{
		stateGame = State::StateMenu;
	}
	slSetForeColor(0.0, 3.0, 0.0, 1.0);
	slSetFontSize(20);
	slText(screenWidth / 2, screenHeight / 2, "Fin del juego, apreta M para vovler al menu ");
	if (player1Wins > player2Wins)
	{
		slSetFontSize(20);
		slText(screenWidth / 2, 100, "Gana el Player1");
	}
	if (player2Wins > player1Wins)
	{
		slSetFontSize(20);
		slText(screenWidth / 2, 100, "Gana el Player2");
	}
	slRender();
}