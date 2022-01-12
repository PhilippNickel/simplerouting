#ifndef FIELD_H
#define FIELD_H

/* number of points on one side the quadratic searching field has */
#define FIELD_SIZE 30

#define UNVISITED -1
#define PATH -2
#define PORT -3

/* point of the field struct */
typedef struct {
	int x, y;
} point_t;

extern int field[FIELD_SIZE][FIELD_SIZE];

void print_field();
void unprint_field();
void init_field();

/*
 * resets the values in the field for a next iteration
 * (keeps ports and paths)
 */
void reset_field();

#endif
