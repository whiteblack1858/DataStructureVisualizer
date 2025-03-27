#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

typedef struct {
	int data[MAX_SIZE];
	int front;
	int rear;
} CircularQueue;

void initQueue(CircularQueue* q) {
	q->front = 0;
	q->rear = 0;
}

int isEmpty(CircularQueue* q) {
	return (q->front == q->rear);
}

void printQueue(CircularQueue* q) {
	printf("큐 상태: ");
	int i = q->front;
	while (i != q->rear) {
		i = (i + 1) % MAX_SIZE;
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

int isFull(CircularQueue *q) {
	printQueue(q);
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

void addq(CircularQueue* q, int value) {
	if (isFull(q)) {
		printf("큐가 가득 찼습니다! \n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = value;
	printf("%d을(를) 큐에 추가했습니다. \n", value);
	printQueue(q);
}

int deleteq(CircularQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어 있습니다! \n");
		return -1;
	}
	q->front = (q->front + 1) % MAX_SIZE;
	int value = q->data[q->front];
	printf("%d을(를) 큐에서 제거했습니다. \n", value);
	printQueue(q);
	return value;
}

int main() {
	CircularQueue q;
	initQueue(&q);

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
			addq(&q, value);
			break;
		case 2:
			printf("삭제된 값: %d\n", deleteq(&q));
			break;
		case 3:
			printf(isFull(&q) ? "원형큐가 가득 찼습니다.\n" : "원형큐가 가득 차지 않았습니다.\n");
			break;
		case 4:
			printf(isEmpty(&q) ? "원형큐가 비어 있습니다.\n" : "원형큐에 요소가 있습니다.\n");
			break;
		case 5:
			printf("프로그램 종료\n");
			return 0;
		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n");
		}
	}
}