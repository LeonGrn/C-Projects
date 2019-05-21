#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"
#include "DList_Gen.h"

#define DATA_FILE "DataFile.txt"
#define DATA_FILE_BIN "DataFile.bin"

typedef struct
{
	Garden** pGardenList;
	int count;
}City;


void	readCity(City* pCity,int binary);
void	showCityGardens(City* pCity);
void	showSpecificGardenInCity(City* pCity);
void	saveCity(City* pCity, int binary);
void	cityAddGarden(City* pCity);
void	addChildToSpecificGardenInCity(City* pCity);
void	birthdayToChild(City* pCity);
int		countChova(City* pCity);
void	sortCityGardensByName(City* pCity);
void	sortCityGardensByTypeCount(City* pCity);
void	sortChildInAGarden(City* pCity);
void	printTest(City* pCity);
void	kindergartensLinkedList(City* pCity);
DLIST*	createLinkedListForKindergartenType(City* pCity,GardenType type);
int		displayKindergartensFroList(DLIST* plst);
void	releaseCity(City* pCity);

#endif
