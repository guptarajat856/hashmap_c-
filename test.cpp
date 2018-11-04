#include <iostream>
#include <string>
#include <assert.h>
#include "hashmap.h"

using namespace std;

int main()
{
	const size_t tableSize = 3;
	HashMap<int, string, tableSize, KeyHash<unsigned long, tableSize>> hmap;
    hmap.put(1, "1");
    hmap.put(2, "2");
    hmap.put(3, "3");
    hmap.put(4, "4");

    string value;
    bool result = hmap.get(2, value);
    assert(result);
    assert(value == "2");

    result = hmap.get(3, value);
    assert(result);
    assert(value == "3");

    result = hmap.get(45, value);
    assert(!result);

    hmap.remove(3);
    result = hmap.get(3, value);
    assert(!result);
}