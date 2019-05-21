#ifndef __PROTOTYPE__
#define __PROTOTYPE__

typedef enum
{
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,	
	ADD_GARDEN,	
	ADD_CHILD,	
	CHILD_BIRTHDAY,	
	COUNT_GRADUATE,
	SORT_GARDENS_BY_NAME,
	SORT_GARDENS_BY_TYPE_COUNT,
	SORT_CHILDS,
	GARDEN_LL,
	NofOptions
} MenuOptions;

int		menu();
char*	getStrExactLength(char* inpStr);
int		checkAllocation(const void* p);

void	insertionSort(const void* list, int count, int sizeOfType, int(*fptr)(const void*, const void*));
void	printStringInt(char* Name, ...);

int		compareInt(const void* n1, const void* n2);
void	checkinsertionSort();
void	printArr(const int* arr, int size);

#endif
