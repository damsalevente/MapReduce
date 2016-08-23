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
		inputFileSimulator.push_back(KeyValuePair<int, double>(i%3, sin(i)));
		mapper.add(inputFileSimulator[i]);
	}
	mapper.map();
	Reduce<int, double> reducer(mapper.getResult());
	reducer.reduceMax();
	reducer.printOut();
	cout << "Minimum " << endl;
	reducer.reduceMin();
	reducer.printOut();
	cout << "Sum" << endl;
	reducer.reduceSum();
	reducer.printOut();

	Map<int, string> Cica;
	Cica.add("catsM.csv");
	Cica.map();
	Reduce<int, string> CicaReduce(Cica.getResult());
	CicaReduce.reduceMax();
	CicaReduce.printOut();
	return 0;
}