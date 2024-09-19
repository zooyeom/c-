//수정 필요한 부분>>
//1. 메뉴 입력 부분에서 1,2,3,4 / 1,2 이외에 입력되면 다시 루프를 하게 코드를 짜야함
//2. 판매량 입력시에 입력할때마다 덧셈이 되는게 아니라 입고 받은 수량으로 다시 루프되면서 판매량이 쌓이지 않는 오류가 있다.
//3. 판매량이 마이너스가 될때를 걸러내는 예외처리가 필요함
//4. 

#include <stdio.h>

void most_product(int release_product[100], int* name, int* sell) {
    int most = 0;
    int number = 0;
    for (int i = 0; i < 5; i++) {
        if (most < release_product[i]) {
            number = i;
            most = release_product[i];
        }
    }
    *name = number;
    *sell = most;
}

void least_product(int release_product[100], int* name, int* sell) {
    int least = 1000000;
    int number = 0;
    for (int i = 0; i < 5; i++) {
        if (least > release_product[i]) {
            number = i;
            least = release_product[i];
        }
    }
    *name = number;
    *sell = least;
}

void Caution(int remain_product[100]) {
    for (int i = 0; i < 5; i++) {
        if (remain_product[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)", i, remain_product[i]);
            printf("\n");
        }
    }
}

void Stocked_product(int stock_product[100]) {
    int menu;
    int name;
    int number;

    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입고수량 입력 2를 선택\n");
    scanf("%d", &menu);

    if (menu == 1) {
        printf("상품들의 입고 수량을 입력해주세요>>>");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &stock_product[i]);
        }
    }
    else if (menu == 2) {
        printf("상품 ID: ");
        scanf("%d", &name);
        printf("입고수량: ");
        scanf("%d", &number);

        stock_product[name] = number;
    }
}

void Sell_product(int release_product[100]) {
    int menu;
    int name;
    int number;

    printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 판매수량 입력 2를 선택\n");
    scanf("%d", &menu);

    if (menu == 1) {
        printf("상품들의 판매 수량을 입력해주세요>>>");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &release_product[i]);
        }
    }
    else if (menu == 2) {
        printf("상품 ID: ");
        scanf("%d", &name);
        printf("판매수량: ");
        scanf("%d", &number);

        release_product[name] = number;
    }
}

void Information(int release_product[100], int stock_product[100]) {
    int remain_product[100] = { 0 };
    int sell_product = 0;
    int all_product = 0;
    int name, sell;
    float sell_percent = 0;

    for (int i = 0; i < 5; i++) {
        remain_product[i] = stock_product[i] - release_product[i];
        sell_product += release_product[i];
        all_product += stock_product[i];
    }
    sell_percent = (float)sell_product / all_product * 100;

    printf("재고 수량은:");
    for (int i = 0; i < 5; i++) {
        printf("%d  ", remain_product[i]);
    }
    printf("\n총 판매량: %d (판매율: %.2f%%)\n", sell_product, sell_percent);

    most_product(release_product, &name, &sell);
    printf("가장 많이 팔린 상품>>> ID: %d, 판매량: %d\n", name, sell);

    least_product(release_product, &name, &sell);
    printf("가장 적게 팔린 상품>>> ID: %d, 판매량: %d\n", name, sell);

    Caution(remain_product);
}

int main() {
    int stock_product[100] = { 0 };
    int release_product[100] = { 0 };
    int remain_product[100] = { 0 };
    int menu = 0;  

    printf("[쇼핑몰 관리 프로그램]\n");

    while (menu != 4) {
        printf("원하는 메뉴를 선택하세요.>>>(1.입고 2.판매 3.상품현황 4.종료)\n");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            Stocked_product(stock_product);
            break;
        case 2:
            Sell_product(release_product);
            break;
        case 3:
            Information(release_product, stock_product);
            break;
        case 4:
            return 0;
        }
    }
}
