#pragma once
#include <vector>

std::vector<bool> Eratosphen(int count, bool var) {
    long long edge = 1299719;
    std::vector<bool> v(edge, false);
    int t_cnt = 0;

    if (var) {
        for (int i = 2; i < v.size(); ++i) {
            if (v[i] == 0) {
                t_cnt++;
                for (int j = i * 2; j < v.size(); j += i) {
                    v[j] = 1;
                }
            }
        }
    }
    else {
       
        for (int i = 2; i * 2 <= v.size(); ++i) {
            if (v[i] == false) {
                t_cnt++;
                for (int j = i * 2; j < v.size(); j += i) {
                    v[j] = true;
                }
            }
            if (t_cnt == count) {
                break;
            }
        }
        
    }
    
    return v;
}