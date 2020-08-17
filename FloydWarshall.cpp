#include "FloydWarshall.h"

FloydWarshall::FloydWarshall(Reader read)
{
	std::vector<Point> list = read.getList();
	SIZE = list.size();
	for (auto el :list)
		roadsCost.insert(roadsCost.end(), el.getRoads().begin(),el.getRoads().end());
	for (size_t k = 0; k < SIZE; ++k)
		for (size_t i = 0; i < SIZE; ++i)
			for (size_t j = 0; j < SIZE; ++j)
				if (roadsCost[k + i * SIZE] != INT_MAX && roadsCost[j + k * SIZE] != INT_MAX)
				{
					int newCost = roadsCost[k + i * SIZE] + roadsCost[j + k * SIZE];
					roadsCost[j + i * SIZE] = roadsCost[j + i * SIZE] > newCost ? newCost : roadsCost[j + i * SIZE];
				}
}

void FloydWarshall::outPrint(int from_, int to_)
{
	std::cout << "Way from " << from_ << " to " << to_ << " costs " << roadsCost.at(to_ + SIZE * from_);
}
