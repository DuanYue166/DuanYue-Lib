#include<cmath>
#include<ctime>
#include<math.h>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<graphics.h>
const int mX=1280,mY=720;
const int numPa=100;
double randf(){
	return (double)(rand()*rand()%1000000)/1000000.0;
}
double rand(double l,double r){
	return l+(r-l)*randf();
}
struct part{
	int t;
	int ox,oy;
	int x,y,rad;
	double dx,dy;
	double vel,omg;
	int amp;
	part(){t=ox=oy=x=y=rad=dx=dy=vel=omg=amp=0;}
	part(int ox,int oy,int rad,double vel,double omg,int amp):ox(ox),oy(oy),rad(rad),vel(vel),omg(omg),amp(amp){
		x=ox,y=oy;
		dx=dy=0;
	}
	void update(){
		++t;
		dx=vel*t;
		dy=amp*sin(omg*t);
		x=ox+dx;
		y=oy+dy;
	}
	void draw(){		//bool
		setcolor(RED);
		setfillcolor(RED);
		fillellipse(x,y,rad,rad);
	}
	void rand_new(){
		int oy=rand()%mY;
		int rad=rand()%10+2;
		int amp=rand()%30+1;
		double vel=rand(5/60.0,100/60.0);
		double omg=rand(1*PI/60,2*PI/60);
		(*this)=part(0,oy,rad,vel,omg,amp);
	}
	void print(){
		printf("%d %d %d\n",x,y,rad);
		printf("%.2lf %.2lf %d\n",vel,omg,amp);
	}
}vec[numPa];
int main(){
	part a;
	srand(time(0));
	initgraph(mX,mY);
	setrendermode(RENDER_MANUAL);
	// part p=part(0,300,10,100.0/60,2.0*PI/60,20);
	for(int i=0;i<numPa;++i){
		part tmp;
		tmp.rand_new();
		vec[i]=tmp;
	}

	for(;is_run();delay_fps(60)){
		cleardevice();
		for(int i=0;i<numPa;++i){
			vec[i].draw();
			vec[i].update();
		}
	}
	return 0;
}