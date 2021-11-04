#include<graphics.h>

bool detect_key(key_code_e ke){
	static key_msg k;
	if(kbhit()){
		k=getkey();
		return k.key==ke;
	}
	return false;
}
bool mouse_left_click(){
	static mouse_msg mk;
	mk=getmouse();
	return mk.is_left() && mk.is_down();
}

void resize(PIMAGE src,int dstx,int dsty,PIMAGE dst){
	static PIMAGE tmp;
	static int srcx,srcy;
	if(tmp==NULL)
		tmp=newimage();
	srcx=getwidth(src);
	srcy=getheight(src);
	putimage(tmp,0,0,dstx,dsty,src,0,0,srcx,srcy);
	if(dst!=NULL)
		delimage(dst);
	dst=newimage(dstx,dsty);
	getimage(dst,tmp,0,0,dstx,dsty);
}
inline void resize_(PIMAGE &src,int &dstx,int &dsty,PIMAGE &dst){
	resize(src,dstx,dsty,dst);
}

class object{
private:
	PIMAGE texture;
	int sx,sy;			//size
public:
	object(){init();}
	void init();
	void load_texture(char []);
	void load_texture(PIMAGE src,int x,int y,int w,int h);
	void resize(int dstx,int dsty);
	void draw(int x,int y,int alpha=0xff) {putimage_alphatransparent(NULL,texture,x,y,BLACK,alpha);}
};
void object::init(){
	if(texture!=NULL)
		delimage(texture);
	texture=newimage();
}
void object::load_texture(char file[]){
	init();
	getimage(texture,file);
	sx=getwidth(texture);
	sy=getheight(texture);
}
void object::load_texture(PIMAGE src,int x,int y,int w,int h){
	init();
	getimage(texture,src,x,y,w,h);
	sx=getwidth(texture);
	sy=getheight(texture);
}
void object::resize(int dstx,int dsty){
	resize_(texture,dstx,dsty,texture);
}

class movement{
private:

public:
	object obj;		//main object
	int x,y;		//current coords
	double vx,vy;
	void setpos(int x_,int y_){x=x_,y=y_;}
};