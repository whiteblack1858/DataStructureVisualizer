#include <stdio.h>
#include "menu.h"

void printMainMenu() {
    printf("-----------------------------------\n");
    printf("\t���� �ð�ȭ ���α׷�\n");
    printf("-----------------------------------\n\n");
}

void printMiniMenu() {
    printf("1. ����(push)\n");
    printf("2. ����(pop)\n");
    printf("3. ������ top�� Ȯ��(peek)\n");
    printf("4. ���� á���� Ȯ��(isFull)\n");
    printf("5. ����ִ��� Ȯ��(isEmpty)\n");  // ���� `isFull` �ߺ� ���� ����
    printf("6. ����\n");
}

