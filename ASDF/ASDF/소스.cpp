#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // n = 1000
// n= 10000 까진 확인됨

void shuffle();
void Print();
void QuickSort(int, int);
void swap(int*, int*);
void MergeSort(int, int);
void MergeArray(int, int, int);

//이제 정렬함수

// left  right 함수를 만들어서 배열이 나뉘어 질때 걔네를 함수로 보내서 
// 그 함수에서 처리된 후 나올 수 있게 하여 배열을 여러개 만들지 않아도 되도록 하면 좋겟다.
// 재귀함수


// 알고리즘...

// 배열 전역변수
int array[MAX] = { 0 };

int prev_array[MAX] = {};
int next_array[MAX] = {};

void main()
{
	int i;
	int r;

	srand(time(NULL));

	for (i = 0; i < MAX; i++) //배열할당 
		array[i] = i;

	shuffle();

	printf("------- Quick Sort 하기 전 -------\n");
	Print();
	QuickSort(0, MAX-1);
	printf("\n\n------- Quick Sort 후 -------\n");
	Print();

	for (i = 0; i < MAX; i++)
		prev_array[i] = i;

	for (i = 0; i < MAX; i++)
	{
		r = rand() % MAX;
		swap(&prev_array[i], &prev_array[r]);
	}

	printf("\n\n------- Merge Sort 하기 전 -------\n");
	for (i = 0; i < MAX; i++)
		printf("%4d ", prev_array[i]); //배열확인
	MergeSort(0, MAX-1);
	printf("\n\n------- Merge Sort 후 -------\n");
	for (i = 0; i < MAX; i++)
		printf("%4d ", prev_array[i]); //배열확인
	printf("\n\n\n");
	for (i = 0; i < MAX; i++)
		printf("%4d ", next_array[i]); //배열확인
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
		printf("%4d ", array[k]); //배열확인
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
			swap(&array[right], &array[0]); // 중간에 pivot이 0으로 잡히게 되면
			printf("\n\n 0을 바꿧당 \n\n"); // 재귀의 고리에서 벗어나는 경우가 발생
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

	while (i <= mid && j <= high)   // 한쪽바구니가 떨어질때까지 반복
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


	pivot = array[MAX - 1]; // pivot 은 맨오른쪽 
	pivotlist[count] = pivot;
	count++;
	
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]); //배열확인
	}

	i = 0;
	j = MAX - 2;


	while (1)
	{
		while (1) // 1차 나눔
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
		

		// 맨오른쪽에 있던 pivot을 pivot자리로 가져옴
		printf("\n\nset1 = %d\n\n", set);
		for (; array[set] == set ; set++) //정렬된 수가 어디까지인지
		{
			printf("\n\nset2 = %d\n\n", set);
		}

		if (set >= pivot)
			break;

		//우선 좌를 생각해보자


		pivotlist[count] = pivot; // 이건  초반 쪼개기
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




	// 이위가 진짜로 짜보세

/*



	printf("\n\n %d \n\n", pivot); // pivot확인

	i = 0;
	j = MAX - 2;

	while (1) // 1차 나눔
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
	// 맨오른쪽에 있던 pivot을 pivot자리로 가져옴

	printf("\n\n\n");
	printf("pivot까지의 배열 =  ");
	for (i = 0; i < pivot + 1; i++)
	{
		printf("%d ", array[i]); //배열확인
	}

	while (pivot > 1)
	{
		size = pivot;
		pivot = array[size - 1];
		printf("\n\n\n");

		pivotlist[count] = pivot;
		count++;
		printf("\n\n %d번째 pivot = %d \n\n", count, pivot);

		i = 0;
		j = size - 2;

		while (1) // 좌측 조지기
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
			printf("%d ", array[i]); //배열확인
		}

	}
	/////////////////////////////////////////////////
	//여기까지 만듬& 확인
	// 위의 과정으로 왼쪽부터 0 1 까지는 맞춰짐 ㅎ
	////////////////////////////////////////////////


	//pivotlist 가 만들어짐 count로 갯수 셈

	//우
	while (r)
	{
		r++;
		count--;
		if (count == 0)
			break;
		pivot = pivotlist[count - 1];

		printf("이게 제대로 돌아갈까 도키도키");

		while (pivot > r * 2 - 1)
		{
			size = pivot;
			pivot = array[size - 1];
			printf("\n\n\n");


			printf("\n\n %d번째 pivot = %d \n\n", count, pivot);

			i = r;
			j = size - 2;

			while (1) // 좌측 조지기
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
				printf("%d ", array[i]); //배열확인
			}
		}
	}









	////////*
	while (count)
	{
	count--;

	pivot = array[pivotlist[count - 2]-1]; //지난 pivot-1자리가 새로운 pivot

	i = pivotlist[count]+1; //바로 전 pivot 다음 부터 정렬
	j = pivot - 1; // pivot앞까지 정렬

	printf("\n\n pivot = %d\n i = %d\n j = %d\n\n", pivot, i, j);

	while (1) // 다시 좌측 조지기
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

	// 이거 심각하네 ㅜㅜ


	// 마지막 array확인용
	printf("\n\n %d \n\n", pivot);
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);


	}
}

*/