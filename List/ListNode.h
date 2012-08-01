// ListNode.h
// Template ListNode class definition
//
// How to Program C++ (Deitel & Deitel)
// Chapter 21 - Data Structures
#pragma once

// forward declaration of class List required to announce that class List
// exists, so it can be used in the friend declation at line xx
template< typename NODETYPE > class List;

template< typename NODETYPE>
class ListNode
{
	// make List a friend
	friend class List< NODETYPE>;

public:
	// constructor
	ListNode(const NODETYPE &);

	// return data in node
	NODETYPE getData() const;

	// destructor
	~ListNode(void);

private:
	// data
	NODETYPE data;

	// pointer to next node in list
	ListNode< NODETYPE > * nextPtr;
};

