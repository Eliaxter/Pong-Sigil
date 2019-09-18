#include "sl.h"
#include "../headers/Game.h"
void Menu()
{
	if (slGetKey(SL_KEY_ENTER))
	{
		stateGame = State::Playing;
		pointsP1 = startPointsP1;
		pointsP2 = startPointsP2;
		player1.x = initialPlayer1PosX;
		player1.y = initialPlayer1PosY;
		player2.x = initialPlayer2PosX;
		player2.y = initialPlayer2PosY;
		ballPosition.x = initBallPosX;
		ballPosition.y = initBallPosY;
	}
	if (slGetKey(SL_KEY_ESCAPE))
	{
		slShouldClose();
	}
	//slSetForeColor(0.1, 0.9, 0.2, 0.4);
	slSetFontSize(20);
	slSetForeColor(0.0, 3.0, 0.0, 1.0);
	slText(screenWidth / 2, 300, "Pong Sigil");
	slSetFontSize(20);
	slText(screenWidth / 2, screenHeight / 2, "Presiona Enter para jugar");
	slSetFontSize(20);
	slText(screenWidth / 2, 100, "Presiona Escape para salir");
	slRender();
}