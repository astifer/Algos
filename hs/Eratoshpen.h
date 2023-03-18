#pragma once
#include <vector>

std::vector<int> Eratosphen(int a) {
    std::vector<int> v(a + 1);


    for (int i = 2; 2 * i <= (a + 1) ; ++i) {
        if (v[i] == 0) {
            for (int j = i * 2; j < v.size(); j += i) {
                v[j] += 1;
            }
        }
    }

    return v;
}