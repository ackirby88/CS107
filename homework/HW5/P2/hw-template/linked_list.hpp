#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

/* system header files */
#include <iostream>

/* namespace */
using namespace std;

/* ========================== */
/* Templated Class Definition */
/* ========================== */
template <class T>
class LinkedList {
  private:
      T data;
      LinkedList *next;

  public:
    /* Constructor */
    LinkedList(T data, LinkedList *next){
        //TODO: assign data
        //TODO: assign next
    }

    /* getters */
    T getData(){//TODO}
    LinkedList* getNext(){//TODO}

    /* setters */
    void setData(T data){//TODO}
    void setNext(LinkedList *next){//TODO}

    /* member functions */
    void prepend(LinkedList **head_ref, T new_data);
    void append(LinkedList **head_ref, T new_data);
    T summation();
    T minimum();
    template <typename FUNC> LinkedList* forEach(FUNC f);
    template <typename FUNC> LinkedList* reduceRight(FUNC f);
    void printList();
};


/* -------------------------------------------------------------------------- */
/* Class LinkedList<T> Member Function Implementations:                       */
/* NOTE: Putting implementation inside header file for templated classes.     */
/*      See why: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl */
/* -------------------------------------------------------------------------- */

/* =============================================== */
/* LinkedList<T>::prepend                          */
/*    Inserts a new node on the front of the list. */
/* =============================================== */
template <class T>
void LinkedList<T>::prepend(LinkedList **head_ref, T new_data){
    /* 1. allocate node */
    //TODO

    /* 2. move the head to point to the new node */
    //TODO
}

/* ============================================= */
/* LinkedList<T>::append                         */
/*    Inserts a new node at the end of the list. */
/* ============================================= */
template <class T>
void LinkedList<T>::append(LinkedList **head_ref, T new_data){
    /* 1. allocate node */
    //TODO

    /* 2. save head_ref for step 4 */
    //TODO

    /* 3. If the Linked List is empty, then make the new node as head */
    //TODO

    /* 4. Else traverse until the last node */
    //TODO

    /* 5. Change the next of last node */
    //TODO

    return;
}

/* ============================================= */
/* LinkedList<T>::summation                      */
/*    Computes summation of data in linked list. */
/* ============================================= */
template <class T>
T LinkedList<T>::summation(){
    return (next == nullptr) ? (data) : (data + next->summation());
}

/* =================================================== */
/* LinkedList<T>::minimum                              */
/*    Computes the minimum element in the linked list. */
/* =================================================== */
template <class T>
T LinkedList<T>::minimum(){
    if(next == nullptr) return data;
    return std::min(data,next->minimum());
}

/* =============================================== */
/* LinkedList<T>::forEach                          */
/*    Applies the function f to each data in list. */
/* =============================================== */
template <typename T>
template <typename FUNC>
LinkedList<T>* LinkedList<T>::forEach(FUNC f){
    //TODO
}

/* =============================================== */
/* LinkedList<T>::reduceRight                      */
/*    Applies the function f to each data in list. */
/* =============================================== */
template <typename T>
template <typename FUNC>
LinkedList<T>* LinkedList<T>::reduceRight(FUNC f){
    //TODO
}

/* ============================= */
/* LinkedList<T>::printList      */
/*    Displays each node's data. */
/* ============================= */
template <class T>
void LinkedList<T>::printList(){
    LinkedList *node = this;
    while (node != nullptr) {
        cout << node->getData() << " ";
        node = node->getNext();
    }
    cout << "\n";
}

#endif /* LINKED_LIST_HPP */ 
