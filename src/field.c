#include "field.h"
#include <stdio.h>
#include <string.h>

int field[FIELD_SIZE][FIELD_SIZE];

void print_field()
{
	for(int i = 0; i < FIELD_SIZE; i++) {
		for(int j = 0; j < FIELD_SIZE; j++) {
			printf("%2i  ", field[j][i]);
		}
		printf("\n");
	}
}

void unprint_field()
{
	for(int i = 0; i <= FIELD_SIZE; i++) {
		/* VT100 excape code to move cursor to start of prev line */
		printf("\33[F");
		/* VT100 excape code to clear a line */
		printf("\33[2K");
	}
}

void init_field()
{
	memset(&field, -1, sizeof(field[0][0]) * FIELD_SIZE * FIELD_SIZE);
}
