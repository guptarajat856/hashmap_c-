
template <typename K, typename V>
class HashNode
{
public:
	HashNode(const K &key, const V &value) :
		_key(key), _value(value), _next(NULL)
	{
	}

	K getKey() const
	{
		return _key;
	}

	V getValue() const
	{
		return _value;
	}

	void setValue(V value)
	{
		_value = value;
	}

	HashNode *getNext() const
	{
		return _next;
	}

	void setNext(HashNode *next)
	{
		_next = next;
	}

private:
	K _key;
	V _value;
	HashNode *_next;
	HashNode(const HashNode&);
	HashNode &operator=(const HashNode&);
};