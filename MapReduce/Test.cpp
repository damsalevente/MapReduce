#include <iostream>
#include "Map.h"
int main()
{
	using namespace std;
	using namespace MapReduce;
	KeyValuePair<int, string> firstElement(1950, "penis");
	KeyValuePair<int, string> secondElement(1950, "not penis");
	KeyValuePair<int, string> thirdElement(1933, "definitely not penis");
	firstElement.printOut();
	Map<int, string> myMap;
	myMap.add(firstElement);
	myMap.add(secondElement);
	myMap.add(thirdElement);
	vector<int> tomb;
	tomb=myMap.getKeys();
	for (auto it : tomb)
	{
		cout << it << endl;;
	}
	vector<string> another;
	another = myMap.getVectorWithKey(1950);
	cout << "1950 elements:" << endl;
	for (auto it : another)
	{
		cout << it << endl;
	}
	myMap.map();
	
	myMap.getListWithIndex(0).printResult();
	myMap.getListWithIndex(1).printResult();
	
	KeyValueList<int,string> *result=myMap.getEverything();
	for (int i=0;i<2;i++)
	{
		result[i].printResult();
	}

	return 0;
}