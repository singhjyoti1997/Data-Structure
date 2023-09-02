#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX_SIZE - 1);
}

void push(char ch) {
    if (isFull()) {
        printf("Stack Overflow: Cannot insert element %c\n", ch);
    } else {
        top++;
        stack[top] = ch;
    }
}

char pop() {
    if (isEmpty()) {
        printf("Stack Underflow: Cannot delete element from empty stack\n");
        return '\0';
    } else {
        char ch = stack[top];
        top--;
        return ch;
    }
}

char* reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
    return str;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);
    char* reversed = reverseString(str);
    printf("Reversed string: %s\n", reversed);

    return 0;
}
