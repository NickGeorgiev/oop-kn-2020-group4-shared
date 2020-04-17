#ifndef __LLIST__HH
#define __LLIST__HH

struct Node
{
    int data;
    Node* next;

    Node (const int& _data, Node* _next): data {_data}, next {_next} {}
};

class LList
{
    Node* start;
    Node* end;
    size_t size;

    void copyLList (const LList&);
    void destroyLList ();

    public:
    LList ();
    LList (const LList&);
    ~LList ();

    LList& operator = (const LList&);
    int& operator [] (const size_t&);
    const int& operator [] (const size_t&) const;

    Node* at(const size_t&) const;
    size_t getSize () const;

    void toStart (const int&);
    void toEnd (const int&);
    void insertAt (const size_t&, const int&);

    void deleteStart ();
    void deleteEnd ();
    void deleteAt (const size_t&);

    void reverseList ();

    void printLList () const;
};

#endif
