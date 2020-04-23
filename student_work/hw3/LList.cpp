#include<iostream>
#include<cassert>

template<class T>
struct Node{
    T elem;
    Node* next;
    Node(const T& _elem, Node* _next = nullptr): elem{_elem}, next{_next}{}
};

template<class T>
class LList{
    Node<T>* start;
    Node<T>* end;
    size_t size;
    //void copyList(const LList<T>&);
    //void destroyList();

//template<class T>
void copyList(const LList<T>& other) {
    size = 0;
    start = end = nullptr;
    Node<T>* other_current = other.start;
    while(other_current){
        toEnd(other_current->elem);
        other_current = other_current->next;
    }
}

//template<class T>
void destroyList() {    
    while(start){
        Node<T>* previous = start;
        start = start->next;
        delete previous;
    }    
}
public:
//template<class T>
LList():start{nullptr}, end{nullptr}, size{0} {}

//template<class T>
LList(const LList<T>& other) {
    copyList(other);
}

//template<class T>
~LList(){
    destroyList(); 
}

//template<class T>
LList<T>& operator=(const LList& other) {
    if(this != &other) {
        destroyList();
        copyList();
    }
    LList tmp(other);
    swapList(tmp);
    return *this;
}

//template<class T>
void print() const {
    Node<T>* current = start;
    while(current) {
        std::cout << current->elem << std::endl;
        current = current->next;
    }
}

//template<class T>
void toEnd(const T& element) {
    if(!start){
        start = end = new Node<T>(element);
    } else {
        end->next = new Node<T>(element);
        end = end->next;
    }
    size++;
}

//template<class T>
void toStart(const T& element) {
    size++;
    start = new Node<T>(element, start);
    if(!start->next) {
        end = start;
    }
}
//template<class T>
void insertElementAt(const size_t& index, const T& element){
    assert(index < size);
    size_t curr_index = 0;
    Node<T>* current = start;
    while(curr_index != index-1 && current) {
        curr_index++;
        current = current->next;
    }
    current->next = new Node<T>(element, current->next);
}
// template<class T>
void reverse(){
    Node<T>* current = start; 
    Node<T>* previous = nullptr, *next = nullptr;
    Node<T>* newend = start;
    while (current != nullptr) { 
        next = current->next; 
        current->next = previous; 
        previous = current; 
        current = next; 
    } 
    start = previous;
    end = newend;
} 




/*
    LList();
    LList(const LList&);
    ~LList();
    LList& operator=(const LList&);
    void print() const;
    void toEnd(const T&);
    void toStart(const T&);
    void insertElementAt(const size_t&,const T&);
*/
    //void reverse();
};
