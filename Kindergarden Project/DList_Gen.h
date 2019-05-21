/*
 * DList_Gen.h
 *
 */

#ifndef DLIST_GEN_H_
#define DLIST_GEN_H_

#include "def.h"



/*** Definitions ***/

// Node
typedef struct d_node
{
	DATA			key;
	struct d_node*	next;
	struct d_node*	prev;
}D_NODE;


// List
typedef struct
{
	D_NODE head;
}DLIST;


/*** Function prototypes ***/

BOOL DL_init(DLIST* pList);					// create new list

D_NODE* DL_insert(D_NODE* pNode, DATA value);	// add new node after *pNode

BOOL DL_delete(D_NODE* pNode);					// erase node after *pNode

D_NODE* DL_find(D_NODE* pNode, DATA value,int (*compare)(const void* , const void*)); // return a pointer to the node

BOOL DL_free(DLIST* pList);					// free list memory

int DL_print(DLIST* pList,void (*print)(const void*));					// print the list content


#endif /* DLIST_GEN_H_ */
