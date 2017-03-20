#include<iostream>
#include "position.h"
#include <conio.h>
using namespace std;

int lenght = 10;

typedef struct body{
	int x,y;
} body ;


int main(){
	system("mode 132,31");
	int i,j = 0,k;
	body snake[10];
	for(i = 1; i <= lenght; i = i + 1 ){
		cout<<"@";
		snake[10-i].x = i;
		snake[10-j].y = 0;
		
	}
	char c;
}


