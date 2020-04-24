#ifndef __LLIST_HH__
#define __LLIST_HH__

template<class T>
struct Node {
    T elem;
    Node* next;
    Node(const T& _elem, Node* _next = nullptr): elem{_elem}, next{_next}{}
};

template<class T>
class LList {
    Node<T>* start;
    Node<T>* end;
    size_t size;
    void copyList(const LList<T>&);
    void destroyList();
    Node<T>* at (size_t pos);
    public:
    LList();
    LList(const LList&);
    ~LList();
    LList& operator=(const LList&);
    Node<T>*& getStart ();
    void print() const;
    void toEnd(const T&);
    void toStart(const T&);
    void reverse ();
    void insertElementAt(const size_t&,const T&);
    T& operator[] (const size_t& i);
    T operator[] (const size_t& i) const;
};
#endif