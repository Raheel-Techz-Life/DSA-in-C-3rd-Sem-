#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int hash[MAX];

/* Hash function */
int create(int key) {
    return key % MAX;
}

/* Linear probing */
void linearProbe(int hash[], int key) {
    int index = create(key);
    int i;

    if (hash[index] == -1) {
        hash[index] = key;
    } else {
        printf("Collision detected\n");

        for (i = index + 1; i < MAX; i++) {
            if (hash[i] == -1) {
                hash[i] = key;
                return;
            }
        }

        for (i = 0; i < index; i++) {
            if (hash[i] == -1) {
                hash[i] = key;
                return;
            }
        }
    }
}

/* Display */
void display(int hash[]) {
    int i, choice;

    printf("\n1.Display All\n2.Filtered Display\n");
    printf("Enter choice:\n");
    scanf("%d", &choice);

    if (choice == 1) {
        for (i = 0; i < MAX; i++)
            printf("%d\t%d\n", i, hash[i]);
    } else {
        for (i = 0; i < MAX; i++)
            if (hash[i] != -1)
                printf("%d\t%d\n", i, hash[i]);
    }
}

int main() {
    int key, ans = 1, i;

    for (i = 0; i < MAX; i++)
        hash[i] = -1;

    printf("Collision handling by Linear Probing\n");

    while (ans) {
        printf("Enter the key:\n");
        scanf("%d", &key);
        linearProbe(hash, key);

        printf("Do you want to continue (1/0):\n");
        scanf("%d", &ans);
    }

    display(hash);
    return 0;
}
