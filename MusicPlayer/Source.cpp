
//commit first, then push all
//remeber to pull also
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//void add_song();
void add_song_collection();
//void display_song();
void display_song_collection();
//void delete_song();
void delete_song_collection();
void create_playlist();
void view_playlist();

struct Song {
	string artist, title, genre;
	float duration;
	Song* nextsong;
	Song* prevsong;

};
Song* Shead = NULL;
struct Playlist {
	string name;
	Song songinfo;
	Playlist* nextplaylist;
	Playlist* prevplaylist;
};
Playlist* PLHead = NULL;

vector<Song> Collection;

void main() {
	int option;
	Song song;
	song.artist = "jacob";
	song.title = "Allo";
	song.genre = "Jazz";
	song.duration = 4.52;
	Collection.push_back(song);
	cout << "\n1. Insert new song" << endl;
	cout << "2. Display songs" << endl;
	cout << "3. Delete songs" << endl;
	cout << "4. Create Playlist" << endl;
	cout << "5. View Playlist" << endl;
	cout << "Choose an option: ";
	cin >> option;
	switch (option)
	{
	case (1):
		add_song_collection();
		break;
	case(2):
		display_song_collection();
		break;
	case(3):
		delete_song_collection();
		break;
	case(4):
		create_playlist();
		break;
	case(5):
		view_playlist();
		break;
	default:
		break;
	}
}

void add_song_collection() {
	Song song;
	cout << "Enter artist name: ";
	cin >> song.artist;
	cout << "Enter song title: ";
	cin >> song.title;
	cout << "Enter song genre: ";
	cin >> song.genre;
	cout << "Enter song duration: ";
	cin >> song.duration;
	Collection.push_back(song);
	main();
}

void display_song_collection() {
	int i = 1;
	cout << "\nThe songs in the Collection are: ";
	cout << "\n" << "No.\tArtist\tTitle\tGenre\tDuration" << endl;
	for (const Song& e : Collection)
	{
		cout << "\n" << i << "\t" << e.artist << "\t" << e.title << "\t" << e.genre << "\t" << e.duration << endl;
		i += 1;
	}

}

void delete_song_collection() {
	int i;
	display_song_collection();
	cout << "Enter song number to delete song: ";
	cin >> i;
	Collection.erase(Collection.begin() + i - 1);
	display_song_collection();
}

void create_playlist() {
	Playlist playlist;
	string x;
	cout << "Enter playlist name: ";
	cin >> x;
	if (PLHead == NULL)
	{
		Playlist* newPL = new Playlist;
		newPL->name = x;
		newPL->nextplaylist = NULL;
		cout << "Playlist " << newPL->name << " created.";
		newPL->nextplaylist = PLHead;
		PLHead = newPL;
	}
	else {
		Playlist* curPL = PLHead;
		while (curPL != NULL)
		{
			if (curPL->name == x) {
				cout << "Playlist " << curPL->name << " already exist.";
				break;
			}
			curPL = curPL->nextplaylist;
		}
		if (curPL == NULL)
		{
			Playlist* newPL = new Playlist;
			newPL->name = x;
			newPL->nextplaylist = NULL;
			cout << "Playlist " << newPL->name << " created.";
			newPL->nextplaylist = PLHead;
			PLHead = newPL;
		}
	}
	main();
}

void view_playlist() {
	if (PLHead == NULL) {
		cout << "The are no playlist.\n";
	}
	else
	{
		Playlist* curPL = PLHead;
		while (curPL != NULL)
		{
			cout << "Playlist " << curPL->name << endl;
			curPL = curPL->nextplaylist;
		}
	}
	main();
}

//void add_song() {
//	int i;
//	display_song_collection();
//	Song* nextsong = new Song;
//	cout << "Enter song number to add song: ";
//	cin >> i;
//
//	nextsong->push_back(Collection.begin() + i - 1);
//	nextsong->artist = ;
//	nextsong->title;
//	nextsong->genre;
//	nextsong->duration;
//	nextsong->nextcol = NULL;
//}

//void add_song(){
//	int id;
//	bool duplicate = false;
//	cout << "Enter the song ID: ";
//	cin >> id;
//
//	if (head != NULL)
//	{
//		Song* current = head;
//		while (current != NULL)
//		{
//			if (current->id == id)
//			{
//				duplicate = true;
//				break;
//			}
//			current = current->next;
//		}
//	}
//	if (head == NULL || !duplicate)
//	{
//		Song* newSong = new Song;
//		cout << "Enter the song ID: ";
//		newSong->id = id;
//		cout << "Enter singer name: ";
//		cin >> newSong->singer;
//		cout << "Enter song title: ";
//		cin >> newSong->title;
//		cout << "Enter song genre: ";
//		cin >> newSong->genre;
//		cout << "Enter song duration: ";
//		cin >> newSong->duration;
//		newSong->next = head;
//		head = newSong;
//	}
//	else {
//		cout << "Error";
//	}
//	main();
//}

//void display_song() {
//	if (head == NULL) {
//		cout << "The list is empty.\n";
//	}
//	else
//	{
//		Song* current = head;
//
//		while (current != NULL)
//		{
//			cout << "Song ID: " << current->id << endl;
//
//			cout << "Singer: " << current->singer << endl;
//
//			cout << "Title: " << current->title << endl;
//
//			cout << "Genre: " << current->genre << endl;
//
//			cout << "Duration: " << current->duration << endl;
//
//			current = current->next;
//		}
//	}
//	main();
//}
//
//void delete_song() {
//	bool found = false;
//	int id;
//	if (head == NULL) {
//		cout << "The list is empty";
//	}
//	else {
//		Song* todelete = head;
//		Song* prev = NULL;
//		cout << "Enter the song ID: ";
//		cin >> id;
//		while (todelete != NULL)
//		{
//			if (todelete->id == id)
//			{
//				found = true;
//				break;
//			}
//			else
//			{
//				prev = todelete;
//				todelete = todelete->next;
//			}
//		}
//		if (found)
//		{
//			if (head->id == id) {
//				todelete = head;
//				head = head->next;
//				delete todelete;
//			}
//			else {
//				prev->next = todelete->next;
//				delete todelete;
//			}
//			cout << "Song deleted" << endl;
//		}
//		else {
//			cout << "Song not found" << endl;
//		}
//
//	}
//	main();
//}

