#include "sl.h"
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
Vector2 ballPosition;
Vector2 ballSpeed;
Rectangle player1;
Rectangle player2;
const int screenWidth = 800;
const int screenHeight = 400;
const int speedInX = 5.0f;
const int speedInY = 5.0f;
const int initBallPosX = 400;
const int initBallPosY = 260;
const int ballRadius = 20;
const int ballVertices = 100;

int main(int args, char *argv[])
{
	// set up our window and a few resources we need
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetTextAlign(SL_ALIGN_CENTER);

	player1.x = 20;
	player1.y = 260;
	player1.width = 7;
	player1.height = 100;

	player2.x = 780;
	player2.y = 260;
	player2.width = 7;
	player2.height = 100;

	ballPosition.x = initBallPosX;
	ballPosition.y = initBallPosY;
	ballSpeed.x = speedInX;
	ballSpeed.y = speedInY;

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		// background glow
		slSetForeColor(0.1, 0.9, 0.2, 0.4);

		ballPosition.x += ballSpeed.x;
		ballPosition.y -= ballSpeed.y;

		if (slGetKey('W') && player1.y <= screenHeight - player1.height / 2) player1.y += 4.0f;
		if (slGetKey('S') && player1.y >= 0 + player1.height / 2) player1.y -= 4.0f;
		if (slGetKey(SL_KEY_UP) && player2.y <= screenHeight - player2.height / 2) player2.y += 4.0f;
		if (slGetKey(SL_KEY_DOWN) && player2.y >= 0 + player2.height / 2) player2.y -= 4.0f;
		//ballPosition.y = player2.y;

		// large text and fat line
		slRectangleFill(player1.x, player1.y, player1.width, player1.height);
		slRectangleFill(player2.x, player2.y, player2.width, player2.height);

		slCircleFill(ballPosition.x, ballPosition.y, ballRadius, ballVertices);

		slSetBackColor(0, 0, 0);

		// smaller subtext
		slSetFontSize(14);

		slRender();
	}
	slClose();
	return 0;
}