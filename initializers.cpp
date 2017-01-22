
#include <iostream>
#include <vector>
#include <initializer_list>

void print(const int *c) {
    while (c && *c) {
        printf("%d", *c);
        c++;
    }
    printf("\n");
}

int main() 
{
    // C++ 03 initializer list
    int arr[4] = { 1,2,3,4 };
    
    print(&arr[0]);

    

    return EXIT_SUCCESS;
}

class MyInitializerList {
    std::vector<int> vec;
    public:
    MyInitializerList(const std::initializer_list<int>& v) {
        for (std::initializer_list<int>::iterator it = v.begin(); it!=v.end(); ++it) {
            vec.push_back(*it);
        }
    }
    void vector_new_feature() {
        // old way
        std::vector<int> a1;
        a1.push_back(1);
        a1.push_back(2);
        // new way
        std::vector<int> a2 = { 1, 2 };
    }
};

