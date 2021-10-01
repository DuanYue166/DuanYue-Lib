#include<cstdio>
#include<graphics.h>
#define GRAY EGERGB(0x80,0x80,0x80)
const int mX=1280,mY=720;
struct dot{
	
};
int main(){
	initgraph(mX,mY);
	setbkcolor(WHITE);
	setcolor(GRAY);
	for(int x=0;x<=mX;x+=50)
		line(x,0,x,mY);
	for(int y=0;y<=mY;y+=50)
		line(0,y,mX,y);
	getch();
}