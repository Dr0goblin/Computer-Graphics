#include <graphics.h>
#include <stdlib.h>

void bresenhamLineDrawing(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        putpixel(x1, y1, WHITE); 

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    bresenhamLineDrawing(100, 100, 300, 300);

    getch();
    closegraph();
    return 0;
}
