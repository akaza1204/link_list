#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_QUEUE 100

typedef struct {
    int data[MAX_QUEUE];
    int front;
    int rear;
} Queue;

void init_queue(Queue* q);
bool is_queue_empty(Queue* q);
bool is_queue_full(Queue* q);
int peek_queue(Queue* q);
int dequeue(Queue* q);
void enqueue(Queue* q, int element);
void print_queue(Queue* q);
// 메뉴 함수
void queue_menu();

#endif