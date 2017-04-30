#ifndef LINE2_H
#define LINE2_H

#include "libvector/vector2.h"

class line2
{
	double rho;
	double theta;

public:
	/*constructor*/			line2			(double rho = 0.0, double theta = 0.0);
	/*constructor*/			line2			(vector2d A, vector2d B);
	/*destructor*/			~line2			();

	vector2d				intersection	(const line2 &l);
};

#endif // LINE2_H
