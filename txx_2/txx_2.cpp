
#include "pch.h"
#include <iostream>
#include "../TX/TXLib.h"
#include <string>
#include <cmath>
using namespace std;
float unform(float a, float b) {
	return a + (b - a)*rand() / RAND_MAX;
}
void pythagorTree(float x, float y, float L,
					float angle, int levels){

	if (levels <= 0)return;
	const float k = 0.7;
	const float angel1 = angle - 45 + unform(-5, 5);
	const float angel2 = angle + 45 + unform(-5, 5);
	float x1 = x + L * cos(angle*M_PI/180);
	float y1 = y - L * sin(angle*M_PI / 180);
	txLine(x, y, x1, y1);
	pythagorTree(x1, y1, k*L, angel1, levels - 1);
	pythagorTree(x1, y1, k*L, angel2, levels - 1);
}
int main()
{
	const int width = 800, height = 600;

	txCreateWindow(width, height);
	txSetFillColor(TX_WHITE);
	txSetColor(TX_BLACK);
	const float L = 200, angle = 90;
	const int levels = 10;
	while ( not GetAsyncKeyState(VK_ESCAPE)) {
		txClear();
		pythagorTree(width/2, height, L, angle, levels);
		txSleep(100);
	}
}

