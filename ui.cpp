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

//paint ��ͼ
void paint() 
{
	TCHAR path[100];//·��ģ��
	IMAGE img;//����һ�����ͼƬ���ڴ�ռ�
	setfillcolor(0xFF55FF);//0x
	loadimage(NULL, _T(".\\images\\back.png"));
	for (int l = 0; l < 8; l++) {
		for (int r = 0; r < 8; r++) {
			//type = rand() % 7;
				_stprintf(path, L".\\images\\%d\\%d.png", types[l][r], t);//����·��
				loadimage(&img, path);//����ͼƬ���ڴ�ռ�
				putimage(200 + 52 * r, 10 + 52 * l, &img);//���ڴ�ռ������Ƭ�ŵ�xy��λ����
		}
	}
	fillrectangle(243, 449, 243 + w, 449 + 15);
}