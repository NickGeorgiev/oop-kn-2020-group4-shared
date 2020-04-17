#ifndef __LLIST_HH__
#define __LLIST_HH__

template<class T>
struct Node {
    T elem;
    Node* next;
    Node(const T& _elem, Node* _next = nullptr): elem{_elem}, next{_next} {}
};

template<class T>
void forward(Node<T>*&);

template<class T>
class LList {
    Node<T>* start;
    Node<T>* end;
    size_t size;

    void destroy();
    void copy(const LList&);
    Node<T>* nodeAt(const size_t&);
    
    public:

    LList(): start{nullptr}, end{nullptr}, size{0} {}
    ~LList();
    LList(const LList&);
    LList& operator=(const LList&);


    void toEnd(const T&);
    void toStart(const T&);
    void insertBefore(const T&, const size_t&);
    void removeAt(const size_t&);
    T& elemAt(const size_t&);
    size_t getSize() const;

    void reverse();
};

#endif
