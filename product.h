#include <stdio.h>

typedef struct {
    char name[50];
    char ex[100];
    char weight[10];
    int price;
    int way; 
} Product;

// 메뉴를 선택하는 함수
int selectMenu();
// 제품을 추가하는 함수
void createProduct(Product *p);
// 하나의 제품 출력 함수
void readProduct(Product p);
void listProduct(Product *p, int num);
// 제품을 수정하는 함수
void updateProduct(Product *p);
// 제품을 삭제하는 함수
int deleteProduct(Product *p);
// 제품이름 검색하는 함수
void searchProduct(Product *p, int count);
// 제품 가격대를 검색하는 함수
void searchPrice(Product *p, int count);
// 배송방법을 검색하는 함수: 새벽배송으로 설정시 새벽배송가능한 제품 검색
void searchWay(Product *p, int count);
// 파일 데이터를 읽는 함수
int loadData(Product *p);
// 파일 데이터에 저장하는 함수
void saveData(Product *p, int num);
