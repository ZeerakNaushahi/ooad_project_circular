#pragma once
#include<string.h>
#include"CircularDLL.h"
#include"Movie.h"
template<typename T>
class InfoManager:public Movie<T>
{
private:
	CircularDLL<Movie<T>> allMovies;
	string infoFile = "moviesinfo.txt";

public:
	InfoManager();
	void addMovie(Movie<T>&);
	void deleteMovieByTitleName(string);
	Movie<T>* findMoviesByTitleName(string);
	void findMoviesByActorName(string);
	void DisplayallMovies();
	void findMovieNodeByTitleName(string);
	void sortMovies();



};

