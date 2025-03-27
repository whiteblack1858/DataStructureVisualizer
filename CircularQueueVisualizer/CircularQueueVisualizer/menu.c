#include <stdio.h>
#include "menu.h"

void printMainMenu() {
    printf("-----------------------------------\n");
    printf("\t원형큐 시각화 프로그램\n");
    printf("-----------------------------------\n\n");
}

void printMiniMenu() {
    printf("1. 삽입(addq)\n");
    printf("2. 삭제(deleteq)\n");
    printf("3. 가득 찼는지 확인(isFull)\n");
    printf("4. 비어있는지 확인(isEmpty)\n");
    printf("5. 종료\n");
}