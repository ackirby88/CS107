/**
 * @file    demo.cpp
 * @brief   Demonstrates the used of the
 *          templated linked list class.
 */

// system header files
#include <bits/stdc++.h>

// header files
#include "linked_list.hpp"

// namespaces
using namespace std;

/* ===================================================== */
/* input function for forEach */
/* -------------------------- */
template<typename T>
T add(T a){
    return a + a;
}
/* ===================================================== */

int main(){
    LinkedList<std::string> *list = nullptr;
    list->prepend(&list, "a");
    list->prepend(&list, "rgr");
    list->prepend(&list, "asdf");
    list->append(&list, "3");
    list->append(&list, "5");

    cout << "List: "; list->printList();

    std::string sum = list->summation();
    std::string min = list->minimum();
    cout << "Sum: " << sum << "\n";
    cout << "Min: " << min << "\n";

    /* pass add function to for_each */
    list->forEach(add<std::string>);
    cout << "ForEach (add): "; list->printList();
    return 0;
}

