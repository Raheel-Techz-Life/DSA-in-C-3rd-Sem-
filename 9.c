
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Node structure */
struct node {
    int co, ex, ey, ez;
    struct node *link;
};

typedef struct node NODE;

/* Create a node */
NODE* createNode(int co, int ex, int ey, int ez) {
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->co = co;
    temp->ex = ex;
    temp->ey = ey;
    temp->ez = ez;
    temp->link = NULL;
    return temp;
}

/* Attach node to circular list */
NODE* attachNode(NODE *head, NODE *temp) {
    NODE *cur = head;
    while (cur->link != head)
        cur = cur->link;

    cur->link = temp;
    temp->link = head;
    return head;
}

/* Read polynomial */
NODE* readPoly() {
    int n, co, ex, ey, ez;
    NODE *head = (NODE*)malloc(sizeof(NODE));
    head->link = head;

    printf("Enter number of terms:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient:\n");
        scanf("%d", &co);
        printf("Enter exponent of x, y, z:\n");
        scanf("%d %d %d", &ex, &ey, &ez);

        head = attachNode(head, createNode(co, ex, ey, ez));
    }
    return head;
}

/* Display polynomial */
void display(NODE *head) {
    NODE *cur = head->link;
    if (cur == head) {
        printf("Polynomial is empty\n");
        return;
    }

    while (cur != head) {
        printf("%dx^%dy^%dz^%d", cur->co, cur->ex, cur->ey, cur->ez);
        cur = cur->link;
        if (cur != head)
            printf(" + ");
    }
    printf("\n");
}

/* Evaluate polynomial */
void evaluate(NODE *head) {
    int x, y, z, result = 0;
    NODE *cur = head->link;

    printf("Enter values of x, y, z:\n");
    scanf("%d %d %d", &x, &y, &z);

    while (cur != head) {
        result += cur->co *
                  pow(x, cur->ex) *
                  pow(y, cur->ey) *
                  pow(z, cur->ez);
        cur = cur->link;
    }
    printf("Result = %d\n", result);
}

/* Add two polynomials */
NODE* addPoly(NODE *p1, NODE *p2) {
    NODE *p3 = (NODE*)malloc(sizeof(NODE));
    p3->link = p3;

    NODE *a = p1->link;
    NODE *b = p2->link;

    while (a != p1 && b != p2) {
        if (a->ex == b->ex && a->ey == b->ey && a->ez == b->ez) {
            p3 = attachNode(p3, createNode(a->co + b->co, a->ex, a->ey, a->ez));
            a = a->link;
            b = b->link;
        }
        else {
            p3 = attachNode(p3, createNode(a->co, a->ex, a->ey, a->ez));
            a = a->link;
        }
    }

    while (a != p1) {
        p3 = attachNode(p3, createNode(a->co, a->ex, a->ey, a->ez));
        a = a->link;
    }

    while (b != p2) {
        p3 = attachNode(p3, createNode(b->co, b->ex, b->ey, b->ez));
        b = b->link;
    }

    return p3;
}

/* Main */
int main() {
    int choice;
    NODE *p1, *p2, *p3;

    while (1) {
        printf("\n1. Represent & Evaluate Polynomial");
        printf("\n2. Add Two Polynomials");
        printf("\n3. Exit");
        printf("\nEnter choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter polynomial:\n");
                p1 = readPoly();
                printf("Polynomial is:\n");
                display(p1);
                evaluate(p1);
                break;

            case 2:
                printf("Enter Polynomial 1:\n");
                p1 = readPoly();
                display(p1);

                printf("Enter Polynomial 2:\n");
                p2 = readPoly();
                display(p2);

                p3 = addPoly(p1, p2);
                printf("Resultant Polynomial:\n");
                display(p3);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
