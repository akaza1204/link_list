#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct Node {
    element data;
    struct Node* link;
} Node;

Node* add_front(Node* head, element value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = head;
    return newNode;   // head °»½Å
}

Node* add_rear(Node* head, element value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = NULL;

    if (head == NULL) {
        return newNode;
    }
    else {
        Node* p = head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = newNode;
    }
    return head;
}

Node* insert(Node* head, element value, Node* pre) {
    if (pre == NULL) return head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = pre->link;
    pre->link = newNode;
    return head;
}

Node* delete(Node* head, Node* pre) {
    if (pre == NULL || pre->link == NULL) return head;
    Node* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

Node* clear(Node* head) {
    Node* p = head;
    Node* removed;
    while (p != NULL) {
        removed = p;
        p = p->link;
        free(removed);
    }
    return NULL;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* sort(Node* head) {
    Node* p = head;
    Node* q = NULL;
    element temp;
    if (head == NULL) return head;

    while (p != NULL) {
        q = p->link;
        while (q != NULL) {
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->link;
        }
        p = p->link;
    }
    return head;
}

void print_list(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

void linked_list_menu() {
    int choice, value, pos;
    Node* head = NULL;

    while (1) {
        printf("\n===== Linked List Menu =====\n");
        printf("1. Add to front\n");
        printf("2. Add to rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Reverse list\n");
        printf("6. Sort list\n");
        printf("7. Clear list\n");
        printf("8. Print list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to add to front: ");
            scanf("%d", &value);
            head = add_front(head, value);
            break;

        case 2:
            printf("Enter value to add to rear: ");
            scanf("%d", &value);
            head = add_rear(head, value);
            break;

        case 3:
            printf("Enter position (0 = front): ");
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &value);

            if (pos == 0) {
                head = add_front(head, value);
            }
            else {
                Node* p = head;
                for (int i = 0; i < pos - 1 && p != NULL; i++) {
                    p = p->link;
                }
                if (p == NULL) {
                    printf("Invalid position\n");
                }
                else {
                    head = insert(head, value, p);
                }
            }
            break;

        case 4:
            printf("Enter position to delete (0 = front): ");
            scanf("%d", &pos);

            if (head == NULL) {
                printf("List is empty\n");
            }
            else if (pos == 0) {  
                Node* removed = head;
                head = head->link;
                free(removed);
            }
            else {
                Node* p = head;
                for (int i = 0; i < pos - 1 && p != NULL; i++) {
                    p = p->link;
                }
                if (p == NULL || p->link == NULL) {
                    printf("Invalid position\n");
                }
                else {
                    Node* removed = p->link;
                    p->link = removed->link;
                    free(removed);
                }
            }
            break;

        case 5:
            head = reverse(head);
            printf("List reversed\n");
            break;

        case 6:
            head = sort(head);
            printf("List sorted\n");
            break;

        case 7:
            head = clear(head);
            printf("List cleared\n");
            break;

        case 8:
            if (head == NULL) {
                printf("List is empty\n");
            }
            else {
                print_list(head);
            }
            break;

        case 9:
            printf("Exit program\n");
            head = clear(head);
          

        default:
            printf("Invalid choice, try again\n");
            break;
        }
    }

}