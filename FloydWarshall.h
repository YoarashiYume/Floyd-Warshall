#ifndef _FLOYDWARSHALL_H_
#define _FLOYDWARSHALL_H_
#include "Point.h"
#include "Reader.h"
class FloydWarshall
{
private:
	std::vector<int> roadsCost;
	int SIZE;
public:
	FloydWarshall(Reader read);
	void outPrint(int from_,int to_);
};
#endif // !1

