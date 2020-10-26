## Problem 2: Linked List
A singly linked list can be implemented by nodes. Each node has 2 properties: a head and a tail. The head is the element held by the first node in the list. The tail is the rest of the list, which is a reference to the next node.

The code provided in [linked_list.hpp](https://github.com/ackirby88/CS107/blob/master/homework/HW5/P2/hw-template/linked_list.hpp) is a partially implemented singly linked list. It consists of one class: LinkedList is a node that holds an element. In this problem, you will finish the implementation of this class. To name a node LinkedList is a bit confusing, but as we will see, although the LinkedList is implemented as a node, it behaves as if it is a whole list.

Start by copying the template code [linked_list.hpp](https://github.com/ackirby88/CS107/blob/master/homework/HW5/P2/hw-template/linked_list.hpp).
For this exercise, you will implement all the sections with comments:  
```C++
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
```

### Part A [15 points]:
**Please implement the constructor, getter, and setter methods.**  
This functions save or return the private stored in the class: `T data; LinkedList *next`.  

**Please implement the `append` method in the LinkedList class.**  
It returns a LinkedList where a node holding the object val is appended.

**Hint**: It's recursive. We recursively invoke the append on the tail, the tail of the tail, and so on. While implementing, try to draw a schematic of what's going on step-by-step for each tail creation. This will give a clearer picture.

Contrast to the Python version, we are making this linked list mutable such that we keep track of the head of the list through reference. When we `prepend` and node, we update the `LinkedList` head pointer. To see a demonstration of the expected behavior, see [demo.cpp](https://github.com/ackirby88/CS107/blob/master/homework/HW5/P2/hw-template/demo.cpp). 

**Please implement the `prepend` method in the LinkedList class.**  
This method is similar to the `append` method but is more efficient since we do not need to traverse the list to update the `head` reference.

### Part B [5 points]:
We want to be able to conveniently apply a function to all elements in this list.  

**Please implement the `forEach` method in the LinkedList class.**  
The `forEach` method takes a function `FUNC f` as an argument, and returns a LinkedList (or `nullptr`) in which the element e in the list is mapped to fun(e). For example:  
```C++
/* header files */
#include "linked_list.hpp"

template<typename T>
T square(T a){
    return a*a;
}

int main(){
    LinkedList<int> *list = nullptr;
    list->prepend(&list, 5);
    list->prepend(&list, 2);
    list->prepend(&list, 3);
    list->append(&list, 1);
    list->append(&list, 7);

    LinkedList<int> *new_list = list->forEach(square<int>);
    cout << "Original List: "; list->printList();
    cout << "forEach  List: "; new_list->printList();

    return 0;
}
```
**Output:**
```C++
Original List: 3 2 5 1 7
forEach  List: 9 4 25 1 49
```

**Note:** In the above example, `forEach` is **not** modifying the values in the LinkedList `list`. It is returning a new LinkedList `new_list`.

### Part C [10 points]:
If we look at the logic of `summation` and `minimum`, we will notice that they are quite similar. Both are first reducing the tail of the list into an intermediate result and then combining the head with the intermediate result. The difference between summation and minimum lies in what this *combining* function is. For summation, two elements are combined by the function:  
```C++
int combine(int a, int b){
    return a+b;
}
```
(We don't really have this function in our code, but its logic is used in summation.)  

For `minimum`, two elements are combined by the hypothetical function:  
```C++
int combine(int a,int b){
    return (a < b) ? a:b;
}
```

**Please implement the `reduceRight` method in the LinkedList class.**
This method requires a function `FUNC f` as an argument. `reduceRight` will first reduce the tail of the list into an intermediate result by applying `f` to the tail nodes. Then, `f` should be applied to the head and the intermediate result to combine them.  

For Example:  
```C++
/* header files */
#include "linked_list.hpp"

template <typename T>
LinkedList<T>* smaller(LinkedList<T> *a, LinkedList<T> *b){
    return (a->getData() < b->getData()) ? a:b;
}

template<typename T>
T square(T a){
    return a*a;
}

int main(){
    LinkedList<int> *list = nullptr;
    list->prepend(&list, 5);
    list->prepend(&list, 2);
    list->prepend(&list, 3);
    list->append(&list, 1);
    list->append(&list, 7);

    LinkedList<int> *reduced  = list->reduceRight(smaller<int>);
    cout << "Original List: "; list->printList();
    cout << "Reduced  List: " << reduced->getData() << "\n";

    return 0;
}
```

**Output:**
```C++
Original List: 5 2 3 1 7
Reduced  List: 1
```

### Part D [10 points]:
For this problem, copy the following code [longest_sentence.cpp](https://github.com/ackirby88/CS107/blob/master/homework/HW5/P2/hw-template/longest_sentence.cpp):  
```C++
/* header files */
#include "longest_sentence.hpp"

LinkedList<std::string> *getListOfSentences(const char *filename){
    LinkedList<std::string> *list = nullptr;
    std::string line;

    std::ifstream ifs(filename);
    if (ifs.is_open() == false) {
        std::cerr << "Couldn't open file..." << std::endl;
        return nullptr;
    }

    while(std::getline(ifs,line)) {
        findAndReplaceAll(line,"...","|"); // avoid ellipsis issue
        findAndReplaceAll(line,".","|");
        findAndReplaceAll(line,"!","|");
        findAndReplaceAll(line,"?","|");
        findAndReplaceAll(line,"\" ","");

        std::istringstream p(line);
        while (std::getline(p, line, '|')) {
            list->append(&list, line);
        }
    }
    return list;
}

template <typename T>
LinkedList<T>* get_longest_sentence(LinkedList<T> *a, LinkedList<T> *b){
    //TODO: use countWords to test longest sentence

    //TODO: return "List" containing longest sentence
}

int main(void){
    LinkedList<std::string> *list_of_sentences = getListOfSentences("swansway-chapter1.txt");

    //TODO: Use reduceRight method -- pass in count_words function

    //TODO: Output longest sentence and length

    return 0;
}
```

Marcel Proust is known for writing long sentences. The `swansway-chapter1.txt` contains the first chapter of *Remembrance of Things Past*. The function `getListOfSentences` will preprocess this file and return a `LinkedList` of all sentences in this chapter.  

**Please implement `get_longest_sentence` and `main` which returns the number of words in the longest sentence.**  
You can assume that anything delimited by a space is a word (see `longest_sentence.hpp`).

**Note:** `getListOfSentences` reads text from swansway-chapter1.txt. You should have the text file in your HW5-final/ directory.
**Hint:** Use the `reduceRight` method that you implemented.

### Deliverables:
[x] `linked_list.hpp`  
[x] `longest_sentence.cpp`  
[x] `longest_sentence.hpp`  
[x] `Makefile`  
