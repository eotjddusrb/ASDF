#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000 // n = 1000


void shuffle();
void QuickSort();


//���� �����Լ�

// left  right �Լ��� ���� �迭�� ������ ���� �³׸� �Լ��� ������ 
// �� �Լ����� ó���� �� ���� �� �ְ� �Ͽ� �迭�� ������ ������ �ʾƵ� �ǵ��� �ϸ� ���ٴ�.
// ����Լ�


// �˰���...

// �迭 ��������
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
	} //int�ڷ����� �Լ��� ���� ri, li�� �����ؾߵɵ�




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