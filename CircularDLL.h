#pragma once
template<typename T>
class Node
{
	T info;
	T*succeeding;
	T*prev;
};

template<typename T>
class CircularDLL
{
private:
	Node<T>*header;
	bool isPointer = false;

public:
	CircularDLL();
	CircularDLL(Node<T>);
	CircularDLL(const Node<T>&);
	void insert(T);
	void insertsortingorder(T);
	void set_header(T);
	Node<T>*get_header();
	void displayfromstart();
	void displayfromend();
	int getSize();
	void DeleteFromStart();
	void DeleteFromEnd();
	void DeleteAt(T);
	bool isEmpty();
	Node<T>*Search(T);
	void clear();
	bool contains(T);
	void DeleteaNode(Node<T>*);
	~CircularDLL();
};