#include "../headers/Palette.h"

#include "../headers/Rectangles.h"

const int initialPlayer1PosX = 20;
const int initialPlayer1PosY = 260;
const int initialPlayer2PosX = 780;
const int initialPlayer2PosY = 260;
const int player1Width = 10;
const int player1Height = 100;
const int player2Width = 10;
const int player2Height = 100;

void InitPlayers() 
{
	player1.x = initialPlayer1PosX;
	player1.y = initialPlayer1PosY;
	player1.width = player1Width;
	player1.height = player1Height;

	player2.x = initialPlayer2PosX;
	player2.y = initialPlayer2PosY;
	player2.width = player2Width;
	player2.height = player2Height;
}