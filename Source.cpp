#include<iostream>
#include"CircularDLL.h"
#include"InfoManager.h"
#include"Movie.h"
#include<string.h>
using namespace std;
template<typename T>
void InsertMovie(InfoManager<T>& info, CircularDLL<string>&actors,CircularDLL<string>&cast)
{
	string title, releaseYear, duration, actorName;
	bool exists = true;
	system("cls");
	while (exists)
	{
		cout << "Enter the title of the movie \n";
		getline(cin, title);
		if (info.findMoviesByTitleName(title))
		{
			system("cls");
			cout << "			Movie already exists with " << title << " title \n";
		}
		else
			exists = false;
	}

	cout << "Enter the Year of Release of movie\n";
	getline(cin, releaseYear);
	cout << "Enter the Duration of Movie\n";
	getline(cin, duration);
	int actoroption = 1;
	while (actoroption != 0)
	{
		system("cls");
		if (!actors.isEmpty())
			cout << "All Actors for the movie  : ";  actors.displayfromstart();
		cout << endl;
		cout << "Press 1 to add an actor of Movie : " << title << " \n";
		cout << "Press 2 to delete an actor name \n";
		cout << "Press 0 Insert movie to infobase :";
		cin >> actoroption;

		cin.ignore();
		if (actoroption == 1)
		{
			cout << "Enter the actor Name : ";
			getline(cin, actorName);
			actors.insertsortingorder(actorName);
		}
		else if (actoroption == 2)
		{
			cout << "Enter the actor Name you want to delete : ";
			getline(cin, actorName);
			actors.DeleteAt(actorName);
		}
	}
	Node<T> casts;
	Movie<string> m(title, releaseYear, duration, actors,casts);
	info.addMovie(m);
	actors.clear();
	system("cls");
}

int main()
{

	InfoManager<string> info;
	CircularDLL<string> Actor;
	CircularDLL<string> Cast;
	string title, cast, actorName;

	int option = -1;
	while (option != 0)
	{
		cout << "Press 1 to add a new Movie Record " << endl;
		cout << "Press 2 to delete a movie " << endl;
		cout << "Press 3 to add a cast to a movie " << endl;
		cout << "Press 4 to delete a cast of a movie " << endl;
		cout << "Press 5 to display all cast of the movie" << endl;
		cout << "Press 6 to find and print info of a movie" << endl;
		cout << "Press 7 to fing all the names of a specfic Actor " << endl;
		cout << "Press 8 to print all the movies in sorted order " << endl;
		cout << "Press 0 to exit : " << endl;
		cout << endl;
		cout << "Enter the option you want to choose: ";
		cin >> option;
		cin.ignore();
		if (option == 1) // inset a movie
		{
			InsertMovie(info, Actor,Cast);
		}		
		else if (option == 2) // delete movie by title name
		{
			system("cls");
			cout << "Enter the title of the movie you want to delete \n";
			getline(cin, title);
			info.deleteMovieByTitleName(title);
			cout << endl;
		}
		else if (option == 3) // add cast
		{
			system("cls");
			cout << "Enter the title of the movie you want to add Cast to \n";
			getline(cin, title);
			Movie<string> * m = info.findMoviesByTitleName(title);
			if (m)
			{
				cout << "Enter new Cast name \n";
				getline(cin, cast);
				m->insertcast(cast);
				system("cls");
			}
			else{
				cout << "No movie found with this title \n\n";
			}
		}
		else if (option == 4)
		{
			system("cls");
			cout << "Enter the title of the movie you want to delete Cast from \n";
			getline(cin, title);
			Movie<string> * m = info.findMoviesByTitleName(title);
			if (m)
			{
				cout << "Enter the case name you want to delete \n";
				getline(cin, cast);
				m->deletecast(cast);
				system("cls");
			}
			else
				cout << "No movie found with this title \n\n";

		}
		else if (option == 5) // view all casts
		{
			system("cls");
			cout << "Enter the title of the movie you want to view Cast of \n";
			getline(cin, title);
			Movie<string> * m = info.findMoviesByTitleName(title);
			if (m)
			{
				m->Display_cast();
				cout << endl;
			}
			else
				cout << "No movie found with this title \n\n";

		}
	}
}