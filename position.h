#ifndef _CONSOLE_POSITION_AZA_H_
#define _CONSOLE_POSITION_AZA_H_

#include <stdlib.h>
#include <stdio.h>

struct Position{
	size_t x;
	size_t y;
};

void set_pos(size_t x, size_t y){
	printf("\033[%zu;%zuf",y,x);
}
void s_set_pos(struct Position pos){
	printf("\033[%zu;%zuf",pos.y,pos.x);
}

#endif
