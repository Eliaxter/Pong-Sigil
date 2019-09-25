#pragma once

extern const float initBallPosX;
extern const float initBallPosY;
extern const float initPowerBallX;
extern const float initPowerBallY;
extern const int ballRadius;
extern const int powerBallRadius;
extern const int ballVertices;
extern const int powerBallVertices;
extern const float speedInX;
extern const float speedInY;
extern float negativeSpeed;

void InitBall();
void InitPowerBall();
void BallCollision();