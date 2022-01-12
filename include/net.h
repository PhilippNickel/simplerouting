#ifndef NET_H
#define NET_H

#define NUM_DEBUG_NETS 10

/* net struct */
typedef struct {
        int x1, x2;
        int y1, y2;
} net_t;

extern net_t nets[NUM_DEBUG_NETS];

/* fills the nets array with nets that have random starts and stops */
void fill_debug_nets();
void print_nets();

#endif
