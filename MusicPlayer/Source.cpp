
//commit first, then push all
//remeber to pull also
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void add_song();
void add_song_collection();
int display_song_collection();
void delete_song_collection();
void create_playlist();
int view_playlist();
void view_songs();
void remove_song();
void delete_playlist();
void playlist_search();

struct Song {	//Node structure for songs
	string artist, title, genre;
	float duration;
	Song* nextsong;
	Song* prevsong;

};
Song* Shead = NULL;

struct Playlist {	//Node structure for playlist
	string name;
	Song* songinfo = NULL;
	Playlist* nextplaylist;
	Playlist* prevplaylist;

};
Playlist* PLHead = NULL;
Song* songinfo = NULL;


vector<Song> Collection;	//Vector named Collection to store songs

void main() {
	int option;
	/*Song song;
	song.artist = "jacob";
	song.title = "Allo";
	song.genre = "Jazz";
	song.duration = 4.52;
	Collection.push_back(song);*/
	cout << "\n1. Insert new song" << endl;
	cout << "2. Display songs" << endl;
	cout << "3. Delete songs" << endl;
	cout << "4. Create Playlist" << endl;
	cout << "5. View Playlist" << endl;
	cout << "6. Add Song to playlist" << endl;
	cout << "7. View Songs in Playlist" << endl;
	cout << "8. Remove song from Playlist" << endl;
	cout << "9. Delete Playlist" << endl;
	cout << "10. Search for playlists with specific songs" << endl;
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
	default:
		break;
	}
}

void add_song_collection() {	//Add songs to the Collection vector
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

int display_song_collection() {		//Display all songs stored in the Collection
	int i = 1;
	cout << "\nThe songs in the Collection are: ";
	cout << "\n" << "No.\tArtist\tTitle\tGenre\tDuration" << endl;
	if (Collection.size() == 0)
	{
		cout << "\nNo songs in collection." << endl;
		return 0;
	}
	else
	{
		for (const Song& e : Collection)
		{
			cout << "\n" << i << "\t" << e.artist << "\t" << e.title << "\t" << e.genre << "\t" << e.duration << endl;
			i += 1;
		}
	}
}

void delete_song_collection() {		//remove selected song from Collection and playlists
	string x;
	int count = 0;
	display_song_collection();
	cout << "Enter song name to delete song: ";
	cin >> x;
	for (const Song& e : Collection)
	{
		if (x == e.title)
		{
			Collection.erase(Collection.begin() + count);
			cout << "Song: " << x << " deleted." << endl;
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
					if (todelete->nextsong != NULL)
					{
						prev->nextsong = todelete->nextsong;
						todelete->nextsong->prevsong = prev;
						delete todelete;
					}
					else
					{
						prev->nextsong = todelete->nextsong;
						delete todelete;
					}
				}
				else
				{
					todelete = currentPL;
					currentPL = currentPL->nextsong;
					delete todelete;
					playlist->songinfo = currentPL;
				}
				cout << "Song: " << x << " deleted from playlist." << endl;
			}
			playlist = playlist->nextplaylist;
		}
	}
	main();
}



void playlist_search() {	//Search and display all playlists that contains a specific song
	if (display_song_collection() != 0)
	{
		bool exist = false;
		string i;
		cout << "Enter song title to display all related playlists: ";
		cin >> i;
		if (PLHead->songinfo == NULL) {
			cout << "There are no songs in any playlist. " << endl;
		}
		for (const Song& e : Collection)
		{
			if (i == e.title)
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
					if (i == currentPL->title) {
						cout << i << " found in playlist: " << playlist->name << endl;
					}
					currentPL = currentPL->nextsong;
				}
				playlist = playlist->nextplaylist;
			}
		}
		else
		{
			cout << "Song does not exist in any playlist. " << endl;
		}
	}
	else
	{
		cout << "Add songs in Collection before searching.";
	}
	main();
}


void create_playlist() {	//create new playlist
	Playlist playlist;
	string x;
	cout << "Enter playlist name: ";
	cin >> x;
	if (PLHead == NULL)
	{
		Playlist* newPL = new Playlist;
		newPL->name = x;
		cout << "Playlist " << newPL->name << " created.";
		newPL->nextplaylist = PLHead;
		PLHead = newPL;
		newPL->songinfo = NULL;
		newPL->prevplaylist = NULL;
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
		Playlist* newPL = new Playlist;
		newPL->name = x;
		newPL->nextplaylist = PLHead;
		PLHead->prevplaylist = newPL;
		cout << "Playlist " << newPL->name << " created.";
		PLHead = newPL;
		newPL->songinfo = NULL;
		newPL->prevplaylist = NULL;
	}
	main();
}

int view_playlist() {	//View all existing playlists
	if (PLHead == NULL) {
		cout << "The are no playlist.\n";
		return 0;
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

}

void add_song() {	//Add songs into specific playlist
	bool exist = false;
	if (view_playlist() != 0) {
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
			if (display_song_collection() != 0)
			{
				cout << "Enter song title to add song: ";
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
							newsong->nextsong->prevsong = newsong;
							cout << "Song successfully added.";
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
							cout << "Song successfully added.";
							break;
						}
					}
				}
			}
			else
			{
				cout << "Add songs in Collection before adding to playlist";
			}
		}
		else
		{
			cout << "Playlist not found.";
		}
	}
	else
	{
		cout << "Playlist not found. ";
	}
	main();
}

void view_songs() {		//View all songs in specific playlist
	bool exist = false;
	if (PLHead == NULL) {
		cout << "The are no playlist.\n";
	}
	else
	{
		Song* currentPL = NULL;
		Playlist* playlist = PLHead;
		string x;
		cout << "Enter playlist name: ";
		cin >> x;
		while (playlist != NULL)
		{
			if (playlist->name == x) {
				exist = true;
				cout << "Playlist " << playlist->name;
				currentPL = playlist->songinfo;
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
					cout << " || " << currentPL->artist << currentPL->title << currentPL->genre << currentPL->duration;
					currentPL = currentPL->nextsong;
				}
			}
			else
			{
				cout << " There are no songs in this playlist.";
			}
		}
		else
		{
			cout << " Playlist does not exist";
		}
	}
	main();
}

void remove_song() {	//Remove specific song from specific playlist
	bool exist = false;
	if (PLHead == NULL) {
		cout << "The are no playlist.\n";
	}
	else
	{
		Song* currentPL = NULL;
		Playlist* playlist = PLHead;
		string x;
		cout << "Enter playlist name: ";
		cin >> x;
		while (playlist != NULL)
		{
			if (playlist->name == x) {
				exist = true;
				cout << "Playlist " << playlist->name << " found.";
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
					cout << " || " << currentPL->artist << currentPL->title << currentPL->genre << currentPL->duration;
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
						cout << "Song " << i << " found.";
						break;
					}
					prev = todelete;
					todelete = todelete->nextsong;
				}
				if (found)
				{
					if (prev != NULL)
					{
						if (todelete->nextsong != NULL)
						{
							prev->nextsong = todelete->nextsong;
							todelete->nextsong->prevsong = prev;
							delete todelete;
						}
						else
						{
							prev->nextsong = todelete->nextsong;
							delete todelete;
						}
					}
					else
					{
						todelete = temp;
						temp = temp->nextsong;
						delete todelete;
						playlist->songinfo = temp;
					}
					cout << "Song deleted." << endl;
				}
				else {
					cout << "Song does not exist." << endl;
				}
			}
			else
			{
				cout << " There are no songs in this playlist.";
			}
		}
		else
		{
			cout << " Playlist does not exist";
		}
	}
	main();
}

void delete_playlist() {	//delete selected playlist
	bool exist = false;
	if (PLHead == NULL) {
		cout << "The are no playlist.\n";
	}
	else
	{
		Song* currentPL = NULL;
		Song* temp = NULL;
		Playlist* todelete = NULL;
		Playlist* playlist = PLHead;
		string x;
		cout << "Enter playlist name: ";
		cin >> x;
		while (playlist != NULL)
		{
			if (playlist->name == x) {
				exist = true;
				cout << "Playlist " << playlist->name << " found.";
				currentPL = playlist->songinfo;
				todelete = playlist;
				break;
			}
			playlist = playlist->nextplaylist;
		}
		if (exist)
		{
			Playlist* hold = todelete;
			while (currentPL != NULL)
			{
				temp = currentPL;
				currentPL = currentPL->nextsong;
				delete temp;
			}
			if (hold->prevplaylist == NULL) {
				if (todelete->nextplaylist != NULL) {
					hold->nextplaylist->prevplaylist = NULL;
					delete hold;
				}
				else
				{
					delete todelete;
					PLHead = NULL;
				}
			}
			else
			{
				todelete->prevplaylist->nextplaylist = todelete->nextplaylist;
				if (todelete->nextplaylist != NULL)
				{
					todelete->nextplaylist->prevplaylist = todelete->prevplaylist;
					delete todelete;
				}
			}
			cout << " Playlist and songs inside deleted.";
		}
		else
		{
			cout << " Playlist does not exist";
		}

	}
	main();
}


