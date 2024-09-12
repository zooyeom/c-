#include <stdio.h>

void most_product(int*a,int*b){
    for(int i=0;i<100;i++){
        
    }
}

int main() {
	int number,number1,number2;
	int stock_product[100];
	int relase_product[100];
	int remain_product[100];
	int i = 0;
    float sell_percent;
    int all_product=0;
    int sell_product=0;
    int most=0;

	printf("상품의 종류 갯수를 입력해주세요>>>\n");
	scanf("%d", &number);

	start:
	printf("상품들의 입고 수량을 입력해주세요>>>\n");
	for (int i = 0; i < number; i++) {
		scanf("%d", &stock_product[i]);
		all_product+=stock_product[i];
	}
	printf("상품들의 판매 수량을 입력해주세요>>>\n");
	for (int i = 0; i < number; i++) {
		scanf("%d", &relase_product[i]);
		sell_product+=relase_product[i];
	}
	for (int i = 0; i < number; i++) {
		remain_product[i] = stock_product[i] - relase_product[i];
	}
	if (remain_product[i] < 0) {
		printf("수량 체크 오류입니다. 다시 입력해주세요.\n");
		goto start;
	}
	printf("검색하고자 하는 상품의 ID를 입력해주세요>>>\n");
	scanf("%d", &number1);

	printf("상품의 수량은>>> %d\n", remain_product[i]);
	printf("모든 상품의 재고를 출력하겠습니다.\n");
	
	for (int i = 0; i < number; i++) {
		printf("%d", remain_product[i]);
		printf(" ");
	}
    printf("\n");
    
    printf("총 판매량: %d\n",sell_product);
    
    //전체 판매율 계산
    sell_percent=(float)sell_product/all_product*100;
    printf("판매율: %.2f%%\n",sell_percent);
    
    //가장 많이 팔린 상품 계산
    for(int i=0;i<number;i++){
        if(most<relase[i]){
            most=relase[i];
        }
    }
    most_product(&)
    printf("가장 많이 팔린 상품>>> ID: %d, 판매량: %d", ,most)
    
    //재고 부족 경고
    for(int i=0;i<number;i++){
        if(remain_product[i]<=2){
            printf("")
        }
    }
}
