#pragma once
#include <vector>
#include <tuple>

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

void Degree() {
    long double a;
    long long n;
    ;
    do {
        std::cin >> a;
        std::cin >> n;
        long long res = FastPow(a, abs(n));
        if (n < 0) {
            res = 1 / res;
        }
        std::cout << res;
        std::cout << std::endl;
    } while (true);
}

std::tuple<int, int, int> extended_gcd(int a, int b)
{
    if (a == 0) {
        return std::make_tuple(b, 0, 1);
    }

    int gcd, x, y;

    // распаковываем возвращаемый функцией кортеж в переменные
    std::tie(gcd, x, y) = extended_gcd(b % a, a);

    return std::make_tuple(gcd, (-(b / a) * x + y), x);
}

void Deofant() {}

void solF() {
    std::vector<int> R;

    int n;
    std::cin >> n;
    int M = 1;

    for (int i = 0; i < n; ++i) {
        int req;
        std::cin >> req;
        R.push_back(req);
        if (req > M) {
            M = req;
        }
    }

    std::vector<bool> ansTF = Eratosphen(M, false);
    std::vector<int> ans;
    for (int i = 2; i < ansTF.size(); ++i) {
        if (ansTF[i] == false) {

            ans.push_back(i);
            if (ans.size() > M) {
                break;
            }
        }
    }
    for (int el : R) {
        std::cout << ans[el - 1] << " ";
    }
}

int comp(long long a) {

    for (long long d = 2; d * d <= a; ++d) {

        if (a % d == 0) {
            return d;
        }
    };
    if (a > 1) {
        return a;
    }

}
