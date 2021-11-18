#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<ctime>
#include<vector>
#include"lib/mylib.h"

#undef _DEBUG
#ifdef _DEBUG
#define dprintf printf
#else
#define dprintf 
#endif

// #define bgc EGERGB(0xda,0xf3,0xef)
#define bgc EGERGB(0x39,0x10,0x85)

int mX=1280,mY=720; 
const int bubble_delay=500;
const int ppm=5400;

char sss[256]={[12]='2',[23]='3'};


int main(int argc,char *argv[]){
	if(argc==2 && !strcmp(argv[1],"-f")){
		mX=GetSystemMetrics(SM_CXSCREEN);
		mY=GetSystemMetrics(SM_CYSCREEN);
		setinitmode(1);
	}
	
	initgraph(mX,mY);
	setbkcolor(bgc);
	setrendermode(RENDER_MANUAL); 

	const int Num=110;
	static movement bubble[Num];
	int t=0;

	bubble_init:{
		for(int i=0;i<Num;++i)
			bubble[i].obj().load_texture("res\\bubble.png");
	}

	for(int px,py;is_run() && !detect_key(key_esc);){
		if(mouse_left_click()){
			dprintf("%d %d\n",px,py);
			mousepos(&px,&py);
			bubble[t].set_pos(px,py);
			bubble[t].obj().draw(px-50,py-50,0x80);
			music_play("res\\bubble_generate.wav");
		}
	}

}