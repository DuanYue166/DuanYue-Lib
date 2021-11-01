#include<cstdio>
#include<graphics.h>
#include<ctime>
#define fgc EGERGB(0x16,0xa0,0x85)
#define bgc EGERGB(0xbd,0xc3,0xc7)
const int mX=1280,mY=720;
const int FPS=60;			//frame per second
const double gx=0,gy=9.8;	//gravity
const double ppm=60;		//pixel per meter
struct Ball{
	double x,y;			//current coords
	double rad;			//radius	,	m
	double vx,vy;		//velocity  ,	m/s
	Ball(){}
	Ball(double x,double y,double rad)
		:x(x),y(y),rad(rad)
		{vx=0,vy=0;}
	void set_v(double vx_,double vy_){
		vx=vx_,vy=vy_;
	}
	void update(){
		x+=vx/FPS*ppm;
		y+=vy/FPS*ppm;
		vx+=gx/FPS;
		vy+=gy/FPS;
	}
	void jump(){
		vy=-8;
	}
	void move(){

	}
	void draw(){
		setcolor(fgc);
		setfillcolor(fgc);
		fillellipsef(x,y,rad*ppm,rad*ppm);
	}
	void test();
};
bool detect(unsigned char dst_key){
	static key_msg k;
	if(kbmsg()){
		k=getkey();
		return k.key==dst_key;
	}
	return false;
}
void Ball::test(){
	x+=y;
}
void print_fps(){
	static char sc[110];
	sprintf(sc,"fps:%.1lf",getfps());
	outtextxy(0,0,sc);
}
void print_run_time(){
	static char sc[110];
	sprintf(sc,"time:%.1lf",clock()/1000.,0);
	outtextxy(0,30,sc);
}
int main(){
	initgraph(mX,mY);
	setbkcolor(bgc);
	setrendermode(RENDER_MANUAL);

	Ball ball(mX/2,mY/2,1);
	for(;is_run() && !detect(key_esc);delay_fps(FPS)){
		cleardevice();
		print_fps();
		print_run_time();
		ball.draw();
		if(detect(key_space))
			ball.jump();
		ball.update();
	}
	return 0;
}
