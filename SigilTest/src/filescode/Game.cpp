#include "../headers/Game.h"

#include "sl.h"

#include "../headers/Initialize.h"
#include "../headers/Menu.h"
#include "../headers/Gameplay.h"
#include "../headers/FinalMenu.h"

State stateGame = State::StateMenu;

void GameLoop() 
{
	Initialize();
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
}