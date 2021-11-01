#include<cstdio>
#include<graphics.h>
#include<ctime>
#include<cmath>
#include"ball.hpp"

#define fgc EGERGB(0x16,0xa0,0x85)
#define bgc EGERGB(0xbd,0xc3,0xc7)
#define GRAY EGERGB(0x80,0x80,0x80)
const int mX=1280,mY=720;
const int FPS=60;
const double ppm=60;		//pixel per meter
const int Num=20;

void print_fps();
void print_run_time();

bool detect_key(key_code_e key);
bool detect_mouse_left();

void attract(Ball &ball,int x,int y);


int main(){
	initgraph(mX,mY,INIT_RENDERMANUAL);
	setbkcolor(bgc);
	randomize();
	Ball ball[Num+1];
	for(int i=1;i<=Num;++i){
		ball[i]=Ball(0,0,0.2,fgc);
		ball[i].random_pos();
		ball[i].random_v(10);
	}
	// ball.set_v(10,10);
	for(int px=0,py=0,pfg=0;is_run() && !detect_key(key_esc);delay_fps(FPS)){
		cleardevice();
		print_fps();
		print_run_time();
		
		if(detect_mouse_left()){
			pfg=1,mousepos(&px,&py);
			ball[0]=Ball(px,py,0.3,GRAY);
		}
		if(pfg){
			for(int i=1;i<=Num;++i)
				attract(ball[i],px,py);
			ball[0].draw();
		}
		for(int i=1;i<=Num;++i){
			ball[i].draw();
			ball[i].update();
		}
	}
	closegraph();
	return 0;
}

void print_fps(){
	static char sc[31];
	sprintf(sc,"fps:%.1f",getfps());
	setcolor(fgc);
	outtextxy(0,0,sc);
}
void print_run_time(){
	static char sc[31];
	sprintf(sc,"time:%.1lf",clock()/1000.0);
	setcolor(fgc);
	outtextxy(0,20,sc);
}
bool detect_key(key_code_e dst){
	if(kbmsg())
		return getkey().key==dst;
	return false;
}
bool detect_mouse_left(){
	return getmouse().is_left();
}
void attract(Ball &ball,int x,int y){
	static const int lima=20,limb=500;
	static const double dt=1.0/FPS;
	static const double K=1e7;		//to be trailed
	static double d,dx,dy;
	static double dv,dvx,dvy;
	dx=x-ball.get_x();
	dy=y-ball.get_y();
	d=sqrt(dx*dx+dy*dy);
	if(abs(dx)<lima || abs(dy)<lima)
		return;
	if(abs(dx)>limb || abs(dy)>limb)
		return;
	dv=K/d/d*dt;			//dv=F*dt/m   F=K*m1*m2/(d*d)
	dvx=dv*dx/d;
	dvy=dv*dy/d;
	ball.inc_v(dvx,dvy);
}
