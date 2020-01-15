#include "pch.h"
#include <iostream>

int main(void) {
	int length, width, i, j;
	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 9; j++) {
			if (i < 9 && j == 1 && i>1)
				{
				printf("%d",i-1);
					}
			if (j < 9 && i == 1 && j > 1) {
				printf("%d", i);
			}
			if ((i + j) % 2 == 0 && i != 1 && j != 1 )
				printf("[X]");
			else
				printf("[ ]",98);
		}
		printf("\n");
	}
	return 0;
}
