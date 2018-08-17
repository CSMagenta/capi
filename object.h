#ifndef _CONSOLE_OBJECT_AZA_H
#define _CONSOLE_OBJECT_AZA_H

#include "./cell.h"

struct Object{
	struct Cell *cells;
	size_t count;
};

void addcell(struct Object *obj, struct Cell cell){
	struct Cell *cells = (struct Cell*)malloc((obj->count + 1) * sizeof(struct Cell));
	for(int i = 0; i < obj->count;i++){
		cells[i] = obj->cells[i];
	}
	cells[obj->count] = cell;
	free(obj->cells);
	obj->cells = cells;
	obj->count++;
}

void printobj(struct Object *obj){
	for(int i = 0; i < obj->count; i++){
		printcell(&obj->cells[i]);
	}
}
void eraseobj(struct Object *obj){
	for(int i = 0; i < obj->count; i++){
		erasecell(&obj->cells[i]);
	}
}
void moveobj(struct Object *obj, int x, int y){
	for(int i = 0; i < obj->count; i++){
		erasecell(&(obj->cells[i]));
	}
	for(int i = 0; i < obj->count; i++){
		obj->cells[i].pos.x += x;
		obj->cells[i].pos.y += y;

		printcell(&(obj->cells[i]));
	}
}

int isjoined(struct Object *first, struct Object *second){
	for(int i = 0; i < first->count;i++){
		for(int j = 0; j < second->count;j++){
			if(first->cells[i].pos.x == second->cells[j].pos.x
			&& first->cells[i].pos.y == second->cells[j].pos.y){ return 1; }
		}
	}

	return 0;
}

#endif
