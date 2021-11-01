#include<graphics.h>
extern const int FPS;		//frame per second
extern const double ppm;	//pixel per meter
extern const int mX,mY;
class Ball{
private:
	double x,y;			//current coords
	double rad;			//radium. m
	double vx,vy;		//velocity. m/s
	color_t color;
public:
	Ball(){}
	Ball(double x,double y,double rad,color_t color=BLACK)
		:x(x),y(y),rad(rad),vx(0),vy(0),color(color){}
	void update();	//for gravity
	void draw();
	double get_x()const{return x;}
	double get_y()const{return y;}
	void random_pos(){x=random(mX),y=random(mY);}
	void random_v(double mv){vx=randomf()*mv,vy=randomf()*mv;}
	void set_v(double vx_,double vy_){vx=vx_,vy=vy_;};
	void inc_v(double dvx,double dvy){vx+=dvx,vy+=dvy;}		//v increase
};
void Ball::update(){	//next frame
	static double dx,dy;
	dx=vx/FPS*ppm,dy=vy/FPS*ppm;
	if(x+dx>mX || x+dx<0)
		dx=-dx,vx=-vx;
	if(y+dy>mY || y+dy<0)
		dy=-dy,vy=-vy;
	x+=dx,y+=dy;
}
void Ball::draw(){
	setcolor(color);
	setfillcolor(color);
	fillellipsef(x,y,rad*ppm,rad*ppm);
}