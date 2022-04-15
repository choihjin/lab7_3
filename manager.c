#include "manager.h"

int selectNum(Product *p, int count) {
        int num;
        listProduct(p, count);
        printf("번호는 (취소 : 0)? ");
        scanf("%d", &num);
        return num;
}