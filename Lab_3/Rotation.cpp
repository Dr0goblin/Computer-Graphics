#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void rotatePoint(int x, int y, int px, int py, float angle, int &newX, int &newY) {
    int translatedX = x - px;
    int translatedY = y - py;
    float rad = angle * M_PI / 180.0;
    newX = round(translatedX * cos(rad) - translatedY * sin(rad)) + px;
    newY = round(translatedX * sin(rad) + translatedY * cos(rad)) + py;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 140, y1 = 170;
    int x2 = 150, y2 = 150;
    int x3 = 130, y3 = 160;
    int px = 140, py = 130;
    float angle = 60.0;

    setcolor(BLUE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    int newX1, newY1, newX2, newY2, newX3, newY3;
    rotatePoint(x1, y1, px, py, angle, newX1, newY1);
    rotatePoint(x2, y2, px, py, angle, newX2, newY2);
    rotatePoint(x3, y3, px, py, angle, newX3, newY3);

    setcolor(WHITE);
    line(newX1, newY1, newX2, newY2);
    line(newX2, newY2, newX3, newY3);
    line(newX3, newY3, newX1, newY1);

    setcolor(YELLOW);
    circle(px, py, 3);
    floodfill(px, py, YELLOW);

    getch();
    closegraph();
    return 0;
}
