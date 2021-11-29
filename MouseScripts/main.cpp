#include<windows.h>
#include<winuser.h>
#define VK_ESC 27
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 

int main(){
	// ShowWindow(GetConsoleWindow(),SW_MINIMIZE);
	while(1){
		if(KEY_DOWN(VK_ESC))
			return 0;
		SetCursorPos(180,400);
		Sleep(1000);
		mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
		Sleep(2000);
		SetCursorPos(760,400);
		Sleep(1000);
		mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
		Sleep(2000);
	}
}