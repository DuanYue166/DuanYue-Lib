#include<iostream>
#include<graphics.h>
#include<cmath>


void init(){

}
double omg=5;
double f(double x){
	return (atan(omg*(x-0.5))+PI/2)/PI;
}
int main(){
	initgraph(1280,720);
	PIMAGE p=newimage();
	getimage(p,"../res/mario.png");
	key_msg k;
	double px=0,py=0;
	double v=20;
	for(int i=0;k.key!=key_esc;++i,i%=8,delay_ms(100)){
		int lx=i*16+0,ly=0;
		cleardevice();
		putimage(px,py,160,320,p,lx,ly,16,32);
		if(kbmsg())
			k=getkey();
		px+=v*f((double)i/8);
	}
	return 0;
}