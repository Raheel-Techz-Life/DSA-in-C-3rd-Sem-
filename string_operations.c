#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringReverse(char* str) {
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int stringCompare(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void stringConcat(char* dest, char* src) {
    int i = stringLength(dest);
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int main() {
    printf("String Operations Demo\n");
    printf("=====================\n\n");
    
    char str1[100] = "Hello";
    char str2[100] = "World";
    char str3[100];
    
    printf("Original string: %s\n", str1);
    printf("String length: %d\n", stringLength(str1));
    
    stringCopy(str3, str1);
    printf("Copied string: %s\n", str3);
    
    stringReverse(str3);
    printf("Reversed string: %s\n", str3);
    
    int cmp = stringCompare(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal\n");
    } else if (cmp < 0) {
        printf("\"%s\" comes before \"%s\"\n", str1, str2);
    } else {
        printf("\"%s\" comes after \"%s\"\n", str1, str2);
    }
    
    stringConcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    
    return 0;
}
