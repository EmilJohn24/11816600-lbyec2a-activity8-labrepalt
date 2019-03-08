#include "console.h"
#include <stdio.h>
#define ROWS 50 //y-axis
#define COLS 50 //x-axis
#include <time.h> //time()
#include <windows.h> //sleep()
void bruteForceAsterisks();
void putHiddenAsterisk(int& x, int& y);

int main(){
	srand(time(0));
	int x,y;
	setWindowSize(ROWS, COLS);
	for(int i = 0; i != 10; i++){
		x = rand() % COLS;
		y = rand() % ROWS;
		putHiddenAsterisk(x, y);
	}

}


void putHiddenAsterisk(int &x, int &y){
	putxy(x, y, TBLACK, "*");
}


