#pragma once
using namespace std;
#include<string>
#include"CircularDLL.h"

template <typename T> 
class Movie:public CircularDLL<T>
{
private:
	string title;
	string Release_Year;
	string duration;
	CircularDLL<string> Actors;
	CircularDLL<string> Cast;

public:
	Movie(string, string, string, CircularDLL<string>,Node<T>);
	bool operator ==(const Movie<T>&);
	string getTitle();
	string getReleaseYear();
	string getDuration();
	CircularDLL<T>* getActors();
	CircularDLL<T>*getCast();
	void insertcast(string);
	void deletecast(string);
	void Display_cast();
	void Display();
	~Movie();


};