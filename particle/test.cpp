#include <graphics.h>
#include <math.h>
#include <cstdio>
#define SCR_WIDTH      1600
#define SCR_HEIGHT     900
#define MAXN 11000
struct Ball {
	float x,y;
	float dx,dy;
	float radius;
	color_t color;
};
Ball ball[MAXN];
char sc[110];
int main() {
	initgraph(SCR_WIDTH, SCR_HEIGHT);
	setrendermode(RENDER_MANUAL);
	float dir = 0.0f;
	float sp = 0.5f;

	for(int i = 0; i != MAXN; ++i){
		ball[i].x = SCR_WIDTH / 2;
		ball[i].y = SCR_HEIGHT / 2;
		randomize();
		sp += 0.01f;
		ball[i].dx = sp * cosf(dir);
		ball[i].dy = sp * sinf(dir);
		ball[i].radius = randomf() * 5 + 2;
		ball[i].color = EGERGB(random(128),random(128),random(128));
		dir += 0.1f;
	}

	int n = 1;
	double t = fclock();
	for(; is_run(); delay_fps(60)) {
		cleardevice();
		if (kbhit()) {
			if (getch() == 27)
				break;
			n += 63;
			n %= MAXN;
		}

		setcolor(WHITE);
		sprintf(sc,"n=%5d fps=%f",n,getfps());
		outtextxy(0,0,sc);


		if(fclock() - t > 0.2) {
			t = fclock();
			if (n < MAXN) ++n;
		}
		for(int i = 0; i != n; ++i) {
			setfillcolor(ball[i].color);
			setcolor(ball[i].color);
			fillellipse(ball[i].x,ball[i].y,ball[i].radius,ball[i].radius);
			ball[i].x += ball[i].dx;
			ball[i].y += ball[i].dy;
			if(ball[i].x < 0.0f || ball[i].x > SCR_WIDTH) ball[i].dx = -ball[i].dx;
			if(ball[i].y < 0.0f || ball[i].y > SCR_HEIGHT) ball[i].dy = -ball[i].dy;
		}
	}
	closegraph();
	return 0;
}