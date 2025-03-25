#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = item;
    }
}
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int evaluatePostfix(char* s) {
    int i, a, b;
    for (i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
         push(s[i] - '0');
        } else {
            b = pop();
            a = pop();
            switch (s[i]) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
                case '^':
                    push(a ^ b);
                    break;
                default:
                    printf("Invalid operator: %c\n", s[i]);
                    return -1;
            }
        }
    }
    return pop();
}
int main() {
    char s[100];
    printf("Enter a postfix expression: ");
    scanf("%s", s);
    int result = evaluatePostfix(s);
    printf("Result of postfix evaluation: %d\n", result);
    return 0;
}
