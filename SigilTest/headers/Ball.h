#pragma once
#include "sl.h"
#include "GlobalComponents.h"

extern const int initBallPosX;
extern const int initBallPosY;
extern const int ballRadius;
extern const int ballVertices;

extern Vector2 ballPosition;
extern Vector2 ballSpeed;

void InitBall();
void BallCollision();