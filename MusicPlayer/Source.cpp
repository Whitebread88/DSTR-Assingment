
//commit first, then push all
//remeber to pull also
#include <iostream>
#include <iomanip>
#include "Source.h"
using namespace std;

void add_song();
void display_song();
void delete_song();

struct Song {
	string singer, title, genre;
	float duration;
	int id, size;
	Song* next;
	Song* prev;
};
Song* head = NULL;

struct playlist {
	string name;
	Song song;
	playlist* next;
	playlist* prev;
};
;

class Collection {
public:
	int song_id;

	void add_song();

	void display_all();
};

void Collection::display_all() {
	cout << "Song ID: " << song.id << endl;

	cout << "Singer: " << song.singer << endl;

	cout << "Title: " << song.title << endl;

	cout << "Genre: " << song.genre << endl;

	cout << "Duration: " << song.duration << endl;
}


void main() {
	Collection collection();
	int option, value;
	cout << "\n1. Insert new song" << endl;
	cout << "2. Display songs" << endl;
	cout << "3. Delete songs" << endl;
	cout << "Choose an option: ";
	cin >> option;
	switch (option)
	{
	case (1):
		add_song();
		break;
	case(2):
		display_song();
		break;
	case(3):
		display_all();
	default:
		break;
	}
}

void Collection::add_song(){
	int id;
	bool duplicate = false;
	cout << "Enter the song ID: ";
	cin >> id;

	if (head != NULL)
	{
		Song* current = head;
		while (current != NULL)
		{
			if (current->id == id)
			{
				duplicate = true;
				break;
			}
			current = current->next;
		}
	}
	if (head == NULL || !duplicate)
	{
		Song* newSong = new Song;
		cout << "Enter the song ID: ";
		newSong->id = id;
		cout << "Enter singer name: ";
		cin >> newSong->singer;
		cout << "Enter song title: ";
		cin >> newSong->title;
		cout << "Enter song genre: ";
		cin >> newSong->genre;
		cout << "Enter song duration: ";
		cin >> newSong->duration;
		newSong->next = head;
		head = newSong;
	}
	else {
		cout << "Error";
	}
	main();
}

void display_song() {
	if (head == NULL) {
		cout << "The list is empty.\n";
	}
	else
	{
		Song* current = head;

		while (current != NULL)
		{
			cout << "Song ID: " << current->id << endl;

			cout << "Singer: " << current->singer << endl;

			cout << "Title: " << current->title << endl;

			cout << "Genre: " << current->genre << endl;

			cout << "Duration: " << current->duration << endl;

			current = current->next;
		}
	}
	main();
}

void delete_song() {
	bool found = false;
	int id;
	if (head == NULL) {
		cout << "The list is empty";
	}
	else {
		Song* todelete = head;
		Song* prev = NULL;
		cout << "Enter the song ID: ";
		cin >> id;
		while (todelete != NULL)
		{
			if (todelete->id == id)
			{
				found = true;
				break;
			}
			else
			{
				prev = todelete;
				todelete = todelete->next;
			}
		}
		if (found)
		{
			if (head->id == id) {
				todelete = head;
				head = head->next;
				delete todelete;
			}
			else {
				prev->next = todelete->next;
				delete todelete;
			}
			cout << "Song deleted" << endl;
		}
		else {
			cout << "Song not found" << endl;
		}
		
	}
	main();
}
	
