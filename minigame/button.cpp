#include<cstdio>
#include<graphics.h>
int main(){
	initgraph(1280,720);
	setbkcolor(WHITE);
	
	int l=540,r=740,ll=360,rr=460;
	setfillcolor(EGERGB(0x80,0x80,0x80));
	bar(l-5,ll-5,r+5,rr+5);
	setfillcolor(GREEN);
	bar(l,ll,r,rr);

	for(mouse_msg msg;is_run();){
		while(mousemsg())
			msg=getmouse();
		if(msg.is_left()){
			int x,y;
			mousepos(&x,&y);
			if(x>=l && x<=r && y>=ll && y<=rr){
				cleardevice();
				Sleep(1000);
				break;
			}
		}
	}
	
	closegraph();
	return 0;
}