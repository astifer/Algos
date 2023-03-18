#pragma once
#include <vector>

class myHeap {
private:
    std::vector<int> heap;

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:

    myHeap() = default;

    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int getMin() {
        return heap[0];
    }

    void deleteMin() {
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }
};

