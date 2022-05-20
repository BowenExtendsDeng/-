using namespace std;

#include <iostream>
#include <graphics.h>
#include "Ball.h"


int main()
{
	const int kGraphWitdh = 800;
	const int kGraphHeight = 800;
	
	const int kRadius1 = 30;
	const int kRadius2 = 45;

	Ball *circle1 = new Ball(20, 20, 50, 80, 240, 128, 128, kRadius1);
	Ball *circle2 = new Ball(30, 15, 600, 400, 64, 224, 208, kRadius2);
    

	initgraph(kGraphWitdh, kGraphHeight);
	setbkcolor(WHITE);
	cleardevice();

	while (true) {
		if (kGraphWitdh <= circle1->GetPosX() + kRadius1) {
			circle1->DirectionLeft();
		}
		if (kGraphHeight <= circle1->GetPosY() + kRadius1) {
			circle1->DirectionUp();
		}
		if (kGraphWitdh <= circle2->GetPosX() + kRadius2) {
			circle2->DirectionLeft();
		}
		if (kGraphHeight <= circle2->GetPosY() + kRadius2) {
			circle2->DirectionUp();
		}
		if (0 >= circle1->GetPosX() + kRadius1) {
			circle1->DirectionRight();
		}
		if (0 >= circle1->GetPosY() + kRadius1) {
			circle1->DirectionDown();
		}
		if (0 >= circle2->GetPosX() + kRadius2) {
			circle2->DirectionRight();
		}
		if (0 >= circle2->GetPosY() + kRadius2) {
			circle2->DirectionDown();
		}
		circle1->Draw();
		circle2->Draw();
		Sleep(1);
		cleardevice();
	}
}
