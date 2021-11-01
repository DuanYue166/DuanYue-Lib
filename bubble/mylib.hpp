#include<graphics.h>

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

class obj{
private:
	PIMAGE texture;
	int sx,sy;			//size
public:
	void init();
	void load_texture(char []);
	void load_texture(PIMAGE src,int x,int y,int w,int h);
	void resize(int dstx,int dsty);
	void draw(int x,int y) {putimage(x,y,texture);}
};
void obj::init(){
	if(texture!=NULL)
		delimage(texture);
	texture=newimage();
}
void obj::load_texture(char file[]){
	init();
	getimage(texture,file);
	sx=getwidth(texture);
	sy=getheight(texture);
}
void obj::load_texture(PIMAGE src,int x,int y,int w,int h){
	init();
	getimage(texture,src,x,y,w,h);
	sx=getwidth(texture);
	sy=getheight(texture);
}
void obj::resize(int dstx,int dsty){
	resize_(texture,dstx,dsty,texture);
}

class movement{
private:

public:

};