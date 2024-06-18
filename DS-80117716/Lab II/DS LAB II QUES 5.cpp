#include <stdio.h>

// Function to return the GCD of a and b and to find x and y such that ax + by = gcd(a, b)
int extendedGcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find the modular inverse of a modulo m
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGcd(a, m, &x, &y);
    if (gcd != 1) {
        return -1;  // Inverse doesn't exist
    }
    return (x % m + m) % m;
}

// Function to find the smallest x such that:
// x ≡ num[0] (mod rem[0])
// x ≡ num[1] (mod rem[1])
// ...
// x ≡ num[k-1] (mod rem[k-1])
int findMinX(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num) / sizeof(num[0]);

    printf("The smallest x such that x ≡ %d (mod %d), x ≡ %d (mod %d), and x ≡ %d (mod %d) is %d\n",
           rem[0], num[0], rem[1], num[1], rem[2], num[2], findMinX(num, rem, k));

    return 0;
}