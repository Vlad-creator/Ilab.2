#include "Triangle.h"

int main()
{
	point p1(0 , 0 , 0);
	point p2(1 , 0 , 0);
	point p3(0 , 1 , 0);
	point p4(5 , 0 , 0);
	point p5(3 , 0 , 0);
	point p6(0 , 3 , 0);
	triangle t1(p1 , p2 , p3);
	triangle t2(p4 , p5 , p6);

	bool res = is_cross(t1 , t2);
	std::cout << res << std::endl;
	return 0;
}