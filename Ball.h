#pragma once

#include <graphics.h>

class Ball
{
private:
	// ��������ٶ�����
	const int kMaxSpeed = 30;
	const int kMinSpeed = 10;

	// ��Ļ������ԣ��ٶȣ�λ�ã���ɫ���뾶
	int speed_x;
	int speed_y;
	int pos_x;
	int pos_y;
	int color_r;
	int color_g;
	int color_b;
	int radius;

	// ������ķ��򣬹涨����Ϊ��������Ϊ��
	int direction_x = 1;
	int direction_y = 1;

public:
	// �ṩ���ҽ���һ�ֹ���i����
	Ball(int init_speed_x, int init_speed_y, int init_pos_x, int init_pos_y, 
		int init_color_r, int init_color_g, int init_color_b, int init_radius);

	// �������ͼ��
	void Draw();

	// �ƶ���ĺ�����
	void MovePosX();

	// �ƶ����������
	void MovePosY();

	// ����x,y���򣬲����������ٶ�
	void AbsAll();

	// �ı���ķ���
	void DirectionUp();
	void DirectionDown();
	void DirectionLeft();
	void DirectionRight();

	// ���¸��ٶȸ�ֵ���ٶ������涨����ٶ�������
	void RandSpeedX();
	void RandSpeedY();

	// ��ȡԲ�ĺ�����
	int GetPosX();

	//��ȡԲ��������
	int GetPosY();
};

