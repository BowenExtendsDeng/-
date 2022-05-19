#include "Ball.h"

Ball::Ball(int init_speed_x, int init_speed_y, int init_pos_x, int init_pos_y, 
	int init_color_r, int init_color_g, int init_color_b, int init_radius) {
	speed_x = init_speed_x;
	speed_y = init_speed_y;
	pos_x = init_pos_x;
	pos_y = init_pos_y;
	color_r = init_color_r;
	color_g = init_color_g;
	color_b = init_color_b;
	radius = init_radius;
}

void Ball::draw() {
	move_pos_x();
	move_pos_y();
	setfillcolor(RGB(color_r, color_g, color_b));
	solidcircle(pos_x, pos_y, radius);
}

void Ball::abs_all() {
	abs_speed_x();
	abs_speed_y();
}

void Ball::move_pos_x() {
	pos_x += speed_x;
}

void Ball::move_pos_y() {
	pos_y += speed_y;
}

void Ball::abs_speed_x() {
	speed_x *= -1;
	rand_speed_x();
}

void Ball::abs_speed_y() {
	speed_y *= -1;
	rand_speed_y();
}

void Ball::rand_speed_x() {
	speed_x = (rand() % (k_max_speed - k_min_speed)) + k_min_speed;
}

void Ball::rand_speed_y() {
	speed_y = (rand() % (k_max_speed - k_min_speed)) + k_min_speed;
}

