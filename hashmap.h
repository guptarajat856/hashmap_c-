#include "hashnode.h"
#include "keyhash.h"
#include <cstddef>

template <typename K, typename V, size_t tableSize, typename F = KeyHash<K, tableSize>>
class HashMap
{
public:
	HashMap() :
		table(), hashFunc()
	{
	}

	~HashMap()
	{
		for(size_t i =0; i <tableSize; i++)
		{
			HashNode<K, V> *entry = table[i];

			while(entry != NULL)
			{
				HashNode<K, V> *prev = entry;
				entry = entry -> getNext();
				delete prev;
			}

			table[i] = NULL;
		}
	}

	bool get(const K &key, V &val)
	{
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> *entry = table[hashValue];

		while (entry != NULL)
		{
			if (entry->getKey() == key)
			{
				val = entry->getValue();
				return true;
			}

			entry = entry->getNext();
		}

		return false;
	}

	void put(const K &key, const V &val)
	{
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];

		while (entry != NULL && entry->getKey() != key)
		{
			prev = entry;
			entry = entry -> getNext();
		}

		if (entry == NULL)
		{
			entry = new HashNode<K, V>(key, val);
			if (prev == NULL)
			{
				table[hashValue] = entry;
			} else {
				prev->setNext(entry);
			}
		} else {
			entry->setValue(val);
		}
	}

	void remove(const K &key)
	{
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];

		while (entry != NULL && entry->getKey() != key)
		{
			prev = entry;
			entry = entry -> getNext();
		}

		if (entry == NULL) {
			return;
		} else {
			if (prev == NULL) {
				table[hashValue] = entry -> getNext();
			} else {
				prev->setNext(entry->getNext());
			}

			delete entry;
		}
	}

private:
	HashMap(const HashMap&);
	const HashMap& operator=(const HashMap&);
	HashNode<K, V> *table[tableSize];
	F hashFunc;
};
