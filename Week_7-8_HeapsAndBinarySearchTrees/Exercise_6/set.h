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

	Set(const Set &s) : theSize{s.theSize}, tree{s.tree} {}

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
		return theSize() == 0;
	}

	void push(const Comparable &t)
	{
		insert(t);
	}

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const
	{
		return iterator(tree.findMin());
	}

	iterator end() const
	{
		return iterator(nullptr);
	}

	iterator insert(const Comparable &t)
	{
		iterator itr = find(t);
		if (itr == end())
		{
			tree.insert(t);
			++theSize;
		}
		return itr;
	}

	iterator find(const Comparable &t)
	{
		return iterator(tree.find(t));
	}

	iterator erase(iterator &itr)
	{
		iterator ret = itr;
		++ret;
		tree.remove(*itr);
		--theSize;
		return ret;
	}
};
