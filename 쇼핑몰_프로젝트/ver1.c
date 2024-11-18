#include <stdio.h>

void most_product(int release_product[100], int*name,int*sell) {
	int most = 0;
	int number = 0;
	for (int i = 0; i < 100; i++) {
		if (most < release_product[i]) {
			number = i;
			most = release_product[i];
		}
	}
	* name = number;
	* sell = most;
}

void least_product(int release_product[100], int* name, int* sell) {
	int least = 1000000;
	int number = 0;
	for (int i = 0; i < 100; i++) {
		if (least > release_product[i]) {
			number = i;
			least = release_product[i];
		}
	}
	*name = number;
	*sell = least;
}

void Caution(int remain_product[100],int number) {
	
	for (int i = 0; i < number; i++) {
		if (remain_product[i] <= 2) {
			printf("상품 ID %d: 재고부족(%d)", i, remain_product[i]);
			printf("\n");
		}
	}
}
int main() {
	int number, number1, number2;
	int stock_product[100];
	int release_product[100];
	int remain_product[100] = { 0 };
	int i = 0;
	float sell_percent;
	int all_product = 0;
	int sell_product = 0;
	int most = 0;
	int name = 0;
	int sell = 0;

	//[1] 상품의 종류 갯수를 등록
	printf("상품의 종류 갯수를 입력해주세요>>>");
	scanf_s("%d", &number);

	//[2] 상품의 입고,판매,남은 수량을 체크
start:
	printf("상품들의 입고 수량을 입력해주세요>>>");
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &stock_product[i]);
		all_product += stock_product[i]; //전체 입고 수량 계산
	}
	printf("상품들의 판매 수량을 입력해주세요>>>");
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &release_product[i]); 
		sell_product += release_product[i]; //전체 판매량 계산
	}
	for (int i = 0; i < number; i++) {
		remain_product[i] = stock_product[i] - release_product[i];
	}

	if (remain_product[i] < 0) { 
		printf("수량 체크 오류입니다. 다시 입력해주세요.\n");
		goto start; 
		//goto로 오류가 나면 다시 입력하도록하기
	}

	printf("검색하고자 하는 상품의 ID를 입력해주세요>>>");
	scanf_s("%d", &number1);

	printf("상품의 수량은>>> %d\n", remain_product[i]);
	printf("모든 상품의 재고를 출력하겠습니다.\n");

	for (int i = 0; i < number; i++) {
		printf("%d", remain_product[i]);
		printf(" ");
	}
	printf("\n");

	//총 판매량 출력
	printf("총 판매량: %d\n", sell_product);

	//전체 판매율 계산
	sell_percent = (float)sell_product / all_product * 100;
	printf("판매율: %.2f%%\n", sell_percent);

	//가장 많이 팔린 상품 계산
		most_product(release_product, &name, &sell);
		printf("가장 많이 팔린 상품>>> ID: %d, 판매량: %d\n",name,sell);

	//가장 적게 팔린 상품 계산
		least_product(release_product, &name, &sell);
		printf("가장 적게 팔린 상품>>> ID: %d, 판매량: %d\n", name, sell);
		
		//재고 부족 경고
		Caution(remain_product,number);
}
