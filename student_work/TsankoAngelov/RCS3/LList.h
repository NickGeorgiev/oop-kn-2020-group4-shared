#ifndef __LLIST_HH__
#define __LLIST_HH__
template<class T>
struct ListNode
{
    T element;
    ListNode* next;
    ListNode(const T& _element, ListNode* _next = nullptr)
    {
        element = _element;
        next = _next;
    } 
};

template<class T>
class LList
{
    ListNode<T>* start;
    ListNode<T>* end;
    int size;
    void copy(const LList<T>&);
    void destroy();
    public:
    LList();
    LList(const LList&);
    LList& operator=(const LList&);
    ~LList();
    void print() const;
    void toEnd(const T&);
    void toStart(const T&);
    void Insert(const int&, const T&);
    void reverse();
    bool equals(const LList&, const LList&);
};
#endif