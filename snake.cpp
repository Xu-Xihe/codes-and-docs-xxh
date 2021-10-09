#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include<Windows.h>
#include <time.h> 
#include <conio.h>
using namespace std;
const int maxn = 1010;
struct node{
	int x;
	int y;
	int op; 
	// 0 up 1 down 2 left 3 right
};
int ox[4] = {-1,1,0,0};
int oy[4] = {0,0,-1,1};
int rowNum = 22, colNum = 42;

char maps[maxn][maxn]; //输出图片
node snake[maxn];	   //蛇身体位置
int snake_long;       
node food[maxn];
int food_num;

void updateMap(char maps[maxn][maxn]){
	for (int i = 0; i < rowNum ;i++)
		for (int j = 0; j < colNum ;j++){
			if (i==0 || i==rowNum-1 || j == 0 || j == colNum-1){
				maps[i][j] = '#';
			}
			else maps[i][j] = ' ';
		}
	for (int i = 0 ;i< food_num ;i++)
		maps[food[i].x][food[i].y] = '*';
	for (int i = snake_long-1; i>=0 ;i--)
		if (i==0){
			if (snake[0].op==0) maps[snake[i].x][snake[i].y] = '^';
			else if (snake[0].op==1) maps[snake[i].x][snake[i].y] = 'V';
			else if (snake[0].op==2) maps[snake[i].x][snake[i].y] = '<';
			else if (snake[0].op==3) maps[snake[i].x][snake[i].y] = '>';
		}
		else 
			maps[snake[i].x][snake[i].y] = 'o';
}
void printMap(char maps[maxn][maxn]){
	for (int i = 0; i < rowNum; i++)
		printf("%s\n",maps[i]);
}

void inite(){
	srand((unsigned)time(NULL)); 
	snake_long = 1;
	snake[0].x = rowNum/2;
	snake[0].y = colNum/2;
	snake[0].op = 0;
	food_num = 15;
	for (int i = 0 ;i< food_num ;i++){
		food[i].x = rand()%(rowNum-2) + 1;
		food[i].y = rand()%(colNum-2) + 1;
	}
	updateMap(maps);
}

void move(int op = -1){
	bool hasEat = false;
	if (op == -1) op = snake[0].op;
	node snake_head = snake[0];
	int pre_op = op;
	snake_head.op = op;
	snake[0].x = (snake[0].x - 1 + ox[op] + rowNum - 2) % (rowNum-2) + 1;
	snake[0].y = (snake[0].y - 1 + oy[op] + colNum - 2) % (colNum-2) + 1;
	for (int i = 0 ;i<food_num ;i++){
		if (snake[0].x == food[i].x && snake[0].y == food[i].y){
			hasEat = true;
			if (snake_long==1)
				snake[snake_long] = snake_head;
			else 
				snake[snake_long] = snake[snake_long-1];
			food[i].x = rand()%(rowNum-2) + 1;
			food[i].y = rand()%(colNum-2) + 1;
		}
	}
	//printf("%d %d\n",snake[0].x,snake[0].y);
	snake[0].op = op;
	for (int i = 1 ; i< snake_long ;i++){
		snake[i].x = (snake[i].x - 1 + ox[snake[i].op] + rowNum - 2) % (rowNum-2) + 1;
		snake[i].y = (snake[i].y - 1 + oy[snake[i].op] + colNum - 2) % (colNum-2) + 1;
		swap(snake[i].op,pre_op);
	}
	if (hasEat) snake_long++;
	updateMap(maps);
}

int main (){
	inite();
	while (1){
		
		if (_kbhit()){
            int ch = _getch();
            cout << ch;
            if (ch == 27){ break; }
            if (ch == 'w') move(0);
            if (ch == 'a') move(2);
            if (ch == 's') move(1);
            if (ch == 'd') move(3);
        }
        else move(-1);
		printMap(maps);
		Sleep(1000);
		system("cls");
	}
	printMap(maps);
	return 0;
}
