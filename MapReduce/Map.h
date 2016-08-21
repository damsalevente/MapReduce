#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

namespace MapReduce
{
	template<class Key, class Value>
	class KeyValueList
	{
		Key key;
		vector<Value> values;
	public:
		KeyValueList() {};
		KeyValueList(Key key, vector<Value> values):key(key), values(values) {};
		
		void printResult()const;
		ostream & operator<<(ostream &o);
	};
	template<class Key, class Value>
	class KeyValuePair
	{
		Key key;
		Value value;
	public:
		KeyValuePair() {};
		KeyValuePair(Key k, Value v) :key(k), value(v) {};
		void addKV(Key k, Value v);
		void printOut()const;
		Key getKey()const;
		Value getValue() const;


	};
	template<class Key, class Value>
	inline void KeyValuePair<Key, Value>::addKV(Key k, Value v)
	{
		key = k;
		value = v;
	}

	template<class Key, class Value>
	inline void KeyValuePair<Key, Value>::printOut() const
	{
		cout << this->key << " " << this->value << endl;
	}

	template<class Key, class Value>
	inline Key KeyValuePair<Key, Value>::getKey() const
	{
		return key;
	}

	template<class Key, class Value>
	inline Value KeyValuePair<Key, Value>::getValue() const
	{
		return value;
	}
	template<class Key,class Value>
	class Map
	{
		
		//This is what a got from a file
		vector<KeyValuePair<Key, Value>> source;
		//this is what i will get, Value* must be inicialised before passing the Value
		vector<KeyValueList<Key,Value>> result;
	public:
		void add( KeyValuePair<Key,Value>  kvp);
		void remove();
		vector<Value> getVectorWithKey(Key k);
		vector<Key> getKeys();
		void map();
		KeyValueList<Key,Value> getListWithIndex(int i)const ;
		KeyValueList<Key, Value>* getEverything()const;

	};
	class Reduce
	{

	};

	

	template<class Key, class Value>
	inline void Map<Key, Value>::add( KeyValuePair<Key,Value> kvp)
	{
		source.push_back(kvp);
	}

	template<class Key, class Value>
	inline void Map<Key, Value>::remove()
	{
		source.pop_back();
	}

	template<class Key, class Value>
	inline vector<Value> Map<Key, Value>::getVectorWithKey(Key k)
	{
		vector<Value> forReturn;
		for (auto it = source.cbegin(); it != source.cend(); ++it)
		{
			if (it->getKey() == k)
				forReturn.push_back(it->getValue());

		}
		return forReturn;
	}

	template<class Key, class Value>
	inline vector<Key> Map<Key, Value>::getKeys()
	{
		vector<Key> theReturned;
		for (auto it = source.cbegin(); it != source.cend(); ++it)
		{
			bool skip=false;
			for (auto before = source.cbegin(); before != it; ++before)
			{
				if (it->getKey() == before->getKey())
					skip = true;
			}
			if (skip == false)
			{
				theReturned.push_back(it->getKey());
			}
		}
		return theReturned;
	}

	template<class Key, class Value>
	inline void Map<Key, Value>::map()
	{
		vector<Key> keys = this->getKeys();
		for (auto it :keys)
		{
			
			result.push_back(KeyValueList<Key,Value>(it, getVectorWithKey(it)));
		}
	}

	template<class Key, class Value>
	inline KeyValueList<Key,Value> Map<Key, Value>::getListWithIndex(int i) const
	{
		return result[i];
	}

	template<class Key, class Value>
	inline KeyValueList<Key, Value>* Map<Key, Value>::getEverything() const
	{
		KeyValueList<Key, Value> *tmp=new KeyValueList<Key, Value>[result.size()];
		for (int i = 0; i < result.size(); i++)
		{
			tmp[i] = getListWithIndex(i);
		}
		return tmp;
	
	}









	template<class Key, class Value>
	inline void KeyValueList<Key, Value>::printResult() const
	{
		cout << "---------------------------------------" << endl;
		cout << "|Key name:\n";
		cout << "| "<<key << endl;
		cout << "|Elements:" << endl;
		for (int it=0;it<values.size();it++)
		{
			cout << "|  ";
			cout << values.at(it) << endl;
		}
		cout << "---------------------------------------" << endl;
	}


}