#include<ctime>
#include<cstdio>
#include<algorithm>
#include<graphics.h>
const int mX=1280,mY=720;
const int a=200,b=100;
int x,y,xx,yy;
void newButton(){
	x=rand()%(mX-a),y=rand()%(mY-b);
	xx=x+a,yy=y+b;
	setfillcolor(EGERGB(0x80,0x80,0x80));
	bar(x-5,y-5,xx+5,yy+5);
	setfillcolor(GREEN);
	bar(x,y,xx,yy);
}
int main(){
	srand(time(0));
	initgraph(mX,mY);
	setbkcolor(WHITE);

	int score=0;
	char sc[110];

	sprintf(sc,"按任意键开始");
	setfont(50,0,"楷体");
	outtextxy(mX/2-100,mY/2-100,sc);
	getch();
	cleardevice();

	newButton();
	time_t t0=time(0),t1=t0+10;
	for(mouse_msg msg;is_run();delay_fps(60)){
		if(t1-time(0)<=0){
			cleardevice();
			sprintf(sc,"score:%d",score);
			setfont(100,0,"楷体");
			outtextxy(mX/2-100,mY/2-100,sc);
			break;
		}
		sprintf(sc,"score:%d time left:%d",score,t1-time(0));
		setfont(20,0,"楷体");
		outtextxy(0,0,sc);
		while(mousemsg())
			msg=getmouse();
		if(msg.is_left()){
			int ix,iy;
			mousepos(&ix,&iy);
			if(ix>=x && ix<=xx && iy>=y && iy<=yy){
				++score;
				cleardevice();
				newButton();
			}
		}
	}
	sprintf(sc,"按任意键退出");
	setfont(50,0,"楷体");
	outtextxy(0,0,sc);
	getch();
	closegraph();
	return 0;
}