#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_STACK 100

typedef struct {
    int data[MAX_STACK];
    int top;
} Stack;


void init_stack(Stack* s);
bool is_empty(Stack* s);
bool is_full(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void print_stack(Stack* s);
// 메뉴 함수
void stack_menu();

#endif