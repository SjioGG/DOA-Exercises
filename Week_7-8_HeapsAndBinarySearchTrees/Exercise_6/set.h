#include <vector>
#include "binary_search_tree.h"

using namespace std;

template <typename Comparable>
class Set
{
private:
	size_t theSize;
	BinarySearchTree<Comparable> tree;

public:
	Set() : theSize(0) {}

	~Set() { clear(); }

	Set(const Set &s) : theSize(s.theSize), tree()
	{
		// Create an iterator to traverse the source set
		iterator it = s.begin();
		iterator end = s.end();

		// Iterate over the source set and insert its elements into the new set
		while (it != end)
		{
			insert(*it);
			++it;
		}
	}

	void clear()
	{
		tree.makeEmpty();
		theSize = 0;
	}

	size_t size() const
	{
		return theSize;
	}

	bool empty() const
	{
		if (theSize == 0)
			return true;
		else
			return false;
	}

	void push(const Comparable &t)
	{
		insert(t);
	}

	void print() { tree.printTree(); } // used for debugging

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const
	{
		return tree.findMin();
	}

	iterator end() const
	{
		return iterator(nullptr);
	}

	iterator insert(const Comparable &t)
	{
		if (tree.contains(t) == false)
		{
			++theSize;
			tree.insert(t);
		}
		return iterator(tree.find(t));
	}

	iterator find(const Comparable &t)
	{
		return iterator(tree.find(t));
	}
	iterator erase(iterator &itr)
	{
		tree.remove(*itr); // Remove the element using its stored value
		--theSize;		   // Decrease the size of the set
		return itr;		   // Returns uninitialized iterator, they didint specify
	}
};
