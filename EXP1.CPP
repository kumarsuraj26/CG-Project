#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>  // For kbhit() and getch()

int main() {
    float x, y, x1, y1, x2, y2, dx, dy, length;
    int i, gd = DETECT, gm;

    printf("Enter the value of x1: ");
    scanf("%f", &x1);
    printf("Enter the value of y1: ");
    scanf("%f", &y1);
    printf("Enter the value of x2: ");
    scanf("%f", &x2);
    printf("Enter the value of y2: ");
    scanf("%f", &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dx = fabs(x2 - x1);
    dy = fabs(y2 - y1);

    if (dx >= dy) {
        length = dx;
    } else {
        length = dy;
    }

    dx = (x2 - x1) / length;
    dy = (y2 - y1) / length;

    x = x1 + 0.5;
    y = y1 + 0.5;
    
    putpixel(x, y, WHITE);

    for (i = 1; i <= length; i++) {
        x += dx;
        y += dy;
        putpixel(x, y, WHITE);
        delay(50);
    }

    // Wait for key press to avoid closing the window immediately
    while (!kbhit());  
    getch();
    closegraph();
    
    return 0;
}
