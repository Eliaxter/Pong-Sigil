#include "sl.h"

extern struct Vector2
{
	float x;
	float y;
};
extern struct Rectangle
{
	float x;
	float y;
	int width;
	int height;
};
extern enum State
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
extern const float speedInX;
extern const float speedInY;
extern State stateGame;