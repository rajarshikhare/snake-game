#include<iostream>
#include "position.h"
#include <conio.h>
using namespace std;

int lenght = 10;
int speed = 90;

typedef struct body{
	int x,y;
} body ;

body snake[10];

int food_x = 63,food_y = 24;

void change_food_location();
void move(char);

void delay(int time){
	int c,d;
	for ( c = 1 ; c <= time*time ; c++ )
       for ( d = 1 ; d <= time*time ; d++ )
       {}
}

int main(){
	system("mode 132,31");
	int i,j = 0,k;
	
	for(i = 1; i <= lenght; i = i + 1 ){
		snake[10-i].x = i*2;
		snake[10-j].y = 0;
		gotoxy(snake[10-i].x,snake[10-j].y);
		cout<<"*";
	}
	char c;
	while(1){
		if((kbhit())){
			c = getch();
			delay(speed);
			move(c);
		} else {
			delay(speed);
			move(c);
		} 
	}
}

void move(char c){
	int i,j,k;
	gotoxy(food_x,food_y);
	cout<<"#";
	if(c == 'd'){
			gotoxy(snake[9].x, snake[9].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].x/132){
				snake[0].x = 0;
			} else {
				snake[0].x = snake[0].x + 2;
			}
			gotoxy(snake[0].x, snake[0].y);
			if(snake[0].x == food_x + 1 && snake[0].y == food_y){
				lenght++;
				change_food_location();
			}
			cout<<"*";
		} else if(c == 's'){
			gotoxy(snake[9].x, snake[9].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].y/31){
				snake[0].y = 0;
			}else {
				snake[0].y++;
			}
			gotoxy(snake[0].x, snake[0].y);
			if(snake[0].x == food_x + 1 && snake[0].y == food_y){
				lenght++;
				change_food_location();
				speed++;
			}
			cout<<"*";
		} else if(c == 'a'){
			gotoxy(snake[9].x, snake[9].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].x <= 0){
				snake[0].x = 132;
			} else {
				snake[0].x = snake[0].x - 2;
			}
			gotoxy(snake[0].x, snake[0].y);
			if(snake[0].x == food_x + 1 && snake[0].y == food_y){
				lenght++;
				change_food_location();
				speed++;
			}
			cout<<"*";
		} else if(c == 'w'){
			gotoxy(snake[9].x, snake[9].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].y <= 0){
				snake[0].x = 0;
			} else {
				snake[0].y--;
			}
			gotoxy(snake[0].x, snake[0].y);
			if(snake[0].x == food_x + 1  && snake[0].y == food_y){
				lenght++;
				change_food_location();
				speed++;
			}
			cout<<"*";
		}
}

void change_food_location(){
	gotoxy(food_x,food_y);
	cout<<" ";
	food_x = rand() % 130;
	food_y = rand() % 30;
}


