#pragma once

#include <graphics.h>

class Ball
{
private:
	const int k_max_speed = 30;
	const int k_min_speed = 10;
	int speed_x;
	int speed_y;
	int pos_x;
	int pos_y;
	int color_r;
	int color_g;
	int color_b;
	int radius;

public:
	Ball(int init_speed_x, int init_speed_y, int init_pos_x, int init_pos_y, 
		int init_color_r, int init_color_g, int init_color_b, int init_radius);

	void draw();

	void move_pos_x();

	void move_pos_y();

	void abs_all();

	void abs_speed_x();

	void abs_speed_y();

	void rand_speed_x();

	void rand_speed_y();
};

