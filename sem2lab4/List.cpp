#include <iostream>
#include <string.h>
#include "Circle.cpp"

using namespace std;

class Node {
	Circle data;
	Node* pNext;
	Node* pPrev;

	Node() :pNext(nullptr), pPrev(nullptr) {}

	Node(Node* prev, const Circle& ndata) :data(ndata) {
		pNext = prev->pNext;
		prev->pNext = this;
		pPrev = prev;
		pNext->pPrev = this;
	}
	~Node() {
		if (pPrev != nullptr) {
			pPrev->pNext = pNext;
		}
		if (pNext != nullptr) {
			pNext->pPrev = pPrev;
		}
		pNext = nullptr;
		pPrev = nullptr;
	}
	friend class List;
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream& in, List& l);
};

class List {
	Node Head;
	Node Tail;
	int size;
public:
	List() {
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
		size = 0;
	}

	void addToHead(const Circle& data) {
		new Node(&Head, data);
		size++;
	}

	void addToTail(const Circle& data) {
		new Node(Tail.pPrev, data);
		size++;
	}

	bool removeFirst(const Circle& data) {
		Node* ptr = Head.pNext;
		for (int i = 0; i < size; i++) {
			if (ptr->data == data) {
				delete ptr;
				size--;
				return true;
			}
			ptr = ptr->pNext;
		}
		return false;
	}

	int removeAllCount(const Circle& data) {
		int removes = 0;
		Node* ptr = Head.pNext;
		for (int i = 0; i < size; i++) {
			if (ptr->data == data) {
				Node* tmp = ptr->pNext;
				delete ptr;
				removes++;
				ptr = tmp;
			}
			else
				ptr = ptr->pNext;
		}
		size -= removes;
		return removes;
	}

	void clear() {
		Node* ptr = Head.pNext;
		for (int i = 0; i < size; i++) {
			Node* tmp = ptr->pNext;
			delete ptr;
			ptr = tmp;
		}
		size = 0;
	}

	void sort() {
		if (size > 1) {
			Node* current = nullptr;
			Node* nextcurrent = nullptr;
			for (current = Head.pNext; current->pNext != &Tail; current = current->pNext) {
				for (nextcurrent = current->pNext; nextcurrent != &Tail; nextcurrent = nextcurrent->pNext) {
					if (current->data.calculateArea() < nextcurrent->data.calculateArea()) {
						Circle temp = current->data;
						current->data = nextcurrent->data;
						nextcurrent->data = temp;
					}
				}
			}
		}
	}
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream& in, List& l);
};