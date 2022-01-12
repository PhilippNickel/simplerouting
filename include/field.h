#ifndef FIELD_H
#define FIELD_H

/* number of points on one side the quadratic searching field has */
#define FIELD_SIZE 20

/* point of the field struct */
typedef struct {
	int x, y;
} point_t;

extern int field[FIELD_SIZE][FIELD_SIZE];

void print_field();
void unprint_field();
void init_field();

#endif
