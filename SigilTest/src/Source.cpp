#include "sl.h"
#include <iostream>
struct Vector2 
{
	float x;
	float y;
};
struct Rectangle 
{
	float x;
	float y;
	int width;
	int height;
};
enum State 
{
	StateMenu,
	Playing,
	Lose
};
Vector2 ballPosition;
Vector2 ballSpeed;
Rectangle player1;
Rectangle player2;
const int screenWidth = 800;
const int screenHeight = 400;
const int minScreenWidth = 0;
const int minscreenHeight = 0;
const float speedInX = 5.0f;
const float speedInY = 5.0f;
const int initBallPosX = 400;
const int initBallPosY = 260;
const int ballRadius = 20;
const int ballVertices = 100;
int pointsP1 = 0;
int pointsP2 = 0;
bool exitGame = false;

State stateGame = State::StateMenu;

void Menu();
void InitializeGame();
void Game();
void FinalMenu();

int main(int args, char *argv[])
{
	InitializeGame();
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE) && true)
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

void Menu()
{
	if (slGetKey(SL_KEY_ENTER))
	{
		stateGame = State::Playing;
		pointsP1 = 0;
		pointsP2 = 0;
	}
	if (slGetKey(SL_KEY_ESCAPE))
	{
		exitGame = true;
	}
	slSetForeColor(0.1, 0.9, 0.2, 0.4);
	slRender();
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
		}
		if (ballPosition.x < minScreenWidth)
		{
			ballPosition.x = initBallPosX;
			pointsP2++;
		}

		if (pointsP1 >= 5 || pointsP2 >= 5)
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

	player1.x = 20;
	player1.y = 260;
	player1.width = 10;
	player1.height = 100;

	player2.x = 780;
	player2.y = 260;
	player2.width = 10;
	player2.height = 100;

	ballPosition.x = initBallPosX;
	ballPosition.y = initBallPosY;
	ballSpeed.x = speedInX;
	ballSpeed.y = speedInY;
}

void FinalMenu()
{
	if (slGetKey('M'))
	{
		stateGame = State::StateMenu;
	}
	slSetForeColor(0.1, 0.9, 0.2, 0.4);
	slRender();
}