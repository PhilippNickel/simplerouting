#include "net.h"
#include "field.h"
#include "routing.h"
#include <unistd.h>

int main()
{
	init_field();
	fill_debug_nets(NUM_DEBUG_NETS);
	for(int i = 0; i < NUM_DEBUG_NETS; i++) {
		route(nets[i]);
	}
	return 0;
}
