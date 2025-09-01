#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK 100

typedef struct {
	int data[MAX_STACK];
	int top;
}Stack;

void init_stack(Stack* s);
bool is_empty(Stack* s);
bool is_full(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void print_stack(Stack* s);

void stack_menu() {
	Stack s;
	init_stack(&s);
	int num;
	int k;
	while (1) {
		printf("1.Add to Stack\n");
		printf("2.Pop from Stack\n");
		printf("3.Print Stack\n");
		printf("4.Clear Stack\n");
		printf("5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &num);

		switch (num) {
		case 1:
			printf("add number?: ");
			scanf("%d", &k);
			push(&s, k);
			break;
		case 2:
			if (is_empty(&s)) {
				printf("stack is empty\n");
				break;
			}
			else printf("pop %d\n", pop(&s));
			break;
		case 3:
			print_stack(&s);
			break;
		case 4:
			printf("clear stack\n");
			init_stack(&s);
			break;
		case 5:
			printf("exit program\n");
			
		default:
			printf("wrong number\n");
			break;
		}
	}

}

void init_stack(Stack* s) {
	s->top = -1;
}
bool is_empty(Stack* s) {
	return s->top == -1;
}
bool is_full(Stack* s) {
	return s->top == MAX_STACK - 1;
}

void push(Stack* s, int value) {
	if (is_full(s) == 1) {
		printf("stack is full\n");
	}
	else {
		s->data[++(s->top)] = value;
	}
}

int pop(Stack* s) {
	return s->data[(s->top)--];
}

int peek(Stack* s) {
	if (is_empty(s) == 1) {
		printf("stack is empty\n");
		return -1;
	}
	else {
		return s->data[(s->top)];
	}
}

void print_stack(Stack* s) {
	for (int i = s->top; i >= 0; i--) {
		printf("%d\n", s->data[i]);
	}
}