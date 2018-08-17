#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "./cell.h"
#include "./color.h"
#include "./position.h"
#include "./keys.h"
#include "./object.h"
#include "./consoleio.h"

#define _POSIX_C_SOURCE 199309L

void threadsleep(int miliseconds);

int main(void){

	struct Cell cell;

	cell.fground = Red;
	cell.bground = Blue;
	cell.symbol = 'X';
	cell.pos.x = 0;
	cell.pos.y = 5;


	struct Object *first = (struct Object*)malloc(sizeof(struct Object));
	first->count = 0;


	addcell(first,cell);
	cell.pos.x+=1;
	addcell(first,cell);
	cell.pos.x+=1;
	addcell(first,cell);
	cell.pos.x+=1;
	addcell(first,cell);
	cell.pos.x+=1;
	addcell(first,cell);

	cell.pos.x += 5;
	cell.symbol = 'M';
	cell.fground = Yellow;
	cell.bground = Magenta;

	struct Object *second = (struct Object*)malloc(sizeof(struct Object));
	second->count = 0;

	addcell(second, cell);
	cell.pos.y += 1;
	addcell(second, cell);
	cell.pos.y += 1;
	addcell(second, cell);
	cell.pos.y += 1;
	addcell(second, cell);
	cell.pos.y += 1;
	addcell(second, cell);
	cell.pos.y += 1;

	printobj(first);
	printobj(second);


	int current_object = 1;
	struct Object *current = first;

	while(1){
		int key;
		if(key = getch()){
			switch(key){
				case LEFT_ARROW:moveobj(current,-1,0);break;
				case RIGHT_ARROW:moveobj(current,1,0);break;
				case UP_ARROW:moveobj(current,0,-1);break;
				case DOWN_ARROW:moveobj(current,0,1);break;
				case SPACE: if(current_object == 1){
					current_object = 2;
					current = second;
				}else{
					current_object = 1;
					current = first;
				}break;
				case ENTER:goto end;
			}
		}else{
			threadsleep(1);
		}
	}

	end:

	free(first->cells);
	free(first);

	free(second->cells);
	free(second);

	printf("\n");
	return 0;
}

void threadsleep(int ms){
	struct timespec remaining = { ms / 1000, (ms % 1000) * 1000000L };
	nanosleep(&remaining, NULL);
}
