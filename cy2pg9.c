
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertChaining(struct Node* hashTable[], int key, int data) {
    int index = key % SIZE;
    struct Node* newNode = createNode(data);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayChaining(struct Node* hashTable[]) {
    printf("Hash Table (Chaining):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        printf("NULL\n");
    }
}

void insertLinearProbing(int hashTable[], int key, int data) {
    int index = key % SIZE;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = data;
}

void displayLinearProbing(int hashTable[]) {
    printf("Hash Table (Linear Probing):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    struct Node* hashTableChaining[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTableChaining[i] = NULL;
    }
    int hashTableLinearProbing[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTableLinearProbing[i] = -1;
    }
    int choice, key, data;

    do {
        printf("\n1. Insert (Chaining)\n");
        printf("2. Display (Chaining)\n");
        printf("3. Insert (Linear Probing)\n");
        printf("4. Display (Linear Probing)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and data for Chaining: ");
                scanf("%d %d", &key, &data);
                insertChaining(hashTableChaining, key, data);
                break;

            case 2:
                displayChaining(hashTableChaining);
                break;

            case 3:
                printf("Enter key and data for Linear Probing: ");
                scanf("%d %d", &key, &data);
                insertLinearProbing(hashTableLinearProbing, key, data);
                break;

            case 4:
                displayLinearProbing(hashTableLinearProbing);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
