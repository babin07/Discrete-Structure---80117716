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

// Function to solve ax ≡ b (mod n)
void solveLinearCongruence(int a, int b, int n) {
    int x, y;
    int gcd = extendedGcd(a, n, &x, &y);

    if (b % gcd != 0) {
        printf("No solution exists.\n");
        return;
    }

    // Calculate the solution
    int x0 = (x * (b / gcd)) % n;
    if (x0 < 0) {
        x0 += n;
    }

    // Print all solutions
    printf("One solution is x ≡ %d (mod %d)\n", x0, n);

    for (int i = 0; i < gcd; i++) {
        printf("x ≡ %d (mod %d)\n", (x0 + i * (n / gcd)) % n, n);
    }
}

int main() {
    int a, b, n;
    printf("Enter values for a, b, and n (for the equation ax ≡ b (mod n)): ");
    scanf("%d %d %d", &a, &b, &n);

    solveLinearCongruence(a, b, n);
    
    return 0;
}