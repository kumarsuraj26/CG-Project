#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#define SIN 0.86602540 // sin(60 degrees)

/* Function to draw the Koch curve */
void koch(int x1, int y1, int x2, int y2, int m) {
    int xx, yy, x[5], y[5], lx, ly;
    int offx = 50, offy = 300;

    lx = (x2 - x1) / 3;
    ly = (y2 - y1) / 3;

    x[0] = x1; // Store point p0
    y[0] = y1;
    x[4] = x2; // Store point p4
    y[4] = y2;
    x[1] = x[0] + lx; // Store point p1
    y[1] = y[0] + ly;
    x[3] = x[0] + 2 * lx; // Store point p3
    y[3] = y[0] + 2 * ly;

    // Translate point p2 to origin
    xx = x[3] - x[1];
    yy = y[3] - y[1];

    // Perform rotation for point p2
    x[2] = (int)(xx * 0.5 + yy * SIN);
    y[2] = (int)(-xx * SIN + yy * 0.5);

    // Perform inverse translation
    x[2] = x[2] + x[1];
    y[2] = y[2] + y[1];

    if (m > 0) {
        // Recursive calls to draw parts of the Koch curve
        koch(x[0], y[0], x[1], y[1], m - 1); // Part 1
        koch(x[1], y[1], x[2], y[2], m - 1); // Part 2
        koch(x[2], y[2], x[3], y[3], m - 1); // Part 3
        koch(x[3], y[3], x[4], y[4], m - 1); // Part 4
    } else {
        // Draw the lines for the current level
        line(offx + x[0], offy + y[0], offx + x[1], offy + y[1]);
        line(offx + x[1], offy + y[1], offx + x[2], offy + y[2]);
        line(offx + x[2], offy + y[2], offx + x[3], offy + y[3]);
        line(offx + x[3], offy + y[3], offx + x[4], offy + y[4]);
    }
}

void main() {
    int n, gd, gm;
    int x1 = 0, x2 = 550, y1 = 0, y2 = 0;

    /* Initialize graphics mode */
    printf("\nEnter the level of curve generation: ");
    scanf("%d", &n);

    gd = DETECT;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    if (graphresult() != 0) {
        printf("Error initializing graphics mode\n");
        exit(1);
    }

    // Draw Koch curve
    koch(x1, y1, x2, y2, n);

    getch();
    closegraph();
}
