#include "Triangle.h"
#include "cross_tr.h"

int main()
{
	int N = 0;
	std::cin >> N;
	triangle TRs[10000];
	for (int i = 0 ; i < N ; ++i)
		std::cin >> TRs[i];
	TRs[1].print();
	return 0;
}