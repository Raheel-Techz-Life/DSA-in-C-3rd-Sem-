#include <stdio.h>
#include <stdlib.h>

struct day {
    char *dname;
    int date;
    char *activity;
};

struct day* create() {
    int i;
    struct day *cal = (struct day*)malloc(7 * sizeof(struct day));

    for (i = 0; i < 7; i++) {
        cal[i].dname = (char*)malloc(20 * sizeof(char));
        cal[i].activity = (char*)malloc(100 * sizeof(char));
    }
    return cal;
}

void read(struct day *cal) {
    int i;
    for (i = 0; i < 7; i++) {
        printf("Enter day name:\n");
        scanf("%s", cal[i].dname);

        printf("Enter date:\n");
        scanf("%d", &cal[i].date);

        printf("Enter activity:\n");
        scanf(" %[^\n]", cal[i].activity);
    }
}

void display(struct day *cal) {
    int i;
    printf("\nWeekly Activity Details\n");
    for (i = 0; i < 7; i++) {
        printf("\nDay: %s", cal[i].dname);
        printf("\nDate: %d", cal[i].date);
        printf("\nActivity: %s\n", cal[i].activity);
    }
}

int main() {
    struct day *calendar;
    int i;

    calendar = create();
    read(calendar);
    display(calendar);

    for (i = 0; i < 7; i++) {
        free(calendar[i].dname);
        free(calendar[i].activity);
    }
    free(calendar);

    return 0;
}
