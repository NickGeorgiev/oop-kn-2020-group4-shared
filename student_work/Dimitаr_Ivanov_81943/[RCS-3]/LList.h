#ifndef __LLIST_HH__
#define __LLIST_HH__

template <class T>
struct Node { // predstavqne na elementi
    T elem;
    Node* next;
    Node(const T& _elem, Node* _next = nullptr): elem{_elem}, next{_next}{} // ako stignem do kraq na lista
};

template<class T>
class LList{
    Node<T>* start;
    Node<T>* end;
    size_t size;
    void copyList(const LList<T>&);
    void destroyList();
    public:
    LList();
    LList(const LList&);
    ~LList();
    LList& operator= (const LList&);
    void print() const;
    void toEnd(const T&);
    void toStart(const T&);
    Node<T>* getStart () const;
    void reverse();
    // void addBefore(const T& element, const T& new_element);
    // void addAfter(const Node<T>*& element, const T& new_element);
    // void addAfter(const T& element, const T& new_element);
    // void addBefore(const Node<T>*& element, const T& new_element);
    void insertElementAt(const size_t&, const T&);
};

#endif

/*

linked list
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

1,2,3
NodeCurr:nodeInfo
1:[elem:1 ; next: 2] -> 2:[elem:2 ; next: 3] -> 3:[elem:3 ; next: nullptr] 1 -> 2 -> 3

####1##############################
########################3##########
###############6###################
##################5################
##############2####################
#########################4#########
##############7####################



*/