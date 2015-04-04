#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char Game_Start();
void Card_Set();

/*
void commit()
{ 
	printf("Hello World\n\n");
	printf("14학번 이연규 입니다.");
	printf("모두 영상보고 동기화 해주세요\n");
	printf("커밋 날려주세요\n");
	
	//Hit(힛) - 플레이어가 추가 카드를 더 원할 때 딜러에게 표현하는 용어.
	//Stay(스테이) - 플레이어가 추가 카드를 더 이상 원하지 않을 때 딜러에게 표현하는 용어.
	//Bust(버스트) - 플레이어가 추가 카드를 받아서(Hit) 21을 초과하였을 때 딜러가 표현하는 용어
	//Push(푸시) - 딜러와 플레이어의 카드 합이 같을 때 딜러가 표현하는 용어(Tie라고도 함) 
	

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
*/
void main()
{


	char start;
	start = Game_Start(); // 게임을 시작하시겠습니까? (Y/N)
	
	if (start != 'Y')
		printf("누구세요");

	Card_Set(); // 카드를 섞어놓음
	/*
	Get_Card(); // 딜러와 나의 초기 카드를 나눠줌
	
	// Stand까지 반복
	Show_Card(); // 지금 딜러의 카드와 나의 카드를 보여줌

	printf("Hit or Stand"); // 선택권부여

	Hit(); // 카드 하나 추가요

	Stand(); // 함 까보자

	Dealer_Turn(); // 딜러의 카드 공개후 딜러 hit or Stand 하여 딜러카드 완료
	
	Result(); // 둘의 카드를 비교하여 결과 승리 or 패배

	ReGame(); // 리겜 선택시 CardSet();으로 이동
	*/

	GameOver:
	return;
}

char Game_Start()
{
	char ans = 'A';
	printf("게임을 시작하시겠습니까? (Y/N) : ");
	scanf("%c", ans);

	return ans;
}

void Card_Set()
{
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

/*카드 돌리기*/
void card_suffle(){

	int a, b, line1, line2, c;
	static int e = 0;
	int card[4][13] = { 0 };


	srand((long)time(NULL));

	for (line1 = 0; line1 < 4; line1++){
		for (c = 0; c < 13; c++){
			line2 = rand() % 13;//행에서 임의의 열 선택
			if (card[line1][line2] == 0)//데이터가 0이면 1추가
				card[line1][line2] = ++e;
			else{
				line2 = rand() % 13;//0이 아닐 경우 다시 선택
				while (card[line1][line2] != 0){//0일 때까지 반복 선택
					line2 = rand() % 13;
				}
				card[line1][line2] = ++e;//추가
			}
		}
		e = 0;//e를 0으로 초기화한 뒤 다음 행으로 이동
	}

	for (a = 0; a < 4; a++){
		for (b = 0; b < 13; b++){
			printf("%d  ", card[a][b]);
		}
		printf("\n");
	}
	return;
}