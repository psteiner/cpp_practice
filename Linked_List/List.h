// List.h
// Template List class definition

#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;

// ListNode class definition
#include "Listnode.h"

template< typename NODETYPE >
class List
{
public:
    // ctor
    List();
    // dtor
    ~List();

    void insertAtFront(const NODETYPE &);
    void insertAtBack(const NODETYPE &);
    bool removeFromFront(NODETYPE &);
    bool removeFromBack(NODETYPE &);
    bool isEmpty() const;
    void print() const;

private:
    ListNode< NODETYPE > *firstPtr;
    ListNode< NODETYPE > *lastPtr;

    // utility function to allocation new node
    ListNode< NODETYPE > *getNewNode( const NODETYPE &);
};

// default ctor
template< typename NODETYPE >
List< NODETYPE >::List() : firstPtr(0), lastPtr(0)
{
    // empty body
}

// destructor
template< typename NODETYPE >
List< NODETYPE>::~List()
{
    // list is not empty
    if(!isEmpty())
    {
        cout << "Destroying all nodes...!\n";
        ListNode< NODETYPE > *currentPtr = firstPtr;
        ListNode< NODETYPE > *tempPtr;

        while( currentPtr != 0)
        {
            tempPtr = currentPtr;
            cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }

    cout << "All ur nodes iz destroyd!\n\n";
}

// insert node at front of list
template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
    // new node
    ListNode< NODETYPE > *newPtr = getNewNode(value);

    // List is empty
    if(isEmpty())
    {
        // new list has only one node
        firstPtr = lastPtr = newPtr;
    }
    else
    {
        // link new node to previous first node
        newPtr->nextPtr = firstPtr;
        // link firstPtr at new node
        firstPtr = newPtr;
    }
}

// insert node at back of list
template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
    // new node
    ListNode< NODETYPE > *newPtr = getNewNode(value);

    // List is empty
    if(isEmpty())
    {
        // new list has only one node
        firstPtr = lastPtr = newPtr;
    }
    else
    {
        // update previous last node
        lastPtr->nextPtr = newPtr;
        // link lastPtr to new last node
        lastPtr = newPtr;
    }
}


// delete node from front of list
template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront(NODETYPE &value)
{
    if(isEmpty())
    {
        return false;
    }
    else
    {

    }
}
#endif
