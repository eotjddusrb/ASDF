#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000 // n = 1000


void shuffle();
void QuickSort();
void Devide(int array[]);

//���� �����Լ�

// left  right �Լ��� ���� �迭�� ������ ���� �³׸� �Լ��� ������ 
// �� �Լ����� ó���� �� ���� �� �ְ� �Ͽ� �迭�� ������ ������ �ʾƵ� �ǵ��� �ϸ� ���ٴ�.
// ����Լ�


// �˰���...

// �迭 ��������
int array[MAX] = { 0 };



void main()
{
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
	int i, j;
	int temp;
	/*
	int li = 0;
	int ri = 0;
	int left[MAX] = {};
	int right[MAX] = {};
	*/
	int pivot; 



	pivot = array[MAX-1];

	//int�ڷ����� �Լ��� ���� ri, li�� �����ؾߵɵ�

	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);
	}


	printf("\n\n\n %d \n\n", pivot);
	
	i = 0;
	j = MAX - 2;
	
	while (1)
	{
		if (array[i] > pivot && array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			printf("swap ");
		}

		if (array[i] < pivot)
		{
			printf("i++ ");
			i++;
		}

		if (i >= pivot)
		{
			break;
		}

		if (array[j] > pivot)
		{
			j--;
			printf("j-- ");
		}
	}
	

	//������� ����
	printf("\n\n\n %d \n\n", pivot);
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);
	}

	


	//Devide(left); // �迭�� ���� �� �̸��� �ִ´�.
	
	/*
	//Ȯ���� ���
	printf("\n\n\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", left[i]);
	}

	printf("\n\n %d \n\n", pivot);

	for (i = 0; i < MAX; i++)
	{
		printf("%d ", right[i]);
	}
	*/

}
/*
void Devide(int array[MAX])
{
	int i;
	int count;

	for (count = 0; array[count] > 0; count++)
	{
		printf("count = ");
		printf("%d ", count);
	}
	

}*/