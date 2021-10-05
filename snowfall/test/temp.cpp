#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<graphics.h>
#define bk EGERGB(150,233,233)
const int mX=1280,mY=720;
PIMAGE cache,res;
PIMAGE resize_g(const PIMAGE &src,int dstx,int dsty){
	if(res==NULL)
		res=newimage();
	cache=newimage(dstx,dsty);
	int srcx=getwidth(src),srcy=getheight(src);
	putimage(cache,0,0,dstx,dsty,src,0,0,srcx,srcy);
	// putimage(0,0,cache);
	// printf("#%d %d\n",getwidth(cache),getheight(cache));
	// getch();
	getimage(res,cache,0,0,dstx,dsty);
	// printf(">%d %d\n",getwidth(res),getheight(res));
	delimage(cache);
	return res;
}
int main(){
	initgraph(mX,mY);
	PIMAGE bg=newimage();
	getimage(bg,"bg.jpg");
	bg=resize_g(bg,mX,mY);
	putimage(0,0,bg);

	PIMAGE tmp=newimage();
	int x=0,y=300;
	setfillcolor(RED);
	for(;is_run();++x){
		getimage(tmp,bg,x,y,20,20);
		bar(x,y,x+20,y+20);
		printf("%d %d\n",getwidth(tmp),getheight(tmp));
		delay_fps(60);
		putimage(x,y,tmp);
	}	
	return 0;
	srand(time(0));
	initgraph(mX,mY);
	setbkcolor(bk);
	PIMAGE img=newimage();
	getimage(img,"snow.png");
	for(int i=1;i<=3000000;++i){
		printf("%d\n",i);
		PIMAGE img2=resize_g(img,10,10);
		// printf("%d %d\n",getwidth(img2),getheight(img2));
		// putimage(0,0,img2);
		putimage_transparent(NULL,img2,rand()%mX,rand()%mY,BLACK);
	}
	return 0;
}
