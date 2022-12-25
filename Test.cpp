//#include "graphics.h"
//#include <iostream>
//#include <math.h>
//#include <stdlib.h> // Provides exit
//#include <ctype.h>
//
//using namespace std;
//
//int main()
//{
//    int gd = DETECT, gm;
//    char data[] = "C:\\MinGW\\lib\\libbgi.a";
//    initgraph(&gd, &gm, data);
//    int XMAX = 800;
//    int YMAX = 600;
//    //you can also pass NULL for third parameter if you did above setup successfully
//    //example: initgraph(&gd, &gm, NULL);
//    circle(200, 200, 100);
//    setcolor(RED);
//    
//    for (int i = 0; i <= XMAX; i = i + 40) {
//        line(0, i, XMAX + i, i);
//    }
//    for (int j = 0; j <= YMAX; j = j + 40) {
//        line(j, 0, j, YMAX + j);
//    }
//    getch();
//    closegraph();
//    return 0;
//}