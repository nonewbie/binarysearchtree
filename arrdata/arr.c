#include "arr.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief 
 *
 * @param arr[]
 * @param len
 */
void printarr(DataType arr[],int len)
{
	int i;
	for (i = 0;i < len; i++) {
		printf("%d\t",arr[i]);
	}
	printf("\n");	
}

void createarr(DataType arr[],int len)
{
	int i ;
	srand( time(NULL) );// stdlib.h
	for(i = 0;i < len; i++)	{
		arr[i] = rand()% RANGE;//stdlib.h
	}	
}

void swap(DataType *a, DataType *b)
{
	DataType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
