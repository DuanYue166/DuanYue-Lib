/*
 * @Author: your name
 * @Date: 2021-11-17 11:38:48
 * @LastEditTime: 2021-11-17 11:45:51
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \bubble\lib\mylib.cpp
 */
#include<vector>
#include<cstdio>
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
/*
void music_play(LPCSTR file){
	static std::vector<MUSIC> vec;
	static int p=0;
	if(p>=vec.size() || vec[p].GetPlayStatus()==MUSIC_MODE_PLAY){
		MUSIC mc;
		vec.push_back(mc);
		p=vec.size()-1;
	}
	if(vec[p].IsOpen())
		vec[p].Close();
	vec[p].OpenFile(file);
	vec[p].Play();
	printf("%d played\n",p);
	p=(p+1==vec.size() ? 0 : p+1);
	// for(auto x:vec)
		// printf("%d ",x.GetPlayStatus());
	printf("\n");
}
*/
/*
*
*
*music.Play()只占单线程？
void music_play(LPCSTR file){
	static const int SZ=50;
	MUSIC mc[SZ];
	static int p=0;
	mc[p].OpenFile(file);
	mc[p].Play();
	printf("%d ",p);
	p=(p+1==SZ ? 0 : p+1);
}
*/

void music_play(LPCSTR file){
	static MUSIC mc;
	mc.OpenFile(file);
	mc.Play();
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

void movement::update(){
	double dt=(clock()-las)/CLOCKS_PER_SEC;
	extern const int ppm;
	x+=vx*dt*ppm;
	y+=vy*dt*ppm;
}