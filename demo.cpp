#include "options.h"

int main(int argc, const char ** argv)
{
	Option op;
	op.regist("key", "default_val");
	op.parseOption(argv);
	op.print();
	return 0;
}
