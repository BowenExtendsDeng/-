using namespace std;

#include <iostream>
#include <cmath>
#include <graphics.h>
#include "Ball.h"


int main()
{
	// ���ô��ڴ�С
	const int kGraphWitdh = 800;
	const int kGraphHeight = 800;
	
	// ��������뾶
	const int kRadius1 = 30;
	const int kRadius2 = 45;

	/*
	 * ��ײ������Ϊ������ײ�ٶ�ֻ�ı�һ�Σ����������ܵ��������ظ���ײ
	 * ������������ײʱ��������Ϊ��ײ������ײǽǰ������������
	 * ����������ǽʱ��������Ϊ�������������ײ�Ŀ���
	 */
	bool collision_lock = false;

	// ��ʼ��������
	Ball *circle1 = new Ball(20, 20, 50, 80, 240, 128, 128, kRadius1);
	Ball *circle2 = new Ball(30, 15, 600, 400, 64, 224, 208, kRadius2);
    
	// ���ƽ���
	initgraph(kGraphWitdh, kGraphHeight);
	setbkcolor(WHITE);
	cleardevice();

	// �����¼�ѭ��
	while (true) {
		
		// ����ǽ���
		if (kGraphWitdh <= circle1->GetPosX() + kRadius1) {
			circle1->DirectionLeft();
			collision_lock = false;
		}
		if (kGraphHeight <= circle1->GetPosY() + kRadius1) {
			circle1->DirectionUp();
			collision_lock = false;
		}
		if (kGraphWitdh <= circle2->GetPosX() + kRadius2) {
			circle2->DirectionLeft();
			collision_lock = false;
		}
		if (kGraphHeight <= circle2->GetPosY() + kRadius2) {
			circle2->DirectionUp();
			collision_lock = false;
		}
		if (0 >= circle1->GetPosX() + kRadius1) {
			circle1->DirectionRight();
			collision_lock = false;
		}
		if (0 >= circle1->GetPosY() + kRadius1) {
			circle1->DirectionDown();
			collision_lock = false;
		}
		if (0 >= circle2->GetPosX() + kRadius2) {
			circle2->DirectionRight();
			collision_lock = false;
		}
		if (0 >= circle2->GetPosY() + kRadius2) {
			circle2->DirectionDown();
			collision_lock = false;
		}

		//������ײ���
		bool balls_touched = ((kRadius1 + kRadius2) >= sqrt(pow(circle1->GetPosX()
			- circle2->GetPosX(), 2) + pow(circle1->GetPosY() - circle2->GetPosY(), 2)));
		if (!collision_lock && balls_touched) {
			circle1->AbsAll();
			circle2->AbsAll();
			collision_lock = true;
		}

		//����ͼ��
		circle1->Draw();
		circle2->Draw();
		Sleep(1);
		cleardevice();
	}
}
