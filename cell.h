#ifndef _CONSOLE_CELL_AZA_H
#define _CONSOLE_CELL_AZA_H

#include <stdlib.h>
#include <stdio.h>
#include "./color.h"
#include "./position.h"

struct Cell {
	Color fground;
	Color bground;

	struct Position pos;

	char symbol;
};

void printcell(struct Cell *cell){
	set_fcolor(cell->fground);
	set_bcolor(cell->bground);

	s_set_pos(cell->pos);
	putchar(cell->symbol);
}
void erasecell(struct Cell *cell){
	set_fcolor(Normal);
	set_bcolor(Normal);
	
	set_pos(cell->pos.x,cell->pos.y);
	putchar(' ');
}

void movecell(struct Cell *cell,int x, int y){
	erasecell(cell);
	cell->pos.x += x;
	cell->pos.y += y;

	printcell(cell);
}

#endif
