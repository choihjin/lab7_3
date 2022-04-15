#include "product.h"
#include <string.h>

int selectMenu() {
        int menu;
        printf("\n** 과일 쇼핑 **\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 파일저장\n");
        printf("6. 제품이름검색\n");
        printf("7. 제품가격검색\n");
        printf("8. 배송방법검색\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는? ");
        scanf("%d", &menu);
        return menu;
}

void createProduct(Product *p) {
        printf("이름은? ");
        scanf("%s", p->name);
        printf("설명은? ");
        scanf("%s", p->ex);
        printf("무게는? ");
        scanf("%s", p->weight);
        getchar();
        printf("가격은? ");
        scanf(" %d", &p->price);
        printf("배송방법은? ");
        scanf("%d", &p->way);
}

void readProduct(Product p) {
        printf("%s %s\n", p.name, p.weight);
        printf("%s\n%d원\n",p.ex, p.price);
        if(p.way == 1) {
                printf("새벽배송\n");
        } else {
                printf("택배배송\n");
        }
        printf("==========================\n");
}

void listProduct(Product *p, int num) {
        for(int i=0; i<num; i++) {
                if(p[i].price == 0) continue;
                printf("%d ", i+1);
                readProduct(p[i]);
        }
}

void updateProduct(Product *p) {
        printf("이름은? ");
        scanf("%s", p->name);
        printf("설명은? ");
        scanf("%s", p->ex);
        printf("무게는? ");
        scanf("%s", p->weight);
        getchar();
        printf("가격은? ");
        scanf("%d", &p->price);
        printf("배송방법은? ");
        scanf("%d", &p->way);
}

int deleteProduct(Product *p) {
        p->price = 0;
        return 1;
}

void searchProduct(Product *p, int count) {
        char search[20];
        int num = 0;
        printf("검색할 제품이름은? ");
        scanf("%s", search);
        printf("===========================\n");
        for(int i=0; i<count; i++) {
                if(p[i].price == 0) continue;
                if(strstr(p[i].name, search)) {
                        printf("%d ", i+1);
                        readProduct(p[i]);
                        num++;
                }
        }
        if(num == 0) {
                printf("=> 검색된 데이터 없음\n");
        }
}

void searchPrice(Product *p, int count) {
        int search;
        int num = 0;
        printf("검색할 가격대는 (만원단위입력)? ");
        scanf("%d", &search);
        #ifdef DEBUG
                printf("=> DEBUGMODE\n");
                printf("search = %d ~ %d\n", search, search+9999);
        #endif
        printf("===========================\n");
        for(int i=0; i<count; i++) {
                if(p[i].price == 0) continue;
                if(p[i].price >= search && p[i].price <= search+9999) {
                        printf("%d ", i+1);
                        readProduct(p[i]);
                        num++;
                }
        }
        if(num == 0) {
                printf("=> 검색된 데이터 없음\n");
        }
}

void searchWay(Product *p, int count) {
        int search;
        int num = 0;
        printf("검색할 배송방법은 (1.새벽배송, 2.택배배송)? ");
        scanf("%d", &search);
        printf("===========================\n");
        for(int i=0; i<count; i++) {
                if(p[i].price == 0) continue;
                if(p[i].way == search) {
                        printf("%d ", i+1);
                        readProduct(p[i]);
                        num++;
                }
        }
        if(num == 0) {
                printf("=> 검색된 데이터 없음\n");
        }
}

int loadData(Product *p) {
    int count=0;
    FILE *fp;
    if ((fp = fopen("product.txt", "r"))) {
        while(1) {
            fscanf(fp, "%s", p[count].name);
            fscanf(fp, "%s", p[count].ex);
            fscanf(fp, "%s", p[count].weight);
            fscanf(fp, "%d", &p[count].price);
            fscanf(fp, "%d", &p[count].way);
            if(feof(fp)) break;
            count++;
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
    } else {
        printf("\n=> 파일 없음\n");
    }
    return count;
}

void saveData(Product *p, int count) {
    FILE *fp2;
    fp2 = fopen("product.txt", "w+");
    for(int i=0; i<count; i++) {
        if(p[i].price == 0) continue;
        fprintf(fp2, "%s %s %s %d %d\n",p[i].name, p[i].ex, p[i].weight, p[i].price, p[i].way);
        #ifdef DEBUG
                if(i==0) {
                        printf("=> DEBUGMODE\n");
                }
                printf("save : %s %s %s %d %d\n",p[i].name, p[i].ex, p[i].weight, p[i].price, p[i].way);
        #endif
    }
    fclose(fp2);
    printf("저장됨!\n");
}
