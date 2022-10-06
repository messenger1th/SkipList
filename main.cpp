#include <iostream>
#include "SkipList.h"
#include <climits>
#include <cassert>
#include <unordered_map>
#include <chrono>

using namespace std;

bool test1(size_t list_height = 10, int element_count = 100000) {
    SkipList<int, int> list(list_height);
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
        assert(list.size() == i + 1);
    }
    for (int i = 0; i < element_count; ++i) {
        list.erase(i);
        assert(list.size() == element_count - i - 1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Pass Test1 : single element insert and erase consequently, elapsed :" << elapsed.count() << endl;
    return true;
}

bool test2(size_t list_height = 30, int element_count = 10000) {
    SkipList<int, int> list(list_height);
    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
        list.erase(i);
        assert(list.size() == 0);
    }
    cout << "Pass Test2 : single value insert & erase" << endl;
    return true;
}

bool test3(size_t list_height = 30, int element_count = 10000) {
    SkipList<int, int> list(list_height);
    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
        list.insert(i, i);
        list.erase(i);
        assert(list.size() == (i + 1));
    }
    cout << "Pass Test3 : two element insert &  erase one of them" << endl;
    return true;
}


bool test4(size_t list_height = 30, int element_count = 10000) {
    SkipList<int, int> list(list_height);
    for (int i = 0; i < element_count; ++i) {
        list.erase(i);
        list.insert(i, i);
        list.insert(i, i);
        assert(list.size() == 2 * (i + 1));
    }
    cout << "Pass Test4 : erase element non in list but insert it twice" << endl;
    return true;
}
bool test5(size_t list_height = 30, int element_count = 10000) {
    SkipList<int, int> list(list_height);
    unordered_map<int, int> frequency;
    int element_total_frequency = 0;
    for (int i = 0; i < element_count; ++i) {
        int insert_random_value = rand() % element_count;
        list.insert(insert_random_value, insert_random_value);
        ++frequency[insert_random_value];
        ++element_total_frequency;
        int erase_random_value = rand() % INT_MAX;
        list.erase(erase_random_value);
        if (frequency[erase_random_value]) {
            --frequency[erase_random_value];
            --element_total_frequency;
        }
        assert(list.size() == element_total_frequency);
    }
    cout << "Pass Test5 : random insert & random erase" << endl;
    return true;
}

bool test_erase_all(size_t list_height = 15, size_t element_count = 10000) {
    SkipList<int, int> list(list_height);
    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
    }
    for (int i = 0; i < element_count; ++i) {
        list.erase_all(i);
    }
    cout << "Pass Test erase_all()" << endl;
    return true;
}

bool test_erase_range(size_t list_height = 15, size_t element_count = 10000) {
    int lower = 0, upper = element_count;
    SkipList<int, int> list(list_height);

    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
    }
    list.erase_range(lower, element_count / 2);
    assert(list.size() == element_count / 2);
    list.erase_range(lower, upper);
    assert(list.size() == 0);
    cout << "Pass Test erase_range()" << endl;
    return true;
}

bool do_test() {
    srand(time(NULL));
    /* test for insert & erase*/
    test1();
    test2();
    test3();
    test4();
    test5();

    /* test for erase_all() & erase_range() */
    test_erase_all();
    test_erase_range();
    return true;
}


int main() {
    do_test();
}
