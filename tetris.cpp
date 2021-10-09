#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>
#include <conio.h>
#include <windows.h>
using namespace std;
char map[22][14];
bool fall,gameover;
struct point {
	int x;
	int y;
};
int score = 0;
struct tetris {
	point block[4];
	int type;/*
	0:++   1:       2:+      3: +    4:+      5: +   6:  +
	  ++     ++++     ++       ++      +++      +++    +++
	                   +       +
	*/
};
tetris tetris;
void __() {
	srand(int((time(0))));
	for (int i = 0;i < 22;i++) {
		for (int j = 0;j < 14;j++) {
			map[i][j] = ' ';
		}
	}
	for (int i = 0;i < 14;i++) {
		map[0][i] = '#';
		map[21][i] = '#';
	}
	for (int i = 1;i < 21;i++) {
		map[i][0] = '#';
		map[i][13] = '#';
	}
	fall = 0;
	gameover = 0;
}
void print() {
	system("cls");
	for (int i = 0;i < 22;i++) {
		for (int j = 0;j < 14;j++) {
			if (i == 5 && map[i][j] == ' ') {
				printf("-");
			}
			else {
				printf("%c",map[i][j]);
			}
		}
		printf("\n");
	}
}
void create(int _type) {
	fall = 1;
	tetris.type = _type;
	tetris.block[0].x = 1;
	tetris.block[0].y = 5;
	if (tetris.type != 4) {
		tetris.block[1].x = 1;
		tetris.block[1].y = 4;
	}
	else {
		tetris.block[1].x = 1;
		tetris.block[1].y = 7;
	}
	if (tetris.type != 1 && tetris.type != 2) {
		tetris.block[2].x = 0;
		tetris.block[2].y = 5;
	}
	else if (tetris.type == 1) {
		tetris.block[2].x = 1;
		tetris.block[2].y = 7;
	}
	else {
		tetris.block[2].x = 2;
		tetris.block[2].y = 5;
	}
	if (tetris.type == 1 || tetris.type == 4 || tetris.type == 5) {
		tetris.block[3].x = 1;
		tetris.block[3].y = 6;
	}
	else if (tetris.type == 0 || tetris.type == 2 || tetris.type == 3) {
		tetris.block[3].x = tetris.type % 2 * 2;
		tetris.block[3].y = 4;
	}
	else {
		tetris.block[3].x = 1;
		tetris.block[3].y = 3;
	}
	fall = 1;
	for (int i = 0;i < 4;i++) {	
		tetris.block[i].x++;
		tetris.block[i].y++;
		map[tetris.block[i].x][tetris.block[i].y] = '+';
	}
}
void over() {
	for (int i = 0;i < 14;i++) {
		if (map[5][i] == 'O') {
			gameover = 1;
		}
	}
}
bool collide() {
	for (int i = 0;i < 4;i++) {
		if (map[tetris.block[i].x][tetris.block[i].y] == 'O' || map[tetris.block[i].x][tetris.block[i].y] == '#') {
			return 1;
		}
	}
	return 0;
}
bool row(int a) {
	bool b = 1;
	for (int i = 1;i < 13;i++) {
		if (map[a][i] != 'O') {
			b = 0;
		}
	}
	return b;
}
void set(char a) {
	for (int i = 0;i < 4;i++) {
		map[tetris.block[i].x][tetris.block[i].y] = a;
	}
}
int abs_(int a) {
	if (a >= 0) {
		return a;
	}
	return (0 - a);
}
bool touch() {
	for (int i = 0;i < 4;i++) {
		if (map[tetris.block[i].x + 1][tetris.block[i].y] == '#' || map[tetris.block[i].x + 1][tetris.block[i].y] == 'O') {
			return 1;
		}
	}
	return 0;
}
void falldown() {
	if (fall) {
		if (!touch()) {
			set(' ');
			for (int i = 0;i < 4;i++) {
				tetris.block[i].x++;
			}
			set('+');
		}
		else {
			set('O');
			fall = 0;
		}
	}
	else {
		return;
	}
}
void move(int op) {
	point pre_block[4];
	set(' ');
	for (int i = 0;i < 4;i++) {
		pre_block[i].x = tetris.block[i].x;
		pre_block[i].y = tetris.block[i].y;
	}
	for (int i = 0;i < 4;i++) {
		tetris.block[i].y += op;
	}
	if (collide()) {
		for (int i = 0;i < 4;i++) {
			tetris.block[i].x = pre_block[i].x;
			tetris.block[i].y = pre_block[i].y;
		}
	}
	set('+');
}
void rotate() {
	point pre_block[4];
	int x0 = tetris.block[0].x;
	int y0 = tetris.block[0].y;
	set(' ');
	for (int i = 0;i < 4;i++) {
		pre_block[i].x = tetris.block[i].x;
		pre_block[i].y = tetris.block[i].y;
	}
	for (int i = 1;i < 4;i++) {
		tetris.block[i].x = x0 - y0 + pre_block[i].y;
		tetris.block[i].y = y0 + x0 - pre_block[i].x;
	}
	if (collide()) {
		for (int i = 0;i < 4;i++) {
			tetris.block[i].x = pre_block[i].x;
			tetris.block[i].y = pre_block[i].y;
		}
	}
	set('+');
}
int main() {
	printf("Press 'A''D' to move the block left and right\nPress 'S' to fall faster\nPress 'R' to rotate the block clockwise");
	sleep(6);
	__();
	while (1) {
		if (!fall) {
			create(rand() % 7);
			print();
			sleep(1);
		}
		else {
			while (_kbhit()) {
				int ch = _getch();
				if (ch == 'a') {
					move(-1);
					print();
				}
				if (ch == 'd') {
					move(1);
					print();
				}
				if (ch == 27) {
					return 0;
				}
				if (ch == 'r') {
					rotate();
					print();
				}
				if (ch == 's') {
					falldown();
					print();
				}
			}
			falldown();
			print();
			Sleep(700);
			for (int i = 1;i < 21;i++) {
				if (row(i)) {
					score += 10;
					for (int j = i;j > 1;j--) {
						for (int k = 1;k < 13;k++) {
							map[j][k] = map[j - 1][k];
						}
					}
				}
			}
		}
		over();
		if (gameover) {
			break;
		}
	}
	if (gameover) {
		for (int i = 1;i < 13;i++) {
			if (map[5][i] != 'O') {
				map[5][i] = '~';
			}
		}
		print();
		printf("Game over\nScore: %d",score);
		sleep(3);
	}
	return 0;
}
