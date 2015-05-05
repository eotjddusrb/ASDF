#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // n = 1000
void QuickSort();
void shuffle();



//이제 정렬함수

void main()
{
	
	int i, r, temp;
	int mid = MAX/2;
	int array[MAX] = { 0 };
	int left[MAX] = {};
	int right[MAX] = {};


	for (i = 0; i < MAX; i++)
	{
		array[i] = i;
	}

	for (i = 0; i < MAX; i++)
	{
		r = rand() % MAX;
		temp = array[i];
		array[i] = array[r];
		array[r] = temp;
	}

	


}