#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

/* Push into stack */
void push(char ch) {
    stack[++top] = ch;
}

/* Pop from stack */
char pop() {
    return stack[top--];
}

/* Operator precedence */
int priority(char ch) {
    switch (ch) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 4;
    }
    return 0;
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;

    printf("Enter the infix expression:\n");
    gets(infix);

    push('#');   // Sentinel

    while ((ch = infix[i++]) != '\0') {

        /* Operand */
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        /* Left parenthesis */
        else if (ch == '(') {
            push(ch);
        }

        /* Right parenthesis */
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }

        /* Operator */
        else {
            while (priority(stack[top]) >= priority(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    /* Pop remaining operators */
    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
