#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<graphics.h>

int main(){
    initgraph(1280,720);
    setbkcolor(EGERGB(0x00,0x5C,0x6F));
    
    setcolor(RED);
    setfillcolor(EGERGB(0x8F,0,0x8F));
    for(int i=0;i<=44;++i){
        circle(i*32,300,150);
        floodfill(i*32,300,RED);
        Sleep(500);
        cleardevice();
    }

    getch();
    return 0;
}