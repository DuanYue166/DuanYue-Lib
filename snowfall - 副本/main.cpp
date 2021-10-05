#include<cmath>
#include<ctime>
#include<math.h>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<graphics.h>
#include<windows.h>
#include<shellapi.h>
#include<iostream>
using namespace std;
#define bk EGERGB(150,233,233)

const int mX=1280,mY=720;
const int numPa=1;

PIMAGE obj,bg;
PIMAGE resize_g(const PIMAGE &src,int dstx,int dsty){
	static PIMAGE cache,res;
	if(res==NULL)
		res=newimage();
	cache=newimage(dstx,dsty);
	int srcx=getwidth(src);
	int srcy=getheight(src);
	putimage(cache,0,0,dstx,dsty,src,0,0,srcx,srcy);
	getimage(res,cache,0,0,dstx,dsty);
	delimage(cache);
	return res;
}

double randf(){
	return (double)(rand()*rand()%1000000)/1000000.0;
}
double rand(double l,double r){
	return l+(r-l)*randf();
}
struct part{
	int t;				//time
	int ox,oy;			//original coords
	int x,y,rad;		//final coords,radius
	double dx,dy;		//delta
	double vel,omg;		//velocity,omiga
	int amp;			//amplitude
	PIMAGE ocu;
	part(){}
	part(int ox,int oy,int rad,double vel,double omg,int amp)
	:ox(ox),oy(oy),rad(rad),vel(vel),omg(omg),amp(amp){
		t=0;
		x=ox,y=oy;
		dx=dy=0;
	}
	bool update(){
		++t;
		dx=amp*sin(omg*t);
		dy=vel*t;
		x=ox+dx;
		y=oy+dy;
		if(y>mY)
			return false;
		return true;
	}
	void draw(){
	/***
	*ball
		setcolor(RED);
		setfillcolor(RED);
		fillellipse(x,y,rad,rad);
	****/
		ocu=newimage(rad,rad);
		printf("%d %d %d %d\n",x,y,rad,rad);
		getimage(ocu,bg,x,y,rad,rad);
		putimage_transparent(NULL,resize_g(obj,rad,rad),x,y,BLACK);
	}
	void rand_new(){
		int ox=rand()%mX;
		int rad=rand()%10+2;
		int amp=rand()%15+1;
		double vel=rand(5/60.0,100/60.0);
		double omg=rand(1*PI/60,2*PI/60);
		(*this)=part(ox,0,rad,vel,omg,amp);
	}
	void reset(){
		putimage(x,y,ocu);
		delimage(ocu);
	}
	void print(){
		printf("t=%d ox=%d oy=%d\n",t,ox,oy);
		printf("x=%d y=%d rad=%d\n",x,y,rad);
		printf("vel=%.2lf omg=%.2lf amp=%d\n",vel,omg,amp);
	}
}vec[numPa];
void init_bg(){
	if(bg==NULL)
		bg=newimage();
	getimage(bg,"bg.jpg");
	bg=resize_g(bg,mX,mY);
	putimage(0,0,bg);
	
	printf("%d %d\n",getwidth(bg),getheight(bg));
}
void flush(){
/*
	static int t;
	if((t++)%300==0){
		SHELLEXECUTEINFO cmd={};
		cmd.cbSize=sizeof(cmd);
		cmd.fMask=SEE_MASK_NOCLOSEPROCESS;
		cmd.lpVerb=L"python";
		cmd.lpFile=L"pics_crawler.py";
		cmd.nShow=SW_SHOWDEFAULT;
		ShellExecuteEx(&cmd);
		init_bg();
	}
*/
	for(int i=0;i<numPa;++i)
		vec[i].reset();
}
void draw(){
	for(int i=0;i<numPa;++i){
		if(!vec[i].update())
			vec[i].rand_new();
		vec[i].draw();
	}
}
int main(){
	srand(time(0));
	setinitmode(INIT_NOFORCEEXIT,0,0);//
	initgraph(mX,mY);
	// setrendermode(RENDER_MANUAL);
	setbkcolor(bk);

	obj=newimage();
	getimage(obj,"snow.png");
	// part p=part(0,300,10,100.0/60,2.0*PI/60,20);
	for(int i=0;i<numPa;++i)
		vec[i].rand_new();

	init_bg();
	char sc[20];
	for(;is_run();){
		// sprintf(sc,"fps:%.1lf",getfps());
		// outtextxy(0,0,sc);

		draw();
		delay_fps(60);
		
		for(int i=0;i<numPa;++i)
			putimage(vec[i].x,vec[i].y+100,vec[i].ocu);

		flush();
	}
	return 0;
}