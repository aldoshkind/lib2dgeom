#include "line2.h"

#include <math.h>

/*constructor*/ line2::line2(double rho, double theta)
{
	this->rho = rho;
	this->theta = theta;
}

/*constructor*/ line2::line2(vector2d A, vector2d B)
{
	theta = atan2((B.y - A.y), (B.x - A.x)) + M_PI / 2;
	rho = A.x * cos(theta) + A.y * sin(theta);
}

/*destructor*/ line2::~line2()
{
	//
}

vector2d line2::intersection(const line2 &l)
{
	vector2d res;
	double denom = sin(theta) * cos(l.theta) - sin(l.theta) * cos(theta);
	if(denom == 0)
	{
		res.x = res.y = std::numeric_limits<double>::infinity();
	}

	res.y = (rho * cos(l.theta) - l.rho * cos(theta)) / denom;

	// выбираем по какой прямой считать x: берём ту, у которой угол ближе к пи/4.
	double c = fabs(M_PI / 4.0 - fmod(theta, M_PI / 2.0));
	double d = fabs(M_PI / 4.0 - fmod(l.theta, M_PI / 2.0));

	if(c < d)
	{
		res.x = (res.y * sin(theta) - rho) / cos(theta);
	}
	else
	{
		res.x = (res.y * sin(l.theta) - l.rho) / cos(l.theta);
	}

	return res;
}
