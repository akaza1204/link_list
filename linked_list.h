#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int element;

typedef struct Node {
    element data;
    struct Node* link;
} Node;

// 함수 선언
Node* add_front(Node* head, element value);
Node* add_rear(Node* head, element value);
Node* insert(Node* head, element value, Node* pre);
Node* delete_after(Node* head, Node* pre);
Node* clear(Node* head);
Node* reverse(Node* head);
Node* sort(Node* head);
void print_list(Node* head);

// 메뉴 함수
void linked_list_menu();

#endif