#include<cstdio>
#include<graphics.h>
int main(){
	initgraph(1280,720);
	setbkcolor(EGERGB(0x00,0x5C,0x6F));

	setviewport(800,500,900,600,0);
	setcolor(EGERGB(0x00,0xCC,0xFF));
	setfontbkcolor(YELLOW);
	setbkmode(TRANSPARENT);
	setfont(120,0,"楷体");
	outtextxy(0,0,"中文楷体");
	getch();
	getheight();
	return 0;
}