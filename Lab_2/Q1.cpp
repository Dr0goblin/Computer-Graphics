//Q1. Draw the circle using mid point circle algorithm//
#include <graphics.h>
#include <iostream>
using namespace std;

// Function to draw a circle using Midpoint Circle Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;  // Initial decision parameter

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc, yc, r;
    cout << "Enter center (xc, yc) and radius: ";
    cin >> xc >> yc >> r;

    drawCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
