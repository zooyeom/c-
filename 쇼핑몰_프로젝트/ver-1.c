#include <stdio.h>

int main() {
	int number,number1,number2;
	int stock_product[100];
	int relase_product[100];
	int remain_product[100];
	int i = 0;

	printf("상품의 종류 갯수를 입력해주세요>>>");
	scanf_s("%d", &number);

	start:
	printf("상품들의 입고 수량을 입력해주세요>>>");
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &stock_product[i]);
	}
	printf("상품들의 판매 수량을 입력해주세요>>>");
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &relase_product[i]);
	}
	for (int i = 0; i < number; i++) {
		remain_product[i] = stock_product[i] - relase_product[i];
	}
	if (remain_product[i] < 0) {
		printf("수량 체크 오류입니다. 다시 입력해주세요.");
		goto start;
	}
	printf("검색하고자 하는 상품의 ID를 입력해주세요>>>");
	scanf_s("%d", &number1);

	printf("상품의 수량은>>> %d\n", remain_product[i]);
	printf("모든 상품의 재고를 출력하겠습니다.\n");
	
	for (int i = 0; i < number; i++) {
		printf("%d", remain_product[i]);
		printf(" ");
	}
}
