#pragma once

extern const int initBallPosX;
extern const int initBallPosY;
extern const int ballRadius;
extern const int ballVertices;
extern const float speedInX;
extern const float speedInY;
extern float negativeSpeed;

void InitBall();
void BallCollision();