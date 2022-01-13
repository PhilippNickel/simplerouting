#ifndef NET_H
#define NET_H
#include "queue.h"

#define NUM_DEBUG_NETS 10

/* net struct */
typedef struct {
        int x1, x2;
        int y1, y2;
	/* queue to save the path in the end */
	queue_t *path;
} net_t;

extern net_t nets[NUM_DEBUG_NETS];

/* fills the nets array with nets that have random starts and stops */
void fill_debug_nets();
void print_nets();

/* fill ports of nets into field */
void fill_ports();

/* prints the path of a given net */
void print_path(net_t net);

#endif
