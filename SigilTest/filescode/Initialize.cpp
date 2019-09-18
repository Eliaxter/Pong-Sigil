#include "sl.h"
#include "../headers/Game.h"

void Initialize()
{
	InitPlayers();
	InitBall();
	// set up our window and a few resources we need
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
}