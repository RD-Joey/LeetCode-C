#include<limits.h>
#include<stdio.h>
double myPower(double x, unsigned int n) {
    if (n == 1) return x;
    double result = myPower(x, n >> 1);
    return n & 1 ? x * result * result : result * result;
}

double myPow(double x, int n) {
    if (n == 0 || x == 1) return 1;
    if (x == 0) return 0;
    //if (n == INT_MIN) return 1 / (x * myPower(x, INT_MAX));
    //if (n < 0) return 1 / myPower(x, -n);
    //return myPower(x, n);

    long long N = n;
    double result = 1, multiple = N < 0 ? 1 / x : x;
    if (N < 0) N = -N;
    for (; N; N >>= 1, multiple *= multiple)
        if (N & 1) result *= multiple;
    return result;
}