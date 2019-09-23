#include "sl.h"
#include "../headers/Game.h"

void Initialize()
{
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
	InitBall();
	InitPlayers();
}