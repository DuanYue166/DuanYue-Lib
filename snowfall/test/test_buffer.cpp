#include<graphics.h>
#include<cstdio>
const int mX=1280,mY=720;
color_t *buf;
int main(){
	initgraph(mX,mY);
	buf=getbuffer((PIMAGE)NULL);
	for(int i=0;i<mX;++i,delay_fps(60))
		for(int j=0;j<mY;++j){
			buf[i+j*mX]=(unsigned)(i*mY+j);
			printf("%d ",(i+j*mX));
		}
	getch();
	closegraph();
	return 0;
}