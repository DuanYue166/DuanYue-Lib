#include<cstdio>
#include<graphics.h>

int main(){
    initgraph(1280,720);
    setbkcolor(EGERGB(0,0x5C,0x6F));
    int T=0;
    while(++T){
        printf("T=%d\n",T);
        key_msg a=getkey();
        if(a.key==key_esc)
            break;
        printf("\t%d %d %d\n",a.key,a.msg,a.flags);
    }
    getch();
    return 0;
}