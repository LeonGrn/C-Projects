#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"




int main(int argc, char* argv[])
{
	City utz = { NULL,0 };
	int uReq;
	int binary;
	if (argc != 2)
	{
		printf("You must enter 1 for binary file 0 for test file\n");
		printf("For example .\\HW4 1\n");
		return 0;
	}

	sscanf(argv[1], "%d", &binary);
	//first time read
	readCity(&utz,binary);
	do
	{
		uReq = menu();
		switch (uReq)
		{
		case  READ_CITY:
			readCity(&utz, binary);
			break;

		case  SHOW_CITY:
			showCityGardens(&utz);
			break;

		case  SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case  WRITE_CITY:
			saveCity(&utz, binary);
			break;

		case  ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case  ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case  CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",countChova(&utz));
			break;

		case SORT_GARDENS_BY_NAME:
			sortCityGardensByName(&utz);
			break;

		case SORT_GARDENS_BY_TYPE_COUNT:
			sortCityGardensByTypeCount(&utz);
			break;

		case SORT_CHILDS:
			sortChildInAGarden(&utz);
			break;

		case GARDEN_LL:
			kindergartensLinkedList(&utz);
			break;

		}
	}while (uReq!=EXIT);
	
	releaseCity(&utz);//free all allocations
	printf("Bye Bye");
	return EXIT_SUCCESS;
}

