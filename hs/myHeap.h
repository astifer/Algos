#pragma once
#include <vector>

class myHeap {
private:
    std::vector<int> heap;

    void siftUp() {
        if (heap.size() == 1) {
            return;
        }
        int kid = heap.size() - 1;
        int par = (kid - 1) / 2;

        while (heap[kid] > heap[par]) {
            int temp = heap[par];
            heap[par] = heap[kid];
            heap[kid] = temp;
            kid = par;
            par = (kid - 1) / 2;
        }
    }

    void siftDown() {

        int last = heap[heap.size() - 1];
        heap.pop_back();
        if (heap.size() == 0) {
            return;
        }
        heap[0] = last;

        int par = 0;
        if (heap.size() == 2) {
            if (heap[1] > heap[par]) {
                int temp = heap[par];
                heap[par] = heap[1];
                heap[1] = temp;
            }
            return;
        }
        
        for ( ; par * 2 + 2 <= heap.size(); ) {
            int l_ind = par * 2 + 1;
            int r_ind = par * 2 + 2;

            if (r_ind == heap.size() && heap[par] < heap[l_ind]) { // left is epsent
                int temp = heap[par];
                heap[par] = heap[l_ind];
                heap[l_ind] = temp;
                return;
            }

            int m_ind = (heap[l_ind] > heap[r_ind]) ? l_ind : r_ind;

            if (heap[m_ind] > heap[par]) {
                int temp = heap[par];
                heap[par] = heap[m_ind];
                heap[m_ind] = temp;
            }
            par = m_ind;
        }

    }

public:

    myHeap() = default;
    size_t size() {
        return heap.size();
    }

    void Insert(int val) {
        heap.push_back(val);
        siftUp();
        
    }

    int getMax() {
        return heap[0];
    }

    void deleteMax() {
        siftDown();
    }
};

class myHeapmin {
private:
    std::vector<int> heap;

    void siftUp() {
        if (heap.size() == 1) {
            return;
        }
        int kid = heap.size() - 1;
        int par = (kid - 1) / 2;

        while (heap[kid] < heap[par]) {
            int temp = heap[par];
            heap[par] = heap[kid];
            heap[kid] = temp;

            kid = par;
            par = (kid - 1) / 2;
        }
    }

    void siftDown() {
        int par = 0;
        int l = par * 2 + 1;
        int r = par * 2 + 2;
        if (heap.size() == 2) {
            if (heap[0] > heap[1]) {
                int temp = heap[0];
                heap[0] = heap[1];
                heap[1] = temp;

            }
            return;
        }
        while (l < heap.size()) {
     
            int m_ind = (heap[r] < heap[l]) ? r : l;
            if (heap[par] > heap[m_ind]) {
                int temp = heap[par];
                heap[par] = heap[m_ind];
                heap[m_ind] = temp;
            }
           
            par = m_ind;
            l = par * 2 + 1;
            r = par * 2 + 2;
        }
        if (heap.size()-1 % 2 == 1 && heap.back() < heap[heap.size() / 2]) {
            int temp = heap.back();
            heap[heap.size()-1] = heap[heap.size() / 2];
            heap[heap.size() / 2] = temp;
        }
    }
    void delMin() {
        if (heap.size() == 0) {
            return;
        }
        else if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        else {
            int last = heap.back();
            heap.pop_back();
            heap[0] = last;
        }
        

    }
public:

    myHeapmin() = default;
    int size() {
        return heap.size();
    }

    void Insert(int val) {
        heap.push_back(val);
        siftUp();

    }

    int getMin() {
        return heap[0];
    }

    void deleteMin() {
        delMin();
        siftDown();
    }
};

void Sol() {
    std::map <std::string, int> mapping;

    mapping["ADD"] = 0;
    mapping["EXTRACT"] = 1;
    mapping["CLEAR"] = 2;

    myHeapmin m;

    std::string line;
    while (std::cin >> line)
    {
        if (line.empty()) {
            break;
        }
        switch (mapping[line])
        {
        case 0:
            int a;
            std::cin >> a;
            m.Insert(a);
            break;

        case 1:
            while (m.size() != 0) {
                m.deleteMin();
            }

            break;
        case 2:
            if (m.size() > 0) {
                std::cout << m.getMin() << std::endl;;
                m.deleteMin();
            }
            else {
                std::cout << "CANNOT" << std::endl;
            }
            break;
        default:
            break;
        }
    }
}