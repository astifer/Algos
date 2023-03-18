#pragma once
#include <vector>


using vertex = int;

struct SegmenTree {
    std::vector<int> tree;
    int size = 1;

    SegmenTree(const std::vector<int>& arr) {
        while (size < static_cast<int> (arr.size())) {
            size *= 2;
        }
        tree.resize(2 * size - 1, 0);
        build(0, 0, size, arr);

    }

    int get(int qleft, int qright) {
        return get(0, 0, size, qleft, qright);
    }

private:
    void build(vertex v, int left, int right, const std::vector<int>& arr) {
        if (left + 1 == right) {
            tree[v] = left < arr.size() ? arr[left] : 0;
        }
        else {
            int mid = (left + right) / 2;
            build(2 * v + 1, left, mid, arr);
            build(2 * v + 2, mid, right, arr);
            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        }
    }

    int get(vertex v, int left, int right, int qleft, int qright) {
        if (qleft <= left && right <= qright) {
            return tree[v];
        }
        else if (qright <= left || right <= qleft) {
            return 0;
        }
        else {
            int mid = (left + right) / 2;
            return get(2 * v + 1, left, mid, qleft, qright) +
                get(2 * v + 2, mid, right, qleft, qright);
        }
    }

};