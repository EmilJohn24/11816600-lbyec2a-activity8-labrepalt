#include "console.h"
#include <stdio.h>
#define ROWS 50 //y-axis
#define COLS 50 //x-axis
#include <time.h> //time()
#include <windows.h> //sleep()
#define TRIES 20
#define ASTERISKS 10
#define EFFECT_AREA 3 
/*size of square opened within player's guess. Should always be odd. 
Not complying will not lead to fatal flaws but it will make the game look ugly.*/
void putHiddenAsterisk(int& x, int& y);
int placeGuess(int& x, int& y);
void anger();

int main(){
	srand(time(0));
	int attempts = 0;
	int score = 0;
	int x,y;
	setWindowSize(ROWS, COLS);
	for(int i = 0; i != ASTERISKS; i++){
		x = rand() % COLS;
		y = rand() % ROWS;
		putHiddenAsterisk(x, y);
	}
	int guessX, guessY;
	while (attempts < TRIES){
		gotoxy(0, 0);
		printf("Attempt# %d: \nScore: %d \nPick a coordinate to make your guess: ", attempts + 1, score);
		scanf("%d, %d", &guessX, &guessY);
		int newScore = placeGuess(guessX, guessY);
		if (newScore >= 0){
			attempts++;
			score += newScore;
			if (score == ASTERISKS){
				printf("\nYou win!!!");
				return 0;
			}
		}
		
		else{
			anger();
		}
	}
	printf("\nIt's over... You're out of attempts");
	return 0;
	
}


void anger(){
	for (int i = 0; i != 5; i++){
		setBackgroundColor(BRED);
		Sleep(100);
		setBackgroundColor(BBLACK);	
	}
}

void putHiddenAsterisk(int &x, int &y){
	putxy(x, y, TBLACK, "*");
}

int placeGuess(int& x, int& y){
	//returns -1 if an illegal move was made, returns score otherwise
	int attemptScore = 0;
	int offset = (EFFECT_AREA - 1) / 2;
	textcolor(BYELLOW | TRED);

	if (x < COLS - 1 && x > 0 && y > 0 && y < ROWS - 1){
		for (int guessX = x - offset; guessX <= x + offset; guessX++){
			for (int guessY = y - offset; guessY <= y + offset; guessY++){
				gotoxy(guessX, guessY);
				if (getConsoleChar(guessX, guessY) == '*'){
					printf("+");
					attemptScore++;
				}
				else{
					printf(" ");
				}
			}
		}
	}
	else{
		attemptScore = -1;
	}
	textcolor(TWHITE | BBLACK);
	return attemptScore;
}
