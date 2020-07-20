#include "common.h"
#include "life.h"
int main(int argc, char** argv)
{
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	struct Grid map = { width, height };
	init(&map);
	while (1) {
		render(&map);
		update(&map);
		Sleep(1000);		
	}

}