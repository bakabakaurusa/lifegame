#ifndef _LIFE_H_
#define _LIFE_H_

#include "common.h"

typedef enum state
{
	DEAD,
	ALIVE
} State;
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

struct Grid
{
	int width;
	int height;
	State cells[MAX_WIDTH][MAX_HEIGHT];
} Grid;

void init(struct Grid* map);

void update(struct Grid* map);

int NeighborCount(struct Grid* map, int x, int y);

void render(struct Grid* map);

#endif
