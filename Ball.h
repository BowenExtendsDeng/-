#pragma once

#include <graphics.h>

class Ball
{
private:
	const int kMaxSpeed = 30;
	const int kMinSpeed = 10;

	int speed_x;
	int speed_y;
	int pos_x;
	int pos_y;
	int color_r;
	int color_g;
	int color_b;
	int radius;

	int direction_x = 1;
	int direction_y = 1;

public:
	Ball(int init_speed_x, int init_speed_y, int init_pos_x, int init_pos_y, 
		int init_color_r, int init_color_g, int init_color_b, int init_radius);

	void Draw();

	void MovePosX();

	void MovePosY();

	void AbsAll();

	void DirectionUp();

	void DirectionDown();

	void DirectionLeft();

	void DirectionRight();

	void RandSpeedX();

	void RandSpeedY();

	int GetPosX();

	int GetPosY();
};

