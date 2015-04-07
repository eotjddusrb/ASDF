#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char Game_Start(); // 게임을 시작하시겠습니까
void Card_Set(); // 카드를 섞는 과정에서 가끔 중간에 쓰레기값이 생성됨 (수정 요함)
int Get_Card(); // 처음 카드 두장 분배
void Show_Card(); // 플레이어와 딜러 처음 2장씩 받은 카드를 보여주는 함수
char* NumtoCard(int num_shape); //문양이 뭔지 찾아내서 문자열에 넣어주는 함수 (사용안한부분도 있음)
void Print_Card(char* shape, int number); //카드를 보여주는 함수
int Hit(int, int); //플레이어가 Hit하면 들어가는 함수
int Player_Sum(int PlayerIndex); //플레이어의 카드 합
void Dealer_Turn(int Pindex, int Cindex, int PlayerSum);
int Dealer_Hit(int, int);

// 전역 변수 선언
int CardSet[52] = { 0 }; // 카드덱
int Player[5] = { 0 }; //플레이어 카드
int Dealer[5] = { 0 }; // 딜러의 카드

void main()
{
	char start = 'A';
	int CardIndex = 4; // 사용된 카드수
	int PlayerIndex = 2; //플레이어의 카드수
	int hos = 1; // Hit or Stand

	int PlayerSum = 0;
	int DealerSum = 0;

	int Gameover = 0;

regame:

	start = Game_Start(); // 게임을 시작하시겠습니까? (Y/N)

	while (start == 'Y')
	{
		Card_Set(); // 카드를 섞어놓음

		Gameover = Get_Card(); // 딜러와 나의 초기 카드를 나눠줌
		if (Gameover == 1)
			break;

		Show_Card(); // 지금 딜러의 카드와 나의 카드를 보여줌

		printf("1.Hit or 2.Stand 몇번을 선택하시겠습니까? : "); // 선택권부여
		scanf_s("%d", &hos); // hit or stand 입력받음
		fflush(stdin);

		while (hos == 1)
		{
			Gameover = Hit(PlayerIndex, CardIndex); // 카드 하나 추가요

			PlayerIndex++; // 플레이어의 카드가 추가됨
			CardIndex++;

			if (PlayerIndex > 4)
			{
				printf("카드를 다섯장 다 받았습니다.\n Stand합니다.\n"); //카드의 최대 수는 다섯장
				break;
			}

			if (Gameover == 1)
				break;


			printf("1.Hit or 2.Stand 몇번을 선택하시겠습니까? : "); // 선택권부여
			scanf_s("%d", &hos);
			fflush(stdin);
		}
		if (Gameover == 1)
			break;

		if (hos == 2)
			printf("Stand하였습니다.\n");

		PlayerSum = Player_Sum(PlayerIndex);

		Dealer_Turn(PlayerIndex, CardIndex, PlayerSum); // 딜러의 카드 공개후 딜러 hit or Stand 하여 딜러카드 완료

		printf("\n다시 ");
		start = Game_Start();
	}

	printf("\n다시 한번 ");

	goto regame;
}

char Game_Start()
{
	char ans = 'A';

	printf("게임을 시작하시겠습니까? (Y/N) : ");
	scanf_s("%c", &ans);
	fflush(stdin);
	return ans;
}

void Card_Set()
{
	// 카드덱을 전역함수로 보냄
	int i, a, b, temp;

	srand((unsigned)time(NULL));

	for (i = 0; i < 52; i++)
	{
		CardSet[i] = i + 1;
	}
	printf("\n");

	for (i = 0; i < 10; i++) //앞의 열장부터 열심히 바꾸고
	{
		a = rand() % 52 + 1;
		b = rand() % 52 + 1;


		temp = CardSet[i];
		CardSet[i] = CardSet[a];
		CardSet[a] = CardSet[b];
		CardSet[b] = temp;
	}

	for (i = 0; i < 10; i++) //또 열심히 섞기
	{
		a = rand() % 52 + 1;
		b = rand() % 52 + 1;

		temp = CardSet[a];
		CardSet[a] = CardSet[b];
		CardSet[b] = temp;
	}

}

int Get_Card()
{
	printf("카드를 나눠 줍니다.\n\n");

	Dealer[0] = CardSet[0];
	Player[0] = CardSet[1];
	Dealer[1] = CardSet[2];
	Player[1] = CardSet[3]; //카드 넣어주고

	if (Dealer[0] % 13 == 1 && (Dealer[1] % 13 == 10 || Dealer[1] % 13 == 11 || Dealer[1] % 13 == 12 || Dealer[1] % 13 == 0))//블랙잭 검사
	{
		printf("Blackjak!!\n 딜러의 승리\n");
		return 1;
	}
	else if ((Dealer[0] % 13 == 10 || Dealer[0] % 13 == 11 || Dealer[0] % 13 == 12 || Dealer[0] % 13 == 0) && Dealer[1] % 13 == 1)
	{
		printf("Blackjak!!\n 딜러의 승리\n");
		return 1;
	}

	if (Player[0] % 13 == 1 && (Player[1] % 13 == 10 || Player[1] % 13 == 11 || Player[1] % 13 == 12 || Player[1] % 13 == 0))
	{
		printf("Blackjak!!\n 플레이어의 승리\n");
		return 1;
	}
	else if ((Player[0] % 13 == 10 || Player[0] % 13 == 11 || Player[0] % 13 == 12 || Player[0] % 13 == 0) && Player[1] % 13 == 1)
	{
		printf("Blackjak!!\n 플레이어의 승리\n");
		return 1;
	}

	return 0;
}

void Show_Card()
{
	char* shape; //카드의 모양
	int num_shape; //카드의 모양을 결정할 숫자
	int number; //카드의 숫자


	num_shape = (Dealer[0] - 1) / 13;
	number = Dealer[0] % 13;

	shape = NumtoCard(num_shape);

	printf("Dealer : ");
	Print_Card(shape, number);
	printf(", ???? \n");

	num_shape = (Player[0] - 1) / 13;
	number = Player[0] % 13;

	shape = NumtoCard(num_shape);

	printf("Player : ");
	Print_Card(shape, number);
	printf(", ");

	num_shape = (Player[1] - 1) / 13;
	number = Player[1] % 13;

	shape = NumtoCard(num_shape); // 문양이 무엇인지 알아냄
	Print_Card(shape, number); // 카드를 보여줌

	printf("\n\n");
}

char* NumtoCard(int num_shape) //1~13은 스페이드 이런 식으로 숫자를 문양으로 변경
{
	char* shape;

	if (num_shape == 0)
		shape = "Spade";
	else if (num_shape == 1)
		shape = "Diamond";
	else if (num_shape == 2)
		shape = "Heart";
	else if (num_shape == 3)
		shape = "Clover";
	else
		printf("오류");

	return shape;
}

void Print_Card(char* shape, int number)
{
	if (number == 1)
		printf("%s A ", shape);
	else if (number == 0)
		printf("%s K ", shape);
	else if (number == 11)
		printf("%s J ", shape);
	else if (number == 12)
		printf("%s Q ", shape);
	else if (number > 1 && number < 11)
		printf("%s %d ", shape, number);
	else
		printf("블루카드 뽑음 ㅈㅅ\n");
}

int Hit(int Pindex, int Cindex)
{
	int i, sum = 0;
	char* shape;
	int num_shape = 0;
	int number;

	Player[Pindex] = CardSet[Cindex];

	printf("당신이 받은 카드는 ");

	num_shape = ((Player[Pindex] - 1) / 13);
	number = (Player[Pindex] % 13);

	shape = NumtoCard(num_shape);
	Print_Card(shape, number);
	printf("\n\n");

	for (i = 0; i < (Pindex + 1); i++)
	{
		if ((Player[i] % 13) == 0 || (Player[i] % 13) > 9)
			sum += 10;
		else if ((Player[i] % 13) > 0 && (Player[i] % 13) < 10)
			sum += (Player[i] % 13);
		else
			printf("오류 카드를 못더함\n");
	}

	if (sum > 21)
	{
		printf("Bust \n");
		printf("You Lose\n");
		return 1;
	}

	return 0;
}

int Player_Sum(int Pindex)
{
	int PlayerSum = 0;
	int i;

	for (i = 0; i < Pindex; i++)
	{
		if ((Player[i] % 13) == 0 || (Player[i] % 13) > 9)
			PlayerSum += 10;
		else if ((Player[i] % 13) > 1 && (Player[i] % 13) < 10)
			PlayerSum += (Player[i] % 13);
		else if ((Player[i] % 13) == 1)
			PlayerSum += 11;
		else
			printf("플레이어 카드를 못더함\n");
	}
	//21이 넘어서 Bust가 되는건 Hit에서 계산 했으므로 여기서 A일때는 11을 넣고 21이 넘게된다면 합에서 10을 빼면 됨

	//이미 Bust는 Hit을 돌면서 검사했기 때문에
	while (PlayerSum > 21) //여기서 21이 넘었다면 A가 존재하기 때문임
		PlayerSum -= 10;



	printf("\n플레이어의 합 : %d \n\n", PlayerSum);
	return PlayerSum;
}

void Dealer_Turn(int Pindex, int Cindex, int PlayerSum)
{
	//딜러의 두번째 카드 까기
	char* shape;
	int num_shape;
	int number;
	int Dindex = 2;
	int DealerSum = 0;
	int DetermineA = 0;
	int i; // i는 언제나 for문의 인덱스
	int Gameover = 0;

	num_shape = (Dealer[0] - 1) / 13;
	number = Dealer[0] % 13;

	shape = NumtoCard(num_shape);

	printf("Dealer : ");
	Print_Card(shape, number);
	printf(" , ");

	num_shape = (Dealer[1] - 1) / 13; //딜러카드의 뒷면 표시
	number = Dealer[1] % 13;

	shape = NumtoCard(num_shape);
	Print_Card(shape, number);
	printf("\n");

	//이제 딜러가 HoS 결정

	for (i = 0; i < Dindex; i++)
	{
		if ((Dealer[i] % 13) == 0 || (Dealer[i] % 13) > 9)
			DealerSum += 10;
		else if ((Dealer[i] % 13) > 1 && (Dealer[i] % 13) < 10)
			DealerSum += (Dealer[i] % 13);
		else if ((Dealer[i] % 13) == 1)
		{
			DealerSum += 11;
			DetermineA += 1; //이거로 A가 몇번 나왔는지 셀수 있음
		}
		else
			printf("딜러 카드를 못더함\n");
	}

	if (DealerSum > 21 && DetermineA > 0) //이런 초기에 버스트 나오는 경우는 AA나온경우뿐임 
	{
		DealerSum -= 10;
		DetermineA -= 1; // 이과정으로 인해 DetermineA는 A의 수를 세는것이 아닌 11로 계산된 A를 세는것으로 변경됨
	}
	printf("딜러 카드의 초기합 : %d \n", DealerSum);

	while (DealerSum < 22)
	{
		while (DealerSum < 16 || DealerSum < PlayerSum)
		{
			Gameover = Dealer_Hit(Dindex, Cindex);
			if (Gameover == 1)
				break;

			if ((Dealer[Dindex] % 13) == 0 || (Dealer[Dindex] % 13) > 9)
				DealerSum += 10;
			else if ((Dealer[Dindex] % 13) > 1 && (Dealer[Dindex] % 13) < 10)
				DealerSum += (Dealer[Dindex] % 13);
			else if ((Dealer[Dindex] % 13) == 1)
			{
				DealerSum += 11;
				DetermineA += 1; //이거로 A가 몇번 나왔는지 셀수 있음
			}

			if (DealerSum > 21 && DetermineA > 0) // A를 11로 할지 1로 할지 결정 
			{
				DealerSum -= 10;
				DetermineA -= 1; // 11로 계산된 A의 수
			}

			Dindex++;
			Cindex++;
		}

		if (Gameover == 1)
			break;

		printf("딜러의 합 : %d \n플레이어의 합 : %d \n", DealerSum, PlayerSum);

		if (DealerSum > PlayerSum && DealerSum < 22) // Dealer_Hit에서 Bust를 검사함
		{
			printf("딜러의 승리\n");
			break;
		}
		else if (DealerSum == PlayerSum)
		{
			printf("Push\n");
			break;
		}
	}

}

int Dealer_Hit(int Dindex, int Cindex)
{
	int i, sum = 0;
	char* shape;
	int num_shape = 0;
	int number = 0;

	Dealer[Dindex] = CardSet[Cindex];

	printf("딜러가 받은 카드는 ");

	num_shape = ((Dealer[Dindex] - 1) / 13);
	number = (Dealer[Dindex] % 13);

	shape = NumtoCard(num_shape);
	Print_Card(shape, number);
	printf("\n");

	for (i = 0; i < (Dindex + 1); i++)
	{
		if ((Dealer[i] % 13) == 0 || (Dealer[i] % 13) > 9)
			sum += 10;
		else if ((Dealer[i] % 13) > 0 && (Dealer[i] % 13) < 10)
			sum += (Dealer[i] % 13);
		else
			printf("오류 카드를 못더함\n");
	}

	if (sum > 21)
	{
		printf("Bust \n");
		printf("Player Win \n");
		return 1;
	}

	return 0;
}
// 올라가라 커밋쨔응  .gitignor 복붙햇는데 올라가라 