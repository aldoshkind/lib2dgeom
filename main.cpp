#include <stdio.h>

#include "line2.h"


int main()
{
	line2 l1(vector2d(0, 1), vector2d(1, 1));
	line2 l2(vector2d(0, 0), vector2d(1, 2));

	vector2d is = l1.intersection(l2);

	return 0;
}
