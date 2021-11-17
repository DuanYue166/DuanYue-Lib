/*
 * @Author: your name
 * @Date: 2021-11-17 11:38:48
 * @LastEditTime: 2021-11-17 11:45:51
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \bubble\lib\mylib.cpp
 */
#include"mylib.h"

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
static inline void resize_(PIMAGE &src,int &dstx,int &dsty,PIMAGE &dst){
	resize(src,dstx,dsty,dst);
}

object::object(){
	init();
}
object::~object(){
	if(texture!=NULL)
		delimage(texture);
}
void object::init(){
	if(texture!=NULL)
		delimage(texture);
	texture=newimage();
}
void object::load_texture(LPCSTR file){
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
void object::draw(int x,int y,int alpha){
	putimage_alphatransparent(NULL,texture,x,y,BLACK,alpha);
}
