#include <stdio.h>

int main() {
	int number,number1,number2;
	int stock_product[100];
	int relase_product[100];
	int remain_product[100];
	int i = 0;

	printf("��ǰ�� ���� ������ �Է����ּ���>>>");
	scanf_s("%d", &number);

	start:
	printf("��ǰ���� �԰� ������ �Է����ּ���>>>");
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &stock_product[i]);
	}
	printf("��ǰ���� �Ǹ� ������ �Է����ּ���>>>");
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &relase_product[i]);
	}
	for (int i = 0; i < number; i++) {
		remain_product[i] = stock_product[i] - relase_product[i];
	}
	if (remain_product[i] < 0) {
		printf("���� üũ �����Դϴ�. �ٽ� �Է����ּ���.");
		goto start;
	}
	printf("�˻��ϰ��� �ϴ� ��ǰ�� ID�� �Է����ּ���>>>");
	scanf_s("%d", &number1);

	printf("��ǰ�� ������>>> %d\n", remain_product[i]);
	printf("��� ��ǰ�� ��� ����ϰڽ��ϴ�.\n");
	
	for (int i = 0; i < number; i++) {
		printf("%d", remain_product[i]);
		printf(" ");
	}
}