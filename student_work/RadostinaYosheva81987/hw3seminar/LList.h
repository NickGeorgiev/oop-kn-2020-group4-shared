#ifndef _LLIST_H
#define _LLIST_H

struct Node{
	int data;
	Node* next;
};

class LList{
    Node* head;
	Node* end;
	size_t size;

  public:
	void copyList(const LList&);
	void deleteList();
	int getHeadNodeData() const;
	int getEndNodeData() const;
    LList();
	LList(const LList&);
	~LList();
	LList& operator=(const LList&);
	void addNewEnd(int);
	void addNewHead(int);
	void print() const;
	void reverse();
	void create(int*, size_t);
};

#endif
