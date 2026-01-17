#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumOfNaturalNumbers(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sumOfNaturalNumbers(n - 1);
}

int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

void printFibonacciSeries(int n) {
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    printf("Recursion Examples Demo\n");
    printf("======================\n\n");
    
    int n = 5;
    printf("Factorial of %d: %d\n", n, factorial(n));
    
    printf("Fibonacci of %d: %d\n", n, fibonacci(n));
    
    printFibonacciSeries(8);
    
    printf("Sum of first %d natural numbers: %d\n", n, sumOfNaturalNumbers(n));
    
    printf("2 raised to power 5: %d\n", power(2, 5));
    
    printf("GCD of 48 and 18: %d\n", gcd(48, 18));
    
    return 0;
}
