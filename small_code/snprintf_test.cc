#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char src[10];
	char des[100];

	memset(src, 0 ,sizeof(src));
	char* cdes = strncpy(des, src, sizeof(des)-1);
	snprintf(des,sizeof(des), "late value.");
	
	printf("returned: %s\nvalue: %s\n",cdes, des);

	return 0;
} 
