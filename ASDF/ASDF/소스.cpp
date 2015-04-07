#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char Game_Start(); // ������ �����Ͻðڽ��ϱ�
void Card_Set(); // ī�带 ���� �������� ���� �߰��� �����Ⱚ�� ������ (���� ����)
int Get_Card(); // ó�� ī�� ���� �й�
void Show_Card(); // �÷��̾�� ���� ó�� 2�徿 ���� ī�带 �����ִ� �Լ�
char* NumtoCard(int num_shape); //������ ���� ã�Ƴ��� ���ڿ��� �־��ִ� �Լ� (�����Ѻκе� ����)
void Print_Card(char* shape, int number); //ī�带 �����ִ� �Լ�
int Hit(int, int); //�÷��̾ Hit�ϸ� ���� �Լ�
int Player_Sum(int PlayerIndex); //�÷��̾��� ī�� ��
void Dealer_Turn(int Pindex, int Cindex, int PlayerSum);
int Dealer_Hit(int, int);

// ���� ���� ����
int CardSet[52] = { 0 }; // ī�嵦
int Player[5] = { 0 }; //�÷��̾� ī��
int Dealer[5] = { 0 }; // ������ ī��

void main()
{
	char start = 'A';
	int CardIndex = 4; // ���� ī���
	int PlayerIndex = 2; //�÷��̾��� ī���
	int hos = 1; // Hit or Stand

	int PlayerSum = 0;
	int DealerSum = 0;

	int Gameover = 0;

regame:

	start = Game_Start(); // ������ �����Ͻðڽ��ϱ�? (Y/N)

	while (start == 'Y')
	{
		Card_Set(); // ī�带 �������

		Gameover = Get_Card(); // ������ ���� �ʱ� ī�带 ������
		if (Gameover == 1)
			break;

		Show_Card(); // ���� ������ ī��� ���� ī�带 ������

		printf("1.Hit or 2.Stand ����� �����Ͻðڽ��ϱ�? : "); // ���ñǺο�
		scanf_s("%d", &hos); // hit or stand �Է¹���
		fflush(stdin);

		while (hos == 1)
		{
			Gameover = Hit(PlayerIndex, CardIndex); // ī�� �ϳ� �߰���

			PlayerIndex++; // �÷��̾��� ī�尡 �߰���
			CardIndex++;

			if (PlayerIndex > 4)
			{
				printf("ī�带 �ټ��� �� �޾ҽ��ϴ�.\n Stand�մϴ�.\n"); //ī���� �ִ� ���� �ټ���
				break;
			}

			if (Gameover == 1)
				break;


			printf("1.Hit or 2.Stand ����� �����Ͻðڽ��ϱ�? : "); // ���ñǺο�
			scanf_s("%d", &hos);
			fflush(stdin);
		}
		if (Gameover == 1)
			break;

		if (hos == 2)
			printf("Stand�Ͽ����ϴ�.\n");

		PlayerSum = Player_Sum(PlayerIndex);

		Dealer_Turn(PlayerIndex, CardIndex, PlayerSum); // ������ ī�� ������ ���� hit or Stand �Ͽ� ����ī�� �Ϸ�

		printf("\n�ٽ� ");
		start = Game_Start();
	}

	printf("\n�ٽ� �ѹ� ");

	goto regame;
}

char Game_Start()
{
	char ans = 'A';

	printf("������ �����Ͻðڽ��ϱ�? (Y/N) : ");
	scanf_s("%c", &ans);
	fflush(stdin);
	return ans;
}

void Card_Set()
{
	// ī�嵦�� �����Լ��� ����
	int i, a, b, temp;

	srand((unsigned)time(NULL));

	for (i = 0; i < 52; i++)
	{
		CardSet[i] = i + 1;
	}
	printf("\n");

	for (i = 0; i < 10; i++) //���� ������� ������ �ٲٰ�
	{
		a = rand() % 52 + 1;
		b = rand() % 52 + 1;


		temp = CardSet[i];
		CardSet[i] = CardSet[a];
		CardSet[a] = CardSet[b];
		CardSet[b] = temp;
	}

	for (i = 0; i < 10; i++) //�� ������ ����
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
	printf("ī�带 ���� �ݴϴ�.\n\n");

	Dealer[0] = CardSet[0];
	Player[0] = CardSet[1];
	Dealer[1] = CardSet[2];
	Player[1] = CardSet[3]; //ī�� �־��ְ�

	if (Dealer[0] % 13 == 1 && (Dealer[1] % 13 == 10 || Dealer[1] % 13 == 11 || Dealer[1] % 13 == 12 || Dealer[1] % 13 == 0))//���� �˻�
	{
		printf("Blackjak!!\n ������ �¸�\n");
		return 1;
	}
	else if ((Dealer[0] % 13 == 10 || Dealer[0] % 13 == 11 || Dealer[0] % 13 == 12 || Dealer[0] % 13 == 0) && Dealer[1] % 13 == 1)
	{
		printf("Blackjak!!\n ������ �¸�\n");
		return 1;
	}

	if (Player[0] % 13 == 1 && (Player[1] % 13 == 10 || Player[1] % 13 == 11 || Player[1] % 13 == 12 || Player[1] % 13 == 0))
	{
		printf("Blackjak!!\n �÷��̾��� �¸�\n");
		return 1;
	}
	else if ((Player[0] % 13 == 10 || Player[0] % 13 == 11 || Player[0] % 13 == 12 || Player[0] % 13 == 0) && Player[1] % 13 == 1)
	{
		printf("Blackjak!!\n �÷��̾��� �¸�\n");
		return 1;
	}

	return 0;
}

void Show_Card()
{
	char* shape; //ī���� ���
	int num_shape; //ī���� ����� ������ ����
	int number; //ī���� ����


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

	shape = NumtoCard(num_shape); // ������ �������� �˾Ƴ�
	Print_Card(shape, number); // ī�带 ������

	printf("\n\n");
}

char* NumtoCard(int num_shape) //1~13�� �����̵� �̷� ������ ���ڸ� �������� ����
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
		printf("����");

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
		printf("���ī�� ���� ����\n");
}

int Hit(int Pindex, int Cindex)
{
	int i, sum = 0;
	char* shape;
	int num_shape = 0;
	int number;

	Player[Pindex] = CardSet[Cindex];

	printf("����� ���� ī��� ");

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
			printf("���� ī�带 ������\n");
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
			printf("�÷��̾� ī�带 ������\n");
	}
	//21�� �Ѿ Bust�� �Ǵ°� Hit���� ��� �����Ƿ� ���⼭ A�϶��� 11�� �ְ� 21�� �ѰԵȴٸ� �տ��� 10�� ���� ��

	//�̹� Bust�� Hit�� ���鼭 �˻��߱� ������
	while (PlayerSum > 21) //���⼭ 21�� �Ѿ��ٸ� A�� �����ϱ� ������
		PlayerSum -= 10;



	printf("\n�÷��̾��� �� : %d \n\n", PlayerSum);
	return PlayerSum;
}

void Dealer_Turn(int Pindex, int Cindex, int PlayerSum)
{
	//������ �ι�° ī�� ���
	char* shape;
	int num_shape;
	int number;
	int Dindex = 2;
	int DealerSum = 0;
	int DetermineA = 0;
	int i; // i�� ������ for���� �ε���
	int Gameover = 0;

	num_shape = (Dealer[0] - 1) / 13;
	number = Dealer[0] % 13;

	shape = NumtoCard(num_shape);

	printf("Dealer : ");
	Print_Card(shape, number);
	printf(" , ");

	num_shape = (Dealer[1] - 1) / 13; //����ī���� �޸� ǥ��
	number = Dealer[1] % 13;

	shape = NumtoCard(num_shape);
	Print_Card(shape, number);
	printf("\n");

	//���� ������ HoS ����

	for (i = 0; i < Dindex; i++)
	{
		if ((Dealer[i] % 13) == 0 || (Dealer[i] % 13) > 9)
			DealerSum += 10;
		else if ((Dealer[i] % 13) > 1 && (Dealer[i] % 13) < 10)
			DealerSum += (Dealer[i] % 13);
		else if ((Dealer[i] % 13) == 1)
		{
			DealerSum += 11;
			DetermineA += 1; //�̰ŷ� A�� ��� ���Դ��� ���� ����
		}
		else
			printf("���� ī�带 ������\n");
	}

	if (DealerSum > 21 && DetermineA > 0) //�̷� �ʱ⿡ ����Ʈ ������ ���� AA���°����� 
	{
		DealerSum -= 10;
		DetermineA -= 1; // �̰������� ���� DetermineA�� A�� ���� ���°��� �ƴ� 11�� ���� A�� ���°����� �����
	}
	printf("���� ī���� �ʱ��� : %d \n", DealerSum);

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
				DetermineA += 1; //�̰ŷ� A�� ��� ���Դ��� ���� ����
			}

			if (DealerSum > 21 && DetermineA > 0) // A�� 11�� ���� 1�� ���� ���� 
			{
				DealerSum -= 10;
				DetermineA -= 1; // 11�� ���� A�� ��
			}

			Dindex++;
			Cindex++;
		}

		if (Gameover == 1)
			break;

		printf("������ �� : %d \n�÷��̾��� �� : %d \n", DealerSum, PlayerSum);

		if (DealerSum > PlayerSum && DealerSum < 22) // Dealer_Hit���� Bust�� �˻���
		{
			printf("������ �¸�\n");
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

	printf("������ ���� ī��� ");

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
			printf("���� ī�带 ������\n");
	}

	if (sum > 21)
	{
		printf("Bust \n");
		printf("Player Win \n");
		return 1;
	}

	return 0;
}
// �ö󰡶� Ŀ��¹��  .gitignor �����޴µ� �ö󰡶� 