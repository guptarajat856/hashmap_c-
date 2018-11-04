#include <cstddef>

template <typename K, size_t tableSize>
struct KeyHash
{
	unsigned operator()(const K &key) const
	{
		return reinterpret_cast<unsigned long>(key) % tableSize;
	}
};