#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "General.h"


static const char* optionStr[NofOptions] =
{
	"Exit","Read City information from file",
	"Show all Kindergartens","Show a specific Kindergarten",
	"Save City information to file","Add a Kindergarten",
	"Add a Child","Birthday to a Child",
	"Count Hova childres",
	"Sort Kindergartens by name",
	"Sort Kindergartens by type and children numbers",
	"Sort children in a Kindergarten",
	"Kindergartens in Linked list"
};


/**************************************************/
int menu()
/**************************************************/
/**************************************************/
{
	int option,i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for(i = 0 ; i < NofOptions; i++)
		printf("\n\t%d. %s.",i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr)
{
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*)malloc(len*sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p)
{
	if (!p)
	{
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

void insertionSort(const void* list, int count, int sizeOfType, int(*fptr)(const void*, const void*))
{
	int i, j;
	char* currentKey;

	char *pList = (char*)list;
	currentKey = (char*)malloc(sizeOfType * sizeof(char));

	for (i = 1; i < count; i++)
	{
		memcpy(currentKey, pList + i*sizeOfType, sizeOfType);
		for (j = i - 1; j >= 0 && (fptr(pList + j*sizeOfType, currentKey) > 0); j--)
			memcpy(pList + (j+1)*sizeOfType, pList + j*sizeOfType, sizeOfType);

		memcpy(pList + (j + 1)*sizeOfType, currentKey, sizeOfType);
	}
	free(currentKey);
}

void	printStringInt(char* name, ...)
{
	va_list parameters;
	char* str;
	int temp;
	
	va_start(parameters, name);
	str = name;
	while (str != NULL)
	{
		temp = va_arg(parameters, int);
		printf("%s ---->  %d\n",str,temp);
		str = va_arg(parameters, char*);
	}
	va_end(parameters);
}

int		compareInt(const void* n1, const void* n2)
{
	int num1  = *(int*)n1;
	int num2  = *(int*)n2;
	return num1-num2;
}

void	checkinsertionSort()
{
	int arr[] = {6,9,3,1,0,8,-10,80};
	int length = sizeof(arr)/sizeof(int);
	printArr(arr,length);

	insertionSort(arr,length , sizeof(int), compareInt);

	printArr(arr,length);

}

void	printArr(const int* arr, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ",arr[i]);
	printf("\n");

}




