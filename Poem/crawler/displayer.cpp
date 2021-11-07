#include<graphics.h>
#include<cstdio>
#include"mylib.hpp"

#define BGC EGERGB(0xff,0xf2,0xe8)
#define FGC EGERGB(0x91,0x81,0x7e)

int mX=250,mY=150;

int main(){
	setinitmode(INIT_ANIMATION|INIT_TOPMOST);
	setcaption("Progress Display");
	initgraph(mX,mY);
	setbkcolor(BGC);

	for(;is_run() && !detect_key(key_esc);delay_jfps(60)){
		FILE *f=fopen("temp","r");
		int a;
		fscanf(f,"%d",&a);
		double p=a/20000.0*100;
		setfont(-mY/2,0,L"等线");
		cleardevice();
		xyprintf(0,0,"%d",a);
		xyprintf(0,mY/2,"%.1lf%%",p);
		printf("%d\n",a);
		fclose(f);
	}

	cleardevice();
	delay(0);
	setfont(mY/2,0,L"等线");
	xyprintf(mY/2,0,L"Done!");

	getch();
	closegraph();
	return 0;
}