#pragma once
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
enum State
{
	StateMenu,
	Playing,
	Lose
};

extern Rectangle player1;
extern Rectangle player2;
extern const int screenWidth;
extern const int screenHeight;
extern const int minScreenWidth;
extern const int minscreenHeight;
extern State stateGame;