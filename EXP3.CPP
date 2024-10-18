//mid point circle 
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void midPointCircleDraw(int x_centre, int y_centre, int r) { 
    int x = r, y = 0; 
    int P = 1 - r; 

    putpixel(x + x_centre, y + y_centre, WHITE); 

    if (r > 0) { 
        putpixel(x + x_centre, -y + y_centre, WHITE); 
        putpixel(y + x_centre, x + y_centre, WHITE); 
        putpixel(-y + x_centre, x + y_centre, WHITE); 
    } 

    while (x > y) { 
        y++; 

        if (P <= 0) 
            P = P + 2 * y + 1; 
        else { 
            x--; 
            P = P + 2 * y - 2 * x + 1; 
        } 

        if (x < y) 
            break; 

        putpixel(x + x_centre, y + y_centre, WHITE); 
        putpixel(-x + x_centre, y + y_centre, WHITE); 
        putpixel(x + x_centre, -y + y_centre, WHITE); 
        putpixel(-x + x_centre, -y + y_centre, WHITE); 

        if (x != y) { 
            putpixel(y + x_centre, x + y_centre, WHITE); 
            putpixel(-y + x_centre, x + y_centre, WHITE); 
            putpixel(y + x_centre, -x + y_centre, WHITE); 
            putpixel(-y + x_centre, -x + y_centre, WHITE); 
        } 
    } 
} 

int main() { 
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");  

    midPointCircleDraw(200, 200, 50); 

    getch();  
    closegraph();  
    return 0;
}

