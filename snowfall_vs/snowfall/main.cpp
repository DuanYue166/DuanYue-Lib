#include<cmath>
#include<ctime>
#include<math.h>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<graphics.h>
#include<windows.h>
#include<shellapi.h>
#include<iostream>
using namespace std;
#define bgc EGERGB(150,233,233)

const int mX = 1280, mY = 720;
const int numPa = 70;
/*
struct _initgraph
{
	 _initgraph()
	 {
		 initgraph(mX,mY);
		 setinitmode(1,0,0);
	 }
	 ~_initgraph()
	 {
		 closegraph();
	 }
}g_initgraph;
*/
PIMAGE obj, bg, tmp;
void resize_g(PIMAGE& dst, const PIMAGE src, int dstx, int dsty) {
	static PIMAGE cache;
	static int srcx, srcy;
	srcx = getwidth(src);
	srcy = getheight(src);
	cache = newimage(dstx, dsty);
	putimage(cache, 0, 0, dstx, dsty, src, 0, 0, srcx, srcy);
	if (dst != NULL)
		delimage(dst);
	dst = newimage();
	getimage(dst, cache, 0, 0, dstx, dsty);
	delimage(cache);
}

double randf() {
	return (double)(rand() * rand() % 1000000) / 1000000.0;
}
double rand(double l, double r) {
	return l + (r - l) * randf();
}
struct part {
	int t;				//time
	int ox, oy;			//original coords
	int x, y, rad;		//final coords,radius
	double dx, dy;		//delta
	double vel, omg;		//velocity,omiga
	int amp;			//amplitude
	PIMAGE ocu;
	bool update() {
		++t;
		dx = amp * sin(omg * t);
		dy = vel * t;
		x = ox + dx;
		y = oy + dy;
		if (y > mY)
			return false;
		return true;
	}
	void draw() {
		/***
		*ball
			setcolor(RED);
			setfillcolor(RED);
			fillellipse(x,y,rad,rad);
		****/
		getimage(ocu, bg, x, y, rad, rad);
		resize_g(tmp, obj, rad, rad);
		putimage_transparent(NULL, tmp, x, y, BLACK);
	}
	void rand_new() {
		t = 0;
		ox = rand() % mX, oy = 0;
		x = ox, y = oy;
		rad = rand() % 10 + 2;
		dx = dy = 0;
		vel = rand(5 / 60.0, 100 / 60.0);
		omg = rand(1 * PI / 60, 2 * PI / 60);
		amp = rand() % 15 + 1;
		if (ocu == NULL)
			ocu = newimage();
	}
	void reset() {
		putimage(x, y, ocu);
	}
	void print() {
		printf("t=%d ox=%d oy=%d\n", t, ox, oy);
		printf("x=%d y=%d rad=%d\n", x, y, rad);
		printf("vel=%.2lf omg=%.2lf amp=%d\n", vel, omg, amp);
	}
}vec[numPa];
void init_bg() {
	bg = newimage(mX, mY);
	getimage(bg, "bg.jpg");
	resize_g(bg, bg, mX, mY);
	putimage(0, 0, bg);
}
void flush() {
	for (int i = 0; i < numPa; ++i)
		vec[i].reset();

	static int t, num;
	static char name[33];
	if ((++t) % 300 == 0) {
		sprintf_s(name, "pics\\bg_%d.jpg", ++num);
		if (bg == NULL)
			bg = newimage();
		getimage(bg, name);
		resize_g(bg, bg, mX, mY);
		putimage(0, 0, bg);
	}
	/*
		static int t;
		if((t++)%300==0){
			SHELLEXECUTEINFO cmd={};
			cmd.cbSize=sizeof(cmd);
			cmd.fMask=SEE_MASK_NOCLOSEPROCESS;
			cmd.lpVerb=L"python";
			cmd.lpFile=L"pics_crawler.py";
			cmd.nShow=SW_SHOWDEFAULT;
			ShellExecuteEx(&cmd);
			init_bg();
		}
	*/
}
void draw() {
	for (int i = 0; i < numPa; ++i) {
		if (!vec[i].update())
			vec[i].rand_new();
		vec[i].draw();
	}
}
void print_fps() {
	static char sc[20];
	sprintf_s(sc, "fps:%.1lf", getfps());
	outtextxy(0, 0, sc);
}
bool detect_esc() {
	static key_msg k;
	if (kbmsg())
		k = getkey();
	return k.key == key_esc;
}
int main() {
	srand(time(0));
	// setinitmode(1);
	initgraph(mX, mY);
	setbkcolor(bgc);
	setrendermode(RENDER_MANUAL);
	obj = newimage();
	getimage(obj, "snow.png");
	for (int i = 0; i < numPa; ++i)
		vec[i].rand_new();

	init_bg();
	for (; is_run() && !detect_esc(); delay_fps(60), flush()) {
		print_fps();
		draw();
	}
	closegraph();
	return 0;
}