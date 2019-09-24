#pragma once

enum State
{
	StateMenu,
	Playing,
	Lose
};
extern State stateGame;

void GameLoop();