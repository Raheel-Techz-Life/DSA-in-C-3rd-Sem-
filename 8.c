#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int ssn;
    char name[50], dept[20], desg[20];
    float sal;
    unsigned long long phno;
    struct node *llink;
    struct node *rlink;
};

struct node *first = NULL, *last = NULL;

void insert_front() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter SSN, Name, Dept, Designation, Salary, PhNo:\n");
    scanf("%d %s %s %s %f %llu",
          &temp->ssn, temp->name, temp->dept,
          temp->desg, &temp->sal, &temp->phno);

    temp->llink = NULL;
    temp->rlink = first;

    if (first != NULL)
        first->llink = temp;
    else
        last = temp;

    first = temp;
}

void insert_rear() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter SSN, Name, Dept, Designation, Salary, PhNo:\n");
    scanf("%d %s %s %s %f %llu",
          &temp->ssn, temp->name, temp->dept,
          temp->desg, &temp->sal, &temp->phno);

    temp->rlink = NULL;
    temp->llink = last;

    if (last != NULL)
        last->rlink = temp;
    else
        first = temp;

    last = temp;
}

void delete_front() {
    struct node *temp;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = first;
    printf("Deleted: %d %s\n", temp->ssn, temp->name);

    first = first->rlink;

    if (first != NULL)
        first->llink = NULL;
    else
        last = NULL;

    free(temp);
}

void delete_rear() {
    struct node *temp;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = last;
    printf("Deleted: %d %s\n", temp->ssn, temp->name);

    last = last->llink;

    if (last != NULL)
        last->rlink = NULL;
    else
        first = NULL;

    free(temp);
}

void display() {
    struct node *p = first;
    int count = 0;

    if (p == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Employee List:\n");
    while (p != NULL) {
        printf("%d %s %s %s %.2f %llu\n",
               p->ssn, p->name, p->dept,
               p->desg, p->sal, p->phno);
        p = p->rlink;
        count++;
    }
    printf("Total employees = %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_rear(); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
