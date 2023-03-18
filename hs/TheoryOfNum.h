#pragma once
#include <vector>

int GCD(long a, long b) {
    while (b) {
        long temp = a;
        a = b;
        b = temp % b;
    }
    return abs(a);
}

int Nod(double a, double b) {
    double res = a / GCD(a, b) * b;
    return res;
}

int FastPow(long long a, long long n) {
    if (n == 0) {
        return a;
    }
    else if (n == 1) {
        return a;
    }
    else if (n == 2) {
        return a * a;
    }
    else if (n % 2 == 1) {
        return  a* FastPow(a, n - 1);
    }
    else {
        return FastPow(a * a, n / 2);
    }
}
int MinDiv(int num) {

    for (int d = 2; d * d <= num; ++d) {
        if (num % d == 0) {
            return d;
        }
    }
    return num;
}