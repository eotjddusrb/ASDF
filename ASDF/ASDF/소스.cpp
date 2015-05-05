#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000 // n = 1000


void shuffle();
void QuickSort();


//이제 정렬함수

// left  right 함수를 만들어서 배열이 나뉘어 질때 걔네를 함수로 보내서 
// 그 함수에서 처리된 후 나올 수 있게 하여 배열을 여러개 만들지 않아도 되도록 하면 좋겟다.
// 재귀함수


// 알고리즘...

// 배열 전역변수
int array[MAX] = { 0 };



void main()
{
	
	int i, r, temp;


	srand(time(NULL));

	shuffle();
	
	QuickSort();
	
}

void shuffle()
{
	int i, r, temp;

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

void QuickSort()
{ 
	int i, r;
	int li = 0;
	int ri = 0;
	int left[MAX] = {};
	int right[MAX] = {};
	int pivot;

	r = rand() % MAX;
	pivot = array[r];

	for (i = 0; i < MAX; i++)
	{
		if (array[i] > pivot)
		{
			right[ri] = array[i];
			ri++;
		}
		else
		{
			left[li] = array[i];
			li++;
		}
	} //int자료형의 함수를 만들어서 ri, li를 리턴해야될듯




	for (i = 0; i < MAX; i++)
	{
		printf("%d ", left[i]);
	}

	printf("\n %d \n", pivot);

	for (i = 0; i < MAX; i++)
	{
		printf("%d ", right[i]);
	}





}