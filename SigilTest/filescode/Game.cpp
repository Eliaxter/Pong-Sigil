#include "sl.h"
#include "../headers/Game.h"

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