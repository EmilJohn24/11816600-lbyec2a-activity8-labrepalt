#include <stdio.h>
#define ROWS 10
#define COLS 10
int main(){
	int i = 0, j = 0;
	while(i != COLS){
		printf("%d\t", i++);
		int j = 0;
		do{
			printf("%d\t", i * ++j);
		}
		while (j != ROWS);
		
		printf("\n");
		
	}
}
