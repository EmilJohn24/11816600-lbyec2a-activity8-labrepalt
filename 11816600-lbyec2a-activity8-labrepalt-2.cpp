/**************************************************
  This program uses 2-level nested for loops to 
  display a rectangle between two coordinate points
  specified by the user.
  
  The user is asked 3 sets of coordinates to plot
  4 rectangles of different colors.
  
  The console graphics library is used.
**************************************************/
#include <stdio.h>
#include <conio.h>
#include "console.h"
#include <math.h>

void plotRect(int color);
void inputCoord(int *x, int *y, int xlimit, int ylimit);
void displayIntro();

int main() {
	int i;
	setBackgroundColor(BBLACK);
	setWindowSize(50,100);
	
	displayIntro();
	system("cls");
	
	// display a line at row 46
	for (i=1;i<=99;i++) putxy(i,46,TWHITE,"-");
	
	// this loop iterates 3 times
	// color of rectangle plotted per iteration is
	// specified by i
	for (i=1;i<=3;i++) {
		plotRect(i);
	}
    gotoxy(0,47);
	printf("press any key to exit.                           ");	
	getch(); // pause until key is pressed
	return 0;
}

void displayIntro() {
	int xlimit, ylimit;
	printf("You will be asked for the upper-left coordinate of the rectangle.\n\n");
	printf("The maximum Y limit is 45, and X limit is 99\n\n");
	getLargestWindowSize(&ylimit,&xlimit);
	printf("The current maximum Y = %i, maximum X = %i\n\n",ylimit,xlimit);
	printf("If the maximum Y or X are less than 50 and 100, respectively, please decrease console window font size and restart program. \n");
	printf("\npress any key to continue. ");
	getch();
}

// asks the user to input coordinates and performs
// limit checking. the user is asked to input again
// if the inputs exceeds the limits
void inputCoord(int *x, int *y, int xlimit, int ylimit) {
	int xcursor = whereX()-10, ycursor = whereY();
	do {
	  gotoxy(xcursor,ycursor);
	  scanf("%i,%i",x,y);		
	} while ((*x > xlimit)||(*x < 0)||(*y > ylimit)||(*y < 0));
}

// * plots a rectangle of "*" using opposite corners coordinates
//   inputted by the user; the color is specified by the parameter
/*


Color coding in <windows.h>:
0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE

Emil Color Encoding Scheme
0001 = 1 = 2 ^ 0 (First Quadrant) [BLUE]
0010 = 2 = 2 ^ 1 (Second Quadrant) [GREEN]
0100 = 4 = 2 ^ 2 (Third Quadrant) [RED]
1000 = 8 = 2 ^ 3 (Fourth Quadrant) [DARK GREY]

Exponent = 2 * (y >= midY) + (x >= midX) 
   3     = 2 *    True     +    True
   2     = 2 *    True     +    False
   1     = 2 *    False    +    True
   0     = 2 *    False    +    False
*/
void plotRect(int color) {
	int x1,y1,x2,y2,x,y;
	gotoxy(0,47);
	printf("Input the upper left coordinates (x,y):            ");
	inputCoord(&x1,&y1,99,45);
	x2 = x1 + 10;
	y2 = y1 + 20;
	int midX = (x1 + x2) / 2;
	int midY = (y1 + y2) / 2;
	// outer loop iterates through rows (y)
	for (y=y1;y<y2;y++)
	   // inner loop iterates through columns (x)
	   for (x=x1;x<x2;x++) {
	   	   int exponent = 2 * (y >= midY) + (x >= midX);
	   	   color = pow(2, exponent);
	       putxy(x,y,color,"*");	
	   }
}

