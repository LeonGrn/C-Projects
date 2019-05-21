/*
 * DList_Gen.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "DList_Gen.h"


//////////////////////////////////////////
// Init
// Aim:		create new list
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL DL_init(DLIST* pList)
{
	if ( pList == NULL ) return False;	// no list to initialize

	pList->head.next = NULL;
	pList->head.prev = NULL;

	return True;
}


/////////////////////////////////////////////////////////////////
// Insert
// Aim:		add new node
// Input:	pointer to the node BEFORE the place for the new one
//			a value to be stored in the new node
// Output:	pointer to the new node
/////////////////////////////////////////////////////////////////
D_NODE* DL_insert(D_NODE* pNode, DATA value)
{
	D_NODE* newN;
	if(pNode == NULL)
		return NULL;
	newN = (D_NODE*)malloc(sizeof(D_NODE));
	if(!newN)
		return NULL;

	newN->key = value;
	newN->next = pNode->next;
	newN->prev = pNode;
	if(pNode->next != NULL) //not the last Node
		pNode->next->prev = newN;
	pNode->next = newN;
	return newN;
}


//////////////////////////////////////////////////////////////
// Delete
// Aim:		erase node
// Input:	pointer to the node to be deleted
// Output:	TRUE if succeeded
//////////////////////////////////////////////////////////////
BOOL DL_delete(D_NODE* pNode)
{
	if(pNode == NULL)
		return False;

	if(pNode->prev != NULL)
		pNode->prev->next = pNode->next;

	if(pNode->next != NULL) //not last node
		pNode->next->prev = pNode->prev;

	free(pNode);
	return True;
}


/////////////////////////////////////////////////////////
// Find
// Aim:		search for a value
// Input:	pointer to the node to start with
//			a value to be found
// Output:	pointer to the node containing the Value
/////////////////////////////////////////////////////////
D_NODE* DL_find(D_NODE* pNode, DATA value, int (*compare)(const void* , const void*))
{
	D_NODE* temp=NULL;
	while(pNode!= NULL)
	{
		if(compare(pNode->key,value) == 0)
		{
			temp = pNode;
			break;
		}
		pNode = pNode->next;
	}

	return temp;
}


////////////////////////////////////////////////
// Free (additional function)
// Aim:		free the list memory
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
////////////////////////////////////////////////
BOOL DL_free(DLIST* pList)
{
	D_NODE *tmp;
	BOOL bCont = True;

	if (!pList)
		return False;

	while(bCont)
	{
		tmp = pList->head.next;
		if(!tmp)
			bCont = False;
		else
			if(!DL_delete(tmp))
				bCont = False;
	}
	return True;
}


////////////////////////////////////////////////
// Print (additional function)
// Aim:		print the list content (assume the DATA is int)
// Input:	pointer to the list structure
// Output:	a number of the printed elements
////////////////////////////////////////////////


int DL_print(DLIST* pList, void (*print)(const void*))
{
	D_NODE	*tmp;
	int		c = 0;

	if (!pList) return 0;

	printf("\n");
	for (tmp = pList->head.next; tmp; tmp = tmp->next, c++)
		print(tmp->key);
	printf("\n");
	return c;
}
