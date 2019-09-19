#pragma once
#include "sl.h"
#include "GlobalComponents.h"

extern const int initBallPosX;
extern const int initBallPosY;
extern const int ballRadius;
extern const int ballVertices;
extern const float speedInX;
extern const float speedInY;

extern Vector2 ballPosition;
extern Vector2 ballSpeed;

void InitBall();
void BallCollision();