#include "life.h"
#include "time.h"

void init(struct Grid* map)
{
	int row, col;
	srand((time(0)));
	for (row = 0; row < map->width; row++)
	{
		for (col = 0; col < map->height; col++)
		{
			int r = rand() % 100 + 1;
			if (r < 35)
			{
				map->cells[row][col] = ALIVE;
			}
			else
			{
				map->cells[row][col] = DEAD;
			}
		}
	}
}
void CopyMap(struct Grid* map, struct Grid newMap)
{
	int row, col;

	for (row = 0; row < map->width; row++)
		for (col = 0; col < map->height; col++)
			map->cells[row][col] = newMap.cells[row][col];
}
void update(struct Grid* map)
{
	int width = map->width;
	int height = map->height;
	struct Grid newMap = { width,height };
	int row, col;
	for (row = 0; row < map->width; row++)
	{
		for (col = 0; col < map->height; col++)
		{
			int count = NeighborCount(map, row, col);
			if (count) {
				//1. ���һ��ϸ����Χ��3��ϸ��Ϊ�������ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣻
				if (count == 3) {
					newMap.cells[row][col] = ALIVE;
				}
				//2. ���һ��ϸ����Χ��2��ϸ��Ϊ�������ϸ��������״̬���ֲ��䣻
				else if (count == 2) {
					newMap.cells[row][col] = map->cells[row][col];
				}
				//3. ����������£���ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䡣
				else if (count == 4) {
					newMap.cells[row][col] = DEAD;
				}
				//�����������
				else {
					newMap.cells[row][col] = DEAD;
				}
			}
		}
	}
	CopyMap(map, newMap);
}



int NeighborCount(struct Grid* map, int x, int y) {
	int count = 0;
	for (int r = x - 1; r <= x + 1; r++) {
		for (int c = y - 1; c <= y + 1; c++) {
			if (map->cells[r][c] == ALIVE) {
				count++;
			}
		}
	}
	return count;
}
void render(struct Grid* map)
{
	int row, col;
	system("cls");
	for (row = 0; row < map->width; row++)
	{
		for (col = 0; col < map->height; col++)
		{
			if (map->cells[row][col] == ALIVE)
			{
				putchar('*');
			}
			else
			{
				putchar(' ');
			}
		}
		putchar('\n');
	}
}
