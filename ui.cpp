#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
int t = 0,type;
int types[8][8];
int w = 0;
void paint();
void Chuli();
void init();
int main()
{
	initgraph(640,480);
	init();
	srand((unsigned int)time(NULL));
	while (1)
	{
		Chuli();
		BeginBatchDraw();
		paint();
		EndBatchDraw();
		Sleep(20);
	}

	_getch();
	return 0;
} 
void init()
	{
		for (int h = 0; h < 8; h++)
		{
			for (int l = 0; l < 8; l++)
			{
				types[h][l] = rand() % 7;
			}
		}
	}
void Chuli() {
	
		if (t == 14) {
			t = 0;
		}
		else
		{
			t++;
		}
		if (w < 330)
		{
			w += 5;
		}
	}

//paint 绘图
void paint() 
{
	TCHAR path[100];//路径模块
	IMAGE img;//申请一个存放图片的内存空间
	setfillcolor(0xFF55FF);//0x
	loadimage(NULL, _T(".\\images\\back.png"));
	for (int l = 0; l < 8; l++) {
		for (int r = 0; r < 8; r++) {
			//type = rand() % 7;
				_stprintf(path, L".\\images\\%d\\%d.png", types[l][r], t);//产生路径
				loadimage(&img, path);//加载图片到内存空间
				putimage(200 + 52 * r, 10 + 52 * l, &img);//把内存空间里的照片放到xy的位置上
		}
	}
	fillrectangle(243, 449, 243 + w, 449 + 15);
}