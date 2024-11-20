#include <stdio.h>

int count = 0;
typedef struct product_info {
	int Product_ID[5];
	char Product_name[5][20];
	int Stocked_num[5];
	int Price[5];
    int Sell_num[5];
}SP;

void Stocked_menu(SP* Sinfo) {
    int ID;
    int number;
    printf("제품의 ID를 입력해주세요>>>");
    scanf("%d", &ID);
    for (int i = 0;i < 5;i++) {
        if (ID == Sinfo->Product_ID[i]) {
            printf("상품명을 변경합니다. 상품명을 적어주세요>>>");
            scanf("%s", &Sinfo->Product_name[i]);
            printf("입고량을 입력해주세요>>>");
            scanf("%d", &Sinfo->Stocked_num[i]);
            printf("상품의 가격을 변경합니다. 입력해주세요>>>");
            scanf("%d", &Sinfo->Price[i]);
            break;
        }
        else {
            printf("상품명을 입력하세요>>>");
            scanf("%s", &Sinfo->Product_name[count]);
            printf("입고량을 입력해주세요>>>");
            scanf("%d", &number);
            Sinfo->Stocked_num[count] += number;
            printf("상품의 가격을 입력해주세요>>>");
            scanf("%d", &Sinfo->Price[count]);
            count++;
            break;
        }
    }
}
void Sell_menu(SP* Sinfo) {
    int ID;
    int number=0;
    printf("상품의 ID를 입력해주세요>>>");
    scanf("%d", &ID);
    for (int i = 0;i < 5;i++) {
        if (ID == Sinfo->Product_ID[i]) {
            printf("판매량을 입력해주세요>>>");
            scanf("%d", &number);
            if (number + Sinfo->Sell_num[i] > Sinfo->Stocked_num[i]) {
                printf("판매량이 입고량을 초과할 순 없습니다. 다시 입력해주세요.\n");
                break;
            }
            else {
                Sinfo->Sell_num[i] += number;
            }
        }
        else {
            printf("ID를 찾을 수 없습니다.\n");
            break;
        }
    }
}
void Product_info(SP* Sinfo) {
    int ID;

    while (1) {
        printf("상품의 ID를 입력해주세요>>>");
        scanf("%d", &ID);

        for (int i = 0;i < 5;i++) {
            if (ID == Sinfo->Product_ID[i]) {
                printf("상품 ID: %d\n", Sinfo->Product_ID[i]);
                printf("상품명: %s\n", Sinfo->Product_name[i]);
                printf("상품가격: %d\n", Sinfo->Price[i]);
                printf("상품 입고량: %d\n", Sinfo->Stocked_num[i]);
                printf("상품 판매량:%d\n", Sinfo->Sell_num[i]);
                printf("총판매금액: %d\n", Sinfo->Sell_num[i] * Sinfo->Price[i]);
                return;
            }
            else {
                printf("검색하신 ID가 존재하지 않습니다. 다시 입력해주세요.");
                continue;
            }
        }

    }
}
void All_info(SP* Sinfo) {
    int sum = 0;
    int all_product = 0;
    printf("<<<상품 재고수량>>>\n");
    for (int i = 0;i < 5;i++) {
        printf("ID: %d, 상품명: %s, 재고수량: %d\n", Sinfo->Product_ID[i], Sinfo->Product_name[i], Sinfo->Stocked_num[i]);
        sum += Sinfo->Sell_num[i];
        all_product += Sinfo->Stocked_num[i];
    }
    printf("총 판매량: %d (판매율: %.2f%%)\n", sum, (float)sum / all_product * 100);
    int most = most_selling_product(Sinfo);
    printf("<<<가장 많이 판매된 상품>>>\n");
    printf("ID: %d, 상품명: %s, 판매량: %d\n", Sinfo->Product_ID[most], Sinfo->Product_name[most], Sinfo->Sell_num[most]);
    int least = least_selling_product(Sinfo);
    printf("<<<가장 적게 판매된 상품>>>\n");
    printf("ID: %d, 상품명: %s, 판매량 %d\n", Sinfo->Product_ID[least], Sinfo->Product_name[least], Sinfo->Sell_num[least]);
    
}
int most_selling_product(SP* Sinfo) {
    int most = Sinfo->Sell_num[0];
    int most_index = 0;
    for (int i = 0;i < 5;i++) {
        if (most < Sinfo->Sell_num[i]) {
            most = Sinfo->Sell_num[i];
            most_index = i;
        }
    }
    return most_index;
}
int least_selling_product(SP* Sinfo) {
    int least = Sinfo->Sell_num[0];
    int least_index = 0;
    for (int i = 0;i < 5;i++) {
        if (least > Sinfo->Sell_num[i]) {
            least = Sinfo->Sell_num[i];
            least_index = i;
        }
    }
    return least_index;
}
void CheckStock(SP* Sinfo) {
    printf("\n<<<재고 부족 상품>>>\n");
    for (int i = 0;i < 5;i++) {
        if (Sinfo->Stocked_num[i] - Sinfo->Sell_num[i] <= 2) {
            printf("상품ID: %d 상품명: %s 제품량: %d\n", Sinfo->Product_ID[i], Sinfo->Product_name[i], Sinfo->Stocked_num[i] - Sinfo->Sell_num[i]);
        } 
    }
}

int main() {
    int menu=0;
    SP Sinfo = { 0 };
    
    while (menu != 5) {
        printf("원하는 메뉴를 선택하세요.>>>1.입고 2.판매 3.개별현황 4.전체현황 5.종료\n");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            Stocked_menu(&Sinfo);
            break;
        case 2:
            Sell_menu(&Sinfo);
            break;
        case 3:
            Product_info(&Sinfo);
            break;
        case 4:
            All_info(&Sinfo);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("올바르지 않은 입력입니다. 메뉴를 다시 입력해주세요.\n");
            printf("\n");
            break;
        }
    }
}
