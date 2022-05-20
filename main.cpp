using namespace std;

#include <iostream>
#include <cmath>
#include <graphics.h>
#include "Ball.h"


int main()
{
	// 设置窗口大小
	const int kGraphWitdh = 800;
	const int kGraphHeight = 800;
	
	// 定义两球半径
	const int kRadius1 = 30;
	const int kRadius2 = 45;

	/*
	 * 碰撞锁：因为两球相撞速度只改变一次，不加锁可能导致两球重复碰撞
	 * 加锁：两球碰撞时加锁，因为碰撞后两球到撞墙前不可能再相遇
	 * 解锁：球碰墙时解锁，因为反向后有重新碰撞的可能
	 */
	bool collision_lock = false;

	// 初始化两个球
	Ball *circle1 = new Ball(20, 20, 50, 80, 240, 128, 128, kRadius1);
	Ball *circle2 = new Ball(30, 15, 600, 400, 64, 224, 208, kRadius2);
    
	// 绘制界面
	initgraph(kGraphWitdh, kGraphHeight);
	setbkcolor(WHITE);
	cleardevice();

	// 进入事件循环
	while (true) {
		
		// 球碰墙检测
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

		//两球相撞检测
		bool balls_touched = ((kRadius1 + kRadius2) >= sqrt(pow(circle1->GetPosX()
			- circle2->GetPosX(), 2) + pow(circle1->GetPosY() - circle2->GetPosY(), 2)));
		if (!collision_lock && balls_touched) {
			circle1->AbsAll();
			circle2->AbsAll();
			collision_lock = true;
		}

		//绘制图形
		circle1->Draw();
		circle2->Draw();
		Sleep(1);
		cleardevice();
	}
}
