#include<cstdio>
#include<windows.h>
#include<graphics.h>
int main(){
	initgraph(1280,720);
	setrendermode(RENDER_MANUAL);
	setbkcolor(EGERGB(0x00,0x5C,0x6F));

	char s[100];
	inputbox_getline("","",s,100);
	/*
	for(int x,y;is_run();delay_fps(60)){
		mousepos(&x,&y);
		sprintf(s,"%4d %4d",x,y);
		outtextxy(0,0,s);
	}
	*/
	return 0;
}