#ifndef __KINDERGARTEN__
#define __KINDERGARTEN__

#include "Child.h"

typedef enum
{
	Chova,
	TromChova,
	TromTromChova,
	NofTypes
} GardenType;

const char* GardenTypeName[NofTypes];

typedef struct
{
	char* name;
	GardenType  type;
	Child** childPtrArr;
	int		childCount;
}Garden;


Garden**	readAllGardensFromFile(char* fileName, int* pGardenCount,int binary);
void		readGarden(FILE* fp, Garden* pGarden, int binary);
int			getGardenCountFromFile(FILE* fp, int binary);
void		readNameTypeCountBinary(FILE* fp, Garden* pGarden);
void		readNameTypeCountText(FILE* fp, Garden* pGarden);

GardenType	getTypeOption();

void	showAllGardens(Garden** pGardenList, int count);
void	showGarden(const Garden* pGarden);
void	showGardenGen(const void* pVoid);

void	writeGardensToFile(Garden** pGardenList, int gardenCount, char* fileName, int binary);
void	writeGarden(FILE* fp,const Garden* pGarden, int binary);
void	writeNameTypeCountBinary(FILE* fp,const Garden* pGarden);
void	writeNameTypeCountText(FILE* fp,const Garden* pGarden);



void	addChildToGarden(Garden** pGardenList, int gardenCount);
Garden**	addGarden(Garden** pGardenList, int* pGardenCount);

void	showGardenMenu(Garden** pGardenList, int count);
Garden*	getGardenAskForName(Garden** pGardenList, int count);

Garden*	findGardenByName(Garden** pGardenList, int count,const char* name);

Child*	getChildAskForId(Garden* pGarden);

void	getGardenFromUser(Garden* pGarden, Garden** pGardenList, int count);
void	getChildCheckIdFromUser(Child* pChild,const Garden* pGarden);

void	handleBirthdayToChild(Garden** pGardenList, int count);

int		compareGardenByName(const void* e1, const void* e2);
int		compareGardenByTypeAndCount(const void* e1, const void* e2);


void	release(Garden** pGardenList, int count);








#endif
