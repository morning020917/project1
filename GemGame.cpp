#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<graphics.h>

/*游戏界面绘制*/
void gamePaint();
/*游戏初始化绘制*/
void gameInit();
/*游戏定时处理*/
void gameInterval();
/*游戏键盘按下*/
void gameKeypress(int key);
/*游戏鼠标按下*/
void gameMouseDown(int mouseX,int mouseY);
/*游戏鼠标右键按下*/
void gameMouseRightDown(int mouseX,int mouseY);
/*游戏鼠标抬起*/
void gameMouseUp(int mouseX,int mouseY);
/*游戏鼠标移动*/
void gameMousemove(int mouseX,int mouseY);

/*
含透明的图的绘制
x为要载入图片的X坐标，y为Y坐标
*/
void drawImage(int  picture_x, int picture_y,IMAGE* picture);  
/*两个矩形碰撞检测
即两个矩形是否相交。
 x1, y1, w1， h1是第一个矩形的xy宽高的四个参数
 x2, y2, w2， h2是第二个矩形的xy宽高的四个参数
 返回0代表不相交 返回1代表相交
*/
int testHit(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 );

/*设置100即每隔100毫秒刷新以下界面绘图。*/
int interval = 20;//TODO: 1 设置定时器时间间隔（单位毫秒）
// TODO: 1 设置窗口: 宽度 高度
int screenWidth = 640;
int screenHeight=480;
int stop = 0;//是否停止游戏
//-----------------------------------//
int times = 0; 
/*初始化游戏 */
void initgame()
{
	srand((unsigned)time(NULL));//随机数初始化
	setbkcolor(NULL);//背景色
	setbkmode(TRANSPARENT);// 设置背景混合模式: TRANSPARENT为透明
	gameInit();
}
/*
	界面绘图演示案例
*/
void paintDemo()
{
	/* 颜色设置：
	//设置线的颜色     Blue Green Red  十六进制表示三原色
	setlinecolor(0x0000ff);//红色的 线
	//-设置填充的颜色
	setfillcolor(0x00ff00);//绿色的 填充
	//-设置字体的颜色
	settextcolor(0xff0000);//蓝色的 字体颜色
	*/


	/*  画直线的案例

		setlinestyle(PS_DASH, 粗细); //PS_DASH 虚线  PS_SOLID 实现 PS_DOT 点线...
		line(点1x坐标 ,点1y坐标,点2x坐标 ,点2y坐标); //两点确定一条直线
		例如：
	
	setlinestyle(PS_DASH, 3);
	line(50 ,50,300 ,200); 
	*/


	/*
	  绘制矩形
	  1.空心矩形
	  rectangle( 顶点x,顶点y,右下点x,右下点的y);
	  按宽度 和 高度计算为
	  rectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度);
	  rectangle(x,y,x+width,y+height);
	  2.实心矩形（无边框）
	  solidrectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度); 
	  3.实心矩形（有边框）
	  fillrectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度); 
	  例如： 绘制一个宽50 高50 的正方形
	
		rectangle( 100,100,100+50,100+50);
		fillrectangle( 100,100,100+50,100+50);
	*/
	

	/*
	  绘制圆形
	  1、空心圆
	  circle( 圆心x坐标,圆心y坐标,半径);
	  2、实心圆（无边框）
	  solidcircle( 圆心x坐标,圆心y坐标,半径);
	  3、实心圆（有边框）
	  fillcircle( 圆心x坐标,圆心y坐标,半径);
	  例如： 
	  
		circle( 75,75,50);
		fillcircle( 75,75,50);
	*/


	/*
	 绘制文字
	 1、设置字体样式
	 settextstyle(字高, 0, _T("字体名称"));
	 2、设置文字位置与内容
	 outtextxy(x,y,L"文字内容");
	 例如：
	 settextstyle(46, 0, _T("黑体"));
	 outtextxy(300,400,L"helloworld你好世界");
	 */


	/*模板化 动态文字
	TCHAR str[100];
	_stprintf (str, L"%s的数学成绩是%d", L"小明",61);
	outtextxy(300,400,str );
	*/


	/*贴图
	1、声明一个存放图片变量（为了节省图片变量内存空间，通常把其放到全局变量位置）
	IMAGE img1 ; 
	2、加载硬盘的图片到图片变量的内存地址
	loadimage(&img1, L".\\图片路径\\图片文件名" ); //.代表项目硬盘存储的位置
	3、把内存中的图片显示到界面上。
	putimage(x,y,&img1); 
	*/


	/*例如：贴一张图 
	//loadimage(&img, L".\\images\\jpg\\1\\image0.jpg") ; //图片不透明
	IMAGE img1 ;
	loadimage(&img1, L".\\images\\1\\image0.png") ; 
	putimage(10,10,&img1);*/


	/*例如：再贴一张图
	IMAGE img2;
	loadimage(&img2, L".\\images\\2\\image8.png") ; 
	putimage(10,200,&img2); */

	/*例如：图片路径含变化的处理
	IMAGE img4;
	TCHAR imgPath[100];
	_stprintf (imgPath, L".\\images\\%d.png",i);
	loadimage(&img4,imgPath ) ;
	putimage(100 ,300,&img4);
	*/

	/*例如：连续贴图，要求相同尺寸的图
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

/*绘制显示游戏界面*/
void paint()
{
	BeginBatchDraw();//打开双缓冲
	cleardevice();// 清屏
	paintDemo();
	gamePaint();
	//-----------------------------//
	EndBatchDraw();//关闭双缓冲
}



/*游戏运行*/
void run()
{
	ExMessage mouse ;
	 
	while (1)	// 游戏主循环  可借助break 结束循环
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

		//------时间处理 勿动-----------//
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
		paint();// 刷新显示游戏界面
	}
}



/*绘制透明背景图*/
 void drawImage(int  picture_x, int picture_y,IMAGE* picture  ) //x为载入图片的X坐标，y为Y坐标
{

	// 变量初始化
	DWORD *dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD *draw = GetImageBuffer(); 
	DWORD *src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x )+ (iy +   picture_y ) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}
//检测两个矩形是否相碰撞
int testHit(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 )
{
 return !(x1 + w1 < x2||
		 y1 + h1 < y2 ||
		 x2 + w2 <x1 ||
		 y2 + h2<y1 );
}
// 主函数，开启游戏
int main  ()
{
	initgraph(screenWidth, screenHeight,SHOWCONSOLE);		
	initgame();					// 初始化游戏
	paint();// 刷新显示游戏界面
	 
	flushmessage();		// 清空鼠标缓冲区
	while (_kbhit()) _getch();	// 清空键盘缓冲区
	run();						// 开始游戏
	closegraph();//关闭图形环
	return 0;
}
 

//--------------优雅的警戒线 以上为雷区 非专业 勿进------------------// 

//定义数据类型
//1 游戏状态标识（枚举）

typedef enum 
{
	GAME_NORMAL,//正常状态
	SELECT_ONE,//选了第一个宝石
	SELECT_TWO,//选了第二个宝石
	CLER, //清楚状态
	APPEND //追加补齐
} GAME_STATE;

//2 宝石状态枚举
typedef enum {
	GEM_NORMAL,//静态宝石
	SELECTED_FIRST,//被选为第一个宝石
	SELECTED_SECOND,//被选为第二个宝石
	TO_CLEAR,//要被清除的宝石
	CLEARING//清除进行中的宝石
} GEM_STATE;

//宝石结构体
 typedef struct {
	int ImageNum;//图片动画编号
	int Type;//宝石的类型号：1~7
	GEM_STATE State;//宝石的状态
} GEM;
 //TODO: 2 函数的前置声明
 void resetGameNormalState();
 int enableSelectSecond();//能够滑动到第二个宝石
 void swapGem();
 void setLineColumn(int mouseX, int mouseY, int* line, int* column);
 int isInGemRaange();
 int enabledLineClear(int line, int column);
 int  enabledColumnClear(int line, int column);
 void toClear(int line, int column, int type);


//TODO: 2 全局变量声明位置 
int level = 3;//难度等级 宝石种类越少越简单
GEM gems[8][8];//所有宝石
GEM gemsTemp[8][8];//临时存放下落的宝石
GAME_STATE gameState;//游戏当前的状态
int line1, column1;//选择的第一个宝石所在的行 列
int line2, column2;//选择的第二个宝石所在的行 列
int imageCount = 14 + 1;//动画图片帧的总数量
int gemsTempTop = 10 - 50 * 2;//宝石下落的距离
int score = 0;//成绩得分
int timeLong = 0;//时间进度条的长度

int t = 0, type;
int types[8][8];
int w = 0;
TCHAR path[100];//路径模块
IMAGE img;//申请一个存放图片的内存空间
IMAGE imgs[7][15];
//TODO: 3 游戏初始化位置  
 void gameInit()
{
	 int a = 10;
	 //宝石的初始化
	 for (int h = 0; h < 8; h++)
	 {
		 for (int l = 0; l < 8; l++)
		 {
			// types[h][l] = rand() % 7;
			 gems[h][l].Type = rand() % level;
			 gemsTemp[h][l].Type = -1;//没有宝石
		 }
	 }
	 //游戏状态初始值
	 gameState = GAME_STATE::GAME_NORMAL;
	 line1 = line2 = column1 = column2 = -1;//-1代表不选择任何的行 列




	 //加载背景图片
	 loadimage(&img, _T(".\\images\\back.png"));
	 //遍历
	 for (int l = 0; l < 7; l++) {
		 for (int r = 0; r < 15; r++) {
			 //type = rand() % 7;
			 _stprintf(path, L".\\images\\%d\\%d.png", l,r);//产生路径
			 loadimage(&imgs[l][r], path);//加载图片到内存空间
		 }
	 }
}
 //TODO: 4 绘图处理位置  
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
			else if (gems[l][r].State == SELECTED_FIRST || gems[l][r].State == SELECTED_SECOND)
			{
				putimage(200 + r * 52, 10 + l * 52, &imgs[gems[l][r].Type][gems[l][r].ImageNum]);
				gems[l][r].ImageNum = (gems[l][r].ImageNum + 1) % imageCount;
			}
			
		}
	}
	fillrectangle(243, 449, 243 + w, 449 + 15);
}
 //TODO: 5 定时处理位置
void gameInterval()
{
	if (gameState==GAME_STATE::SELECT_TWO
		&& gems[line2][column2].ImageNum==14)
	{
		//被选的宝石回到初始状态
		gems[line1][column1].State = GEM_NORMAL;
		gems[line2][column2].State = GEM_NORMAL;
		if (enabledLineClear(line1,column1)
			|| enabledLineClear(line2,column2)
			|| enabledColumnClear(line1, column1)
			|| enabledColumnClear(line2, column2)
			) 
		{
			gameState = GAME_STATE::CLER;
		}
		else 
		{
			swapGem();
			resetGameNormalState();

		}
	}

	//清除状态
	if (gameState == GAME_STATE::CLER) 
	{
		if (enabledLineClear(line1,column1)||enabledColumnClear(line1, column1)) //宝石1能清除吗？
		{
			toClear( line1,  column1, gems[line1][column1].Type);
		}

		if (enabledLineClear(line2, column2) || enabledColumnClear(line2, column2))//宝石2能清除吗？
		{

		}
	}
}
//TODO: 6 处理键盘控制位置
void gameKeypress(int key)
{
	switch (key)
	{
	case 'A':
	case 'a':    // 左
				
		break;	
	case 'S':
	case 's':   // 下
				
		break;	
	case 'D':
	case 'd':   // 右
				
		break;	
	case 'W':  // 上
	case 'w':  
		
		break;	

	case 72: //上
		
		break;
	case 80://下
				  
		break;
	case 75://左
		 	 
		break;
	case 77://右
		  	  
		break;
	default://任意键
		break;
	}
}

//TODO: 7 处理鼠标控制位置
void gameMouseDown(int mouseX,int mouseY)
{
	//printf("鼠标按下了左键\n");
	if (gameState == GAME_STATE::GAME_NORMAL)
	{
		//得到宝石所在行列
		setLineColumn(mouseX, mouseY, &line1, &column1);
		if (isInGemRaange()//判断是否在宝石阵内部
			&& gems[line1][column1].State == GEM_STATE::GEM_NORMAL  //当前选择的宝石是否是静止状态
			)
		{
			gems[line1][column1].State = GEM_STATE::SELECTED_FIRST;
			gameState = GAME_STATE::SELECT_ONE;
		}
		else
		{
			resetGameNormalState();
		}
	}

	else
	{
		resetGameNormalState();
		//恢复 禁止状态
	}
}
void gameMouseUp(int mouseX,int mouseY)
{
	//printf("鼠标松开了左键\n");
	if (gameState == SELECT_ONE) 
	{
		//判断 鼠标在哪行 哪列
		setLineColumn(mouseX, mouseY, &line2, &column2);
		if (enableSelectSecond()) 
		{
			gems[line2][column2].State = SELECTED_SECOND;
			//交换宝石
			swapGem();
			gameState = SELECT_TWO;
		}
		else 
		{
			resetGameNormalState();
		}
	}
	else 
	{
		resetGameNormalState();
	}
	
}
void gameMousemove (int mouseX,int mouseY)
{
	 
}

void gameMouseRightDown(int mouseX,int mouseY)
{
	 
}
//--------------重构--------------------------------------------------------------------------------------------------
void resetGameNormalState() 
{
	gameState = GAME_NORMAL;
	if (line1 != -1)
	{
		gems[line1][column1].State = GEM_NORMAL;
		line1 = column1 = -1;
	}
	if (line2 != -1)
	{
		gems[line2][column2].State = GEM_NORMAL;
		line2 = column2 = -1;
	}
}
int enableSelectSecond() 
{
	if (line2 == line1)
	{
		if (column1 > column2)
		{
			column2 = column1 - 1;
		}
		else {
			column2 = column1 + 1;
		}
		return column2>=0&&column2<8;
	}
	else if (column2 == column1)
	{
		if (line2 < line1)
		{
			line2 = line1 - 1;
		}
		else
		{
			line2 = line1 + 1;
		}
		return line2>=0&&line2<8;
	}
	return 0;
}
void swapGem() 
{
   GEM t;
   t = gems[line1][column1];
   gems[line1][column1] = gems[line2][column2];
   gems[line2][column2] = t;
}
void setLineColumn(int mouseX, int mouseY,int * line,int * column)
{
	*line = (mouseY - 10) / 52;
	*column = (mouseX - 200) / 52;
}
int isInGemRaange()
{
	return line1 >= 0 && line1 < 8 && column1 >= 0 && column1 < 8;
}
int enabledLineClear(int line, int column) 
{
	int count = 0;
	for (int left = column - 1;left>=0 && gems[line][left].Type == gems[line][column].Type;left--)
	{
		count++;
	}
	for (int right = column; right < 8 && gems[line][right].Type == gems[line][column].Type; right++) {
		count++;
	}
	return count >= 3;
}
int  enabledColumnClear(int line, int column)
{
	int count = 0;
	for (int top = line - 1; top >= 0 && gems[top][column].Type == gems[line][column].Type; top--)
	{
		count++;
	}
	for (int bottom = line; bottom < 8 && gems[bottom][column].Type == gems[line][column].Type; bottom++) 
	{
		count++;
	}
	return count >= 3;
}
void toClear(int line,int column, int type) 
{
	if (gems[line][column].Type == type
		&& gems[line][column].State == GEM_NORMAL) 
	{
		gems[line][column].State = TO_CLEAR;
		if (line - 1 >= 0) 
		{
			toClear(line - 1, column, type);
		}
		if (line + 1 < 8) 
		{
			toClear(line + 1, column, type);
		}
		if (column - 1 >= 0) 
		{
			toClear(line, column - 1, type);
		}
		if (column + 1 < 8) 
		{
			toClear(line, column + 1, type);
		}
	}
}