#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE 100

typedef struct {
	int data[MAX_QUEUE];
	int front;
	int rear;
}Queue;

void init_queue(Queue* q);
bool is_queue_empty(Queue* q);
bool is_queue_full(Queue* q);
int peek_queue(Queue* q);
int dequeue(Queue* q);
void enqueue(Queue* q, int element);
void print_queue(Queue* q);

void queue_menu() {
	Queue q;
	init_queue(&q);
	int num;
	int k;
	while (1) {
		printf("1.Add to Queue\n");
		printf("2.Pop from Queue\n");
		printf("3.Print Queue\n");
		printf("4.Clear Queue\n");
		printf("5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &num);
		switch (num) {
		case 1:
			printf("add number?: ");
			scanf("%d", &k);
			enqueue(&q, k);
			break;
		case 2:
			if (is_queue_empty(&q)) {
				printf("queue is empty\n");
				break;
			}
			else printf("pop %d\n", dequeue(&q));
			break;
		case 3:
			print_queue(&q);
			break;
		case 4:
			printf("clear queue\n");
			init_queue(&q);
			break;
		case 5:
			printf("exit program\n");
			return 0;
		default:
			printf("wrong number\n");
			break;
		}
	}
}

void init_queue(Queue* q) {
	q->rear = 0;
	q->front = 0;
}

bool is_queue_empty(Queue* q) {
	return (q->front) >= (q->rear);
}

bool is_queue_full(Queue* q) {
	return q->rear == MAX_QUEUE - 1;
}

int peek_queue(Queue* q) {
	if (is_queue_empty(q) == 1) { return -1; }
	else { return q->data[q->front]; }
}
int dequeue(Queue* q) {

	return q->data[(q->front)++];
}
void enqueue(Queue* q, int element) {
	if (is_queue_full(q) == 1) {
		printf("queue is full");
	}
	else {
		q->data[(q->rear)++] = element;
	}
}
void print_queue(Queue* q) {
	for (int i = q->front; i < q->rear; i++) {
		printf("%d\n", q->data[i]);
	}
}