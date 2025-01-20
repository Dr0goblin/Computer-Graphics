//Q2. Draw the eclipse using mid point eclipse algorithm//
#include <graphics.h>
#include <iostream>
using namespace std;

// Function to draw an ellipse using Midpoint Ellipse Algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2;
    int x = 0, y = ry;

    // Initial decision parameter for region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // Region 1
    while (dx < dy) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }

    // Initial decision parameter for region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    // Region 2
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc, yc, rx, ry;
    cout << "Enter center (xc, yc) and radii (rx, ry): ";
    cin >> xc >> yc >> rx >> ry;

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}

