#include <cstdio>
#include <iostream>
#include <graphics.h>
#include <ctime>
#include <cmath>
using namespace std;
//void EGEAPI putimage(PIMAGE pDstImg, int dstX, int dstY, const PIMAGE pSrcImg, DWORD dwRop = SRCCOPY);
const int w = 640,h = 480;
const int coladdR = 1,coladdG = 2,coladdB = 5;//自发光度
color_t scrbuf[w][h];
color_t *buf = NULL;

const int barN = 15;
struct filbar {
	float fx,fy;//浮点坐标
	float vx,vy;//速度方向
	int x,y;
	int bw,bh;
	double rotate;//顺时针pi = 90°
	double cosr,sinr;
	color_t tmpbuf[w][h];
	color_t mixedcol;
	double alpha;//(不)透明度
};
filbar bardat[barN];
color_t colmix(color_t A,color_t B,double alpha) {
	return EGERGB(coladdR+(int)((1.0-alpha)*(double)EGEGET_R(A)+alpha*(double)EGEGET_R(B)),
	              coladdG+(int)((1.0-alpha)*(double)EGEGET_G(A)+alpha*(double)EGEGET_G(B)),
	              coladdB+(int)((1.0-alpha)*(double)EGEGET_B(A)+alpha*(double)EGEGET_B(B)));
}
void init(color_t col) {
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < h; ++j)
			scrbuf[i][j] = col;
	for (int i = 0; i < barN; ++i) {
		double bs = randomf()/2.0;
		bardat[i].bw = (double)w*bs;
		bardat[i].bh = (double)h*bs;
		bardat[i].x = rand()%(w-bardat[i].bw-20)+10;
		bardat[i].y = rand()%(h-bardat[i].bh-20)+10;
		bardat[i].mixedcol = /*RGB(rand()%32,rand()%32,rand()%32)*/0x777777;
		bardat[i].rotate = /*randomf()*/randomf()/16.0*(rand()%2?1:-1);
		bardat[i].cosr = cos(-bardat[i].rotate);
		bardat[i].sinr = sin(-bardat[i].rotate);
		bardat[i].alpha = /*randomf()*/0.75;
		bardat[i].fx = bardat[i].x;
		bardat[i].fy = bardat[i].y;
		bardat[i].vx = randomf()*(rand()%2?1.0:-1.0);
		bardat[i].vy = randomf()*(rand()%2?1.0:-1.0);
	}
}
void deal(color_t bkcol=0) {
	for (int n = 0; n < barN; ++n)
		for (int i = 0; i < bardat[n].bw; ++i)
			for (int j = 0; j < bardat[n].bh; ++j) {
				bardat[n].tmpbuf[i][j] = colmix(bardat[n].mixedcol,scrbuf[i*w/bardat[n].bw][j*h/bardat[n].bh],bardat[n].alpha);
			}
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < h; ++j)
			scrbuf[i][j] = bkcol;
	for (int n = 0; n < barN; ++n)
		for (int i = 0; i < bardat[n].bw; ++i)
			for (int j = 0; j < bardat[n].bh; ++j) {
				/*  double rotx = bardat[n].x+(double)i*bardat[n].cosr+(double)j*bardat[n].sinr;
					double roty = bardat[n].y-(double)i*bardat[n].sinr+(double)j*bardat[n].cosr;
					if (rotx >= 0&&roty >= 0&&rotx < w&&roty < h)
						scrbuf[(int)rotx][(int)roty] = colmix(scrbuf[(int)rotx][(int)roty],bardat[n].tmpbuf[i][j],bardat[n].alpha);
					//scrbuf[i+bardat[n].x][j+bardat[n].y] = colmix(scrbuf[i+bardat[n].x][j+bardat[n].y],bardat[n].tmpbuf[i][j],bardat[n].alpha);
					*/ //顺向思维 就是根据输入推出输出 缺点是损失某像素

				double rotx = (double)i*bardat[n].cosr+(double)j*bardat[n].sinr;
				double roty = -(double)i*bardat[n].sinr+(double)j*bardat[n].cosr;
				if (rotx >= 0&&roty >= 0&&rotx < bardat[n].bw&&roty < bardat[n].bh)
					scrbuf[i+bardat[n].x][j+bardat[n].y] = colmix(scrbuf[i+bardat[n].x][j+bardat[n].y],bardat[n].tmpbuf[(int)rotx][(int)roty],bardat[n].alpha);
				//逆向思维 损失块
			}
}
void updata() {
	for (int i = 0; i < barN; ++i) {
		bardat[i].fx += bardat[i].vx;
		bardat[i].fy += bardat[i].vy;
		if (bardat[i].fx<=10.0||bardat[i].fx+(double)bardat[i].bw>=(double)w-10.0)bardat[i].vx = -bardat[i].vx,bardat[i].fx+=bardat[i].vx*2;
		if (bardat[i].fy<=10.0||bardat[i].fy+(double)bardat[i].bh>=(double)h-10.0)bardat[i].vy = -bardat[i].vy,bardat[i].fy+=bardat[i].vy*2;
		bardat[i].x = bardat[i].fx;
		bardat[i].y = bardat[i].fy;
	}
}
void print() {
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < h; ++j)
			buf[i+j*w] = scrbuf[i][j];
}
int main() {
	srand(time(NULL));
	setinitmode (2);
	initgraph(w,h);
	setfont(16,8,"FIXEDSYS");
	buf = getbuffer((PIMAGE)NULL);
	init(0);
	for (;; delay_fps(60)) {
		deal(0);
		updata();
		// print();
		setcolor (0x00ff00);/*
		for (int i = 0; i < barN; ++i) {
			line (bardat[i].x,bardat[i].y,bardat[i].x+bardat[i].bw,bardat[i].y);
			line (bardat[i].x,bardat[i].y,bardat[i].x,bardat[i].y+bardat[i].bh);
			line (bardat[i].x+bardat[i].bw,bardat[i].y+bardat[i].bh,bardat[i].x+bardat[i].bw,bardat[i].y);
			line (bardat[i].x+bardat[i].bw,bardat[i].y+bardat[i].bh,bardat[i].x,bardat[i].y+bardat[i].bh);
		}*/
		setcolor (0xffffff);
		xyprintf (0,464,"fps:%.5f",getfps());
	}
}
