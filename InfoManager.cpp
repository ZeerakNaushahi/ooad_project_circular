#include<iostream>
#include"CircularDLL.h"
#include"Movie.h"
#include"InfoManager.h"
#include<string.h>
using namespace std;

template<typename T>
InfoManager<T>::InfoManager()
{

}

template<typename T>
void InfoManager<T>::addMovie(Movie<T>&m)
{
	if (!findMoviesByTitleName(m.getTitle())){
		allMovies.Insert(m);
		sortMovies();
	}
	else
		cout << "Movie with this \" " << m.getTitle() << " \" title already exists" << endl;
}

template<typename T>
void InfoManager<T>::deleteMovieByTitleName(string title)
{
	Node<Movie<T>> * movie;
	movie = findMovieNodeByTitleName(title);
	if (movie != nullptr)
	{
		allMovies.DeletingaNode(movie);
		cout << title << "  deleted\n";
	}
	else
		cout << "No Movie Found with this name\n";
}

template <typename T>
Movie<T>*InfoManager<T>::findMoviesByTitleName(string title)
{
	int size = allMovies.getSize();
	Node<Movie<T>>* m = allMovies.get_header();
	for (int i = 0; i < size; i++)
	{
		if (m->info.getTitle() == title)
		{
			return &m->info;
		}
		m = m->succeeding;
	}
	return nullptr;
}

template<typename T>
void InfoManager<T>::findMoviesByActorName(string actorName)
{
	CircularDLL<Movie<T>> movies;
	int size = allMovies.getSize();

	Node<Movie<T>> *m = allMovies.get_header();
	for (int i = 0; i < size; i++)
	{
		CircularDLL<string> * actors = m->info.getActors();
		if (actors->contains(actorName))
		{
			cout << "Movie:          ";  m->info.Display();
			movies.Insert(m->info);
		}
		m = m->succeeding;
	}
	cout << endl;

}

template<typename T>
void InfoManager<T>::sortMovies()
{
	Node<Movie<T>> *temp;
	Node<Movie<T>> *temp2;

	int size = allMovies.getSize();
	temp = allMovies.get_header();
	for (int i = 0; i < size; i++)
	{
		temp2 = allMovies.get_header();
		for (int j = 0; j < size; j++)
		{
			if (toCapital(temp->info.getTitle()) < toCapital(temp2->info.getTitle()))
				swap(temp->info, temp2->info);
			temp2 = temp2->succeeding;
		}
		temp = temp->succeeding;
	}
}

template<typename T>
void InfoManager<T>::DisplayallMovies()
{
	int size = allMovies.getSize();
	Node<Movie<T>>* temp = allMovies.get_header();
	cout << "                Name  ReleaseDate  Duration" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Movie" << i + 1 << " :        ";
		temp->info.Display();
		temp = temp->succeeding;
	}
	cout << endl;
}

template<typename T>
void InfoManager<T>::findMovieNodeByTitleName(string title)
{
	int size = allMovies.getSize();
	Node<Movie<T>>* m = allMovies.get_header();
	for (int i = 0; i < size; i++)
	{
		if (m->info.getTitle() == title)
		{
			return m;
		}
		m = m->succeeding;
	}
	return nullptr;
}
