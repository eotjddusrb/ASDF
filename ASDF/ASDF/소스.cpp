#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void commit()
{ 
	printf("Hello World\n\n");
	printf("14학번 이연규 입니다.");
	printf("모두 영상보고 동기화 해주세요\n");
	printf("커밋 날려주세요\n");
	/*
	Hit(힛) - 플레이어가 추가 카드를 더 원할 때 딜러에게 표현하는 용어.
	Stay(스테이) - 플레이어가 추가 카드를 더 이상 원하지 않을 때 딜러에게 표현하는 용어.
	Bust(버스트) - 플레이어가 추가 카드를 받아서(Hit) 21을 초과하였을 때 딜러가 표현하는 용어
	Push(푸시) - 딜러와 플레이어의 카드 합이 같을 때 딜러가 표현하는 용어(Tie라고도 함) 
	*/

	//14학번 홍수빈

}

void post_programing()
{
	//두개의 저장소-딜러와 플레이어
	//게임시작시 배팅금액을 걸고
	//딜러는 앞면으로 한장 뒷면으로 한장 플레이어는 앞면으로 두장을 받는다
	//플레이어는 딜러의 앞면 카드와 자신의 카드 두장의 합을 생각하여
	//한장 더받을지(Hit), 멈출지(Stand) 결정한다.
	//카드를 받았을 때 Bust 되면 즉시 플레이어의 패배가 된다. (딜러의 패공개& 딜러의 승리라고 출력)
	//딜러는 카드의 합이 15이하라면 한장을 더 받아야한다.
	//플레이어가 Stand하기로 결정하면 딜러의 두번째 카드가 공개되고,
	//딜러가 카드를 더 받을지 멈출지 판단하여 게임이 종료된다.
	//딜러가 카드를 다 받고 Stand 하게 되거나 21이 되면 종료.

}

void into_source()
{
	//게임 시작화면 출력
	//카드 분배.
	//hit or stand 선택 화면
	// hit 함수 stand 함수
	// 다시 카드를 보고 hit or  ,stand 선택
	// 수가 넘어가면 bust 출력 
	//stand하면 딜러의 차례 딜러의 카드가 공개되며
	// 1) if 딜러는 15이하일경우 hit
	// 2) else if 딜러가 플레이어의 수보다 작은경우는 hit 
	// 3) 딜러가 플레이어의 수보다 큰경우는 stand
	// 4) 딜러와 플레이어의 수가 같은경우 는 stand
	// 게임 다시 시작

}











void card_practice()
{

	//모양 순서는 스페이드 다이아 하트 클로버 순으로 함
	//  1 = 스페이드 A
	// 2 = 스페이드 2
	// 11 = 스페이드 J
	// 14 = 다이아 A

	// 52 = 클로버 K
	
	int CardSet[52];
	int i, a, b, c, temp;

	srand((unsigned)time(NULL));

	for (i = 0; i < 52; i++)
	{
		CardSet[i] = i + 1;
	}

	for (i = 0; i < 20; i++)
	{
		a = rand() % 52 + 1;
		b = rand() % 52 + 1;
		c = rand() % 52 + 1;
		temp = CardSet[a];
		CardSet[a] = CardSet[b];
		CardSet[b] = CardSet[c];
		CardSet[c] = temp;
	}
}


// 이주현
// 스페이드 다이아 하트 클로버
//카드 돌리기 함수

void cardpractice()
{
	int i, k;
	int card[4][13] = { 0 };
	int get_card;
	int n;

	int srand((unsigned)time(NULL));

	i = 1 + rand() % 4;
	k = 1 + rand() % 13;
	get_card = card[i][k];
	
}

void fixing()
{
	int CardSet[4][13];
	int i, j, k;
	srand((unsigned)time(NULL));

	for (i = 0; i < 4; i++)
		for (j = 0; j < 13; j++)
		{
			CardSet[i][j] = i + 1;
		}
}