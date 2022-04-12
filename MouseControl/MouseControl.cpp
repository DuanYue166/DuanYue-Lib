#include<windows.h>
#include<winuser.h>
#include<cstdio>
constexpr auto VK_ESC = 27;
constexpr auto VK_C = 67;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 

int main() {
	//ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
	ShowWindow(GetConsoleWindow(), SW_NORMAL);
	POINT p;
	while (1) {
		if (KEY_DOWN(VK_ESC))
			return 0;
		GetCursorPos(&p);
		printf("\rnowpos:%4d %4d", p.x, p.y);
		continue;
		Sleep(1000);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(2000);

		if (KEY_DOWN(VK_ESC))
			return 0;
		SetCursorPos(900, 500);
		GetCursorPos(&p);
		printf("\rnowpos:%4d %4d", p.x, p.y);
		Sleep(1000);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(2000);
	}
}