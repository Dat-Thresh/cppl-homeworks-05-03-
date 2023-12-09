#include <iostream>
#include <vector>
#include <algorithm>

class functor {
    int sum;
    int count;

public:
    functor() :sum{ 0 }, count{ 0 } {};
    void operator()(std::vector<int> vec) {
        for (auto &x : vec) {
            
            if (x % 3 == 0) {
                count++;
                sum += x;
            }
        }
    }
    int get_sum() {
        return sum;
    }
    int get_count() {
        return count;
    }
};

void print_v(int a) {
    std::cout << a << " ";
}

int main() {
    std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };
    functor func;
    func(vec);
    std::cout << "[IN]: ";
    std::for_each(vec.begin(), vec.end(), print_v);

    std::cout << "\n[OUT]: " << "get_sum() = " << func.get_sum() << std::endl;
    std::cout << "[OUT]: " << "get_count() = " << func.get_count() << std::endl;
    return 0;
}