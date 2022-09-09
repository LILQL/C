#pragma once
#include <stdio.h>
#include <graphics.h> //图形界面库头文件
#include <math.h>     //计算圆形的轨迹坐标
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//#include 包含头文件
//#pragma comment（lib."文件名称"）  包含库文件

constexpr auto WND_WIDTH = 1000;
constexpr auto WND_HEIGHT = 600;
constexpr auto PI = 3.141592653589793238;
constexpr auto NUM = 14;

/***********结构****************/
struct JET //烟花弹
{
    int x, y;     //发射点坐标
    int hx, hy;   //最高点坐标  爆炸坐标
    int height;   //高度  最高点y 发射点y的差值
    bool isshoot; //是否发射状态

    DWORD t1, t2, dt; //保存时间  时间可以用来描述发射速度
    IMAGE img[2];     //保存烟花一明一暗的图片
    byte n : 1;       //保存烟花弹的明暗状态  位段
                      //字节为单位 int 4 char 1 n一个位 0-1
} jet[NUM];           //结构体数组13  img这个数组

struct FIRE
{
    int r;
    int max_r;
    int x, y;
    int cen_x, cen_y;
    int width, height;
    int xy[240][240];
    bool show;
    bool draw;
    DWORD t1, t2, dt;
} fire[NUM];

void welcome();
void init(int i);
void loadimages();
void choice(DWORD &t1);
void shoot();
void Show(DWORD *pMem);
void clss(int a);
void delay(int a);
void detabase(int a);
int main()
{
    // res 1.wav
    PlaySound(L"sound.dll", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
    // mp3播放
    // mciSendString(L"open 1.mp3 alias bkmusic", NULL, 0, NULL);
    // mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
    int a;
    for (a = 0; a < 5; a++)
    {
        detabase(a);
        delay(100000);
        clss(1);
    }
    delay(500000);
    initgraph(WND_WIDTH, WND_HEIGHT); // init初始化  graph图形界面 窗口
    srand((unsigned int)time(NULL));
    DWORD t1 = timeGetTime();
    DWORD *pMem = GetImageBuffer();
    //第一个界面
    welcome();

    //初始化
    for (int i = 0; i < NUM; i++)
    {
        init(i);
    }

    loadimages();
    BeginBatchDraw();
    while (!_kbhit())
    {
        // Sleep(10);
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                int px1 = rand() % 1000;
                int py1 = rand() % 600;

                if (py1 < 599)
                {
                    pMem[py1 * 1000 + px1] = pMem[py1 * 1000 + px1 + 1] = BLACK;
                }
            }
        }
        choice(t1);
        shoot();
        Show(pMem);
        EndBatchDraw();
    }
    return 0;
}

void welcome()
{
    settextcolor(YELLOW);

    for (int i = 0; i < 50; i++)
    {
        //圆心（500,300） 半径150  60个均匀点的x,y
        int x = 500 + int(150 * sin(PI * 2 * i / 60));
        int y = 300 + int(150 * cos(PI * 2 * i / 60));
        cleardevice();
        settextstyle(i, 0, L"微软雅黑");
        outtextxy(x - 100, y - 150, L"测试使用1234567890"); //在指定的位置去输出字符
        outtextxy(x, y - 100, L"测试1234567890");
        Sleep(25);
    }

    //_getch();   //接收字符 不回显 直接接收
    Sleep(2000);
    cleardevice();
    settextstyle(25, 0, L"宋体");
    outtextxy(400, 150, L"1，");
    outtextxy(400, 200, L"2");
    outtextxy(400, 250, L"3，");
    outtextxy(400, 300, L"4，");
    outtextxy(400, 350, L"5");
    outtextxy(560, 400, L"---6");

    Sleep(3000);
    //_getch();
}

void init(int i)
{
    int r[14] = {120, 120, 155, 123, 130, 147, 138, 138, 130, 135, 140, 132, 155, 160};
    int x[14] = {120, 120, 110, 117, 110, 93, 102, 102, 110, 105, 100, 108, 110, 132};
    int y[14] = {120, 120, 85, 118, 120, 105, 103, 110, 110, 120, 1201, 04, 85, 145};

    fire[i].x = 0;
    fire[i].y = 0;
    fire[i].width = 240;
    fire[i].height = 240;
    fire[i].max_r = r[i];
    fire[i].cen_x = x[i];
    fire[i].cen_y = y[i];
    fire[i].show = false;
    fire[i].dt = 5;
    fire[i].t1 = timeGetTime();
    fire[i].r = 0;

    //初始化  烟花弹
    jet[i].x = 0;
    jet[i].y = 0;
    jet[i].hx = 0;
    jet[i].hy = 0;
    jet[i].height = 0;
    jet[i].t1 = timeGetTime(); //获取系统时间
    jet[i].dt = rand() % 10;   // 0-9的随机时间
    jet[i].n = 0;
    jet[i].isshoot = false;
}

void loadimages()
{
    IMAGE fm, gm;
    loadimage(&fm, L"flower.dll", 3120, 240);
    for (int i = 0; i < NUM; i++)
    {
        SetWorkingImage(&fm);
        getimage(&gm, i * 240, 0, 240, 240);
        SetWorkingImage(&gm);

        for (int a = 0; a < 240; a++)
        {
            for (int b = 0; b < 240; b++)
            {
                fire[i].xy[a][b] = getpixel(a, b);
            }
        }
    }

    IMAGE jetimg;
    loadimage(&jetimg, L"shoot.dll", 200, 50);

    // set设置 working正在工作的 image图片
    SetWorkingImage(&jetimg);

    for (int i = 0; i < NUM; i++)
    {
        int n = rand() % 5; // 0-4的随机数

        getimage(&jet[i].img[0], n * 20, 0, 20, 50);
        getimage(&jet[i].img[1], (n + 5) * 20, 0, 20, 50);
    }
    SetWorkingImage(NULL);
}

void choice(DWORD &t1)
{
    DWORD t2 = timeGetTime();

    if (t2 - t1 > 2) // 2ms产生一个烟花弹
    {
        int n = rand() % 200; // 0-199
        if (n < NUM && jet[n].isshoot == false && fire[n].show == false)
        {
            //重置烟花弹
            jet[n].x = rand() % (WND_WIDTH - 20);
            jet[n].y = rand() % 100 + 400; // 450-549
            jet[n].hx = jet[n].x;
            jet[n].hy = rand() % 400; // 0-399
            jet[n].height = jet[n].y - jet[n].hy;
            jet[n].isshoot = true;
            // n
            putimage(jet[n].x, jet[n].y, &jet[n].img[jet[n].n]);
        }
        t1 = t2;
    }
}

void shoot()
{
    for (int i = 0; i < NUM; i++)
    {
        jet[i].t2 = timeGetTime();
        if (jet[i].t2 - jet[i].t1 > jet[i].dt && jet[i].isshoot == true)
        {
            putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n]);

            if (jet[i].hy < jet[i].y)
            {
                jet[i].n++; // 0-1  明暗交替
                jet[i].y -= 5;
            }
            putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n]);

            if (jet[i].y <= jet[i].hy)
            {
                fire[i].y = jet[i].hy;
                fire[i].x = jet[i].hx;
                fire[i].show = true;
                jet[i].isshoot = false;
            }
            jet[i].t1 = jet[i].t2;
        }
    }
}

void Show(DWORD *pMem)
{
    int drt[16] = {5, 5, 5, 5, 5, 6, 25, 25, 25, 25, 25, 55, 55, 55, 55, 55}; // dt

    for (int i = 0; i < NUM; i++)
    {
        fire[i].t2 = timeGetTime();

        if (fire[i].t2 - fire[i].t1 > fire[i].dt && fire[i].show == true)
        {
            if (fire[i].r < fire[i].max_r)
            {
                fire[i].r++;
                fire[i].dt = drt[fire[i].r / 10];
                fire[i].draw = true;
            }

            if (fire[i].r >= fire[i].max_r - 1)
            {
                fire[i].draw = false;
                init(i);
            }
            fire[i].t1 = fire[i].t2;
        }

        if (fire[i].draw)
        {
            for (double a = 0; a <= 6.28; a += 0.01)
            {
                int x1 = (int)(fire[i].cen_x + fire[i].r * cos(a));
                int y1 = (int)(fire[i].cen_y + fire[i].r * sin(a));

                if (x1 > 0 && x1 < fire[i].width && y1 > 0 && y1 < fire[i].height)
                {
                    int b = fire[i].xy[x1][y1] & 0xff;
                    int g = (fire[i].xy[x1][y1] >> 8) & 0xff;
                    int r = (fire[i].xy[x1][y1] >> 16);
                    int xx = (int)(fire[i].x + fire[i].r * cos(a));
                    int yy = (int)(fire[i].y + fire[i].r * sin(a));

                    if (r > 0x20 && g > 0x20 && b > 0x20 && xx > 0 && xx < 1000 && yy < 600 && yy > 0)
                    {
                        pMem[yy * 1000 + xx] = BGR(fire[i].xy[x1][y1]);
                    }
                }
            }
            fire[i].draw = true;
        }
    }
}
void clss(int a)
{
    system("cls");
}
void delay(int a)
{
    while (a)
    {
        a--;
    }
}
void detabase(int a)
{
    switch (a)
    {
    case 1:
    {
        // printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("            ■■                            ■■  \n");
        printf("            ■■              ■■■■■■■■■■\n");
        printf("            ■■■            ■■■■■■■■    \n");
        printf("  ■■■■■■■■■■■■    ■■                \n");
        printf("  ■■■■■■■■■■■■    ■■                \n");
        printf("                  ■          ■■                \n");
        printf("      ■■        ■■        ■■                \n");
        printf("      ■■        ■■        ■■                \n");
        printf("      ■■      ■■          ■■                \n");
        printf("■■■■■■■■■■■■■    ■■■■■■■■■■\n");
        printf("■■■■■■■■■■■■■■  ■■■■■■■■■■\n");
        printf("            ■■              ■■        ■■    \n");
        printf("            ■■              ■■        ■■    \n");
        printf("  ■■■■■■■■■■■■    ■■        ■■    \n");
        printf("  ■■■■■■■■■■■■    ■■        ■■    \n");
        printf("            ■■              ■■        ■■    \n");
        printf("      ■    ■■    ■        ■■        ■■    \n");
        printf("    ■■■  ■■  ■■      ■■          ■■    \n");
        printf("    ■■    ■■    ■■    ■■          ■■    \n");
        printf("  ■■      ■■    ■■■  ■■          ■■    \n");
        printf("■■■      ■■      ■    ■■          ■■    \n");
        printf("■■        ■■          ■■            ■■    \n");
        printf("        ■■■■        ■■■            ■■    \n");
        printf("        ■■■■          ■              ■■    \n");
    }
    break;
    case 2:
    {
        // printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("            ■■■                              \n");
        printf("            ■■■                              \n");
        printf("            ■■                                \n");
        printf("          ■■■                                \n");
        printf("        ■■■■■■■■■■■■■■■■■■■  \n");
        printf("        ■■■          ■■■              ■  \n");
        printf("      ■■■              ■■                  \n");
        printf("    ■■■                ■■                  \n");
        printf("  ■■■■                ■■                  \n");
        printf("■■■■                  ■■                  \n");
        printf("  ■■    ■■■■■■■■■■■■■■■■■    \n");
        printf("          ■■■■■■■■■■■■■■■■■    \n");
        printf("          ■■            ■■                  \n");
        printf("          ■■            ■■                  \n");
        printf("          ■■            ■■                  \n");
        printf("          ■■            ■■                  \n");
        printf("          ■■            ■■                  \n");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("                          ■■                  \n");
        printf("                          ■■                  \n");
        printf("                          ■■                  \n");
        printf("                          ■■                  \n");
        printf("                          ■■                  \n");
        printf("                          ■■                  \n");
        printf("                          ■■                  \n");
    }
    break;
    case 3:
    {
        // printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("        ■■                  ■■                \n");
        printf("        ■■                  ■■                \n");
        printf("        ■■                  ■■                \n");
        printf("        ■■                  ■■                \n");
        printf("        ■■          ■■■■■■■■■■■      \n");
        printf("        ■■          ■■■■■■■■■■■■    \n");
        printf("  ■■  ■■  ■■            ■■      ■■      \n");
        printf("  ■■  ■■    ■■          ■■      ■■      \n");
        printf("■■    ■■    ■■          ■■      ■■      \n");
        printf("■■    ■■    ■■■        ■■      ■■      \n");
        printf("■■    ■■                  ■■      ■■      \n");
        printf("■■    ■■                  ■■      ■■      \n");
        printf("■■    ■■                  ■■      ■■■    \n");
        printf("        ■■      ■■■■■■■■■■■■■■■■\n");
        printf("        ■■      ■■■■■■■■■        ■■■\n");
        printf("        ■■                  ■■■              \n");
        printf("        ■■                ■■■■              \n");
        printf("        ■■                ■■  ■■            \n");
        printf("        ■■              ■■    ■■            \n");
        printf("        ■■              ■■      ■■          \n");
        printf("        ■■            ■■        ■■■        \n");
        printf("        ■■          ■■■          ■■■      \n");
        printf("        ■■        ■■■              ■■■■  \n");
        printf("        ■■      ■■■■                ■■■■\n");
        printf("        ■■      ■■■                    ■■  \n");
        printf("        ■■        ■                            \n");
    }
    break;
    case 4:
    {
        //不用                                             不用
        // printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("                                    ■■          \n");
        printf("        ■■  ■■■■■■■■■■■■■■        \n");
        printf("      ■■■■■■■■■■■■■■■■■■■      \n");
        printf("      ■■■                                      \n");
        printf("      ■■                                        \n");
        printf("      ■■              ■■                      \n");
        printf("      ■■              ■■                      \n");
        printf("      ■■              ■■                      \n");
        printf("      ■■              ■■                      \n");
        printf("    ■■■              ■■                      \n");
        printf("    ■■■              ■■                      \n");
        printf("    ■■■■■■■■■■■■■■■■■■■■■    \n");
        printf("    ■■■■            ■■■              ■    \n");
        printf("                        ■■                      \n");
        printf("                        ■■                      \n");
        printf("            ■          ■■                      \n");
        printf("          ■■■■      ■■      ■■■          \n");
        printf("          ■■■        ■■      ■■■■        \n");
        printf("        ■■■          ■■        ■■■■      \n");
        printf("      ■■■            ■■          ■■■■    \n");
        printf("    ■■■              ■■            ■■■■  \n");
        printf("  ■■■                ■■                      \n");
        printf("  ■■■                ■■                      \n");
        printf("                  ■■■■■                      \n");
        printf("                    ■■■■                      \n");
        printf("                    ■■                          \n");
    }
    break;
    case 5:
    {
        printf("happy spring festival!");
    }
    break;
    }
}
