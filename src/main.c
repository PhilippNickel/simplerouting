#include "net.h"
#include "field.h"
#include "routing.h"
#include <unistd.h>

int main()
{
	init_field();
	fill_debug_nets(NUM_DEBUG_NETS);
	route(nets[0]);

	return 0;
}
