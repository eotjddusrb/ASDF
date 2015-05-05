#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000 // n = 1000


void shuffle();
void QuickSort();
void Devide(int pivot);

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
	int size;
	int count = 1;
	/*
	int li = 0;
	int ri = 0;
	int left[MAX] = {};
	int right[MAX] = {};
	*/
	int pivot; 

	pivot = array[MAX-1]; // pivot �� �ǿ����� 



	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]); //�迭Ȯ��
	}


	printf("\n\n\n %d \n\n", pivot); // pivotȮ��
	
	i = 0;
	j = MAX - 2;
	
	while (1) // 1�� ����
	{
		if (array[i] > pivot && array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}

		if (array[i] < pivot)
		{
			i++;
		}

		if (i >= pivot)
		{
			break;
		}

		if (array[j] > pivot)
		{
			j--;
		}
	}

	//������� Ȯ����
	temp = array[pivot];
	array[pivot] = array[MAX - 1];
	array[MAX - 1] = temp; 
	// �ǿ����ʿ� �ִ� pivot�� pivot�ڸ��� ������



	while (pivot > 2)
	{
		size = pivot;
		pivot = array[size - 1];


		i = 0;
		j = size - 2;


		while (1) // ���� ������
		{
			if (array[i] > pivot && array[j] < pivot)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}

			if (array[i] < pivot)
			{
				i++;
			}

			if (i >= pivot)
			{
				break;
			}

			if (array[j] > pivot)
			{
				j--;
			}
		}

		temp = array[pivot];
		array[pivot] = array[size- 1];
		array[size - 1] = temp;
		
		for (i = 0; i < size - 1; i++)
		{
			printf(" %d ", array[i]);
		}
		printf("\n\n %d��° pivot = %d \n\n", count , pivot);
		count++;
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
void Devide(int size)
{
	int i, j, temp;
	int pivot;
	int* left;

	left = (int*)malloc(size*sizeof(int));
	
	printf("\n\n ����̵� ����¼��\n\n\n");
	for (i = 0; i < size; i++)
	{
		left[i] = left[i];
		printf(" %d", left[i]);
	}

	printf("\n\n\n");

	pivot = left[size-1];

	i = 0;
	j = size - 2;

	while (1) 
	{
		if (left[i] > pivot && left[j] < pivot)
		{
			temp = left[i];
			left[i] = left[j];
			left[j] = temp;
			printf("swap ");
		}

		if (left[i] < pivot)
		{
			printf("i++ ");
			i++;
		}

		if (i >= pivot)
		{
			break;
		}

		if (left[j] > pivot)
		{
			j--;
			printf("j-- ");
		}
	}

	temp = left[pivot];
	left[pivot] = left[MAX - 1];
	left[MAX - 1] = temp;


	
	free(left);
}*/