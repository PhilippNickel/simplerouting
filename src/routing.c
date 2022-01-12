#include "net.h"
#include "queue.h"
#include "field.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* pointer to queue to save the to be visited points */
queue_t *queue;

/* helps to traverse the field */
const int xincr[8] = { -1, 0, 1, 0 };
const int yincr[8] = { 0, 1, 0, -1 };

void route(net_t net)
{
	int startx = net.x1;
	int starty = net.y1;
	int endx = net.x2;
	int endy = net.y2;

	/* prepare starting point */
	point_t start;
	start.x = startx;
	start.y = starty;

	/* put starting point in queue */
	queue = queue_new();
	queue_enqueue(queue, &start);

	int counter = 0;
	int x, y, nextx, nexty;
	point_t *point_ptr;
	field[startx][starty] = 0;

	/*
	 * do as long as there are points
	 * to be marked or
	 * endpoint is reached
	 */
	do {
		/* get next point from queue */
		point_ptr = (point_t*)queue_dequeue(queue);

		x = point_ptr->x;
		y = point_ptr->y;
		printf("got queued: %i, %i\n", x, y);
		counter = field[x][y];

		/* circle around every point */
		for(int i = 0; i < 4; i++) {
			nextx = x + xincr[i];
			nexty = y + yincr[i];

			/* check if point is visitable */
			if(!(field[nextx][nexty] != UNVISITED ||
			   nextx < 0 ||
			   nexty < 0 ||
			   nextx > FIELD_SIZE ||
			   nexty > FIELD_SIZE)) {
				field[nextx][nexty] = counter + 1;

				/* put the point in the to be visited queue */
				point_t *next = malloc(sizeof(point_t));
				next->x = nextx;
				next->y = nexty;
				queue_enqueue(queue, next);
			}


		}
		usleep(50*1000);
		unprint_field();
		print_field();
		counter++;

	} while(!(queue_empty(queue) == TRUE || (x == endx && y == endy)));

	/* backtrace */

	/* go to end point */
	x = endx;
	y = endy;

	do {
		counter = field[x][y];
		field[x][y] = PATH;

		/* circle around every point */
		for(int i = 0; i < 4; i++) {
			nextx = x + xincr[i];
			nexty = y + yincr[i];

			/* go to the one with val = currval - 1 */
			if(field[nextx][nexty] == (counter - 1)) {
				x = nextx;
				y = nexty;
				break;
			}

			usleep(50*1000);
			unprint_field();
			print_field();

		}
	} while (!(x == startx && y == starty));

	/* mark start and end of net as ports */
	field[startx][starty] = PORT;
	field[endx][endy] = PORT;

	reset_field();

	usleep(50*1000);
	unprint_field();
	print_field();
}
