#ifndef _MY_LIB_H
#define _MY_LIB_H
/*
 * @Author: DuanYue
 * @Date: 2021-11-17 11:39:03
 * @LastEditTime: 2021-11-17 11:44:13
 * @LastEditors: Please set LastEditors
 * @FilePath: \bubble\mylib.h
 */


#include<graphics.h>

bool detect_key(key_code_e ke);
bool mouse_left_click();

void resize(PIMAGE src,int dstx,int dsty,PIMAGE dst);

class object{
private:
	PIMAGE texture;
	int sx,sy;			//size
public:
	object();
	~object();
	void init();
	void load_texture(LPCSTR file);
	void load_texture(PIMAGE src,int x,int y,int w,int h);
	void resize(int dstx,int dsty);
	void draw(int x,int y,int alpha);
};

class movement{
private:

public:
	object obj;		//main object
	int x,y;		//current coords
	double vx,vy;
	void setpos(int x_,int y_){x=x_,y=y_;}
};


/*
 * @Author: DuanYue
 * @Date: 2021-11-17 11:39:03
 * @LastEditTime: 2021-11-17 11:44:13
 * @LastEditors: Please set LastEditors
 * @FilePath: \bubble\mylib.h
 */
#endif