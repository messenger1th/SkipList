#include <iostream>
#include "SkipList.h"
#include <climits>
#include <cassert>
#include <unordered_map>

using namespace std;

bool test1(size_t tree_height = 30, int element_count = 10000) {
    SkipList<int, int> list(tree_height);
    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
        assert(list.size() == i + 1);
    }

    for (int i = 0; i < element_count; ++i) {
        list.erase(i);
        assert(list.size() == element_count - i - 1);
    }
    cout << "Pass Test1 : single element insert and erase consequently" << endl;
    return true;
}

bool test2(size_t tree_height = 30, int element_count = 10000) {
    SkipList<int, int> list(30);
    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
        list.erase(i);
        assert(list.size() == 0);
    }
    cout << "Pass Test2 : single value insert & erase" << endl;
    return true;
}

bool test3(size_t tree_height = 30, int element_count = 10000) {
    SkipList<int, int> list(30);
    for (int i = 0; i < element_count; ++i) {
        list.insert(i, i);
        list.insert(i, i);
        list.erase(i);
        assert(list.size() == (i + 1));
    }
    cout << "Pass Test3 : two element insert &  erase one of them" << endl;
    return true;
}


bool test4(size_t tree_height = 30, int element_count = 10000) {
    SkipList<int, int> list(30);
    for (int i = 0; i < element_count; ++i) {
        list.erase(i);
        list.insert(i, i);
        list.insert(i, i);
        assert(list.size() == 2 * (i + 1));
    }
    cout << "Pass Test4 : erase element non in list but insert it twice" << endl;
    return true;
}
bool test5(size_t tree_height = 30, int element_count = 10000) {
    SkipList<int, int> list(30);
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


bool do_test() {
    /* test for insert & erase*/
    test1();
    test2();
    test3();
    test4();
    test5();

    //TODO: test for erase_all() & erase_range();
    return true;
}


int main() {
    do_test();
}
