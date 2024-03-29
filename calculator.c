#include <stdio.h>
#include <math.h>

float add(int a, int b);
float sub(int a, int b);
double multi(int a, int b);
double div(int a, int b);
double power(int a, int b);
double root(int a, int b);

int main() {
    int a, b;
    char ch;
    double ans;

    printf("Enter operation (+, -, *, /, ^, r): \n");
    scanf(" %c", &ch);

    printf("Enter the required numbers: \n");
    scanf("%d%d", &a, &b);

    switch (ch) {
        case '+': ans = add(a, b); break;
        case '-': ans = sub(a, b); break;
        case '*': ans = multi(a, b); break;
        case '/': ans = div(a, b); break;
        case '^': ans = power(a, b); break;
        case 'r': ans = root(a, b); break;
        default: printf("Please enter proper instructions!!");
    }

    printf("%f\n", ans);
    return 0;
}

float add(int a, int b) {
    return (float)(a + b);
}

float sub(int a, int b) {
    return (float)(a - b);
}

double multi(int a, int b) {
    return (float)(a * b);
}

double div(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: Division by zero.\n");
        return 0.0;
    }
}

double power(int a, int b) {
    return pow(a, b);
}

double root(int a, int b) {
    return pow(a, 1.0 / b);
}