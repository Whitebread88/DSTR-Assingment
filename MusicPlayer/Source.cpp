
//commit first, then push all
//remeber to pull also
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Song {	//Node structure for songs
	string artist, title, genre;
	float duration;
	Song* nextsong;

};
Song* Shead = NULL;

struct Playlist {	//Node structure for playlist
	string name;
	Song* songinfo = NULL;
	Playlist* nextplaylist;

};
Playlist* PLHead = NULL;
Song* songinfo = NULL;


vector<Song> Collection;	//Vector named Collection to store songs

void add_song();
void add_song_collection();
void display_song_collection();
void delete_song_collection();
void create_playlist();
void view_playlist();
void view_songs();
void remove_song();
void delete_playlist();
void playlist_search();
int song_collection_check();
int playlist_check();
void play_song_collection();
void play_song_playlist(Song*);



void main() {
	int option;
	/*Song song;
	song.artist = "jacob";
	song.title = "Allo";
	song.genre = "Jazz";
	song.duration = 4.52;
	Collection.push_back(song);*/
	cout << "\n\n========< SONGTIFY MUSIC MANAGEMENT APPLICATION >======== " << endl;
	cout << "\nOptions available: " << endl;
	cout << "\n1. Insert new song into Collection" << endl;
	cout << "2. Display songs in Collection" << endl;
	cout << "3. Delete songs in Collection" << endl;
	cout << "4. Create new Playlist" << endl;
	cout << "5. View Playlists" << endl;
	cout << "6. Add Song to Playlist" << endl;
	cout << "7. View Songs in Playlist" << endl;
	cout << "8. Remove song from Playlist" << endl;
	cout << "9. Delete Playlist" << endl;
	cout << "10. Search for Playlists with specific songs" << endl;
	cout << "11. Exit Application" << endl;
	cout << "\nChoose an option: ";
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
	case(6):
		add_song();
		break;
	case(7):
		view_songs();
		break;
	case(8):
		remove_song();
		break;
	case(9):
		delete_playlist();
		break;
	case(10):
		playlist_search();
		break;
	case(11):
		exit(0);
		break;
	default:
		exit(0);
		break;
	}
}

void add_song_collection() {	//Add songs to the Collection vector
	Song song;

	cout << "\n========< ADD SONG INTO COLLECTION >======== " << endl;
	cout << "Enter artist name: ";
	cin >> song.artist;
	cout << "Enter song title: ";
	cin >> song.title;
	cout << "Enter song genre: ";
	cin >> song.genre;
	cout << "Enter song duration: ";
	cin >> song.duration;
	Collection.push_back(song);
	cout << "\n------< Song added to collection successfully! >------";

	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}

void display_song_collection() {		//Display all songs stored in the Collection
	int i = 1;

	if (Collection.size() == 0)
	{
		cout << "\n------< No songs in collection. >------" << endl;
	}
	else
	{
		cout << "\n < SONGS IN COLLECTION >" << endl;
		cout << "\n" << "No.\tArtist\tTitle\tGenre\tDuration" << endl;
		for (const Song& e : Collection)

		{
			cout << "\n" << i << "\t" << e.artist << "\t" << e.title << "\t" << e.genre << "\t" << e.duration << endl;
			i += 1;
		}
	}
	int choice;
	cout << "\n\n------Press 1 to play a song, 2 to return to main menu & 3 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		play_song_collection();
		break;
	case (2):
		main();
		break;
	case(3):
		exit(0);
		break;
	default:
		break;
	}
}

int song_collection_check() {
	int i = 1;

	if (Collection.size() == 0)
	{
		cout << "\n------< No songs in collection. >------" << endl;
		return 0;
	}
	else
	{
		cout << "\n < SONGS IN COLLECTION >" << endl;
		cout << "\n" << "No.\tArtist\tTitle\tGenre\tDuration" << endl;
		for (const Song& e : Collection)

		{
			cout << "\n" << i << "\t" << e.artist << "\t" << e.title << "\t" << e.genre << "\t" << e.duration << endl;
			i += 1;
		}
	}
}

void delete_song_collection() {		//remove selected song from Collection and playlists
	cout << "\n========< DELETE SONGS IN COLLECTION >======== " << endl;
	string x;
	int count = 0;
	song_collection_check();
	cout << "Enter song name to delete song: ";
	cin >> x;
	for (const Song& e : Collection)
	{
		if (x == e.title)
		{
			Collection.erase(Collection.begin() + count);
			cout << "------< Song: " << x << " deleted from collection. >------" << endl;
		}
		count += 1;
	}
	if (PLHead != NULL) {
		Playlist* playlist = PLHead;
		while (playlist != NULL)
		{
			Song* currentPL = playlist->songinfo;
			Song* todelete = currentPL;
			bool found = false;
			Song* prev = NULL;
			while (todelete != NULL)
			{
				if (x == todelete->title)
				{
					found = true;
					break;
				}
				prev = todelete;
				todelete = todelete->nextsong;
			}
			if (found)
			{
				if (prev != NULL)
				{
					prev->nextsong = todelete->nextsong;
					delete todelete;
				}
				else
				{
					currentPL = currentPL->nextsong;
					delete todelete;
					playlist->songinfo = currentPL;
				}
				cout << "-----< Song: " << x << " deleted from playlist. >------" << endl;
			}
			playlist = playlist->nextplaylist;
		}
	}
	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}


void playlist_search() {	//Search and display all playlists that contains a specific song
	cout << "\n========< SEARCH SONG IN PLAYLIST >======== " << endl;
	if (song_collection_check() != 0) {
		bool exist = false;
		string a;
		cout << "Enter song title to display all related playlists: ";
		cin >> a;
		if (PLHead->songinfo == NULL) {
			cout << "There are no songs in any playlist. " << endl;
		}
		for (const Song& e : Collection)
		{
			if (a == e.title)
			{
				exist = true;
				break;
			}
		}
		if (exist)
		{
			Playlist* playlist = PLHead;
			while (playlist != NULL)
			{
				Song* currentPL = playlist->songinfo;
				while (currentPL != NULL)
				{
					if (a == currentPL->title) {
						cout << "------< " << a << " found in playlist: " << playlist->name << " >------" << endl;
					}
					currentPL = currentPL->nextsong;
				}
				playlist = playlist->nextplaylist;
			}
		}
		else
		{
			cout << "------< Song does not exist in any playlist. >------ " << endl;
		}
	}
	else
	{
		cout << " ------< Add songs in Collection before searching. >------";
	}
	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}


void create_playlist() {	//create new playlist
	cout << "\n========< CREATE PLAYLIST >======== " << endl;
	Playlist playlist;
	string x;
	cout << "Enter playlist name: ";
	cin >> x;
	if (PLHead == NULL)
	{
		Playlist* newPL = new Playlist;
		newPL->name = x;
		cout << "------< Playlist " << newPL->name << " created. >------" << endl;;
		newPL->nextplaylist = PLHead;
		PLHead = newPL;
		newPL->songinfo = NULL;
	}
	else {
		Playlist* curPL = PLHead;
		while (curPL != NULL)
		{
			if (curPL->name == x) {
				cout << "------< Playlist " << curPL->name << " already exist. >------" << endl;;
				break;
			}
			curPL = curPL->nextplaylist;
		}
		Playlist* newPL = new Playlist;
		newPL->name = x;
		newPL->nextplaylist = PLHead;
		cout << "------< Playlist " << newPL->name << " created. >------" << endl;
		PLHead = newPL;
		newPL->songinfo = NULL;
	}
	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}

void view_playlist() {	//View all existing playlists

	if (PLHead == NULL) {
		cout << "\n------< There are no existing playlist. >------\n";
	}
	else
	{
		cout << "\n < PLAYLISTS AVAILABLE > \n" << endl;
		Playlist* curPL = PLHead;
		while (curPL != NULL)
		{
			cout << "Playlist: " << curPL->name << endl;
			curPL = curPL->nextplaylist;
		}
	}
	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}

int playlist_check() {	//Check if there are existing playlist
	if (PLHead == NULL) {
		cout << "\n------< There are no existing playlist. >------\n";
		return 0;
	}
	else
	{
		cout << "\n < PLAYLISTS AVAILABLE > \n" << endl;
		Playlist* curPL = PLHead;
		while (curPL != NULL)
		{
			cout << "Playlist: " << curPL->name << endl;
			curPL = curPL->nextplaylist;
		}
	}
}

void add_song() {	//Add songs into specific playlist
	cout << "\n========< ADD SONGS INTO PLAYLIST >======== " << endl;
	bool exist = false;
	if (playlist_check() != 0) {
		Playlist* PL = PLHead;
		string s;
		cout << "Enter playlist name: ";
		cin >> s;
		while (PL != NULL)
		{
			if (PL->name == s) {
				exist = true;
				cout << "Playlist " << PL->name << " found.";
				break;
			}
			PL = PL->nextplaylist;
		}
		if (exist)
		{
			string x;
			Song* newsong = new Song;
			if (song_collection_check() != 0)
			{
				cout << "\nEnter song title to add song: ";
				cin >> x;
				for (const Song& e : Collection)
				{
					if (x == e.title)
					{
						if (PL->songinfo != NULL)
						{
							newsong->artist = e.artist;
							newsong->title = e.title;
							newsong->genre = e.genre;
							newsong->duration = e.duration;
							newsong->nextsong = PL->songinfo;
							PL->songinfo = newsong;
							cout << " ------< Song successfully added. >------";
							break;
						}
						else
						{
							newsong->artist = e.artist;
							newsong->title = e.title;
							newsong->genre = e.genre;
							newsong->duration = e.duration;
							newsong->nextsong = NULL;
							PL->songinfo = newsong;
							cout << "------< Song successfully added. >------";
							break;
						}
					}
					else
					{
						cout << "------< Song does not exist. >------";
					}
				}
			}
			else
			{
				cout << "------< Add songs in Collection before adding to playlist. >------";

			}
		}
		else
		{
			cout << "------< Playlist not found. >------";

		}
	}
	else
	{
		cout << "------< Playlist not found. >------ ";

	}
	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}

void view_songs() {		//View all songs in specific playlist
	cout << "\n========< VIEW SONGS IN PLAYLIST >======== " << endl;
	bool exist = false;
	Song* SongPL=NULL;
	if (playlist_check() != 0) {
		Song* currentPL = NULL;
		Playlist* playlist = PLHead;
		string x;
		cout << "\nEnter playlist name: ";
		cin >> x;
		while (playlist != NULL)
		{
			if (playlist->name == x) {
				exist = true;
				cout << "Playlist: " << playlist->name;
				currentPL = playlist->songinfo;
				SongPL = playlist->songinfo;
				break;
			}
			playlist = playlist->nextplaylist;

		}
		if (exist)
		{
			if (currentPL != NULL)
			{
				while (currentPL != NULL)
				{
					cout << " || " << " Artist: " << currentPL->artist << " Title: " << currentPL->title << " Genre: " << currentPL->genre << " Duration: " << currentPL->duration;
					currentPL = currentPL->nextsong;
				}
			}
			else
			{
				cout << "\n------< There are no songs in this playlist. >-----";
			}
		}
		else
		{
			cout << "\n------< Playlist does not exist. >------";
		}
	}
	else
	{
		cout << "------< There are no playlist. >------\n";
	}
	int choice;
	cout << "\n\n------Press 1 to play song, 2 to return to main menu & 3 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		play_song_playlist(SongPL);
		break;
	case (2):
		main();
		break;
	case(3):
		exit(0);
		break;
	default:
		break;
	}
}

void remove_song() {	//Remove specific song from specific playlist
	cout << "\n========< REMOVE SONG IN PLAYLIST >======== " << endl;
	bool exist = false;
	if (playlist_check() != 0) {
		Song* currentPL = NULL;
		Playlist* playlist = PLHead;
		string x;
		cout << "Enter playlist name: ";
		cin >> x;
		while (playlist != NULL)
		{
			if (playlist->name == x) {
				exist = true;
				cout << "------< Playlist " << playlist->name << " found. >------";
				currentPL = playlist->songinfo;
				break;
			}
			playlist = playlist->nextplaylist;

		}
		if (exist)
		{
			if (currentPL != NULL)
			{
				Song* temp = currentPL;
				while (currentPL != NULL)
				{
					cout << " || " << " Artist: " << currentPL->artist << " Title: " << currentPL->title << " Genre: " << currentPL->genre << " Duration: " << currentPL->duration;
					currentPL = currentPL->nextsong;
				}
				bool found = false;
				string i;
				Song* todelete = temp;
				Song* prev = NULL;
				cout << "\nEnter song title to remove song: ";
				cin >> i;
				while (todelete != NULL)
				{
					if (i == todelete->title)
					{
						found = true;
						cout << "\n------< Song " << i << " found. >------";
						break;
					}
					prev = todelete;
					todelete = todelete->nextsong;
				}
				if (found)
				{
					if (prev != NULL)
					{
						prev->nextsong = todelete->nextsong;
						delete todelete;
					}
					else
					{
						temp = temp->nextsong;
						delete todelete;
						playlist->songinfo = temp;
					}
					cout << "\n------< Song deleted successfully. >------" << endl;
				}
				else {
					cout << "\n------< Song does not exist. >------" << endl;
				}
			}
			else
			{
				cout << "\n------< There are no songs in this playlist. >------";
			}
		}
		else
		{
			cout << "\n------< Playlist does not exist. >------";
		}
	}
	else
	{
		cout << "------< There are no playlist. >------\n";
	}
	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}

void delete_playlist() {	//delete selected playlist
	cout << "\n========< DELETE PLAYLIST >======== " << endl;
	bool exist = false;
	if (playlist_check() != 0) {
		Song* currentPL = NULL;
		Song* temp = NULL;
		Playlist* todelete = NULL;
		Playlist* prev = NULL;
		Playlist* playlist = PLHead;
		string x;
		cout << "Enter playlist name: ";
		cin >> x;
		while (playlist != NULL)
		{
			if (playlist->name == x) {
				exist = true;
				cout << "\n------< Playlist " << playlist->name << " found. >------";
				currentPL = playlist->songinfo;
				todelete = playlist;
				break;
			}
			prev = playlist;
			playlist = playlist->nextplaylist;
		}
		if (exist)
		{
			while (currentPL != NULL)
			{
				temp = currentPL;
				currentPL = currentPL->nextsong;
				delete temp;
			}
			if (prev != NULL)
			{
				prev->nextplaylist = todelete->nextplaylist;
				delete todelete;
			}
			else
			{
				playlist = todelete->nextplaylist;
				delete todelete;
				PLHead = playlist;
			}
			cout << "\n------< Playlist and songs inside deleted successfully. >------";
		}
		else
		{
			cout << "-\n-----< Playlist does not exist >------";
		}
	}
	else
	{
		cout << "------< There are no playlist. >------\n";
	}
	int choice;
	cout << "\n\n------Press 1 to return to main menu & 2 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		main();
		break;
	case(2):
		exit(0);
		break;
	default:
		break;
	}
}

void play_song_collection() {
	string x;
	song_collection_check();
	cout << "\nEnter song name to play song: ";
	cin >> x;
	for (const Song& e : Collection)
	{
		if (x == e.title)
		{
			cout << "------< Song: " << x << " is playing. >------" << endl;
			break;
		}
	}
	int choice;
	cout << "\n\n------Press 1 to play another song, 2 to return to main menu & 3 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		play_song_collection();
		break;
	case (2):
		main();
		break;
	case(3):
		exit(0);
		break;
	default:
		break;
	}
}

void play_song_playlist(Song *SongPL) {
	string x;
	Song* CurrentPL;
	CurrentPL = SongPL;
	cout << "Enter the song name: ";
	cin >> x;
	if (CurrentPL != NULL)
	{
		while (CurrentPL!= NULL)
		{
			if (x == CurrentPL->title)
			{
				cout << "Song " << x << " is playing" << endl;
				break;
			}
			CurrentPL = CurrentPL->nextsong;
		}
	}
	else
	{
		cout << "\n------< There are no songs in this playlist. >-----";
	}
	int choice;
	cout << "\n\n------Press 1 to play another song, 2 to return to main menu & 3 to exit------" << endl;
	cout << "Enter an option: ";
	cin >> choice;
	switch (choice)
	{
	case (1):
		play_song_playlist(SongPL);
		break;
	case (2):
		main();
		break;
	case(3):
		exit(0);
		break;
	default:
		break;
	}
}

