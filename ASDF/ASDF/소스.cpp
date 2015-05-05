#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000 // n = 1000


void shuffle();
void QuickSort();
void Devide(int array[]);

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

	//int자료형의 함수를 만들어서 ri, li를 리턴해야될듯

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
	

	//여기까지 만듬
	printf("\n\n\n %d \n\n", pivot);
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);
	}

	


	//Devide(left); // 배열을 넣을 때 이름만 넣는다.
	
	/*
	//확인차 출력
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