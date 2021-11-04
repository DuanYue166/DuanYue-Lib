#include "graphics.h"
int main()
{
    initgraph(640, 480);
    rectangle(0, 0, 200, 200);
    getch();
	window_setviewport(100, 100, 400, 400);
    getch();
    closegraph();
    return 0;
}
