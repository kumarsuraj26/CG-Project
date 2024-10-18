// Bresenhams line drawing
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

void main() {
    float x, y, x1, y1, x2, y2, dx, dy, e;
    int i, gd, gm;
    
    clrscr()n

    printf("Enter the value of x1: ");
    scanf("%f", &x1);
    printf("Enter the value of y1: ");
    scanf("%f", &y1);
    printf("Enter the value of x2: ");
    scanf("%f", &x2);
    printf("Enter the value of y2: ");
    scanf("%f", &y2);

    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    x = x1;
    y = y1;
    putpixel(x, y, 15);

    e = 2 * dy - dx;
    i = 1;

    do {
        while (e >= 0) {
            y = y + 1;
            e = e - 2 * dx;
        }
        x = x + 1;
        e = e + 2 * dy;
        i = i + 1;
        putpixel(x, y, 15);
    } while (i <= dx);

    getch();
    closegraph();
}
