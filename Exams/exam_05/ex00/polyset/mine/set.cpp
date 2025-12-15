#include "set.hpp"

set::set(searchable_bag& bag) : _bag(&bag)
{
}

set::set(const set& other) : _bag(other._bag)
{
}

set& set::operator=(const set& other)
{
	if (this != &other)
		_bag = other._bag;
	return *this;
}

set::~set()
{
}

void set::insert(int value)
{
	if (!_bag->has(value))
		_bag->insert(value);
}

void set::insert(int* array, int size)
{
	for (int i = 0; i < size; i++)
		insert(array[i]);
}

bool set::has(int value) const
{
	return _bag->has(value);
}

void set::print() const
{
	_bag->print();
}

void set::clear()
{
	_bag->clear();
}

searchable_bag& set::get_bag() const
{
	return *_bag;
}
