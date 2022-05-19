using namespace std;

#include <iostream>
#include <graphics.h>
#include "Ball.h"


int main()
{
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();

	Ball *circle1 = new Ball(20, 20, 50, 80, 240, 128, 128, 30);
	Ball *circle2 = new Ball(30, 15, 600, 400, 64, 224, 208, 45);

	while (true) {
		circle1->draw();
		circle2->draw();
		Sleep(20);
		cleardevice();
	}
}
