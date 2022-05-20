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

void Ball::Draw() {
	MovePosX();
	MovePosY();
	setfillcolor(RGB(color_r, color_g, color_b));
	solidcircle(pos_x, pos_y, radius);
}

void Ball::AbsAll() {
	direction_x *= -1;
	direction_y *= -1;
	RandSpeedX();
	RandSpeedY();
}

void Ball::MovePosX() {
	pos_x = pos_x + speed_x * direction_x;
}

void Ball::MovePosY() {
	pos_y = pos_y + speed_y * direction_y;
}

void Ball::DirectionLeft() {
	direction_x = -1;
}

void Ball::DirectionUp() {
	direction_y = -1;
}

void Ball::DirectionRight() {
	direction_x = 1;
}

void Ball::DirectionDown() {
	direction_y = 1;
}

void Ball::RandSpeedX() {
	speed_x = (rand() % (kMaxSpeed - kMinSpeed)) + kMinSpeed;
}

void Ball::RandSpeedY() {
	speed_y = (rand() % (kMaxSpeed - kMinSpeed)) + kMinSpeed;
}

int Ball::GetPosX() {
	return pos_x;
}

int Ball::GetPosY() {
	return pos_y;
}