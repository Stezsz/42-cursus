#include "searchable_tree_bag.hpp"
#include <cstdlib>

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other)
{
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{
}

bool searchable_tree_bag::search_node(node* n, int value)
{
	if (n == 0)
		return false;

	if (n->value == value)
		return true;

	if (value < n->value)
		return search_node(n->l, value);
	else
		return search_node(n->r, value);
}

bool searchable_tree_bag::has(int value) const
{
	return search_node(tree, value);
}
