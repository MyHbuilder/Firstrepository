#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
#define CHESS_NUMBER 3

//函数的声明放在头文件里；函数的实现放在.c文件里，主函数就放在text文件里；这是代码的模块化  

void Menu_Game();

void Init_Checkerboard(char Checkerboard[ROW][COL], int row, int col);

void Show_Checkerboard(char Checkerboard[ROW][COL], int row, int col);

void Player_Move(char Checkerboard[ROW][COL], int row, int col);

void Computer_Move(char Checkerboard[ROW][COL], int row, int col);

char Full_Checkerboard(char b[ROW][COL], int row, int col);

char Win_Game(char Checkerboard[ROW][COL], int row, int col);

void Game(char Checkerboard[ROW][COL], int row, int col);

void Init_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Checkerboard[i][j] = ' ';
		}
	}
}
//初始化棋盘

void Menu_Game()
{
	printf("      **********************************************************************************************************\n");
	printf("      *********                                                                                        *********\n");
	printf("      *********                                    杨秋月的游戏殿堂                                    *********\n");
 	printf("      *********                                                                                        *********\n");
	printf("      *********                                    输入 1 :开始游戏                                    *********\n");
	printf("      *********                                    输入 0 :结束游戏                                    *********\n");
	printf("      *********                  注：输入的两个位置之间需要加一个空格 （位置输完后点击回车键）         *********\n");
	printf("      *********                            注：输入顺序与范围 行（1-3） 列（1-3）                      *********\n");
	printf("      *********                              秋月的棋子是：*   鸿崽的棋子是#                           *********\n");
	printf("      **********************************************************************************************************\n");
}


void Show_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
	{
		printf("---");
		printf("|");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Checkerboard[i][j]);
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
				printf("|");
		}
		printf("\n");
	}
}
//显示棋盘


void Player_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("杨秋月请输入你要下的位置：\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= ROW && x > 0 && x <= ROW)
		{

			if (Checkerboard[x - 1][y - 1] == ' ')
			{
				Checkerboard[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被输入\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入，要按到格式和范围来哦\n");
		}
	}

}
//玩家移动

void Computer_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (Checkerboard[x][y] == ' ')
		{
			Checkerboard[x][y] = '#';
			break;
		}
	}



}
//电脑移动

char Full_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (Checkerboard[i][j] == ' ')
				return 'N';
	return 'F';
}
//判断棋盘是否下满 

char Win_Game(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j, n, z, flag = 0;
	for (i = 0; i < row; i++)
	{       flag=0;
		for (j = 0; j < col - 1; j++)
		{
			if ((Checkerboard[i][j] == Checkerboard[i][j + 1]) && (Checkerboard[i][j] != ' '))
			{
				flag++;
			}
			else
			{
				flag = 0;
			} 
			if (flag == CHESS_NUMBER - 1)
				return Checkerboard[i][j];
		}
	}
	//判断行是否三子
    flag = 0;
	for (i = 0; i < row ; i++)
	{      flag=0;
		for (j = 0; j < col-1; j++)
		{
			if ((Checkerboard[j][i] == Checkerboard[j + 1][i]) && (Checkerboard[j][i] != ' '))
			{
				flag++;
			}
			else
			{
				flag = 0;
			}
			if (flag == CHESS_NUMBER - 1)
				 return Checkerboard[j][i];
		}
	}
	//判断列是否三子 

	z=row,n=0;
	while(z){
	  for(i=n , j=0;i<row-1,j<col-1;i++,j++){
	    if(Checkerboard[i][j]==Checkerboard[i+1][j+1]&&Checkerboard[i][j]!=' ') 
  		  flag++; 
  	    else 
		  flag=0;
  	    if(flag==CHESS_NUMBER -1)
  	      return Checkerboard[i][j];     
	  }
	   n++;
	   z--;	   
	}
	flag=0,z=col,n=0;
	while(z){
	  for(i=0,j=n;i<row-1,j<col-1;i++,j++){
	    if(Checkerboard[i][j]==Checkerboard[i+1][j+1]&&Checkerboard[i][j]!=' ') 
  		  flag++; 
  	    else 
		  flag=0;
  	    if(flag==CHESS_NUMBER -1)
  	      return Checkerboard[i][j];     
	  }
	   n++;
	   z--;	   
	}
	//判断左对角线是否三子
	
   flag=0;
   z=col,n=col-1;
	while(z){
	  for(i=0,j=n;i<row-1,j>0;i++,j--){
	    if(Checkerboard[i][j]==Checkerboard[i+1] [j-1]&&Checkerboard[i][j]!=' ') 
  		  flag++; 
  	    else 
		  flag=0;
  	    if(flag==CHESS_NUMBER -1)
  	      return Checkerboard[i][j];     
	  }
	   n--;
	   z--;	   
	}
	flag=0,z=row,n=0;
	while(z){
	  for(i=n,j=col-1;i<row-1,j>0;i++,j--){
	    if(Checkerboard[i][j]==Checkerboard[i+1][j-1]&&Checkerboard[i][j]!=' ') 
  		  flag++; 
  	    else 
		  flag=0;
  	    if(flag==CHESS_NUMBER -1)
  	      return Checkerboard[i][j];     
	  }
	   n++;
	   z--;	   
	}
	//判断右对角线是否三子

	if (Full_Checkerboard(Checkerboard, ROW, COL) == 'F')
		return 'F';
	//判断棋盘是否下满

	return 'N';
}
//判断游戏胜负情况

void Game(char Checkerboard[ROW][COL], int row, int col)
{
	char flag = 'N';
	srand((unsigned int)time(NULL));
	//设置随机数 
	Init_Checkerboard(Checkerboard, ROW, COL);
	Show_Checkerboard(Checkerboard, ROW, COL);
	while (1)
	{
		printf("现在是你的回合\n");
		Player_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

		printf("现在是鸿崽帅哥的回合\n");
		Computer_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

	}
	if (flag == '*')
	{
		printf("杨秋月获胜 胜之不武\n");
	}
	else if (flag == '#')
	{
		printf("黄鸿获胜oh耶耶耶耶耶真牛逼\n");
	}
	else if (flag == 'F')
	{
		printf("棋盘满，平局\n");
	}
}

int main()
{
	int n;
	char Checkerboard[ROW][COL] = { 0 };
//	srand((int)time(NULL));//使得随机数不重复 time函数指1970年1月1日零时起到现在的时间，一直在变化 
	do
	{
		Menu_Game();
		printf("输入 1 开始游戏 输入 0 结束游戏：\n");
		scanf("%d", &n);
        printf("\n");
		switch (n)
		{
		case 1:
			Game(Checkerboard, ROW, COL);
			break;
		case 0:
			printf("结束游戏了哟拜拜\n");
			break;
		default:
			printf("傻蛋输错了撒，重新输\n");
			break;
		}

	} while (n);

	return 0;
}
