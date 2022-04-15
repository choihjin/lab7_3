#include "manager.h"

int main() {
    Product p[20];
    int count = 0;
    int index = 0;
    int menu = 0;

    count = loadData(p);
    index = count;
     while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1) {
            if(count>0) {
                listProduct(p,index);
            } else {
                printf("등록된 제품없음!!\n");
            }
        }
        else if (menu == 2) {
            createProduct(&p[index]);
            count++;
            index++;
        }
        else if (menu == 3) {
            int num = selectNum(p,index);
            if(num == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&p[num-1]);
            printf("=>수정됨!\n");
        }
        else if (menu == 4) {
            int num = selectNum(p,index);
            if(num == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int delete;
            printf("정말로 삭제하시겠습니까?(삭제: 1) ");
            scanf("%d",&delete);
            if(delete == 1) {
                if(deleteProduct(&p[num-1]) == 1) {
                    count--;
                    printf("=> 삭제됨!\n");
                }
            }
        }
         else if (menu == 5) {
            saveData(p, index);
        }
        else if (menu == 6) {
            searchProduct(p, index);
        }
        else if (menu == 7) {
            searchPrice(p, index);
        }
        else if (menu == 8) {
            searchWay(p, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}