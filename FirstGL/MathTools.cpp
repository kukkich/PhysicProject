#include "MathTools.h"

int sign(double value)
{
	if (!value) return 0;
	if (value > 0) return 1;
	return -1;
}
