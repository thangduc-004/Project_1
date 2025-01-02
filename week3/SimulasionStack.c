//c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 

int stack[MAX_SIZE]; 
int top = -1;       
void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;  
    } else {
        printf("Stack Overflow\n");  
    }
}

void pop() {
    if (top >= 0) {
        printf("%d\n", stack[top--]); 
    } else {
        printf("NULL\n"); 
}
}
int main() {
    char command[20];  
    int value;         

    while (1) {
        scanf("%s", command);  

        if (strcmp(command, "#") == 0) {
            break;  
        }

        if (strcmp(command, "PUSH") == 0) {
            scanf("%d", &value);  
            push(value);          
        } else if (strcmp(command, "POP") == 0) {
            pop();  
        }
    }

    return 0;
}
