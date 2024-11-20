#include <stdio.h>

#define MAX_PRODUCTS 5
#define NAME_LENGTH 20

typedef struct product_info {
    int Product_ID[MAX_PRODUCTS];
    char Product_name[MAX_PRODUCTS][NAME_LENGTH];
    int Stocked_num[MAX_PRODUCTS];
    int Price[MAX_PRODUCTS];
    int Sell_num[MAX_PRODUCTS];
} SP;

int count = 0;

void Stocked_menu(SP* Sinfo) {
    int ID;
    int number;
    printf("제품의 ID를 입력해주세요>>>");
    if (scanf("%d", &ID) != 1) {
        printf("유효하지 않은 입력입니다.\n");
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    
    for (int i = 0; i < count; i++) {
        if (ID == Sinfo->Product_ID[i]) {
            printf("상품명을 변경합니다. 상품명을 적어주세요>>>");
            scanf("%19s", Sinfo->Product_name[i]); // 버퍼 오버플로우 방지
            printf("입고량을 입력해주세요>>>");
            if (scanf("%d", &number) != 1) {
                printf("유효하지 않은 입력입니다.\n");
                
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                return;
            }
            Sinfo->Stocked_num[i] += number;
            printf("상품의 가격을 변경합니다. 입력해주세요>>>");
            if (scanf("%d", &Sinfo->Price[i]) != 1) {
                printf("유효하지 않은 입력입니다.\n");
               
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                return;
            }
            printf("상품 정보가 업데이트되었습니다.\n");
            return;
        }
    }

    
    if (count < MAX_PRODUCTS) { 
        Sinfo->Product_ID[count] = ID;
        printf("신규 상품명을 입력하세요>>>");
        scanf("%19s", Sinfo->Product_name[count]); 
        printf("입고량을 입력해주세요>>>");
        if (scanf("%d", &number) != 1) {
            printf("유효하지 않은 입력입니다.\n");
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            return;
        }
        Sinfo->Stocked_num[count] = number;
        printf("상품의 가격을 입력해주세요>>>");
        if (scanf("%d", &Sinfo->Price[count]) != 1) {
            printf("유효하지 않은 입력입니다.\n");
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            return;
        }
        Sinfo->Sell_num[count] = 0; 
        count++;
        printf("신규 상품이 추가되었습니다.\n");
    }
    else {
        printf("더 이상 상품을 추가할 수 없습니다.\n");
    }
}

void Sell_menu(SP* Sinfo) {
    int ID;
    int number = 0;
    printf("상품의 ID를 입력해주세요>>>");
    if (scanf("%d", &ID) != 1) {
        printf("유효하지 않은 입력입니다.\n");
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    for (int i = 0; i < count; i++) {
        if (ID == Sinfo->Product_ID[i]) {
            printf("판매량을 입력해주세요>>>");
            if (scanf("%d", &number) != 1) {
                printf("유효하지 않은 입력입니다.\n");
                
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                return;
            }
            if (number + Sinfo->Sell_num[i] > Sinfo->Stocked_num[i]) {
                printf("판매량이 입고량을 초과할 순 없습니다. 다시 입력해주세요.\n");
            }
            else {
                Sinfo->Sell_num[i] += number;
                printf("판매가 완료되었습니다.\n");
            }
            return;
        }
    }
    printf("ID를 찾을 수 없습니다.\n");
}

void Product_info(SP* Sinfo) {
    int ID;
    printf("상품의 ID를 입력해주세요>>>");
    if (scanf("%d", &ID) != 1) {
        printf("유효하지 않은 입력입니다.\n");
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    for (int i = 0; i < count; i++) {
        if (ID == Sinfo->Product_ID[i]) {
            printf("상품 ID: %d\n", Sinfo->Product_ID[i]);
            printf("상품명: %s\n", Sinfo->Product_name[i]);
            printf("상품가격: %d\n", Sinfo->Price[i]);
            printf("상품 입고량: %d\n", Sinfo->Stocked_num[i]);
            printf("상품 판매량:%d\n", Sinfo->Sell_num[i]);
            printf("총판매금액: %d\n", Sinfo->Sell_num[i] * Sinfo->Price[i]);
            return;
        }
    }
    printf("검색하신 ID가 존재하지 않습니다. 다시 입력해주세요.\n");
}

void All_info(SP* Sinfo) {
    int sum = 0;
    int all_product = 0;
    printf("<<<상품 재고수량>>>\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, 상품명: %s, 재고수량: %d\n",
            Sinfo->Product_ID[i],
            Sinfo->Product_name[i],
            Sinfo->Stocked_num[i] - Sinfo->Sell_num[i]);
        sum += Sinfo->Sell_num[i];
        all_product += Sinfo->Stocked_num[i];
    }
    if (all_product > 0)
        printf("총 판매량: %d (판매율: %.2f%%)\n", sum, (float)sum / all_product * 100);
    else
        printf("판매율을 계산할 수 없습니다.\n");

    if (count > 0) {
        int most = most_selling_product(Sinfo);
        if (most != -1) {
            printf("<<<가장 많이 판매된 상품>>>\n");
            printf("ID: %d, 상품명: %s, 판매량: %d\n",
                Sinfo->Product_ID[most],
                Sinfo->Product_name[most],
                Sinfo->Sell_num[most]);
        }

        int least = least_selling_product(Sinfo);
        if (least != -1) {
            printf("<<<가장 적게 판매된 상품>>>\n");
            printf("ID: %d, 상품명: %s, 판매량: %d\n",
                Sinfo->Product_ID[least],
                Sinfo->Product_name[least],
                Sinfo->Sell_num[least]);
        }
    }
    else {
        printf("등록된 상품이 없습니다.\n");
    }
}

int most_selling_product(SP* Sinfo) {
    if (count == 0) return -1;
    int most = Sinfo->Sell_num[0];
    int most_index = 0;
    for (int i = 1; i < count; i++) {
        if (most < Sinfo->Sell_num[i]) {
            most = Sinfo->Sell_num[i];
            most_index = i;
        }
    }
    return most_index;
}

int least_selling_product(SP* Sinfo) {
    if (count == 0) return -1;
    int least = Sinfo->Sell_num[0];
    int least_index = 0;
    for (int i = 1; i < count; i++) {
        if (least > Sinfo->Sell_num[i]) {
            least = Sinfo->Sell_num[i];
            least_index = i;
        }
    }
    return least_index;
}

void CheckStock(SP* Sinfo) {
    printf("\n<<<재고 부족 상품>>>\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (Sinfo->Stocked_num[i] - Sinfo->Sell_num[i] <= 2) {
            printf("상품ID: %d 상품명: %s 제품량: %d\n",
                Sinfo->Product_ID[i],
                Sinfo->Product_name[i],
                Sinfo->Stocked_num[i] - Sinfo->Sell_num[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("재고가 부족한 상품이 존재하지 않습니다.\n");
    }
}

int main() {
    int menu = 0;
    SP Sinfo = { 0 };

    while (menu != 5) {
        printf("\n원하는 메뉴를 선택하세요.>>>1.입고 2.판매 3.개별현황 4.전체현황 5.종료\n");
        printf(">>>");
        if (scanf("%d", &menu) != 1) {
            printf("유효하지 않은 입력입니다.\n");
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

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
            CheckStock(&Sinfo);
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("올바르지 않은 입력입니다. 메뉴를 다시 입력해주세요.\n");
            printf("\n");
            break;
        }
    }
    return 0;
}
