#include"CircularDLL.h"
#include<iostream>
#include<string.h>
using namespace std;

template<typename T>
CircularDLL<T>::CircularDLL()
{
	header = nullptr;
}

template<typename T>
CircularDLL<T>::CircularDLL(Node<T> head)
{
	header = new Node<T>;
	*header = head;
}

template<typename T>
CircularDLL<T>::CircularDLL(const Node<T> &other)
{
	header = new Node<T>;
	*header = *(other.header);
}
template<typename T>
void CircularDLL<T>::insert(T data)
{
	Node<T> * temp = new Node<T>;
	temp->info = data;
	if (header == nullptr)
	{
		header = temp;
		header->succeeding = header;
		header->prev = header;
	}
	else{
		header->prev->succeeding = temp;
		temp->prev = header->prev;
		header->prev = temp;
		temp->succeeding = header;
	}
}

template<typename T>
void CircularDLL<T>::insertsortingorder(T info)
{
	insert(info);
	Node<T> *temp;
	Node<T> *temp2;

	int size = getSize();
	temp = header;
	for (int i = 0; i < size; i++)
	{
		temp2 = header;
		for (int j = 0; j < size; j++)
		{
			if (toCapital(temp->info) < toCapital(temp2->info))
				swap(temp->info, temp2->info);
			temp2 = temp2->succeeding;
		}
		temp = temp->succeeding;
	}
}


template<typename T>
Node<T>* CircularDLL<T>::get_header()
{
	return header;
}

template<typename T>
void CircularDLL<T>::displayfromstart()
{
	if (isEmpty())
	{
		return;
	}
	Node<T> * temp = header;
	while (temp != header->prev)
	{
		cout << temp->info << "  ";
		temp = temp->succeeding;
	}
	cout << temp->info << "  ";
	cout << endl;
}


template<typename T>
void CircularDLL<T>::displayfromend()
{
	if (isEmpty())
	{
		return;
	}
	Node<T> * temp = header->prev;
	while (temp != header)
	{
		cout << temp->info << "  ";
		temp = temp->prev;
	}
	cout << temp->info << "  ";
	cout << endl;
}

template<typename T>
int CircularDLL<T>::getSize()
{
	if (header == nullptr)
		return 0;
	int x = 0;
	Node<T> * temp = header;
	while (temp != header->prev)
	{
		temp = temp->succeeding;
		x++;
	}
	x++;
	return x;
}

template<typename T>
void CircularDLL<T>::DeleteFromStart()
{
	DeleteaNode(header);
}

template<typename T>
void CircularDLL<T>::DeleteFromEnd()
{
	DeleteaNode(header->previous);
}

template<typename T>
void CircularDLL<T>::DeleteaNode(Node<T>* remove)
{
	if (remove == nullptr)
		return;
	if (isEmpty())
		return;
	if (remove == header)
	{
		if (getSize() == 1)
			header = nullptr;
		else
		{
			header->succeeding->prev = header->prev;
			header->prev->succeeding = header->succeeding;
			header = header->succeeding;
		}
		delete remove;
	}
	else{
		remove->prev->succeeding = remove->succeeding;
		remove->succeeding->prev = remove->prev;
		delete remove;
	}
}

template<typename T>
void CircularDLL<T>::DeleteAt(T info)
{
	DeleteaNode(Search(info));
}


template<typename T>
bool CircularDLL<T>::isEmpty()
{
	if (header == NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template<typename T>
Node<T>* CircularDLL<T>::Search(T var)
{
	Node<T> * temp = header;
	for (int i = 0; i < getSize(); i++)
	{
		if (temp->info == var)
			return temp;
		temp = temp->succeeding;
	}
	return nullptr;
}

template<typename T>
void CircularDLL<T>::clear()
{
	header = nullptr;
}

template<typename T>
bool CircularDLL<T>::contains(T info)
{
	Node<T>*temp = header;
	if (isEmpty())
		return false;
	int size = getSize();
	for (int i = 0; i < size; i++)
	{
		if (temp->info == info)
			return true;
		temp = temp->succeeding;
	}
	return false;
}

template<typename T>
CircularDLL<T>::~CircularDLL()
{
	delete header;
}

