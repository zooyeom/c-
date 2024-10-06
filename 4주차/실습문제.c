#include <stdio.h>
#include <windows.h>

void most_product(int release_product[100], char product_name[5][20], int* ID, int* sell,char** name) {
    *sell = 0;
    
    for (int i = 0; i < 5; i++) {
        if (*sell < release_product[i]) {
            *ID = i;
            *sell = release_product[i];
            *name = product_name[i];
        }
    }
}

void least_product(int release_product[100], char product_name[5][20], int* ID, int* sell, char** name) {
    *sell = 10000;
    for (int i = 0; i < 5; i++) {
        if (*sell > release_product[i]) {
            *ID = i;
            *sell = release_product[i];
            *name = product_name[i];
        }
    }
}

void Caution(int remain_product[100],char product_name[5][20]) {
    for (int i = 0; i < 5; i++) {
        if (remain_product[i] <= 2) {
            printf("상품 ID%d 상품명: %s >>> 재고부족(%d)", i,product_name[i], remain_product[i]);
            printf("\n");
        }
    }
}

void Stocked_product(int stock_product[100]) {
    int menu;
    int name;
    int number;

stock_product:
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
    else {
        printf("올바르지 않은 입력입니다. 다시 입력해주세요.\n");
        Sleep(2000);
        printf("\n");
        goto stock_product;
    }
}

void Sell_product(int release_product[100],int stock_product[100]) {
    int menu;
    int name;
    int number;

    sell_product:
        printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 판매수량 입력 2를 선택\n");
        scanf("%d", &menu);

        if (menu == 1) {
        printf("상품들의 판매 수량을 입력해주세요>>>");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &release_product[i]);
            if (release_product[i] > stock_product[i]) {
                while (release_product[i] > stock_product[i]) {
                    printf("재고 상품보다 판매된 상품의 개수가 더 많습니다.\n");
                    printf("남은 상품의 개수는 0 미만이 될 수 없습니다. 다시 입력해주세요.\n");
                    scanf("%d", &release_product[i]);
                }
            }
        }
        
        }
        else if (menu == 2) {
            printf("상품 ID: ");
            scanf("%d", &name);
            printf("판매수량: ");
            scanf("%d", &number);

            release_product[name] = number;
        }
        else {
            printf("올바르지 않은 입력입니다. 다시 입력해주세요.\n");
            Sleep(2000);
            printf("\n");
            goto sell_product;
        }
}

void Information(int release_product[100], int stock_product[100], char product_name[5][20]) {
    int remain_product[100] = { 0 };
    int sell_product = 0;
    int all_product = 0;
    int ID, sell;
    char *name;
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

    most_product(release_product, product_name, &ID, &sell,&name);
    printf("가장 많이 팔린 상품>>> ID: %d, 상품명: %s, 판매량: %d\n", ID,name, sell);
    
    least_product(release_product,product_name, &ID, &sell,&name);
    printf("가장 적게 팔린 상품>>> ID: %d, 상품명: %s, 판매량: %d\n", ID,name, sell);

    Caution(remain_product,product_name);
}

void Product_name(char product_name[5][20]) {
    
    for (int i = 0; i < 5; i++) {
        printf("ID %d의 상품명을 입력해주세요>>> ",i+1);
        scanf("%s", product_name[i]);
        printf("\n");
    }
}
int main() {
    int stock_product[100] = { 0 };
    int release_product[100] = { 0 };
    int remain_product[100] = { 0 };
    char product_name[5][20];
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
            Sell_product(release_product,stock_product);
            break;
        case 3:
            Information(release_product, stock_product,product_name);
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
