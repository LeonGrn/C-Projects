#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "City.h"
#include "Kindergarten.h"
#include "Child.h"
#include "General.h"

void readCity(City* pCity, int binary)
{
	char fileName[100];
	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}
	if (binary)
		strcpy(fileName, DATA_FILE_BIN);
	else
		strcpy(fileName, DATA_FILE);
	pCity->pGardenList = readAllGardensFromFile(fileName, &pCity->count,binary);
	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void	showCityGardens(City* pCity)
{
	showAllGardens(pCity->pGardenList, pCity->count);
	printTest(pCity);
}

void	showSpecificGardenInCity(City* pCity)
{
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity, int binary)
{
	char fileName[100];
	if (binary)
		strcpy(fileName, DATA_FILE_BIN);
	else
		strcpy(fileName, DATA_FILE);
	writeGardensToFile(pCity->pGardenList, pCity->count, fileName,binary);
}

void cityAddGarden(City* pCity)
{
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL)//Allocation error
		printf("Error adding kindergarten\n");
}

void	addChildToSpecificGardenInCity(City* pCity)
{
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void	birthdayToChild(City* pCity)
{
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int	countChova(City* pCity)
{
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++)
	{
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void	sortCityGardensByName(City* pCity)
{
	insertionSort(pCity->pGardenList, pCity->count, sizeof(Garden*), compareGardenByName);
}

void	sortCityGardensByTypeCount(City* pCity)
{
	qsort(pCity->pGardenList, pCity->count, sizeof(Garden*), compareGardenByTypeAndCount);

}

void	sortChildInAGarden(City* pCity)
{
	Garden* pGarden;

	pGarden = getGardenAskForName(pCity->pGardenList, pCity->count);
	if (pGarden == NULL)
	{
		printf("no such Kindergarten\n");
		return;
	}

	insertionSort(pGarden->childPtrArr, pGarden->childCount, sizeof(Child*), compareChildrenId);
}

void printTest(City* pCity)
{
	if (pCity->count >= 3)
	{
		printf("Kindergarten Info:\n");
		printStringInt(pCity->pGardenList[0]->name, pCity->pGardenList[0]->childCount,
				pCity->pGardenList[1]->name, pCity->pGardenList[1]->childCount,
				pCity->pGardenList[2]->name, pCity->pGardenList[2]->childCount, NULL);
	}
}

void	kindergartensLinkedList(City* pCity)
{
	GardenType type;
	DLIST* plst;

	type =	getTypeOption();
	plst = createLinkedListForKindergartenType(pCity,type);
	if(plst == NULL)
	{
		printf("Error creating list\n");
		return;
	}

	printf("Kindergartens list:\n");
	if(!displayKindergartensFroList(plst))
		printf("Error printing list\n");

	DL_free(plst);
	free(plst);
}

DLIST*	createLinkedListForKindergartenType(City* pCity,GardenType type)
{
	int i;
	Garden* pTemp;
	DLIST*	plst;

	plst = (DLIST*)malloc(1*sizeof(DLIST));
	if(!plst)
		return NULL;

	if(!DL_init(plst))
		return NULL;

	D_NODE* node = &plst->head;

	for(i = 0; i< pCity->count; i++)
	{
		if(pCity->pGardenList[i]->type == type)
		{
			pTemp = pCity->pGardenList[i];
			node = DL_insert(node,pTemp);
			if(node == NULL)
				return 0;
		}
	}
	return plst;
}

int	displayKindergartensFroList(DLIST* plst)
{

	return DL_print(plst,showGardenGen);

}


void	releaseCity(City* pCity)
{
	release(pCity->pGardenList, pCity->count);
}
