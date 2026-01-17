#include <stdio.h>

char STR[100], PAT[50], REP[50], ANS[200];

void read() {
    printf("Enter the MAIN string:\n");
    gets(STR);

    printf("Enter the PATTERN string:\n");
    gets(PAT);

    printf("Enter the REPLACE string:\n");
    gets(REP);
}

void match() {
    int i = 0, j = 0, k, found = 0;

    while (STR[i] != '\0') {
        k = 0;

        while (STR[i + k] == PAT[k] && PAT[k] != '\0') {
            k++;
        }

        if (PAT[k] == '\0') {   // Full pattern matched
            found = 1;
            for (int m = 0; REP[m] != '\0'; m++) {
                ANS[j++] = REP[m];
            }
            i = i + k;
        } else {
            ANS[j++] = STR[i++];
        }
    }

    ANS[j] = '\0';

    if (found)
        printf("The RESULTANT string is: %s\n", ANS);
    else
        printf("Pattern not found!!!\n");
}

int main() {
    read();
    match();
    return 0;
}
