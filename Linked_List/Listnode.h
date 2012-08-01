// Listnode.h
// Template ListNode class definition
#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of List class
template< typename NODETYPE > class List;

template< typename NODETYPE >
class ListNode
{
    // make List a friend
    friend class List< NODETYPE >;

public:
    // CTOR
    ListNode(const NODETYPE &);
    // return data in node
    NODETYPE getData() const;
private:
    // data
    NODETYPE data;
    // next node in list
    ListNode< NODETYPE > * nextPtr;
};

// ctor
template< typename NODETYPE >
ListNode< NODETYPE >::ListNode(const NODETYPE &info) : data(info), nextPtr(0)
{
    // empty body
}

template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const
{
    return data;
}

#endif