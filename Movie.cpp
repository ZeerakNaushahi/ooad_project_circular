#include"Movie.h"
#include"CircularDLL.h"
#include<iostream>
#include<string.h>
using namespace std;

template<typename T>
Movie<T>::Movie(string t, string ry, string d, CircularDLL<string>a, Node<T>h) :CircularDLL<T>(h)
{
	title = t;
	releaseYear = ry;
	duration = d;
	actors = a;

}

template<typename T>
bool Movie<T>::operator==(const Movie<T> &a)
{
	if ((a.title) == (this->title))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
string Movie<T>::getTitle()
{
	return title;
}

template<typename T>
string Movie<T>::getReleaseYear()
{
	return releaseYear;
}

template<typename T>
string Movie<T>::getDuration()
{
	return duration;
}

template<typename T>
CircularDLL<T>* Movie<T>::getActors()
{
	return &Actors;
}

template<typename T>
CircularDLL<T>*Movie<T>::getCast()
{
	return &Cast;
}

template<typename T>
void Movie<T>::insertcast(string cast)
{
	Cast.insert(cast);
}

template<typename T>
void Movie<T>::deletecast(string cast)
{
	Cast.DeleteAt(cast);
}

template<typename T>
void Movie<T>::Display_cast()
{
	cout << "Casts : ";
	Cast.displayfromstart();
	cout << endl;
}

template<typename T>
Movie<T>::~Movie()
{

}