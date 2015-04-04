#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char Game_Start();
void Card_Set();

/*
void commit()
{ 
	printf("Hello World\n\n");
	printf("14�й� �̿��� �Դϴ�.");
	printf("��� ���󺸰� ����ȭ ���ּ���\n");
	printf("Ŀ�� �����ּ���\n");
	
	//Hit(��) - �÷��̾ �߰� ī�带 �� ���� �� �������� ǥ���ϴ� ���.
	//Stay(������) - �÷��̾ �߰� ī�带 �� �̻� ������ ���� �� �������� ǥ���ϴ� ���.
	//Bust(����Ʈ) - �÷��̾ �߰� ī�带 �޾Ƽ�(Hit) 21�� �ʰ��Ͽ��� �� ������ ǥ���ϴ� ���
	//Push(Ǫ��) - ������ �÷��̾��� ī�� ���� ���� �� ������ ǥ���ϴ� ���(Tie��� ��) 
	

	//14�й� ȫ����

}

void post_programing()
{
	//�ΰ��� �����-������ �÷��̾�
	//���ӽ��۽� ���ñݾ��� �ɰ�
	//������ �ո����� ���� �޸����� ���� �÷��̾�� �ո����� ������ �޴´�
	//�÷��̾�� ������ �ո� ī��� �ڽ��� ī�� ������ ���� �����Ͽ�
	//���� ��������(Hit), ������(Stand) �����Ѵ�.
	//ī�带 �޾��� �� Bust �Ǹ� ��� �÷��̾��� �й谡 �ȴ�. (������ �а���& ������ �¸���� ���)
	//������ ī���� ���� 15���϶�� ������ �� �޾ƾ��Ѵ�.
	//�÷��̾ Stand�ϱ�� �����ϸ� ������ �ι�° ī�尡 �����ǰ�,
	//������ ī�带 �� ������ ������ �Ǵ��Ͽ� ������ ����ȴ�.
	//������ ī�带 �� �ް� Stand �ϰ� �ǰų� 21�� �Ǹ� ����.

}

void into_source()
{
	//���� ����ȭ�� ���
	//ī�� �й�.
	//hit or stand ���� ȭ��
	// hit �Լ� stand �Լ�
	// �ٽ� ī�带 ���� hit or  ,stand ����
	// ���� �Ѿ�� bust ��� 
	//stand�ϸ� ������ ���� ������ ī�尡 �����Ǹ�
	// 1) if ������ 15�����ϰ�� hit
	// 2) else if ������ �÷��̾��� ������ �������� hit 
	// 3) ������ �÷��̾��� ������ ū���� stand
	// 4) ������ �÷��̾��� ���� ������� �� stand
	// ���� �ٽ� ����

}
*/
void main()
{


	char start;
	start = Game_Start(); // ������ �����Ͻðڽ��ϱ�? (Y/N)
	
	if (start != 'Y')
		printf("��������");

	Card_Set(); // ī�带 �������
	/*
	Get_Card(); // ������ ���� �ʱ� ī�带 ������
	
	// Stand���� �ݺ�
	Show_Card(); // ���� ������ ī��� ���� ī�带 ������

	printf("Hit or Stand"); // ���ñǺο�

	Hit(); // ī�� �ϳ� �߰���

	Stand(); // �� ���

	Dealer_Turn(); // ������ ī�� ������ ���� hit or Stand �Ͽ� ����ī�� �Ϸ�
	
	Result(); // ���� ī�带 ���Ͽ� ��� �¸� or �й�

	ReGame(); // ���� ���ý� CardSet();���� �̵�
	*/

	GameOver:
	return;
}

char Game_Start()
{
	char ans = 'A';
	printf("������ �����Ͻðڽ��ϱ�? (Y/N) : ");
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

	//��� ������ �����̵� ���̾� ��Ʈ Ŭ�ι� ������ ��
	//  1 = �����̵� A
	// 2 = �����̵� 2
	// 11 = �����̵� J
	// 14 = ���̾� A

	// 52 = Ŭ�ι� K
	
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

/*ī�� ������*/
void card_suffle(){

	int a, b, line1, line2, c;
	static int e = 0;
	int card[4][13] = { 0 };


	srand((long)time(NULL));

	for (line1 = 0; line1 < 4; line1++){
		for (c = 0; c < 13; c++){
			line2 = rand() % 13;//�࿡�� ������ �� ����
			if (card[line1][line2] == 0)//�����Ͱ� 0�̸� 1�߰�
				card[line1][line2] = ++e;
			else{
				line2 = rand() % 13;//0�� �ƴ� ��� �ٽ� ����
				while (card[line1][line2] != 0){//0�� ������ �ݺ� ����
					line2 = rand() % 13;
				}
				card[line1][line2] = ++e;//�߰�
			}
		}
		e = 0;//e�� 0���� �ʱ�ȭ�� �� ���� ������ �̵�
	}

	for (a = 0; a < 4; a++){
		for (b = 0; b < 13; b++){
			printf("%d  ", card[a][b]);
		}
		printf("\n");
	}
	return;
}