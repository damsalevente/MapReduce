#include <iostream>
#include "Map.h"
int main()
{
	using namespace std;
	using namespace MapReduce;
	Map<int, double> mapper;
	vector<KeyValuePair<int, double>> inputFileSimulator;
	for (int i = 0; i < 100; i++)
	{
		inputFileSimulator.push_back(KeyValuePair<int, double>(i%2, sin(i)));
		mapper.add(inputFileSimulator[i]);
	}
	mapper.map();
	Reduce<int, double> reducer(mapper.getResult());
	reducer.reduceMax();
	reducer.printOut();
	return 0;
}