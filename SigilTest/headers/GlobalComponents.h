#include "sl.h"
#include "Game.h"

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
Vector2 ballPosition;
Vector2 ballSpeed;
Rectangle player1;
Rectangle player2;
const int screenWidth = 800;
const int screenHeight = 400;
const int minScreenWidth = 0;
const int minscreenHeight = 0;
const float speedInX = 5.0f;
const float speedInY = 5.0f;
State stateGame = State::StateMenu;