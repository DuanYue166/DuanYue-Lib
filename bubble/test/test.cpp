//用户交互——鼠标2
#include <graphics.h>

#include <stdio.h>

#include<iostream>

int main()
{
	// MUSIC mc1,mc2;
	// mc1.OpenFile("bubble_generate.wav");
	// mc1.Play();
	// delay(500);
	// mc2.OpenFile("bubble_burst.wav");
	// mc2.Play();
	// delay(1000);
	// return 0;
        initgraph(640, 480);

        setrendermode(RENDER_MANUAL); //不使用自动刷新，减少闪烁 

        setfont(18, 0, "宋体");

        mouse_msg msg = {0};
        for ( ; is_run(); delay_fps(60))
        {
                //获取鼠标消息，此函数不会等待，运行后会立即返回
                while (mousemsg())
                {
                        msg = getmouse();
                }

                cleardevice();
                xyprintf(0, 0, "x = %10d  y = %10d",
                        msg.x, msg.y);
                xyprintf(0, 20, "move  = %d down  = %d up    = %d",
                        (int)msg.is_move(),
                        (int)msg.is_down(),
                        (int)msg.is_up());
                xyprintf(0, 40, "left  = %d mid   = %d right = %d",
                        (int)msg.is_left(),
                        (int)msg.is_mid(),
                        (int)msg.is_right());
                xyprintf(0, 60, "wheel = %d  wheel rotate = %d",
                        (int)msg.is_wheel(),
                        msg.wheel);
        }

        closegraph();
        return 0;
}