#ifndef __LLIST_HH__
#define __LLIST_HH__


template<class T>
struct Node {
    T element; 
    Node* next; 
    Node(const T& _element, Node* _next = nullptr): element(_element), next(_next) {};

};

template<class T>
class LList{
    private:

    Node<T>* start; 
    Node<T>* end; 
    size_t size; 
    void copyList(const LList<T>&);
    void destroyList();

    public:
    LList();
    LList(const LList&);
    ~LList();
    LList& operator=(const LList&);
    void print() const;
    void toEnd(const T&);
    void toStart(const T&);

    
    void reverse();
    size_t getSize() const; //method for getting the size
    Node<T>* atStart() const; //method that returns the 1st element
    Node<T>* atEnd() const; //method that returns the last element
    Node<T>* at(const size_t& at) const; //method that returns an element at a given position
};




#endif