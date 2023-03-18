#pragma once
#include <vector>

int GCD(long a, long b) {
    if (a == 0) {
        return 1;
    }
    // a > b
    if (b > a) {
        std::swap(a, b);
    }

    long balance = -1;
    while (balance != 0) {
        balance = a % b;
        a = b;
        b = balance;
    }
    return a;
}

int MinDiv(int num) {

    for (int d = 2; d * d <= num; ++d) {
        if (num % d == 0) {
            return d;
        }
    }
    return num;
}