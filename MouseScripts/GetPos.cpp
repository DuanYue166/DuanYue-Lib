#include<windows.h>
#include<winuser.h>
#include<cstdio>

int main(){
	POINT lp;
	while(1){
		GetCursorPos(&lp);
		printf("\r%4d %4d",lp.x,lp.y);

	}
}