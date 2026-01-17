#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char usn[20], name[50], branch[10];
    int sem;
    unsigned long long phno;
    struct node *link;
};

struct node *first = NULL, *last = NULL;

void insert_front() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter USN, Name, Branch, Sem, PhNo:\n");
    scanf("%s %s %s %d %llu",
          temp->usn, temp->name, temp->branch,
          &temp->sem, &temp->phno);

    temp->link = first;
    first = temp;

    if (last == NULL)
        last = temp;
}

void insert_rear() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter USN, Name, Branch, Sem, PhNo:\n");
    scanf("%s %s %s %d %llu",
          temp->usn, temp->name, temp->branch,
          &temp->sem, &temp->phno);

    temp->link = NULL;

    if (first == NULL) {
        first = last = temp;
    } else {
        last->link = temp;
        last = temp;
    }
}

void delete_front() {
    struct node *temp;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = first;
    printf("Deleted: %s %s\n", temp->usn, temp->name);
    first = first->link;
    free(temp);

    if (first == NULL)
        last = NULL;
}

void delete_rear() {
    struct node *temp, *prev;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    if (first->link == NULL) {
        printf("Deleted: %s %s\n", first->usn, first->name);
        free(first);
        first = last = NULL;
        return;
    }

    prev = first;
    while (prev->link != last)
        prev = prev->link;

    printf("Deleted: %s %s\n", last->usn, last->name);
    free(last);
    last = prev;
    last->link = NULL;
}

void display() {
    struct node *p = first;
    int count = 0;

    if (p == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Student List:\n");
    while (p != NULL) {
        printf("%s %s %s %d %llu\n",
               p->usn, p->name, p->branch, p->sem, p->phno);
        p = p->link;
        count++;
    }
    printf("Total students = %d\n", count);
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
