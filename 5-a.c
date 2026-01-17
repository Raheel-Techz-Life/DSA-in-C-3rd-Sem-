#include <stdio.h>
#include <math.h>

#define MAX 50

int stack[MAX];
int top = -1;

/* Push */
void push(int x) {
    stack[++top] = x;
}

/* Pop */
int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter postfix expression:\n");
    gets(postfix);

    for (i = 0; postfix[i] != '\0'; i++) {

        /* Operand */
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        }

        /* Operator */
        else {
            op2 = pop();
            op1 = pop();

            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
            push(result);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
