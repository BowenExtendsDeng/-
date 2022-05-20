#pragma once

#include <graphics.h>

class Ball
{
private:
	// 定义球的速度区间
	const int kMaxSpeed = 30;
	const int kMinSpeed = 10;

	// 球的基本属性：速度，位置，颜色，半径
	int speed_x;
	int speed_y;
	int pos_x;
	int pos_y;
	int color_r;
	int color_g;
	int color_b;
	int radius;

	// 定义球的方向，规定右下为正，左上为负
	int direction_x = 1;
	int direction_y = 1;

public:
	// 提供有且仅有一种构造i函数
	Ball(int init_speed_x, int init_speed_y, int init_pos_x, int init_pos_y, 
		int init_color_r, int init_color_g, int init_color_b, int init_radius);

	// 绘制球的图案
	void Draw();

	// 移动球的横坐标
	void MovePosX();

	// 移动球的纵坐标
	void MovePosY();

	// 让球x,y反向，并重新设置速度
	void AbsAll();

	// 改变球的方向
	void DirectionUp();
	void DirectionDown();
	void DirectionLeft();
	void DirectionRight();

	// 重新给速度赋值，速度在上面定义的速度区间内
	void RandSpeedX();
	void RandSpeedY();

	// 获取圆心横坐标
	int GetPosX();

	//获取圆心纵坐标
	int GetPosY();
};

