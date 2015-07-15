#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000 // n = 1000
// n= 10000 ���� Ȯ�ε�
// ���� �׽�Ʈ

void shuffle();
void Print(); //�迭 Ȯ��
void QuickSort(int, int);
void swap(int*, int*);
void MergeSort(int, int); // MergeSort�Լ��� ����Լ��� ����
void MergeArray(int, int, int); // ��;ȿ��� ����

// �迭 ��������
int array[MAX] = { 0 };
int next_array[MAX] = {};

void main()
{
	int i;
	int r;

	srand(time(NULL));

	shuffle();

	printf("------- Quick Sort �ϱ� �� -------\n");
	Print();
	QuickSort(0, MAX-1);
	printf("\n\n------- Quick Sort �� -------\n");
	Print();
	
	shuffle();

	printf("\n\n------- Merge Sort �ϱ� �� -------\n");
	Print();
	MergeSort(0, MAX-1);
	printf("\n\n------- Merge Sort �� -------\n");
	Print();
}

void shuffle()
{
	int i, r;

	for (i = 0; i < MAX; i++) //�迭�Ҵ� 
		array[i] = i;

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
	k = low; //���ĵ� �迭�� ���� �ڸ��� �����ִ� �ε���
	 
	while (i <= mid && j <= high)   // ���ʹٱ��ϰ� ������������ �ݺ� 
	{ 
		if (array[i] < array[j]) 
		{ 
			next_array[k] = array[i]; //���ʹ迭���� ���ų�
			i++; 
		} 
		else 
		{ 
			next_array[k] = array[j]; //������ �迭���� ���ų�
			j++; 
		} 
		k++; //�Է¹���
	} // ���ʹٱ��ϰ� ������������ �ݺ� 
	 
	if (i > mid) //
	{ 
		for (; j <= high; j++) 
		{ 
			next_array[k] = array[j]; 
			k++; 
		} 
	} 
	else 
	{ 
		for (; i <= mid; i++) 
		{ 
			next_array[k] = array[i]; 
			k++; 
		} 
	} //
	 
	for (l = low; l <= high; l++) 
	{ 
		array[l] = next_array[l]; 
	} 
} 