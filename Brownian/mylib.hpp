/*****************************
useful function about graphic
graphics.h included
******************************/
#include<graphics.h>
#include<ctime>
#include<iostream>

extern int mX,mY;

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

void display_fps(int x,int y){
	xyprintf(x,y,"fps:%4.1f",getfps());
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


//load_texture first!
//only contain texture and size of the object
class object{
private:
	PIMAGE texture;
	int sx,sy;			//size
public:
	object(){texture=newimage();}
	~object();
	
	void load_texture(char []);
	void load_texture(PIMAGE src);
	void load_texture(PIMAGE src,int x,int y,int w,int h);
	
	void resize(int dstx,int dsty);
	void draw(int x,int y,int alpha=0xff) 
		   {putimage_alphatransparent(NULL,texture,x,y,BLACK,alpha);}
};
object::~object(){
	if(texture!=NULL)
		delimage(texture);
}
void object::load_texture(PIMAGE src){
	sx=getwidth(src);
	sy=getheight(src);
	getimage(texture,src,0,0,sx,sy);
}
void object::load_texture(char file[]){
	getimage(texture,file);
	sx=getwidth(texture);
	sy=getheight(texture);
}
void object::load_texture(PIMAGE src,int x,int y,int w,int h){
	getimage(texture,src,x,y,w,h);
	sx=getwidth(texture);
	sy=getheight(texture);
}
void object::resize(int dstx,int dsty){
	resize_(texture,dstx,dsty,texture);
}


//coords&velocity contained
class movement{
private:
	object obj_;	//main object
	double x,y;		//current coords
	double vx,vy;	//velocity of x&y , pixel/ms
	clock_t las;	//last time
	bool bordered;
public:
	movement(){las=0;}
	object &obj(){return obj_;}

	void set_pos(int x_,int y_){x=x_,y=y_;}
	void set_v(double vx_,double vy_){vx=vx_,vy=vy_;}
	
	void update();
	void draw(int alpha=0xff){obj_.draw(x,y,alpha);}

	void set_border(bool flag=1){bordered=flag;}
};
void movement::update(){
	if(!las)
		return las=clock(),void();
	static clock_t now;
	static int dx,dy;
	now=clock();
	dx=(now-las)*vx,dy=(now-las)*vy;
	if(bordered){
		if(x+dx>mX || x+dy<1)
			dx=-dx,vx=-vx;
		if(y+dy>mY || y+dy<1)
			dy=-dy,vy=-vy;
	}
	x+=dx,y+=dy;
	las=now;
}