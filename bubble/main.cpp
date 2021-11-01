#include<graphics.h>
#include<windows.h>
#include"mylib.hpp"

int mX=1280,mY=720;

bool mouse_left_click(){
	static mouse_msg mk;
	mk=getmouse();
	return mk.is_left() && mk.is_down();
}
void draw_bubble(){
	
}

int main(int argc,char *argv[]){
	if(argc==2 && !strcmp(argv[1],"-f")){
		mX=GetSystemMetrics(SM_CXSCREEN);
		mY=GetSystemMetrics(SM_CYSCREEN);
		setinitmode(1);
	}
	
	initgraph(mX,mY);
	setrendermode(RENDER_MANUAL);

	for(int px,py;is_run();delay_fps(60)){
		if(mouse_left_click()){
			mousepos(&px,&py);

		}
	}

}