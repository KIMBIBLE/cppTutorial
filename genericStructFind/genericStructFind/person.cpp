#include "person.h"

int compareAge(void *vp1, void *vp2)
{
	vp1 = &((Person *)vp1)->age;
	if (*(int*)vp1 > *(int*)vp2)
		return 1;
	else if (*(int*)vp1 == *(int*)vp2)
		return 0;
	else
		return -1;
}

int compareName(void *vp1, void *vp2)
{
	vp1 = ((Person *)vp1)->name;
	vp2 = ((Person *)vp2)->name;
	return strcmp((char*)vp1, (char*)vp2);
}
