#include <iostream>
#include <vector>
#include <queue>

void Radix() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::cin >> n;
    std::vector<int32_t> v(n);
    for (size_t i = 0; i < v.size(); ++i) {
        std::cin >> v[i];
    }
   
    std::vector<std::queue<int32_t> > q(256);
    for (int k = 0; k < 4; ++k) {
        for (size_t i = 0; i < v.size(); ++i) {
            int k_byte = (v[i] >> (8 * k)) & 255;
            q[k_byte].push(v[i]);
        }
        size_t i = 0;
        for (size_t j = 0; j < 256; ++j) {
            while (!q[j].empty()) {
                v[i] = q[j].front();
                q[j].pop();
                ++i;
            }
        }
    }

    size_t index_neg = v.size();

    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] < 0) {
            index_neg = i;
            break;
        }
    }

    //reverse(v, 0, index_neg);
    //reverse(v, index_neg, v.size());
    //reverse(v, 0, v.size());


    for (const int& x : v) {
        std::cout << x << ' ';
    }
}