#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
#define CHESS_NUMBER 3

//��������������ͷ�ļ��������ʵ�ַ���.c�ļ���������ͷ���text�ļ�����Ǵ����ģ�黯  

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
//��ʼ������

void Menu_Game()
{
	printf("      **********************************************************************************************************\n");
	printf("      *********                                                                                        *********\n");
	printf("      *********                                    �����µ���Ϸ����                                    *********\n");
 	printf("      *********                                                                                        *********\n");
	printf("      *********                                    ���� 1 :��ʼ��Ϸ                                    *********\n");
	printf("      *********                                    ���� 0 :������Ϸ                                    *********\n");
	printf("      *********                  ע�����������λ��֮����Ҫ��һ���ո� ��λ����������س�����         *********\n");
	printf("      *********                            ע������˳���뷶Χ �У�1-3�� �У�1-3��                      *********\n");
	printf("      *********                              ���µ������ǣ�*   ���̵�������#                           *********\n");
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
//��ʾ����


void Player_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("��������������Ҫ�µ�λ�ã�\n");
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
				printf("�������ѱ�����\n");
			}
		}
		else
		{
			printf("����������������룬Ҫ������ʽ�ͷ�Χ��Ŷ\n");
		}
	}

}
//����ƶ�

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
//�����ƶ�

char Full_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (Checkerboard[i][j] == ' ')
				return 'N';
	return 'F';
}
//�ж������Ƿ����� 

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
	//�ж����Ƿ�����
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
	//�ж����Ƿ����� 

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
	//�ж���Խ����Ƿ�����
	
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
	//�ж��ҶԽ����Ƿ�����

	if (Full_Checkerboard(Checkerboard, ROW, COL) == 'F')
		return 'F';
	//�ж������Ƿ�����

	return 'N';
}
//�ж���Ϸʤ�����

void Game(char Checkerboard[ROW][COL], int row, int col)
{
	char flag = 'N';
	srand((unsigned int)time(NULL));
	//��������� 
	Init_Checkerboard(Checkerboard, ROW, COL);
	Show_Checkerboard(Checkerboard, ROW, COL);
	while (1)
	{
		printf("��������Ļغ�\n");
		Player_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

		printf("�����Ǻ���˧��Ļغ�\n");
		Computer_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

	}
	if (flag == '*')
	{
		printf("�����»�ʤ ʤ֮����\n");
	}
	else if (flag == '#')
	{
		printf("�ƺ��ʤohҮҮҮҮҮ��ţ��\n");
	}
	else if (flag == 'F')
	{
		printf("��������ƽ��\n");
	}
}

int main()
{
	int n;
	char Checkerboard[ROW][COL] = { 0 };
//	srand((int)time(NULL));//ʹ����������ظ� time����ָ1970��1��1����ʱ�����ڵ�ʱ�䣬һֱ�ڱ仯 
	do
	{
		Menu_Game();
		printf("���� 1 ��ʼ��Ϸ ���� 0 ������Ϸ��\n");
		scanf("%d", &n);
        printf("\n");
		switch (n)
		{
		case 1:
			Game(Checkerboard, ROW, COL);
			break;
		case 0:
			printf("������Ϸ��Ӵ�ݰ�\n");
			break;
		default:
			printf("ɵ�����������������\n");
			break;
		}

	} while (n);

	return 0;
}
