#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    int x_min, y_min, x_max, y_max;
};

bool liangBarskyClip(Rect window, int x1, int y1, int x2, int y2, int &x1_clip, int &y1_clip, int &x2_clip, int &y2_clip) {
    
    int p[] = {- (x2 - x1), x2 - x1, - (y2 - y1), y2 - y1}; 
    int q[] = {x1 - window.x_min, window.x_max - x1, y1 - window.y_min, window.y_max - y1};

    float t0 = 0.0f, t1 = 1.0f;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0)
                return false;  
        } else {
            float t = (float)q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1)
                    return false; 
                if (t > t0)
                    t0 = t;
            } else {
                if (t < t0)
                    return false;
                if (t < t1)
                    t1 = t;
            }
        }
    }

    x1_clip = x1 + t0 * (x2 - x1);
    y1_clip = y1 + t0 * (y2 - y1);
    x2_clip = x1 + t1 * (x2 - x1);
    y2_clip = y1 + t1 * (y2 - y1);

    return true;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Rect clipWindow = {200, 150, 400, 400};

    int x1 = 30, y1 = 40, x2 = 250, y2 = 160;

    int x1_clip, y1_clip, x2_clip, y2_clip;
    bool clipped = liangBarskyClip(clipWindow, x1, y1, x2, y2, x1_clip, y1_clip, x2_clip, y2_clip);

    setcolor(WHITE);
    rectangle(clipWindow.x_min, clipWindow.y_min, clipWindow.x_max, clipWindow.y_max);

    setcolor(BLUE);
    line(x1, y1, x2, y2);

    if (clipped) {
        setcolor(GREEN);
        line(x1_clip, y1_clip, x2_clip, y2_clip);
    }

    getch();

    closegraph();
    return 0;
}


