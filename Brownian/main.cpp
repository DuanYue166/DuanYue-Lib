#include<cmath>
#include<graphics.h>
#include<iostream>
#include"mylib.hpp"

#define BGC EGERGB(0xc0,0xd6,0xcb)
#define FGC EGERGB(0x38,0x18,0x01)

int mX=1280,mY=720;
const int FPS=30;

void rand_v(movement &m){
	static double vx,vy;
	double alp=randomf()*2*PI;
	vx=cos(alp),vy=sin(alp);
	m.set_v(vx,vy);
	std::cerr<<vx<<" "<<vy<<std::endl;
	printf("%.2lf %.2lf\n",vx,vy);
}

int main(){
	setinitmode(INIT_ANIMATION);
	initgraph(mX,mY);
	setbkcolor(BGC);

	movement ball;
	initball:{
		PIMAGE img=newimage(100,100);
		setcolor(FGC,img);
		setfillcolor(FGC,img);
		fillellipse(50,50,50,50,img);
		ball.obj().load_texture(img);
		delimage(img);
		ball.set_pos(mX/2-50,mY/2-50);
		ball.set_border(1);
		rand_v(ball);
	}

	double las=0;
	double vx,vy;
	for(;is_run() && !detect_key(key_esc);delay_jfps(FPS)){
		cleardevice();
		display_fps(0,0);
		if(fclock()-las>0.3){
			rand_v(ball);
			las=fclock();
		}
		ball.update();
		ball.draw();
	}
	closegraph();
	return 0;
}