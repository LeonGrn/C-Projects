#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"


/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild, int binary)
{
	if (binary)
	{
		char data[2];
		fread(data, sizeof(char), 2, fp);
		pChild->id = (data[1] & 0x1F) << 8 | (data[0]&0xFF);
		pChild->age = (data[1] >> 5) & 0x7;
	} else {
		//Child ID
		fscanf(fp, "%d", &pChild->id);
		fscanf(fp, "%d", &pChild->age);
	}
}


/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild)
{
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}


/**************************************************/
void getChildFromUser(Child* pChild, int id)
/**************************************************/
/**************************************************/
{
	pChild->id = id;

	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}


/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp,const Child* pChild, int binary)
{
	if (binary)
	{
		char data[2];
		data[0] = pChild->id & 0xFF;
		data[1] = pChild->id >> 8 | (pChild->age & 0x7)<<5;
		fwrite(data, sizeof(char), 2, fp);
	} else
		fprintf(fp,"%d %d\n",pChild->id, pChild->age);
}

//sort and search
int	findChildById(Child** pChildList, int count, int id)
{
	Child** hChild = NULL;

	Child temp = {id,0};
	Child* pTemp = &temp;

	qsort(pChildList, count, sizeof(Child*), compareChildrenId);
	hChild = (Child**)bsearch(&pTemp, pChildList, count, sizeof(Child*), compareChildrenId);

	if (!hChild)
		return -1;

	return hChild-pChildList; //will be the index

}

void birthday(Child* pChild)
{
	pChild->age++;
}

int compareChildrenId(const void* e1, const void* e2)
{
	Child* pCh1 = *(Child**)e1;
	Child* pCh2 = *(Child**)e2;

	return pCh1->id - pCh2->id;
}


//void	releaseChild(Child* pChild)
//{
//	//nothing to release
//}
