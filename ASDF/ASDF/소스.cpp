#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // n = 1000
// n= 10000 ���� Ȯ�ε�

void shuffle();
void Print();
void QuickSort(int, int);
void swap(int*, int*);
void MergeSort(int, int);
void MergeArray(int, int, int);

//���� �����Լ�

// left  right �Լ��� ���� �迭�� ������ ���� �³׸� �Լ��� ������ 
// �� �Լ����� ó���� �� ���� �� �ְ� �Ͽ� �迭�� ������ ������ �ʾƵ� �ǵ��� �ϸ� ���ٴ�.
// ����Լ�


// �˰���...

// �迭 ��������
int array[MAX] = { 0 };

int prev_array[MAX] = {};
int next_array[MAX] = {};

void main()
{
	int i;
	int r;

	srand(time(NULL));

	for (i = 0; i < MAX; i++) //�迭�Ҵ� 
		array[i] = i;

	shuffle();

	printf("------- Quick Sort �ϱ� �� -------\n");
	Print();
	QuickSort(0, MAX-1);
	printf("\n\n------- Quick Sort �� -------\n");
	Print();

	for (i = 0; i < MAX; i++)
		prev_array[i] = i;

	for (i = 0; i < MAX; i++)
	{
		r = rand() % MAX;
		swap(&prev_array[i], &prev_array[r]);
	}

	printf("\n\n------- Merge Sort �ϱ� �� -------\n");
	for (i = 0; i < MAX; i++)
		printf("%4d ", prev_array[i]); //�迭Ȯ��
	MergeSort(0, MAX-1);
	printf("\n\n------- Merge Sort �� -------\n");
	for (i = 0; i < MAX; i++)
		printf("%4d ", prev_array[i]); //�迭Ȯ��
	printf("\n\n\n");
	for (i = 0; i < MAX; i++)
		printf("%4d ", next_array[i]); //�迭Ȯ��
}

void shuffle()
{
	int i, r;

	for (i = 0; i < MAX; i++)
	{
		r = rand() % MAX;
		swap(&array[i], &array[r]);
	}
}

void Print()
{
	int k;

	for (k = 0; k < MAX; k++)
		printf("%4d ", array[k]); //�迭Ȯ��
}

void QuickSort(int left, int right)
{
	int pivot;
	int i, j;

	if (left <= right)
	{
		/*
		if (array[right] == 0)
		{
			swap(&array[right], &array[0]); // �߰��� pivot�� 0���� ������ �Ǹ�
			printf("\n\n 0�� �مf�� \n\n"); // ����� ������ ����� ��찡 �߻�
		}
	*/
		pivot = array[right];

		i = left - 1;
		j = right;
		
		while (1)
		{
			while (array[++i] < pivot);
			while (array[--j] > pivot);
			if (i > j)
				break;
			swap(&array[i], &array[j]);
		}
		swap(&array[pivot], &array[right]);
		
		QuickSort(left, pivot - 1);
		QuickSort(pivot + 1, right);
	}
}

void swap(int*A, int*B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

void MergeSort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(low, mid);
		MergeSort(mid + 1, high);
		MergeArray(low, mid, high);
	}
}

void MergeArray(int low, int mid, int high)
{
	int i, j, k, l;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high)   // ���ʹٱ��ϰ� ������������ �ݺ�
	{
		if (prev_array[i])
		{
			next_array[k] = prev_array[i];
			i++;
		}
		else
		{
			next_array[k] = prev_array[j];
			j++;
		}
		k++;
	}
	
	if (i > mid)
	{
		for (; j <= high; j++)
		{
			next_array[k] = prev_array[j];
			k++;
		}
	}
	else
	{
		for (; i <= mid; i++)
		{
			next_array[k] = prev_array[i];
			k++;
		}
	}

	for (l = low; l <= high; l++)
	{
		next_array[l] = prev_array[l]; // prev_array[l] = next_array[l];
	}
}





/*

////
void Quick_Sort()
{
	int i, j, r = 1;
	int temp;
	int size;
	int count = 0;
	int pivot;


	int pi1 = 0;
	int pi2 = 0;
	int set = 0;

	int pivotlist[100] = {};


	pivot = array[MAX - 1]; // pivot �� �ǿ����� 
	pivotlist[count] = pivot;
	count++;
	
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]); //�迭Ȯ��
	}

	i = 0;
	j = MAX - 2;


	while (1)
	{
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
				printf("\n i = %d \n pivot = %d \n", i, pivot);
				break;
			}

			if (array[j] > pivot)
			{
				j--;
			}
		}

		for (i = 0; i < pivot; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
		
		temp = array[pivot];
		array[pivot] = array[MAX - 1];
		array[MAX - 1] = temp;
		

		// �ǿ����ʿ� �ִ� pivot�� pivot�ڸ��� ������
		printf("\n\nset1 = %d\n\n", set);
		for (; array[set] == set ; set++) //���ĵ� ���� ����������
		{
			printf("\n\nset2 = %d\n\n", set);
		}

		if (set >= pivot)
			break;

		//�켱 �¸� �����غ���


		pivotlist[count] = pivot; // �̰�  �ʹ� �ɰ���
		count++;
		
		if (array[pivot - 1] == 0)
		{
			temp = array[pivot - 1];
			array[pivot - 1] = array[0];
			array[0] = temp;
		}
		
		pivot = array[pivot - 1];

		i = set;
		j = pivot - 1;



	}




	// ������ ��¥�� ¥����

/*



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









	////////*
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
	////////////////////////////////
	printf("\n\n");

	for (i = 0; i < pivot + 1; i++)
	printf("%d ", array[i]);

	break;
	}

	// �̰� �ɰ��ϳ� �̤�


	// ������ arrayȮ�ο�
	printf("\n\n %d \n\n", pivot);
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);


	}
}

*/