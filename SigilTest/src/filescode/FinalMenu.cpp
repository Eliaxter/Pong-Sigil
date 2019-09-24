#include "../headers/FinalMenu.h"

#include "sl.h"

#include "../headers/Game.h"
#include "../headers/GlobalComponents.h"
#include "../headers/Gameplay.h"

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