#include <stdio.h>
#include "menu.h"

void printMainMenu() {
    printf("-----------------------------------\n");
    printf("\t스택 시각화 프로그램\n");
    printf("-----------------------------------\n\n");
}

void printMiniMenu() {
    printf("1. 삽입(push)\n");
    printf("2. 삭제(pop)\n");
    printf("3. 스택의 top값 확인(peek)\n");
    printf("4. 가득 찼는지 확인(isFull)\n");
    printf("5. 비어있는지 확인(isEmpty)\n");  // 기존 `isFull` 중복 문제 수정
    printf("6. 종료\n");
}

