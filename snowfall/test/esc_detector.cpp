#include<graphics.h>
const int mX=800,mY=600;
int main(){
	initgraph(mX,mY);
	key_msg k;
	for(;is_run();delay_fps(60)){
		if(kbmsg()){
			k=getkey();
			if(k.key==key_esc)
				break;
		}
	}
	closegraph();
	return 0;
}