//수정해야할 부분들
//1. 구조체를 이용하여 더 깔끔한 코드를 만들어보기

#include <stdio.h>
#include <windows.h>

void most_product(int release_product[100], int* ID, int* sell) {
    *ID = 0;
    *sell = release_product[0];
    for (int i = 0; i < 5; i++) {
        if (*sell < release_product[i]) {
            *ID = i;
            *sell = release_product[i];
        }
    }
}

void least_product(int release_product[100], int* ID, int* sell) {
    *ID = 0;
    *sell = release_product[0];
    for (int i = 0; i < 5; i++) {
        if (*sell > release_product[i]) {
            *ID = i;
            *sell = release_product[i];
        }
    }
}

void Caution(int remain_product[100], char product_name[5][20]) {
    for (int i = 0; i < 5; i++) {
        if (remain_product[i] <= 2) {
            printf("상품 ID%d 상품명: %s >>> 재고부족(%d)", i, product_name[i], remain_product[i]);
            printf("\n");
        }
    }
}

void Stocked_product(int stock_product[100]) {
    int menu;
    int name;
    int number;
    int input;

stock_product:
    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입고수량 입력 2를 선택\n");
    scanf("%d", &menu);

    if (menu == 1) {
        printf("상품들의 입고 수량을 입력해주세요>>>");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &input);
            stock_product[i] += input;
        }
    }
    else if (menu == 2) {
        printf("상품 ID: ");
        scanf("%d", &name);
        printf("입고수량: ");
        scanf("%d", &number);

        stock_product[name] += number;
    }
    else {
        printf("올바르지 않은 입력입니다. 다시 입력해주세요.\n");
        Sleep(2000);
        printf("\n");
        goto stock_product;
    }
}

void Sell_product(int release_product[100], int stock_product[100]) {
    int menu;
    int name;
    int number;
    int temp_release_product[5] = { 0 };

    while (1) {
        printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 판매수량 입력 2를 선택\n");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("상품들의 판매 수량을 입력해주세요>>>");
            for (int i = 0; i < 5; i++) {
                scanf("%d", &temp_release_product[i]);
                if (release_product[i] + temp_release_product[i] > stock_product[i]) {
                    printf("판매 수량이 재고를 초과했습니다. 다시 입력해주세요.\n");
                    break;
                }
                else {
                    for (int i = 0;i < 5;i++) release_product[i] += temp_release_product[i];
                }
            }
        }
        else if (menu == 2) {
            printf("상품 ID: ");
            scanf("%d", &name);
            if (name < 1 || name > 5) {
                printf("잘못된 상품 ID입니다. 다시 입력해주세요.\n");
                continue;
            }

            printf("판매수량: ");
            scanf("%d", &number);
            if (release_product[name - 1] + number > stock_product[name - 1]) {
                printf("판매 수량이 재고를 초과했습니다. 다시 입력해주세요.\n");
            }
            else {
                release_product[name - 1] += number;
                break;
            }
        }
        else {
            printf("올바르지 않은 입력입니다. 다시 입력해주세요.\n");
            Sleep(2000);
            printf("\n");
        }
        }
    }

    void Information(int release_product[100], int stock_product[100], char product_name[5][20]) {
        int remain_product[100] = { 0 };
        int sell_product = 0;
        int all_product = 0;
        int ID, sell;
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

        most_product(release_product,&ID, &sell);
        printf("가장 많이 팔린 상품>>> ID: %d, 상품명: %s, 판매량: %d\n", ID, product_name[ID], sell);

        least_product(release_product,&ID, &sell);
        printf("가장 적게 팔린 상품>>> ID: %d, 상품명: %s, 판매량: %d\n", ID, product_name[ID], sell);

        Caution(remain_product, product_name);
    }

    void Product_name(char product_name[5][20]) {

        for (int i = 0; i < 5; i++) {
            printf("ID %d의 상품명을 입력해주세요>>> ", i + 1);
            scanf("%s", product_name[i]);
            printf("\n");
        }
    }
    int main() {
        int stock_product[100] = { 0 };
        int release_product[100] = { 0 };
        char product_name[5][20] = { NULL };
        int menu = 0;

        printf("[쇼핑몰 관리 프로그램]\n");

        while (menu != 5) {
            printf("원하는 메뉴를 선택하세요.>>>(1.입고 2.판매 3.상품현황 4.상품명 입력 5.종료)\n");
            scanf("%d", &menu);

            switch (menu) {
            case 1:
                Stocked_product(stock_product);
                break;
            case 2:
                Sell_product(release_product, stock_product);
                break;
            case 3:
                Information(release_product, stock_product, product_name);
                break;
            case 4:
                Product_name(product_name);
                break;
            case 5:
                return 0;
                break;
            default:
                printf("올바르지 않은 입력입니다. 메뉴를 다시 입력해주세요.\n");
                Sleep(2000);
                printf("\n");
                continue;
                break;
            }

        }
    }
