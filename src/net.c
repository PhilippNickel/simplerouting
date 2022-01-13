#include "net.h"
#include "field.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

net_t nets[NUM_DEBUG_NETS];

void fill_debug_nets(int amount)
{
	/* init random number generator */
	time_t t;
	srand((unsigned) time(&t));

	for (int i = 0; i < amount; i++) {
		net_t nnet;
		nnet.x1 = rand() % (FIELD_SIZE);
		nnet.x2 = rand() % (FIELD_SIZE);
		nnet.y1 = rand() % (FIELD_SIZE);
		nnet.y2 = rand() % (FIELD_SIZE);
		nnet.path = queue_new();
		nets[i] = nnet;
	}
}

void print_nets()
{
	for (int i = 0; i < NUM_DEBUG_NETS; i++) {
		printf("Net %i: (%i, %i) -> (%i, %i)\n", i, nets[i].x1,
		       nets[i].y1, nets[i].x2, nets[i].y2);
	}
}

void fill_ports()
{
	int x1, y1, x2, y2;
	for (int i = 0; i < NUM_DEBUG_NETS; i++) {
		x1 = nets[i].x1;
		y1 = nets[i].y1;
		x2 = nets[i].x2;
		y2 = nets[i].y2;
		field[x1][y1] = PORT;
		field[x2][y2] = PORT;
	}
}

void print_path(net_t net)
{
	printf("Found path:\n");
	point_t *point;
	int i = 0;
	while((point = (point_t *)queue_dequeue(net.path)) != NULL) {
		printf("P %i, x:%i, y:%i\n", i, point->x, point->y);
		i++;
	}
}
