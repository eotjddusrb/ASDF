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


	pivot = array[MAX - 1]; // pivot 은 맨오른쪽 
	pivotlist[count] = pivot;
	count++;
	/*
	for (i = 0; i < MAX; i++)
	{
	printf("%d ", array[i]); //배열확인
	}*/

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
	/*
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

	printf("\n\n");

	for (i = 0; i < pivot + 1; i++)
	printf("%d ", array[i]);

	break;
	}*/

	// 이거 심각하네 ㅜㅜ


	// 마지막 array확인용
	printf("\n\n %d \n\n", pivot);
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);


	}
}