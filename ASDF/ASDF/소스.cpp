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
	int i, j, r = 1;
	int temp;
	int size;
	int count = 0;
	int pivot;

	int pivotlist[100] = {};


	pivot = array[MAX - 1]; // pivot �� �ǿ����� 
	pivotlist[count] = pivot;
	count++;
	/*
	for (i = 0; i < MAX; i++)
	{
	printf("%d ", array[i]); //�迭Ȯ��
	}*/

	printf("\n\n %d \n\n", pivot); // pivotȮ��

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

	temp = array[pivot];
	array[pivot] = array[MAX - 1];
	array[MAX - 1] = temp;
	// �ǿ����ʿ� �ִ� pivot�� pivot�ڸ��� ������

	printf("\n\n\n");
	printf("pivot������ �迭 =  ");
	for (i = 0; i < pivot + 1; i++)
	{
		printf("%d ", array[i]); //�迭Ȯ��
	}

	while (pivot > 1)
	{
		size = pivot;
		pivot = array[size - 1];
		printf("\n\n\n");

		pivotlist[count] = pivot;
		count++;
		printf("\n\n %d��° pivot = %d \n\n", count, pivot);

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
		array[pivot] = array[size - 1];
		array[size - 1] = temp;

		printf("\n\n\n");
		printf("size = %d\n", size);
		printf("array[size] = %d \n", array[size]);
		printf("pivot = %d \n", pivot);
		printf("array[pivot] = %d \n", array[pivot]);
		printf("\n\n\n");

		for (i = 0; i < pivot + 1; i++)
		{
			printf("%d ", array[i]); //�迭Ȯ��
		}

	}
	/////////////////////////////////////////////////
	//������� ����& Ȯ��
	// ���� �������� ���ʺ��� 0 1 ������ ������ ��
	////////////////////////////////////////////////


	//pivotlist �� ������� count�� ���� ��

	//��
	while (r)
	{
		r++;
		count--;
		if (count == 0)
			break;
		pivot = pivotlist[count - 1];

		printf("�̰� ����� ���ư��� ��Ű��Ű");

		while (pivot > r * 2 - 1)
		{
			size = pivot;
			pivot = array[size - 1];
			printf("\n\n\n");


			printf("\n\n %d��° pivot = %d \n\n", count, pivot);

			i = r;
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
			array[pivot] = array[size - 1];
			array[size - 1] = temp;

			printf("\n\n\n");
			printf("size = %d\n", size);
			printf("array[size] = %d \n", array[size]);
			printf("pivot = %d \n", pivot);
			printf("array[pivot] = %d \n", array[pivot]);
			printf("\n\n\n");

			for (i = 0; i < pivot + 1; i++)
			{
				printf("%d ", array[i]); //�迭Ȯ��
			}
		}
	}
	/*
	while (count)
	{
	count--;

	pivot = array[pivotlist[count - 2]-1]; //���� pivot-1�ڸ��� ���ο� pivot

	i = pivotlist[count]+1; //�ٷ� �� pivot ���� ���� ����
	j = pivot - 1; // pivot�ձ��� ����

	printf("\n\n pivot = %d\n i = %d\n j = %d\n\n", pivot, i, j);

	while (1) // �ٽ� ���� ������
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

	printf("\n\n");

	for (i = 0; i < pivot + 1; i++)
	printf("%d ", array[i]);

	break;
	}*/

	// �̰� �ɰ��ϳ� �̤�


	// ������ arrayȮ�ο�
	printf("\n\n %d \n\n", pivot);
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);


	}
}