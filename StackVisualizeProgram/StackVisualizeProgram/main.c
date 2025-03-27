#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void printStack(Stack* s) {
    printf("\n현재 스택 상태:\n\n");
    for (int i = s->top; i >= 0; i--) {
        printf("| %d |\n", s->data[i]);
    }
    printf("-----\n\n");
}

int isEmpty(Stack* s) {
    printStack(s);
    return s->top == -1;
}

int isFull(Stack* s) {
    printStack(s);
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->data[++(s->top)] = value;
    printStack(s);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    int value = s->data[(s->top)--];
    printStack(s);
    return value;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    int value = s->data[s->top];
    printStack(s);
    return value;
}

int main() {
    Stack s;
    init(&s);

    int choice, value;
    while (1) {
        printMainMenu();
        printMiniMenu();
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 값 입력: ");
            scanf("%d", &value);
            push(&s, value);
            break;
        case 2:
            printf("삭제된 값: %d\n", pop(&s));
            break;
        case 3:
            printf("Top 값: %d\n", peek(&s));
            break;
        case 4:
            printf(isFull(&s) ? "스택이 가득 찼습니다.\n" : "스택이 가득 차지 않았습니다.\n");
            break;
        case 5:
            printf(isEmpty(&s) ? "스택이 비어 있습니다.\n" : "스택에 요소가 있습니다.\n");
            break;
        case 6:
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
        }
    }
}
