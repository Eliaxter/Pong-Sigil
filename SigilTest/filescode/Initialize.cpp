#include "../headers/Initialize.h"

#include "sl.h"

#include "../headers/GlobalComponents.h"
#include "../headers/Ball.h"
#include "../headers/Palette.h"

void Initialize()
{
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
	InitBall();
	InitPlayers();
}