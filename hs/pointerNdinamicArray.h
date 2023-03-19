
class ArrayD {
private:
    int _size;
    int* _data;

public:

    ArrayD() {
        _size = 0;
        _data = new int[0];

    }

    ArrayD(int size) {
        _size = size;
        _data = new int[size];
    }

    ArrayD(int size, int args[]) {
        _size = size;
        _data = new int[size];

        for (int i = 0; i < size; ++i) {
            _data[i] = args[i];
        }
    }

    ArrayD(const ArrayD& other) {

        _data = new int[other._size];
        _size = other._size;

        for (int i = 0; i < other._size; ++i)
        {
            _data[i] = other._data[i];
        }

    }

    int Size() {
        return _size;
    }
    ~ArrayD() {
        delete[] _data;
    }


};


struct node {
    int val;
    node* next;
    node(int _val) : val(_val), next(nullptr) {};
};


class ArrayPointer {

    node* start;
    int size;

    ArrayPointer() : start(nullptr), size(0) {}

    void push(int val) {

        node* elem = new node(val);

        if (size > 0) {
            elem->next = start;

        }
        start = elem;
        ++size;
    }

    void mid_push(int val) {

        if (size > 0) {

            node* elem = new node(val);
            int index = size / 2 + (size % 2);

            node* link = start;
            node* next = link->next;

            for (int tmp_i = 1; tmp_i != index; ++tmp_i) {
                link = next;
                next = link->next;

            }
            link->next = elem;
            elem->next = next;
            ++size;

        }
        else {
            push(val);
        }

    }

    void push_back(int val) {

        node* elem = new node(val);
        int index = size;

        if (size == 0) {
            push(val);
            return;

        }

        node* link = start;
        node* next;

        if (size == 1) {
            link->next = elem;
            elem->next = nullptr;
            ++size;
            return;
        }
        else {
            next = link->next;
        }

        for (int tmp_i = 2; tmp_i < index; ++tmp_i) {
            link = next;
            next = link->next;
        }

        next->next = elem;
        elem->next = nullptr;

        ++size;
    }

    int pop() {
        if (size == 0) {
            return 0;
            // exception
            // ...


        }
        else {
            node* tmp = start; //delete in main code
            start = start->next;
            --size;
            return tmp->val;
        }
    }

    int front() {
        if (size == 0) {
            return ;
            // exception
            // ...
            // ...
        }
        else {
            return start->val;
        }
    }

    ~ArrayPointer()
    {
        while (size > 0) {
            int temp = pop();
        }
    }
};
