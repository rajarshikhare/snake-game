#include<iostream>
#include "position.h"
#include <conio.h>
#include<windows.h>

using namespace std;

int lenght = 10;
int speed = 150;
int game_point = 0;
char previous_char;

typedef struct body{
	int x,y;
} body ;

body snake[80];

int food_x = 64,food_y = 24;

void food_encounter();
void move(char);
void check_game();

void delay(int speed){
	/*int c,d;
	for ( c = 1 ; c <= speed*speed ; c++ )
       for ( d = 1 ; d <= speed*speed ; d++ )
       {}*/
	Sleep(speed);
}

int main(){
	system("mode 80,31 && color 4A");
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
	cout<<"@";
	if((previous_char == 'w' && c == 's') || (previous_char == 's' && c == 'w') || (previous_char == 'a' && c == 'd') || (previous_char == 'd' && c == 'a')){
		return;
	} 
	previous_char = c;
	if(c == 'd'){
			gotoxy(snake[lenght - 1].x, snake[lenght - 1].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].x/78){
				snake[0].x = 0;
			} else {
				snake[0].x = snake[0].x + 2;
			}
			gotoxy(snake[0].x, snake[0].y);
			check_game();
			if(snake[0].x == food_x && snake[0].y == food_y){
				lenght++;
				food_encounter();
			}
			gotoxy(snake[0].x,snake[0].y);
			cout<<"*";
		} else if(c == 's'){
			gotoxy(snake[lenght - 1].x, snake[lenght - 1].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].y/29){
				snake[0].y = 0;
			}else {
				snake[0].y++;
			}
			gotoxy(snake[0].x, snake[0].y);
			check_game();
			if(snake[0].x == food_x && snake[0].y == food_y){
				lenght++;
				food_encounter();
			}
			gotoxy(snake[0].x,snake[0].y);
			cout<<"*";
		} else if(c == 'a'){
			gotoxy(snake[lenght - 1].x, snake[lenght - 1].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].x <= 1){
				snake[0].x = 78;
			} else {
				snake[0].x = snake[0].x - 2;
			}
			gotoxy(snake[0].x, snake[0].y);
			check_game();
			if(snake[0].x == food_x && snake[0].y == food_y){
				lenght++;
				food_encounter();
			}
			gotoxy(snake[0].x,snake[0].y);
			cout<<"*";
		} else if(c == 'w'){
			gotoxy(snake[lenght - 1].x, snake[lenght - 1].y);
			cout<<" ";
			for(i = lenght - 1; i > 0; i--){
				snake[i].x = snake[i-1].x;
				snake[i].y = snake[i-1].y;
			}
			if(snake[0].y <= 1){
				snake[0].y = 29;
			} else {
				snake[0].y--;
			}
			gotoxy(snake[0].x, snake[0].y);
			check_game();
			if(snake[0].x == food_x && snake[0].y == food_y){
				lenght++;
				food_encounter();
			}
			gotoxy(snake[0].x,snake[0].y);
			cout<<"*";
		}
		gotoxy(0,30);
		cout<<"Game point : "<<game_point;
}

void food_encounter(){
	gotoxy(food_x,food_y);
	cout<<" ";
	int a;
	while(1){
		a = rand() % 80;
		if(a%2 == 0){
			break;
		}
	}
	//a = rand() % 80;
	food_x = a;
	food_y = rand() % 29;
	speed-=5;
	game_point+=5;
}

void check_game(){
	int i;
	for(i = 1; i < lenght; i++){
		if(snake[0].x == snake[i].x && snake[0].y == snake[i].y){
			gotoxy(80/2-17,31/2);
			cout<<"Game over and your score was : "<<game_point<<endl;
			getch();
			getch();getch();getch();getch();getch();getch();getch();
			exit(0);
		}
	}
}
