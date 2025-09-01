#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"

int main() {
    int choice;
    while (1) {
        printf("\n=== Main Menu ===\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            stack_menu();
            break;
        case 2:
            queue_menu();
            break;
        case 3:
            linked_list_menu();
            break;
        case 4:
            printf("Bye!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
	return 0;
}