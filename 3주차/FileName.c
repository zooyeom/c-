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
            printf("��ǰ ID %d: ������(%d)", i, remain_product[i]);
            printf("\n");
        }
    }
}

void Stocked_product(int stock_product[100]) {
    int menu;
    int name;
    int number;

    printf("�԰���� �Է�: ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �԰���� �Է� 2�� ����\n");
    scanf("%d", &menu);

    if (menu == 1) {
        printf("��ǰ���� �԰� ������ �Է����ּ���>>>");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &stock_product[i]);
        }
    }
    else if (menu == 2) {
        printf("��ǰ ID: ");
        scanf("%d", &name);
        printf("�԰����: ");
        scanf("%d", &number);

        stock_product[name] = number;
    }
}

void Sell_product(int release_product[100]) {
    int menu;
    int name;
    int number;

    printf("�Ǹż��� �Է�: ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Ǹż��� �Է� 2�� ����\n");
    scanf("%d", &menu);

    if (menu == 1) {
        printf("��ǰ���� �Ǹ� ������ �Է����ּ���>>>");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &release_product[i]);
        }
    }
    else if (menu == 2) {
        printf("��ǰ ID: ");
        scanf("%d", &name);
        printf("�Ǹż���: ");
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

    printf("��� ������:");
    for (int i = 0; i < 5; i++) {
        printf("%d  ", remain_product[i]);
    }
    printf("\n�� �Ǹŷ�: %d (�Ǹ���: %.2f%%)\n", sell_product, sell_percent);

    most_product(release_product, &name, &sell);
    printf("���� ���� �ȸ� ��ǰ>>> ID: %d, �Ǹŷ�: %d\n", name, sell);

    least_product(release_product, &name, &sell);
    printf("���� ���� �ȸ� ��ǰ>>> ID: %d, �Ǹŷ�: %d\n", name, sell);

    Caution(remain_product);
}

int main() {
    int stock_product[100] = { 0 };
    int release_product[100] = { 0 };
    int remain_product[100] = { 0 };
    int menu = 0;  // �ʱ�ȭ

    printf("[���θ� ���� ���α׷�]\n");

    while (menu != 4) {
        printf("���ϴ� �޴��� �����ϼ���.>>>(1.�԰� 2.�Ǹ� 3.��ǰ��Ȳ 4.����)\n");
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
