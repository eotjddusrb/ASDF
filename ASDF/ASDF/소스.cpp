#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000 // n = 1000
// n= 10000 까진 확인됨
// 변경 테스트

void shuffle();
void Print(); //배열 확인
void QuickSort(int, int);
void swap(int*, int*);
void MergeSort(int, int); // MergeSort함수를 재귀함수로 선언
void MergeArray(int, int, int); // 재귀안에서 정렬

// 배열 전역변수
int array[MAX] = { 0 };
int next_array[MAX] = {};

void main()
{
	int i;
	int r;

	srand(time(NULL));

	shuffle();

	printf("------- Quick Sort 하기 전 -------\n");
	Print();
	QuickSort(0, MAX-1);
	printf("\n\n------- Quick Sort 후 -------\n");
	Print();
	
	shuffle();

	printf("\n\n------- Merge Sort 하기 전 -------\n");
	Print();
	MergeSort(0, MAX-1);
	printf("\n\n------- Merge Sort 후 -------\n");
	Print();
}

void shuffle()
{
	int i, r;

	for (i = 0; i < MAX; i++) //배열할당 
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
		printf("%4d ", array[k]); //배열확인
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
	k = low; //정렬된 배열이 들어가는 자리를 맞춰주는 인덱스
	 
	while (i <= mid && j <= high)   // 한쪽바구니가 떨어질때까지 반복 
	{ 
		if (array[i] < array[j]) 
		{ 
			next_array[k] = array[i]; //왼쪽배열에서 들어가거나
			i++; 
		} 
		else 
		{ 
			next_array[k] = array[j]; //오른쪽 배열에서 들어가거나
			j++; 
		} 
		k++; //입력받음
	} // 한쪽바구니가 떨어질때까지 반복 
	 
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