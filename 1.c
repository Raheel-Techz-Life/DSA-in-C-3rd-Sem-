#include <stdio.h>
#include <stdlib.h>

struct Day {
    char *day;
    int date;
    char *activity;
};

struct Day* create() {
    struct Day *cal = (struct Day*)malloc(7 * sizeof(struct Day));
    int i;
    for (i = 0; i < 7; i++) {
        cal[i].day = (char*)malloc(20 * sizeof(char));
        cal[i].activity = (char*)malloc(100 * sizeof(char));
    }
    return cal;
}

void read(struct Day *cal) {
    int i;
    for (i = 0; i < 7; i++) {
        printf("Enter the day name for Day %d: ", i + 1);
        scanf("%s", cal[i].day);

        printf("Enter the date for Day %d: ", i + 1);
        scanf("%d", &cal[i].date);

        printf("Enter the activity for Day %d: ", i + 1);
        scanf(" %[^\n]", cal[i].activity);
    }
}

void display(struct Day *cal) {
    int i;
    printf("\nWeekly Activity Report:\n\n");
    for (i = 0; i < 7; i++) {
        printf("Day %d: %s\n", i + 1, cal[i].day);
        printf("Date: %d\n", cal[i].date);
        printf("Activity: %s\n\n", cal[i].activity);
    }
}

int main() {
    int i;
    struct Day *calendar;

    calendar = create();
    read(calendar);
    display(calendar);

    for (i = 0; i < 7; i++) {
        free(calendar[i].day);
        free(calendar[i].activity);
    }
    free(calendar);

    return 0;
}
