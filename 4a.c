#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *getNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = data;
    temp->next = NULL;
    return temp;
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void insertBeg(struct Node **head, int info) {
    struct Node *newNode = getNode(info);
    newNode->next = *head;
    *head = newNode;
}

void insertLast(struct Node **head, int info) {
    struct Node *newNode = getNode(info);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node *search(struct Node *head, int data) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->info == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void insertAfter(struct Node **head, int data, int info) {
    struct Node *temp = search(*head, data);
    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }
    struct Node *newNode = getNode(info);
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeBeg(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeLast(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void removeAfter(struct Node **head, int data) {
    struct Node *temp = search(*head, data);
    if (temp == NULL || temp->next == NULL) {
        printf("No node to remove after %d\n", data);
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int main() {
    struct Node *head = NULL;
    int ch, info, data;
    do {
        printf("\n1.........Add Begining"
               "\n2.........Add Last"
               "\n3.........Add After"
               "\n4.........Remove Begining"
               "\n5.........Remove Last"
               "\n6.........Remove After"
               "\n7.........Search"
               "\n8.........Show"
               "\n9.........Exit"
               "\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);
            insertBeg(&head, info);
            break;
        case 2:
            printf("Enter info: ");
            scanf("%d", &info);
            insertLast(&head, info);
            break;
        case 3:
            printf("Enter data after which to insert: ");
            scanf("%d", &data);
            printf("Enter info: ");
            scanf("%d", &info);
            insertAfter(&head, data, info);
            break;
        case 4:
            removeBeg(&head);
            break;
        case 5:
            removeLast(&head);
            break;
        case 6:
            printf("Enter data after which to remove: ");
            scanf("%d", &data);
            removeAfter(&head, data);
            break;
        case 7:
            printf("Enter data to search: ");
            scanf("%d", &data);
            if (search(head, data))
                printf("%d found\n", data);
            else
                printf("%d not found\n", data);
            break;
        case 8:
            traverse(head);
            break;
        case 9:
            printf("This code is executed by : Shreya Goel\n");
            break;
        default:
            printf("Not defined yet\n");
        }
    } while (ch != 9);
    // Free all nodes before exit
    while (head != NULL) {
        removeBeg(&head);
    }
    return 0;
}