#include "../headers/Game.h"

void Initialize() 
{
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
	// set up our window and a few resources we need
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
}