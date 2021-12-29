#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<graphics.h>

/*��Ϸ�������*/
void gamePaint();
/*��Ϸ��ʼ������*/
void gameInit();
/*��Ϸ��ʱ����*/
void gameInterval();
/*��Ϸ���̰���*/
void gameKeypress(int key);
/*��Ϸ��갴��*/
void gameMouseDown(int mouseX,int mouseY);
/*��Ϸ����Ҽ�����*/
void gameMouseRightDown(int mouseX,int mouseY);
/*��Ϸ���̧��*/
void gameMouseUp(int mouseX,int mouseY);
/*��Ϸ����ƶ�*/
void gameMousemove(int mouseX,int mouseY);

/*
��͸����ͼ�Ļ���
xΪҪ����ͼƬ��X���꣬yΪY����
*/
void drawImage(int  picture_x, int picture_y,IMAGE* picture);  
/*����������ײ���
�����������Ƿ��ཻ��
 x1, y1, w1�� h1�ǵ�һ�����ε�xy��ߵ��ĸ�����
 x2, y2, w2�� h2�ǵڶ������ε�xy��ߵ��ĸ�����
 ����0�����ཻ ����1�����ཻ
*/
int testHit(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 );

/*����100��ÿ��100����ˢ�����½����ͼ��*/
int interval = 20;//TODO: 1 ���ö�ʱ��ʱ��������λ���룩
// TODO: 1 ���ô���: ��� �߶�
int screenWidth = 640;
int screenHeight=480;
int stop = 0;//�Ƿ�ֹͣ��Ϸ
//-----------------------------------//
int times = 0; 
/*��ʼ����Ϸ */
void initgame()
{
	srand((unsigned)time(NULL));//�������ʼ��
	setbkcolor(NULL);//����ɫ
	setbkmode(TRANSPARENT);// ���ñ������ģʽ: TRANSPARENTΪ͸��
	gameInit();
}
/*
	�����ͼ��ʾ����
*/
void paintDemo()
{
	/* ��ɫ���ã�
	//�����ߵ���ɫ     Blue Green Red  ʮ�����Ʊ�ʾ��ԭɫ
	setlinecolor(0x0000ff);//��ɫ�� ��
	//-����������ɫ
	setfillcolor(0x00ff00);//��ɫ�� ���
	//-�����������ɫ
	settextcolor(0xff0000);//��ɫ�� ������ɫ
	*/


	/*  ��ֱ�ߵİ���

		setlinestyle(PS_DASH, ��ϸ); //PS_DASH ����  PS_SOLID ʵ�� PS_DOT ����...
		line(��1x���� ,��1y����,��2x���� ,��2y����); //����ȷ��һ��ֱ��
		���磺
	
	setlinestyle(PS_DASH, 3);
	line(50 ,50,300 ,200); 
	*/


	/*
	  ���ƾ���
	  1.���ľ���
	  rectangle( ����x,����y,���µ�x,���µ��y);
	  ����� �� �߶ȼ���Ϊ
	  rectangle( ����x,����y,����x+���,����y+�߶�);
	  rectangle(x,y,x+width,y+height);
	  2.ʵ�ľ��Σ��ޱ߿�
	  solidrectangle( ����x,����y,����x+���,����y+�߶�); 
	  3.ʵ�ľ��Σ��б߿�
	  fillrectangle( ����x,����y,����x+���,����y+�߶�); 
	  ���磺 ����һ����50 ��50 ��������
	
		rectangle( 100,100,100+50,100+50);
		fillrectangle( 100,100,100+50,100+50);
	*/
	

	/*
	  ����Բ��
	  1������Բ
	  circle( Բ��x����,Բ��y����,�뾶);
	  2��ʵ��Բ���ޱ߿�
	  solidcircle( Բ��x����,Բ��y����,�뾶);
	  3��ʵ��Բ���б߿�
	  fillcircle( Բ��x����,Բ��y����,�뾶);
	  ���磺 
	  
		circle( 75,75,50);
		fillcircle( 75,75,50);
	*/


	/*
	 ��������
	 1������������ʽ
	 settextstyle(�ָ�, 0, _T("��������"));
	 2����������λ��������
	 outtextxy(x,y,L"��������");
	 ���磺
	 settextstyle(46, 0, _T("����"));
	 outtextxy(300,400,L"helloworld�������");
	 */


	/*ģ�廯 ��̬����
	TCHAR str[100];
	_stprintf (str, L"%s����ѧ�ɼ���%d", L"С��",61);
	outtextxy(300,400,str );
	*/


	/*��ͼ
	1������һ�����ͼƬ������Ϊ�˽�ʡͼƬ�����ڴ�ռ䣬ͨ������ŵ�ȫ�ֱ���λ�ã�
	IMAGE img1 ; 
	2������Ӳ�̵�ͼƬ��ͼƬ�������ڴ��ַ
	loadimage(&img1, L".\\ͼƬ·��\\ͼƬ�ļ���" ); //.������ĿӲ�̴洢��λ��
	3�����ڴ��е�ͼƬ��ʾ�������ϡ�
	putimage(x,y,&img1); 
	*/


	/*���磺��һ��ͼ 
	//loadimage(&img, L".\\images\\jpg\\1\\image0.jpg") ; //ͼƬ��͸��
	IMAGE img1 ;
	loadimage(&img1, L".\\images\\1\\image0.png") ; 
	putimage(10,10,&img1);*/


	/*���磺����һ��ͼ
	IMAGE img2;
	loadimage(&img2, L".\\images\\2\\image8.png") ; 
	putimage(10,200,&img2); */

	/*���磺ͼƬ·�����仯�Ĵ���
	IMAGE img4;
	TCHAR imgPath[100];
	_stprintf (imgPath, L".\\images\\%d.png",i);
	loadimage(&img4,imgPath ) ;
	putimage(100 ,300,&img4);
	*/

	/*���磺������ͼ��Ҫ����ͬ�ߴ��ͼ
	IMAGE img3;
	TCHAR imgPath[100];
	int i;
	for (i = 0; i <=23; i++)
	{
		_stprintf (imgPath, L".\\images\\%d\\image%d.png", 3,i);
		loadimage(&img3,imgPath ) ; 
		putimage(100*i,300,&img3); 
	}*/
	 
}

/*������ʾ��Ϸ����*/
void paint()
{
	BeginBatchDraw();//��˫����
	cleardevice();// ����
	paintDemo();
	gamePaint();
	//-----------------------------//
	EndBatchDraw();//�ر�˫����
}



/*��Ϸ����*/
void run()
{
	ExMessage mouse ;
	 
	while (1)	// ��Ϸ��ѭ��  �ɽ���break ����ѭ��
	{
		
		if (peekmessage(&mouse,EM_MOUSE,false))
		{
			mouse=getmessage();
			if (mouse.message == WM_LBUTTONDOWN )
			{
				gameMouseDown(mouse.x,mouse.y);
				paint();
				continue;
			}
			else if (mouse.message == WM_LBUTTONUP )
			{
				gameMouseUp(mouse.x,mouse.y);
				paint();
				continue;
			}
			else if(mouse.message == WM_RBUTTONDOWN)
			{
				gameMouseRightDown(mouse.x, mouse.y);
				//paint();
				//continue;
			}
			else if(mouse.message == WM_MOUSEMOVE)
			{
				//gameMousemove(mouse.x,mouse.y);
				//paint();
				//continue;
			}
			
		}

		
		if (_kbhit())
		{
			int k=_getch();
			 
			gameKeypress(k);
			paint();
			continue;
		}

		//------ʱ�䴦�� ��-----------//
		Sleep(1);
		times++;
		if(times%(interval/10)!=0){
			continue;
		}
		times=0;
		if(stop)
		{
			break;
		}
		gameInterval();
		 
		//-------------------------------//
		paint();// ˢ����ʾ��Ϸ����
	}
}



/*����͸������ͼ*/
 void drawImage(int  picture_x, int picture_y,IMAGE* picture  ) //xΪ����ͼƬ��X���꣬yΪY����
{

	// ������ʼ��
	DWORD *dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD *draw = GetImageBuffer(); 
	DWORD *src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x )+ (iy +   picture_y ) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}
//������������Ƿ�����ײ
int testHit(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 )
{
 return !(x1 + w1 < x2||
		 y1 + h1 < y2 ||
		 x2 + w2 <x1 ||
		 y2 + h2<y1 );
}
// ��������������Ϸ
int main  ()
{
	initgraph(screenWidth, screenHeight,SHOWCONSOLE);		
	initgame();					// ��ʼ����Ϸ
	paint();// ˢ����ʾ��Ϸ����
	 
	flushmessage();		// �����껺����
	while (_kbhit()) _getch();	// ��ռ��̻�����
	run();						// ��ʼ��Ϸ
	closegraph();//�ر�ͼ�λ�
	return 0;
}
 

//--------------���ŵľ����� ����Ϊ���� ��רҵ ���------------------// 

//������������
//1 ��Ϸ״̬��ʶ��ö�٣�

typedef enum 
{
	GAME_NORMAL,//����״̬
	SELECT_ONE,//ѡ�˵�һ����ʯ
	SELECT_TWO,//ѡ�˵ڶ�����ʯ
	CLER, //���״̬
	APPEND //׷�Ӳ���
} GAME_STATE;

//2 ��ʯ״̬ö��
typedef enum {
	GEM_NORMAL,//��̬��ʯ
	SELECTED_FIRST,//��ѡΪ��һ����ʯ
	SELECTED_SECOND,//��ѡΪ�ڶ�����ʯ
	TO_CLEAR,//Ҫ������ı�ʯ
	CLEARING//��������еı�ʯ
} GEM_STATE;

//��ʯ�ṹ��
 typedef struct {
	int ImageNum;//ͼƬ�������
	int Type;//��ʯ�����ͺţ�1~7
	GEM_STATE State;//��ʯ��״̬
} GEM;

//TODO: 2 ȫ�ֱ�������λ�� 
int level = 3;//�Ѷȵȼ� ��ʯ����Խ��Խ��
GEM gems[8][8];//���б�ʯ
GEM gemsTemp[8][8];//��ʱ�������ı�ʯ
GAME_STATE gameState;//��Ϸ��ǰ��״̬
int line1, column1;//ѡ��ĵ�һ����ʯ���ڵ��� ��
int line2, column2;//ѡ��ĵڶ�����ʯ���ڵ��� ��
int imageCount = 14 + 1;//����ͼƬ֡��������
int gemsTempTop = 10 - 50 * 2;//��ʯ����ľ���
int score = 0;//�ɼ��÷�
int timeLong = 0;//ʱ��������ĳ���

int t = 0, type;
int types[8][8];
int w = 0;
TCHAR path[100];//·��ģ��
IMAGE img;//����һ�����ͼƬ���ڴ�ռ�
IMAGE imgs[7][15];
//TODO: 3 ��Ϸ��ʼ��λ��  
 void gameInit()
{
	 int a = 10;
	 //��ʯ�ĳ�ʼ��
	 for (int h = 0; h < 8; h++)
	 {
		 for (int l = 0; l < 8; l++)
		 {
			// types[h][l] = rand() % 7;
			 gems[h][l].Type = rand() % level;
			 gemsTemp[h][l].Type = -1;//û�б�ʯ
		 }
	 }
	 //��Ϸ״̬��ʼֵ
	 gameState = GAME_STATE::GAME_NORMAL;
	 line1 = line2 = column1 = column2 = -1;//-1����ѡ���κε��� ��




	 //���ر���ͼƬ
	 loadimage(&img, _T(".\\images\\back.png"));
	 //����
	 for (int l = 0; l < 7; l++) {
		 for (int r = 0; r < 15; r++) {
			 //type = rand() % 7;
			 _stprintf(path, L".\\images\\%d\\%d.png", l,r);//����·��
			 loadimage(&imgs[l][r], path);//����ͼƬ���ڴ�ռ�
		 }
	 }
}
 //TODO: 4 ��ͼ����λ��  
void gamePaint()
{
	setfillcolor(0xFF55FF);//0x
	putimage(0, 0, &img);
	for (int l = 0; l < 8; l++) {
		for (int r = 0; r < 8; r++) 
		{
			if (gems[l][r].State==GEM_NORMAL)
			{
				putimage(200 + r * 52, 10 + l * 52, &imgs[gems[l][r].Type][0]);
			}
			else if (gems[l][r].State == SELECTED_FIRST) 
			{
				putimage(200 + r * 52, 10 + l * 52, &imgs[gems[l][r].Type][gems[l][r].ImageNum]);
				gems[l][r].ImageNum = (gems[l][r].ImageNum + 1) % imageCount;
			}
			
		}
	}
	fillrectangle(243, 449, 243 + w, 449 + 15);
}
 //TODO: 5 ��ʱ����λ��
void gameInterval()
{
	
}
//TODO: 6 ������̿���λ��
void gameKeypress(int key)
{
	switch (key)
	{
	case 'A':
	case 'a':    // ��
				
		break;	
	case 'S':
	case 's':   // ��
				
		break;	
	case 'D':
	case 'd':   // ��
				
		break;	
	case 'W':  // ��
	case 'w':  
		
		break;	

	case 72: //��
		
		break;
	case 80://��
				  
		break;
	case 75://��
		 	 
		break;
	case 77://��
		  	  
		break;
	default://�����
		break;
	}
}

//TODO: 7 ����������λ��
void gameMouseDown(int mouseX,int mouseY)
{
	printf("��갴�������\n");
}
void gameMouseUp(int mouseX,int mouseY)
{
	//printf("����ɿ������\n");
	if (gameState==GAME_STATE::GAME_NORMAL) 
	{
		//�õ���ʯ��������
		line1 = (mouseY - 10) / 52;
		column1 = (mouseX - 200) / 52;
		if (line1 >= 0 && line1 < 8 && column1 >= 0 && column1 < 8//�ж��Ƿ��ڱ�ʯ���ڲ�
			&& gems[line1][column1].State== GEM_STATE::GEM_NORMAL  //��ǰѡ��ı�ʯ�Ƿ��Ǿ�ֹ״̬
			) 
		{
			gems[line1][column1].State = GEM_STATE::SELECTED_FIRST;
		}
	}
	else
	{
		//�ָ� ��ֹ״̬
	}
}
void gameMousemove (int mouseX,int mouseY)
{
	 
}

void gameMouseRightDown(int mouseX,int mouseY)
{
	 
}