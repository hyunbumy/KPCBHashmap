#ifndef HASHMAP_H
#define	HASHMAP_H

#include<string>

template<typename T>
class Hashmap
{
public:
	Hashmap(int size);
	~Hashmap();
	bool set(std::string key, T value);
	T getValue(std::string key);
	T deleteValue(std::string key);
	float load();

private:
	int getIndex(std::string key);
	int size_;	// Size of the map
	int item_count;	// Number of items currently in the map
	T* map_;	// Pointer to the array table
};

template<typename T>
Hashmap<T>::Hashmap(int size) : size_(size), item_count(0)
{
	map_ = new T[size]();
}

template<typename T>
Hashmap<T>::~Hashmap()
{
	delete[] map_;
}

template<typename T>
bool Hashmap<T>::set(std::string key, T value)
{
	int ind = getIndex(key);
	if (!map_[ind])
	{
		map_[ind] = value;
		item_count++;
		return true;
	}

	return false;
}

template<typename T>
T Hashmap<T>::getValue(std::string key)
{
	if (map_[getIndex(key)] == nullptr)
		return nullptr;
	return map_[getIndex(key)];
}

template<typename T>
T Hashmap<T>::deleteValue(std::string key)
{
	auto curr = map_[getIndex(key)];
	if (curr)
	{
		auto val = curr;
		curr = nullptr;
		item_count--;
		return val;
	}
	return nullptr;
}

template<typename T>
float Hashmap<T>::load()
{
	return ((float)item_count) / size_;
}

/**
 *	Takes in the key as a string and hashes it
 *	Then returns its appropriate index in the map
 *	@param key a string key for a pair to be mapped
 *	@return index of the map for the pair
 */
template<typename T>
int Hashmap<T>::getIndex(std::string key)
{
	std::hash<std::string> key_hash;
	return key_hash(key) % size_;
}

#endif