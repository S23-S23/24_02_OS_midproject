#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_wagu()
{
    printf("\n");
    printf("    ##   ##    ##      ####    ##  ##            ##   ##    ##      ####    ##  ##  \n");
    printf("    ##   ##   ####    ##  ##   ##  ##            ##   ##   ####    ##  ##   ##  ##  \n");
    printf("    ##   ##  ##  ##   ##       ##  ##            ##   ##  ##  ##   ##       ##  ##  \n");
    printf("    ## # ##  ######   ## ###   ##  ##            ## # ##  ######   ## ###   ##  ##  \n");
    printf("    #######  ##  ##   ##  ##   ##  ##            #######  ##  ##   ##  ##   ##  ##  \n");
    printf("    ### ###  ##  ##   ##  ##   ##  ##            ### ###  ##  ##   ##  ##   ##  ##  \n");
    printf("    ##   ##  ##  ##    ####     ####             ##   ##  ##  ##    ####     ####   \n");
    printf("\n");
    printf("                         ����깰 ���ŷ� ����Ʈ                                  \n");
    printf("\n"); printf("\n");
    system("pause");
    system("cls");
}
void print_enter()
{
    printf("\n\n\n\n\n\n\n");
}
void print_good()
{
    printf("                             ");
}

struct Item {
    char name[50];
    float price;
    int quality;
    int quantity;
};
struct buyer_Item {
    char name[50];
    float price;
    int quality;
    int quantity;
};
#pragma region comparing
int compare_names(const void* a, const void* b) {
    return strcmp((*(struct Item**)a)->name, (*(struct Item**)b)->name);
}

int compare_prices(const void* a, const void* b) {
    if ((*(struct Item**)a)->price < (*(struct Item**)b)->price) return -1;
    if ((*(struct Item**)a)->price > (*(struct Item**)b)->price) return 1;
    return 0;
}

int compare_quality(const void* a, const void* b) {
    return (*(struct Item**)a)->quality - (*(struct Item**)b)->quality;
}

int compare_quantity(const void* a, const void* b) {
    return (*(struct Item**)a)->quantity - (*(struct Item**)b)->quantity;
}

void sort_by_name(struct Item** items, int numItems) {
    qsort(items, numItems, sizeof(struct Item*), compare_names);
}

void sort_by_price(struct Item** items, int numItems) {
    qsort(items, numItems, sizeof(struct Item*), compare_prices);
}

void sort_by_quality(struct Item** items, int numItems) {
    qsort(items, numItems, sizeof(struct Item*), compare_quality);
}

void sort_by_quantity(struct Item** items, int numItems) {
    qsort(items, numItems, sizeof(struct Item*), compare_quantity);
}
#pragma endregion

void main_select()
{
    print_enter();
    print_good();
    printf("�޴��� �������ּ���. (1, 2, 3 �Է�)\n");
    printf("\n");
    print_good();
    printf("1. ������\n");
    print_good();
    printf("2. �Ǹ���\n");
    print_good();
    printf("3. �����ϱ�\n");
    print_enter();
    print_enter();
    print_enter();
}

#pragma region seller
void print_seller_menu() {
    system("cls");
    print_enter();
    print_good();
    printf("�Ǹ��ڴ� �������.\n");
    print_good();
    printf("�޴��� �������ּ���.\n");
    print_enter();
    print_good();
    printf("1. ��ǰ �Ǹ�\n");
    print_good();
    printf("2. �Ǹ� ���\n");
    print_good();
    printf("3. �ڷ� ����\n");
}
void sell_item(struct Item** items, int* numItems, int* maxItems) {
    system("cls");
    if (*numItems >= *maxItems) {
        *maxItems *= 2;
        items = (struct Item**)realloc(items, *maxItems * sizeof(struct Item*));
    }
    items[*numItems] = (struct Item*)malloc(sizeof(struct Item));

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("�Ǹ��� ��ǰ�� �̸��� �Է����ּ��� : ");
    fgets(items[*numItems]->name, sizeof(items[*numItems]->name), stdin);
    items[*numItems]->name[strcspn(items[*numItems]->name, "\n")] = '\0'; // Remove newline character

    printf("�Ǹ��� ��ǰ�� ������ �Է����ּ��� : ");
    scanf("%f", &items[*numItems]->price);
    getchar(); 

    printf("�Ǹ��� ��ǰ�� ǰ���� �Է����ּ���(1~10) : ");
    scanf("%d", &items[*numItems]->quality);
    getchar();

    printf("�Ǹ��� ��ǰ�� ������ �Է����ּ��� : ");
    scanf("%d", &items[*numItems]->quantity);
    getchar(); 

    (*numItems)++;

    printf("\n\n��ǰ ��� �Ϸ�!");
    getchar();
}
void sales_history(struct Item** items, int numItems) {
    bool bsalehistory = true;
    while (bsalehistory)
    {
        system("cls");
        printf("�Ǹ� ����:\n");
        printf("--------------------------------------------------\n");
        printf(" %-20s | %-10s | %-8s | %-8s\n", "�̸�", "����", "ǰ��", "����");
        printf("--------------------------------------------------\n");

        for (int i = 0; i < numItems; i++) {
            printf(" %-20s | %-8.f �� | %-8d | %-8d\n",
                items[i]->name, items[i]->price, items[i]->quality, items[i]->quantity);
        }

        printf("--------------------------------------------------\n");
        printf("�Ǹ� ���� ����\n\n");

        printf("�̸� ������ �����Ϸ��� '1'�� �������� \n");
        printf("���� ������ �����Ϸ��� '2'�� �������� \n");
        printf("ǰ�� ������ �����Ϸ��� '3'�� �������� \n");
        printf("���� ������ �����Ϸ��� '4'�� �������� \n");
        printf("�ڷΰ����� '.'�� ��������");
        char sort_select = 0;
        scanf("%c", &sort_select);
        switch (sort_select)
        {
        case '1':
            sort_by_name(items, numItems);
            break;
        case '2':
            sort_by_price(items, numItems);
            break;
        case '3':
            sort_by_quality(items, numItems);
            break;
        case '4':
            sort_by_quantity(items, numItems);
            break;
        case '.':
            bsalehistory = false;
            break;
        default:
            break;
        }
    }
}
void seller(struct Item** items, int* numItems, int* maxItems)
{
    print_enter();
    bool ender = true;
    while (ender)
    {
        char menu_select = 0;
        print_seller_menu();
        scanf("%c", &menu_select);
        switch (menu_select)
        {
        case '1':
            sell_item(items, numItems, maxItems);
            break;
        case '2':
            sales_history(items, *numItems);
            break;
        case '3':
            ender = false;
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
}

#pragma endregion
#pragma region buyer
void buying_item(struct Item** items, int* numItems, const char* search_name);
void print_buyer_menu() {
    system("cls");
    print_enter();
    print_good();
    printf("�����ڴ� �������.\n");
    print_good();
    printf("�޴��� �������ּ���.\n");
    print_enter();
    print_good();
    printf("1. ��ǰ �˻�\n");
    print_good();
    printf("2. ���� ���\n");
    print_good();
    printf("3. �ڷ� ����\n");
}
void search_item(struct Item** items, int* numItems, int* maxItems) {
    while (1) {
        system("cls");
        printf("�Ǹ����� ��ǰ��:\n");
        printf("--------------------------------------------------\n");
        printf(" %-20s | %-10s | %-8s | %-8s\n", "�̸�", "����", "ǰ��", "����");
        printf("--------------------------------------------------\n");

        for (int i = 0; i < *numItems; i++) {
            printf(" %-20s | %-8.f �� | %-8d | %-8d\n",
                items[i]->name, items[i]->price, items[i]->quality, items[i]->quantity);
        }
        printf("--------------------------------------------------\n");

        printf("�˻��� ��ǰ�� �̸��� �Է����ּ��� (�ڷΰ����� '.'�� �Է��ϼ���): ");
        char search_name[50];
        scanf("%s", search_name);
        if (strcmp(search_name, ".") == 0) {
            break;
        }
        buying_item(items, numItems, search_name);
    }
}
void buying_item(struct Item** items, int* numItems, const char* search_name) {
    int index = -1;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i]->name, search_name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("�ش� ��ǰ�� ã�� �� �����ϴ�.\n");
        return;
    }

    int quantity_to_buy;
    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &quantity_to_buy);

    getchar();

    if (items[index]->quantity < quantity_to_buy) {
        printf("��û�Ͻ� ������ ����� �����ϴ�.\n");
        return;
    }

    float total_cost = items[index]->price * quantity_to_buy;
    items[index]->quantity -= quantity_to_buy;

    struct buyer_Item* buyer_item = (struct buyer_Item*)malloc(sizeof(struct buyer_Item));
    if (buyer_item == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }

    strcpy(buyer_item->name, search_name);
    buyer_item->price = items[index]->price;
    buyer_item->quality = items[index]->quality;
    buyer_item->quantity = quantity_to_buy;

    printf(" %.f X %d = %.f \n ", items[index]->price, quantity_to_buy, total_cost);
    printf("��޺� : 3000�� \n");
    printf("�� ����: %.f��\n", total_cost + 2500);
    printf("���ſϷ�!\n");
    printf("�ڷΰ����� '.'�� ��������");
    getchar();
}
void buy_history(struct buyer_Item** items, int numItems) {
    system("cls");
    printf("���� ����:\n");
    printf("--------------------------------------------------\n");
    printf(" %-20s | %-10s | %-8s | %-8s\n", "�̸�", "����", "ǰ��", "����");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf(" %-20s | %-8.f �� | %-8d | %-8d\n",
            items[i]->name, items[i]->price, items[i]->quality, items[i]->quantity);
    }

    printf("--------------------------------------------------\n");
    printf("���� ���� ����\n\n");

    printf("�ڷΰ����� '.'�� ��������\n");
    char select = 0;
    scanf(" %c", &select);
}
void buyer(struct Item** items, int* numItems, int* maxItems) {
    print_enter();
    bool ender = true;
    while (ender) {
        int menu_select = 0;
        print_buyer_menu();
        scanf("%d", &menu_select);
        getchar(); 

        switch (menu_select) {
        case 1:
            search_item(items, numItems, maxItems);
            break;
        case 2:
            buy_history(items, numItems);
            break;
        case 3:
            ender = false;
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
}

#pragma endregion

int main() {

#pragma region
    struct Item** items;
    int numItems = 11;
    int maxItems = 30;

    items = (struct Item**)malloc(maxItems * sizeof(struct Item*));

    items[0] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[0]->name, "����");
    items[0]->price = 6900;
    items[0]->quality = 8;
    items[0]->quantity = 50;

    items[1] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[1]->name, "�ź�");
    items[1]->price = 8000;
    items[1]->quality = 7;
    items[1]->quantity = 20;

    items[2] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[2]->name, "�ٳ���");
    items[2]->price = 5000;
    items[2]->quality = 9;
    items[2]->quantity = 15;

    items[3] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[3]->name, "���");
    items[3]->price = 8900;
    items[3]->quality = 6;
    items[3]->quantity = 8;

    items[4] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[4]->name, "����");
    items[4]->price = 18900;
    items[4]->quality = 7;
    items[4]->quantity = 12;

    items[5] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[5]->name, "����");
    items[5]->price = 4000;
    items[5]->quality = 8;
    items[5]->quantity = 50;

    items[6] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[6]->name, "����");
    items[6]->price = 2500;
    items[6]->quality = 8;
    items[6]->quantity = 45;

    items[7] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[7]->name, "��ȣ��");
    items[7]->price = 2500;
    items[7]->quality = 3;
    items[7]->quantity = 20;

    items[8] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[8]->name, "ȣ��");
    items[8]->price = 3000;
    items[8]->quality = 9;
    items[8]->quantity = 12;

    items[9] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[9]->name, "������");
    items[9]->price = 1000;
    items[9]->quality = 3;
    items[9]->quantity = 23;

    items[10] = (struct Item*)malloc(sizeof(struct Item));
    strcpy(items[10]->name, "����");
    items[10]->price = 4500;
    items[10]->quality = 10;
    items[10]->quantity = 12;

#pragma endregion

    print_wagu();

#pragma region login
    char user_name[64];
    print_enter();
    print_good();
    printf("   Login\n ");
    print_good();
    printf("ID ::        ");
    fgets(user_name, sizeof(user_name), stdin);
    print_good();
    printf("\n\n");
    print_good(); 
    printf("Welcome, %s", user_name);
    system("pause");
#pragma endregion

    bool bmain = true;
    while (bmain)
    {
        main_select();
        int main_select = 0;
        scanf("%d", &main_select);
        getchar();
        switch (main_select)
        {
        case 1:
            buyer(items, &numItems, &maxItems);
            break;
        case 2:
            seller(items, &numItems, &maxItems);
            break;
        case 3:
            system("cls");
            printf("�α׾ƿ��մϴ�. \n");
            bmain = false;
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < numItems; i++) {
        free(items[i]);
    }
    free(items);
    return 0;
}