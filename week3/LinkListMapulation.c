//c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addLast(Node** head, int data) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == data) return;
        temp = temp->next;
    }

    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void addFirst(Node** head, int data) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == data) return;
        temp = temp->next;
    }

    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void addAfter(Node* head, int u, int v) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == u) return;
        temp = temp->next;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->data == v) {
            Node* newNode = createNode(u);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void addBefore(Node** head, int u, int v) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == u) return;
        temp = temp->next;
    }
    if (*head != NULL && (*head)->data == v) {
        addFirst(head, u);
        return;
    }

    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == v) {
            Node* newNode = createNode(u);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void removeNode(Node** head, int k) {
    Node* current = *head;
    Node* prev = NULL;

    if (current != NULL && current->data == k) {
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != k) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;
    prev->next = current->next;
    free(current);
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
  
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        addLast(&head, val);
    }
  
    char command[20];
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "#") == 0) {
            break;
        }

        if (strcmp(command, "addlast") == 0) {
            int k;
            scanf("%d", &k);
            addLast(&head, k);
        } else if (strcmp(command, "addfirst") == 0) {
            int k;
            scanf("%d", &k);
            addFirst(&head, k);
        } else if (strcmp(command, "addafter") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            addAfter(head, u, v);
        } else if (strcmp(command, "addbefore") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            addBefore(&head, u, v);
        } else if (strcmp(command, "remove") == 0) {
            int k;
            scanf("%d", &k);
            removeNode(&head, k);
        } else if (strcmp(command, "reverse") == 0) {
            reverseList(&head);
        }
    }

    printList(head);
    return 0;
}
