#ifndef __CHILD__
#define __CHILD__


typedef struct
{
	int	 id;
	int  age;
}Child;


void	readChild(FILE* fp, Child* pChild, int binary);
void	getChildFromUser(Child* pChild, int id);
void	showChild(const Child* pChild);
void	writeChild(FILE* fp,const Child* pChild,int binary);
int		findChildById(Child** pChildList, int count, int id);
void	birthday(Child* pChild);
int		compareChildrenId(const void* e1, const void* e2);
//void	releaseChild(Child* pChild);
#endif
