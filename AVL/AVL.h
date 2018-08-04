#pragma once
#include <iostream>

#define ROW 10
#define COL 20

using namespace std;

template <typename T>
class Node {
private:
	T key;
	int height;
	Node<T>* left;
	Node<T>* right;

public:
	Node(T k) { key = k; left = right = 0; height = 1; }

public:
	int HEIGHT(Node<T>*);
	int BFACTOR(Node<T>*);
	void FIXHEIGHT(Node<T>*);
	Node<T>* ROTATERIGHT(Node<T>*);
	Node<T>* ROTATELEFT(Node<T>*);
	Node<T>* BALANCE(Node<T>*);
	Node<T>* INSERT(Node<T>*, T);
	Node<T>* FINDMIN(Node<T>*);
	Node<T>* REMOVE(Node<T>*, T);
	void PREORDER(const Node<T>*);
	void INORDER(const Node<T>*);
	void POSTORDER(const Node<T>*);
	void PRINT(const Node<T>* p, T (*arr)[COL], int& i, int level);
};


template <typename T>
int Node<T>::HEIGHT(Node* p) {
	return (p ? p->height : 0);
}

template <typename T>
int Node<T>::BFACTOR(Node* p) {
	return (HEIGHT(p->right) - HEIGHT(p->left));
}

template <typename T>
void Node<T>::FIXHEIGHT(Node* p) {
	int hl = HEIGHT(p->left);
	int hr = HEIGHT(p->right);

	p->height = ((hl > hr) ? hl : hr) + 1;
}

template <typename T>
Node<T>* Node<T>::ROTATERIGHT(Node<T>* p) {
	Node<T>* q = p->left;
	p->left = q->right;
	q->right = p;

	FIXHEIGHT(p);
	FIXHEIGHT(q);

	return q;
}

template <typename T>
Node<T>* Node<T>::ROTATELEFT(Node<T>* q) {
	Node<T>* p = q->right;
	q->right = p->left;
	p->left = q;

	FIXHEIGHT(q);
	FIXHEIGHT(p);

	return p;
}

template <typename T>
Node<T>* Node<T>::BALANCE(Node<T>* p) {
	FIXHEIGHT(p);

	if (BFACTOR(p) == 2)
	{
		if (BFACTOR(p->right) < 0)
			p->right = ROTATERIGHT(p->right);

		return ROTATELEFT(p);
	}

	if (BFACTOR(p) == -2)
	{
		if (BFACTOR(p->left) > 0)
			p->left = ROTATELEFT(p->left);

		return ROTATERIGHT(p);
	}

	return p;
}

template <typename T>
Node<T>* Node<T>::INSERT(Node<T>* p, T k) {
	if (!p) return new Node<T>(k);

	if (k < p->key)
		p->left = INSERT(p->left, k);

	else
		p->right = INSERT(p->right, k);

	return BALANCE(p);
}

template <typename T>
Node<T>* Node<T>::FINDMIN(Node<T>* p) {
	return (p->left ? FINDMIN(p->left) : p);
}

template <typename T>
Node<T>* Node<T>::REMOVE(Node<T>* p, T k) {
	if (!p) return 0;

	if (k < p->key)
		p->left = REMOVE(p->left, k);

	else if (k > p->key)
		p->right = REMOVE(p->right, k);

	else {
		Node<T>* q = p->left;
		Node<T>* r = p->right;

		if (!r) {
			delete p;
			return q;
		}

		p = r;
		Node<T>* min = FINDMIN(p);
		min->left = q;
	}

	return BALANCE(p);
}

template <typename T>
void Node<T>::PREORDER(const Node<T>* p) {
	if (p != NULL) {
		cout << p->key << "  ";
		PREORDER(p->left);
		PREORDER(p->right);
	}
}

template <typename T>
void Node<T>::INORDER(const Node<T>* p) {
	if (p != NULL) {
		INORDER(p->left);
		cout << p->key << "  ";
		INORDER(p->right);
	}
}

template <typename T>
void Node<T>::POSTORDER(const Node<T>* p) {
	if (p != NULL) {
		POSTORDER(p->left);
		POSTORDER(p->right);
		cout << p->key << "  ";
	}
}

template <typename T>
void Node<T>::PRINT(const Node<T>* p, T (*arr)[COL], int& i, int level) {
	if (p != NULL) {
		PRINT(p->left, arr, i, level + 1);
		arr[level][i++] = p->key;
		PRINT(p->right, arr, i, level + 1);
	}
}