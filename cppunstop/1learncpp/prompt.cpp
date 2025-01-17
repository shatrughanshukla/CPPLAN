/*

we're working on a project on music library system and we have created two features in it one for music and its initial code in which initial program will run like creation of Id and login and all music and song attributes are added to it the code is 

#include <bits/stdc++.h> // Or use specific includes
#include <memory>        // Include for shared_ptr

using namespace std;

// Function to print vector
template <typename T> void PrintVector(const vector<T>& arr) {
    for (const auto& i : arr) {
        cout << i << ", ";
    }
    cout << endl; // Newline for better formatting
}
// Media class
class Media {
protected:
    string Genre;
    string Title;
    int YearOfRelease;
    int Duration;
    int LikeCount;
    int Shares;
    double RatingCount;
    bool Liked;
    double YourRating;

public:
    Media(string g, string t, int y, int len, int l, int s, double r)
        : Genre(g), Title(t), YearOfRelease(y), Duration(len), LikeCount(l),
          Shares(s), RatingCount(r), Liked(false), YourRating(0.0) {}

    virtual void play() = 0; // Remove const
    virtual void DisplayShortInfo() const = 0;
    virtual void DisplayAllInfo() const = 0;
    virtual ~Media() {}
};
// Song class
class Song : public Media {
private:
    vector<string> Artists;
    string Album;
    string Composer;
    string Lyricist;
    string MusicLabel;

public:
    Song(string t, vector<string> art, int y, string alb, string g, int len,
         int l, int s, double r, string com, string lyr, string label)
        : Media(g, t, y, len, l, s, r), Artists(art), Album(alb), Composer(com),
          Lyricist(lyr), MusicLabel(label) {}

    void play() override {
        cout << "Playing song: " << Title << " by ";
        PrintVector(Artists);

        // Ask user if they liked the song
        char likeResponse;
        cout << "Did you like this song? (Yes/No): ";
        cin >> likeResponse;
        Liked = (likeResponse == 'Y' || likeResponse == 'y');

        // Ask for rating if liked
        if (Liked) {
            cout << "Rate the song out of 5: ";
            cin >> YourRating;
            // Ensure rating is within range
            if (YourRating < 0)
                YourRating = 0;
            else if (YourRating > 5)
                YourRating = 5;
        } else {
            YourRating = 0.0;
        }
    }

    void DisplayShortInfo() const override {
        cout << "Song: " << Title << ", Artists: ";
        PrintVector(Artists);
    }

    void DisplayAllInfo() const override {
        cout << "Song: " << Title << ", Artists: ";
        PrintVector(Artists);
        cout << "Genre: " << Genre << ", Album: " << Album
             << ", Likes: " << LikeCount << endl
             << "Ratings: " << RatingCount << ", Shares: " << Shares
             << ", Composer: " << Composer << endl
             << "Lyricist: " << Lyricist << ", MusicLabel: " << MusicLabel
             << ", Duration: " << Duration
             << " sec, Year Of Release: " << YearOfRelease << endl
             << "Liked: ";
        Liked ? cout << "Yes, Your Rating of this song: " << YourRating << endl
              : cout << "No" << endl;
    }

    friend class Manager;
};
// SongPlaylist class
class SongPlaylist {
private:
    string Name;
    bool IsPublic;
    vector<shared_ptr<Song>> Songs;

public:
    SongPlaylist(){};
    SongPlaylist(string name, bool isPublic) : Name(name), IsPublic(isPublic) {}

    void AddSong(shared_ptr<Song> song) { Songs.push_back(move(song)); }

    void DisplaySongs() const {
        if (Songs.empty()) {
            cout << "Playlist \"" << Name << "\" is empty." << endl;
            return;
        }
        cout << "Playlist: " << Name << (IsPublic ? " (Public)" : " (Private)")
             << endl;
        for (const auto& song : Songs) {
            song->DisplayShortInfo();
        }
    }

    bool IsAccessible() const { return IsPublic; }

    const string& GetName() const { return Name; }
    const vector<shared_ptr<Song>>& GetSongs() const { return Songs; }

    friend class Manager;
};

// Manager class
class Manager {
private:
    string UserName;
    string PassWord;
    vector<shared_ptr<Song>> StoredSongs;
    vector<SongPlaylist> UserSongPlaylists;

public:
    Manager(string U, string p) : UserName(U), PassWord(p) {}

    shared_ptr<Song> PlayASongByTitle(string t) {
        for (auto& it : StoredSongs) {
            if (it->Title == t) {
                it->play();
                return it;
            }
        }
        return nullptr;
    }
    bool WeGotTheArtist(const vector<string>& Artists, const string& Art) {
        for (const auto& Artist : Artists) {
            if (Artist == Art) {
                return true;
            }
        }
        return false;
    }
    shared_ptr<Song> PlayASongByArtist(const string& art) {
        for (const auto& song : StoredSongs) {
            if (WeGotTheArtist(song->Artists, art)) {
                song->play();
                return song; // Return song if found and played
            }
        }
        return nullptr;
    }
    shared_ptr<Song> PlayASongByAlbum(const string& Alb) {
        for (const auto& song : StoredSongs) {
            if (song->Album == Alb) {
                song->play();
                return song;
            }
        }
        return nullptr;
    }
    shared_ptr<Song> PlayASongByMusicL(const string& MusLab) {
        for (const auto& song : StoredSongs) {
            if (song->MusicLabel == MusLab) {
                song->play();
                return song;
            }
        }
        return nullptr;
    }
    void AddSongToLib(shared_ptr<Song> song) {
        StoredSongs.push_back(move(song));
        sort(StoredSongs.begin(), StoredSongs.end(),
             [](const shared_ptr<Song>& S1, const shared_ptr<Song>& S2) {
                 return S1->Title < S2->Title;
             });
    }

    void DisplayAllSongs() const {
        if (StoredSongs.empty()) {
            cout << "\nThe music library is empty." << endl;
            return;
        }
        for (const auto& song : StoredSongs) {
            song->DisplayShortInfo();
        }
    }

    SongPlaylist CreateSongPlaylist() {
        string name;
        int p;
        bool Pub;
        cout << "\nEnter playlist name: ";
        getline(cin, name);
        cout << "Private(1) or Public(2): ";
        cin >> p;
        Pub = (p == 2);
        SongPlaylist Play(name, Pub);
        UserSongPlaylists.emplace_back(Play);
        cout << "New Playlist Has Been Created Successfully";
        return Play;
    }
    void AddSongToSongPlaylist(SongPlaylist& SongPlaylist,
                               shared_ptr<Song> song) {
        SongPlaylist.AddSong(move(song));
        cout << "\nSong added to the Playlist \"" << SongPlaylist.GetName()
             << "\"." << endl;
        return;
    }
    void AddSongToSongPlaylist(const string& SongPlaylistName,
                               shared_ptr<Song> song) {
        for (auto& SongPlaylist : UserSongPlaylists) {
            if (SongPlaylist.Name == SongPlaylistName) {
                SongPlaylist.AddSong(move(song));
                cout << "\nSong added to the Playlist \"" << SongPlaylistName
                     << "\"." << endl;
                return;
            }
        }
        cout << "\nSongPlaylist \"" << SongPlaylistName << "\" not found."
             << endl;
    }
    int DisplayAllUserSongPlaylists() const {
        if (UserSongPlaylists.empty()) {
            cout << "\nNo UserSongPlaylists created yet." << endl;
            return 1;
        }
        for (const auto& SongPlaylist : UserSongPlaylists) {
            cout << SongPlaylist.GetName() << endl;
        }
        return 0;
    }

    void DeletePlaylist(const string& plName) {
        auto it = remove_if(UserSongPlaylists.begin(), UserSongPlaylists.end(),
                            [&](const SongPlaylist& playlist) {
                                return playlist.GetName() == plName;
                            });

        if (it != UserSongPlaylists.end()) {
            UserSongPlaylists.erase(it, UserSongPlaylists.end());
            cout << "\nPlaylist has been deleted successfully." << endl;
        } else {
            cout << "\nlaylist not found." << endl;
        }
    }

    friend class Accounts;
};

class Accounts {
private:
    vector<Manager> UserAccounts;

public:
    Manager CreateAccount() {
        string UserName;
        string PassWord;
        cout << "Enter user name: ";
        getline(cin, UserName);
        cout << "Enter a password: ";
        getline(cin, PassWord);
        Manager User = Manager(UserName, PassWord);
        this->UserAccounts.emplace_back(User);
        cout << "Account has been successfully created." << endl;
        return User;
    }
    int UserFound(string name) {
        int i = 0;
        for (auto it : UserAccounts) {
            if (it.UserName == name) {
                return i;
            }
            i++;
        }
        return -1;
    }
    bool CheckPass(string pass, int i) {
        if (UserAccounts[i].PassWord == pass)
            return true;
        return false;
    }
    Manager GetNewUser(int i) { return UserAccounts[i]; }
};

shared_ptr<Song> CreateSong() {
    string t;
    vector<string> art;
    string alb, g, com, lyr, label;
    int NumArt, y, len;

    cout << "\nADDING SONG TO LIBRARY" << endl;
    cout << "Enter the Title: ";
    getline(cin, t);
    cout << "Enter the No. of Artists: ";
    cin >> NumArt;
    cin.ignore(); // Clear newline character left in the input stream

    for (int i = 0; i < NumArt; i++) {
        cout << "Enter the name of ";
        if (i == 0) {
            cout << "1st ";
        } else if (i == 1) {
            cout << "2nd ";
        } else if (i == 2) {
            cout << "3rd ";
        } else {
            cout << i + 1 << "th ";
        }
        cout << "Artist: ";
        string artistName;
        getline(cin, artistName);
        art.push_back(artistName); // Add the artist name to the vector
    }

    cout << "Enter the Album: ";
    getline(cin, alb);
    cout << "Enter the Genre: ";
    getline(cin, g);
    cout << "Enter the Composer: ";
    getline(cin, com);
    cout << "Enter the Lyricist: ";
    getline(cin, lyr);
    cout << "Enter the Music Label: ";
    getline(cin, label);
    cout << "Enter the year of release: ";
    cin >> y;
    cout << "Enter the duration in seconds: ";
    cin >> len;
    cin.ignore(); // Clear newline character left in the input stream
    return make_shared<Song>(t, art, y, alb, g, len, 0, 0, 0.0, com, lyr,
                             label);
}

void PlaylistAdd(Manager& user1, shared_ptr<Song>& FoundSong) {
    char ch;
    cout << "\nAdd the Song to Lib(Y/N)?";
    cin >> ch;
    if (ch == 'Y') {
        while (true) {
            int choice1;
            cout << "1. Create a new SongPlaylist"
                 << "2. Add to existing SongPlaylists"
                 << "Enter your choice: ";
            cin >> choice1;
            cin.ignore();
            if (choice1 == 1) {
                SongPlaylist CurrentPlaylist = user1.CreateSongPlaylist();
                user1.AddSongToSongPlaylist(CurrentPlaylist, FoundSong);
            } else {
                string name;
                user1.DisplayAllUserSongPlaylists();
                cout << "Enter Playlist Name: ";
                getline(cin, name);
                user1.AddSongToSongPlaylist(name, FoundSong);
            }
            break;
        }
    }
}
// Function to display main menu options
void displayMainMenu() {
    cout << "----------------------------------------\n";
    cout << "1. Create New Account\n"
         << "2. Login To Existing Account\n"
         << "3. Exit\n"
         << "Enter your choice: ";
}
// Function to handle song-playing choices
void playSongMenu(Manager& user) {
    while (true) {
        int choice;
        cout << "----------------------------------------\n";
        cout << "1. Play By Title\n"
             << "2. Play By Artist\n"
             << "3. Play By Album\n"
             << "4. Play By Music Label\n"
             << "5. Go Back\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 5)
            break;
        if (choice == 6) {
            cout << "\nExiting Library...\n";
            exit(0);
        }

        string searchParam;
        cout << "\nEnter search term: ";
        getline(cin, searchParam);

        shared_ptr<Song> foundSong;
        switch (choice) {
        case 1:
            foundSong = user.PlayASongByTitle(searchParam);
            break;
        case 2:
            foundSong = user.PlayASongByArtist(searchParam);
            break;
        case 3:
            foundSong = user.PlayASongByAlbum(searchParam);
            break;
        case 4:
            foundSong = user.PlayASongByMusicL(searchParam);
            break;
        default:
            cout << "\nInvalid choice.\n";
            continue;
        }

        if (foundSong) {
            foundSong->play();
        } else {
            cout << "\nSong not found.\n";
        }
        PlaylistAdd(user, foundSong);
    }
}

// Function to handle playlist management choices
void managePlaylistMenu(Manager& user) {
    while (true) {
        int choice;
        cout << "----------------------------------------\n";
        cout << "1. Create New Playlist\n"
             << "2. Add Song to Existing Playlist\n"
             << "3. Delete Playlist\n"
             << "4. Go Back\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 4)
            break;
        if (choice == 5) {
            cout << "\nExiting Library...\n";
            exit(0);
        }
        SongPlaylist Current;
        int a;
        string playlistName, songTitle;
        switch (choice) {
        case 1:
            Current = user.CreateSongPlaylist();
            while (true) {
                char ch21;
                cout << "\nAdd song to this playist?(Y/N) :";
                cin >> ch21;
                if (ch21 == 'Y' or ch21 == 'y') {
                    string title;
                    cout << "Enter song name: ";
                    getline(cin, title);
                    shared_ptr<Song> FoundSong = user.PlayASongByTitle(title);
                    if (FoundSong == nullptr) {
                        cout << "Song not found.\n";
                    } else {
                        user.AddSongToSongPlaylist(Current, FoundSong);
                    }
                } else if (ch21 == 'N' or ch21 == 'n') {
                    break;
                } else {
                    cout << "\nYou've entered wrong answer. Enter Y for yes and N for no.\n";
                }
            }
            break;

        case 2:
            cout << "\nDisplaying existing playlists: \n";
            a = user.DisplayAllUserSongPlaylists();
            if (a) {
                break;
            }
            cout << "Enter playlist name: ";
            getline(cin, playlistName);
            cout << "Enter song title to add: ";
            getline(cin, songTitle);
            if (auto song = user.PlayASongByTitle(songTitle)) {
                user.AddSongToSongPlaylist(playlistName, song);
                cout << "Added '" << songTitle << "' to " << playlistName
                     << "\n";
            } else {
                cout << "Song not found.\n";
            }
            break;

        case 3:
            cout << "\nDisplaying existing playlists: \n";
            a = user.DisplayAllUserSongPlaylists();
            if (a) {
                cout << "Nothing to delete\n";
                break;
            }
            cout << endl;
            cout << "Enter playlist name to delete: ";
            getline(cin, playlistName);
            user.DeletePlaylist(playlistName);
            cout << "Deleted playlist: " << playlistName << "\n";
            break;

        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

// Function to handle main user session actions
void userSession(Manager& user) {
    while (true) {
        cout << "----------------------------------------\n";
        int choice;
        cout << "1. Play a Song\n"
             << "2. Manage Playlist\n"
             << "3. Add Song to Library\n"
             << "4. Display All Songs\n"
             << "5. Display Playlists\n"
             << "6. Log Out\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            playSongMenu(user);
            break;
        case 2:
            managePlaylistMenu(user);
            break;
        case 3: {
            auto newSong =
                CreateSong(); // Assuming CreateSong() is defined elsewhere
            user.AddSongToLib(newSong);
            break;
        }
        case 4:
            user.DisplayAllSongs();
            break;
        case 5:
            user.DisplayAllUserSongPlaylists();
            break;
        case 6:
            return;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

int main() {
    Accounts device;
    cout << "Welcome to the Library Management System\n";

    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Manager newUser = device.CreateAccount();
            userSession(newUser);
        } else if (choice == 2) {
            string username, password;
            cout << "Enter Username: ";
            getline(cin, username);

            int userIndex = device.UserFound(username);
            if (userIndex == -1) {
                cout << "User not found.\n";
                continue;
            }

            cout << "Enter Password: ";
            getline(cin, password);

            if (device.CheckPass(password, userIndex)) {
                cout << "Login successful.\n";
                Manager existingUser = device.GetNewUser(userIndex);
                userSession(existingUser);
            } else {
                cout << "Incorrect password.\n";
            }
        } else if (choice == 3) {
            cout << "Thank you for using the Library Management System.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

analyse this code and don't change and remove any attributes and functions, we have to merge this code with a code on git hub the second code to be merge with this is for podcasts, the code is 

#include <bits/stdc++.h> // Or use specific includes
#include <memory>        // Include for shared_ptr

using namespace std;

// Function to print vector
template <typename T> void PrintVector(const vector<T>& arr) {
    for (const auto& i : arr) {
        cout << i << ", ";
    }
    cout << endl; // Newline for better formatting
}
// Media class
class Media {
protected:
    string Genre;
    string Title;
    int YearOfRelease;
    int Duration;
    int LikeCount;
    int Shares;
    double RatingCount;
    bool Liked;
    double YourRating;

public:
    Media(string g, string t, int y, int len, int l, int s, double r)
        : Genre(g), Title(t), YearOfRelease(y), Duration(len), LikeCount(l),
          Shares(s), RatingCount(r), Liked(false), YourRating(0.0) {}

    virtual void play() = 0; // Remove const
    virtual void DisplayShortInfo() const = 0;
    virtual void DisplayAllInfo() const = 0;
    virtual ~Media() {}
};
// Song class
class Song : public Media {
private:
    vector<string> Artists;
    string Album;
    string Composer;
    string Lyricist;
    string MusicLabel;

public:
    Song(string t, vector<string> art, int y, string alb, string g, int len,
         int l, int s, double r, string com, string lyr, string label)
        : Media(g, t, y, len, l, s, r), Artists(art), Album(alb), Composer(com),
          Lyricist(lyr), MusicLabel(label) {}

    void play() override {
        cout << "Playing song: " << Title << " by ";
        PrintVector(Artists);

        // Ask user if they liked the song
        char likeResponse;
        cout << "Did you like this song? (Yes/No): ";
        cin >> likeResponse;
        Liked = (likeResponse == 'Y' || likeResponse == 'y');

        // Ask for rating if liked
        if (Liked) {
            cout << "Rate the song out of 5: ";
            cin >> YourRating;
            // Ensure rating is within range
            if (YourRating < 0)
                YourRating = 0;
            else if (YourRating > 5)
                YourRating = 5;
        } else {
            YourRating = 0.0;
        }
    }

    void DisplayShortInfo() const override {
        cout << "Song: " << Title << ", Artists: ";
        PrintVector(Artists);
    }

    void DisplayAllInfo() const override {
        cout << "Song: " << Title << ", Artists: ";
        PrintVector(Artists);
        cout << "Genre: " << Genre << ", Album: " << Album
             << ", Likes: " << LikeCount << endl
             << "Ratings: " << RatingCount << ", Shares: " << Shares
             << ", Composer: " << Composer << endl
             << "Lyricist: " << Lyricist << ", MusicLabel: " << MusicLabel
             << ", Duration: " << Duration
             << " sec, Year Of Release: " << YearOfRelease << endl
             << "Liked: ";
        Liked ? cout << "Yes, Your Rating of this song: " << YourRating << endl
              : cout << "No" << endl;
    }

    friend class Manager;
};
// SongPlaylist class
class SongPlaylist {
private:
    string Name;
    bool IsPublic;
    vector<shared_ptr<Song>> Songs;

public:
    SongPlaylist(){};
    SongPlaylist(string name, bool isPublic) : Name(name), IsPublic(isPublic) {}

    void AddSong(shared_ptr<Song> song) { Songs.push_back(move(song)); }

    void DisplaySongs() const {
        if (Songs.empty()) {
            cout << "Playlist \"" << Name << "\" is empty." << endl;
            return;
        }
        cout << "Playlist: " << Name << (IsPublic ? " (Public)" : " (Private)")
             << endl;
        for (const auto& song : Songs) {
            song->DisplayShortInfo();
        }
    }

    bool IsAccessible() const { return IsPublic; }

    const string& GetName() const { return Name; }
    const vector<shared_ptr<Song>>& GetSongs() const { return Songs; }

    friend class Manager;
};

// Manager class
class Manager {
private:
    string UserName;
    string PassWord;
    vector<shared_ptr<Song>> StoredSongs;
    vector<SongPlaylist> UserSongPlaylists;

public:
    Manager(string U, string p) : UserName(U), PassWord(p) {}

    shared_ptr<Song> PlayASongByTitle(string t) {
        for (auto& it : StoredSongs) {
            if (it->Title == t) {
                it->play();
                return it;
            }
        }
        return nullptr;
    }
    bool WeGotTheArtist(const vector<string>& Artists, const string& Art) {
        for (const auto& Artist : Artists) {
            if (Artist == Art) {
                return true;
            }
        }
        return false;
    }
    shared_ptr<Song> PlayASongByArtist(const string& art) {
        for (const auto& song : StoredSongs) {
            if (WeGotTheArtist(song->Artists, art)) {
                song->play();
                return song; // Return song if found and played
            }
        }
        return nullptr;
    }
    shared_ptr<Song> PlayASongByAlbum(const string& Alb) {
        for (const auto& song : StoredSongs) {
            if (song->Album == Alb) {
                song->play();
                return song;
            }
        }
        return nullptr;
    }
    shared_ptr<Song> PlayASongByMusicL(const string& MusLab) {
        for (const auto& song : StoredSongs) {
            if (song->MusicLabel == MusLab) {
                song->play();
                return song;
            }
        }
        return nullptr;
    }
    void AddSongToLib(shared_ptr<Song> song) {
        StoredSongs.push_back(move(song));
        sort(StoredSongs.begin(), StoredSongs.end(),
             [](const shared_ptr<Song>& S1, const shared_ptr<Song>& S2) {
                 return S1->Title < S2->Title;
             });
    }

    void DisplayAllSongs() const {
        if (StoredSongs.empty()) {
            cout << "\nThe music library is empty." << endl;
            return;
        }
        for (const auto& song : StoredSongs) {
            song->DisplayShortInfo();
        }
    }

    SongPlaylist CreateSongPlaylist() {
        string name;
        int p;
        bool Pub;
        cout << "\nEnter playlist name: ";
        getline(cin, name);
        cout << "Private(1) or Public(2): ";
        cin >> p;
        Pub = (p == 2);
        SongPlaylist Play(name, Pub);
        UserSongPlaylists.emplace_back(Play);
        cout << "New Playlist Has Been Created Successfully";
        return Play;
    }
    void AddSongToSongPlaylist(SongPlaylist& SongPlaylist,
                               shared_ptr<Song> song) {
        SongPlaylist.AddSong(move(song));
        cout << "\nSong added to the Playlist \"" << SongPlaylist.GetName()
             << "\"." << endl;
        return;
    }
    void AddSongToSongPlaylist(const string& SongPlaylistName,
                               shared_ptr<Song> song) {
        for (auto& SongPlaylist : UserSongPlaylists) {
            if (SongPlaylist.Name == SongPlaylistName) {
                SongPlaylist.AddSong(move(song));
                cout << "\nSong added to the Playlist \"" << SongPlaylistName
                     << "\"." << endl;
                return;
            }
        }
        cout << "\nSongPlaylist \"" << SongPlaylistName << "\" not found."
             << endl;
    }
    int DisplayAllUserSongPlaylists() const {
        if (UserSongPlaylists.empty()) {
            cout << "\nNo UserSongPlaylists created yet." << endl;
            return 1;
        }
        for (const auto& SongPlaylist : UserSongPlaylists) {
            cout << SongPlaylist.GetName() << endl;
        }
        return 0;
    }

    void DeletePlaylist(const string& plName) {
        auto it = remove_if(UserSongPlaylists.begin(), UserSongPlaylists.end(),
                            [&](const SongPlaylist& playlist) {
                                return playlist.GetName() == plName;
                            });

        if (it != UserSongPlaylists.end()) {
            UserSongPlaylists.erase(it, UserSongPlaylists.end());
            cout << "\nPlaylist has been deleted successfully." << endl;
        } else {
            cout << "\nlaylist not found." << endl;
        }
    }

    friend class Accounts;
};

class Accounts {
private:
    vector<Manager> UserAccounts;

public:
    Manager CreateAccount() {
        string UserName;
        string PassWord;
        cout << "Enter user name: ";
        getline(cin, UserName);
        cout << "Enter a password: ";
        getline(cin, PassWord);
        Manager User = Manager(UserName, PassWord);
        this->UserAccounts.emplace_back(User);
        cout << "Account has been successfully created." << endl;
        return User;
    }
    int UserFound(string name) {
        int i = 0;
        for (auto it : UserAccounts) {
            if (it.UserName == name) {
                return i;
            }
            i++;
        }
        return -1;
    }
    bool CheckPass(string pass, int i) {
        if (UserAccounts[i].PassWord == pass)
            return true;
        return false;
    }
    Manager GetNewUser(int i) { return UserAccounts[i]; }
};

shared_ptr<Song> CreateSong() {
    string t;
    vector<string> art;
    string alb, g, com, lyr, label;
    int NumArt, y, len;

    cout << "\nADDING SONG TO LIBRARY" << endl;
    cout << "Enter the Title: ";
    getline(cin, t);
    cout << "Enter the No. of Artists: ";
    cin >> NumArt;
    cin.ignore(); // Clear newline character left in the input stream

    for (int i = 0; i < NumArt; i++) {
        cout << "Enter the name of ";
        if (i == 0) {
            cout << "1st ";
        } else if (i == 1) {
            cout << "2nd ";
        } else if (i == 2) {
            cout << "3rd ";
        } else {
            cout << i + 1 << "th ";
        }
        cout << "Artist: ";
        string artistName;
        getline(cin, artistName);
        art.push_back(artistName); // Add the artist name to the vector
    }

    cout << "Enter the Album: ";
    getline(cin, alb);
    cout << "Enter the Genre: ";
    getline(cin, g);
    cout << "Enter the Composer: ";
    getline(cin, com);
    cout << "Enter the Lyricist: ";
    getline(cin, lyr);
    cout << "Enter the Music Label: ";
    getline(cin, label);
    cout << "Enter the year of release: ";
    cin >> y;
    cout << "Enter the duration in seconds: ";
    cin >> len;
    cin.ignore(); // Clear newline character left in the input stream
    return make_shared<Song>(t, art, y, alb, g, len, 0, 0, 0.0, com, lyr,
                             label);
}

void PlaylistAdd(Manager& user1, shared_ptr<Song>& FoundSong) {
    char ch;
    cout << "\nAdd the Song to Lib(Y/N)?";
    cin >> ch;
    if (ch == 'Y') {
        while (true) {
            int choice1;
            cout << "1. Create a new SongPlaylist"
                 << "2. Add to existing SongPlaylists"
                 << "Enter your choice: ";
            cin >> choice1;
            cin.ignore();
            if (choice1 == 1) {
                SongPlaylist CurrentPlaylist = user1.CreateSongPlaylist();
                user1.AddSongToSongPlaylist(CurrentPlaylist, FoundSong);
            } else {
                string name;
                user1.DisplayAllUserSongPlaylists();
                cout << "Enter Playlist Name: ";
                getline(cin, name);
                user1.AddSongToSongPlaylist(name, FoundSong);
            }
            break;
        }
    }
}
// Function to display main menu options
void displayMainMenu() {
    cout << "----------------------------------------\n";
    cout << "1. Create New Account\n"
         << "2. Login To Existing Account\n"
         << "3. Exit\n"
         << "Enter your choice: ";
}
// Function to handle song-playing choices
void playSongMenu(Manager& user) {
    while (true) {
        int choice;
        cout << "----------------------------------------\n";
        cout << "1. Play By Title\n"
             << "2. Play By Artist\n"
             << "3. Play By Album\n"
             << "4. Play By Music Label\n"
             << "5. Go Back\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 5)
            break;
        if (choice == 6) {
            cout << "\nExiting Library...\n";
            exit(0);
        }

        string searchParam;
        cout << "\nEnter search term: ";
        getline(cin, searchParam);

        shared_ptr<Song> foundSong;
        switch (choice) {
        case 1:
            foundSong = user.PlayASongByTitle(searchParam);
            break;
        case 2:
            foundSong = user.PlayASongByArtist(searchParam);
            break;
        case 3:
            foundSong = user.PlayASongByAlbum(searchParam);
            break;
        case 4:
            foundSong = user.PlayASongByMusicL(searchParam);
            break;
        default:
            cout << "\nInvalid choice.\n";
            continue;
        }

        if (foundSong) {
            foundSong->play();
        } else {
            cout << "\nSong not found.\n";
        }
        PlaylistAdd(user, foundSong);
    }
}

// Function to handle playlist management choices
void managePlaylistMenu(Manager& user) {
    while (true) {
        int choice;
        cout << "----------------------------------------\n";
        cout << "1. Create New Playlist\n"
             << "2. Add Song to Existing Playlist\n"
             << "3. Delete Playlist\n"
             << "4. Go Back\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 4)
            break;
        if (choice == 5) {
            cout << "\nExiting Library...\n";
            exit(0);
        }
        SongPlaylist Current;
        int a;
        string playlistName, songTitle;
        switch (choice) {
        case 1:
            Current = user.CreateSongPlaylist();
            while (true) {
                char ch21;
                cout << "\nAdd song to this playist?(Y/N) :";
                cin >> ch21;
                if (ch21 == 'Y' or ch21 == 'y') {
                    string title;
                    cout << "Enter song name: ";
                    getline(cin, title);
                    shared_ptr<Song> FoundSong = user.PlayASongByTitle(title);
                    if (FoundSong == nullptr) {
                        cout << "Song not found.\n";
                    } else {
                        user.AddSongToSongPlaylist(Current, FoundSong);
                    }
                } else if (ch21 == 'N' or ch21 == 'n') {
                    break;
                } else {
                    cout << "\nYou've entered wrong answer. Enter Y for yes and N for no.\n";
                }
            }
            break;

        case 2:
            cout << "\nDisplaying existing playlists: \n";
            a = user.DisplayAllUserSongPlaylists();
            if (a) {
                break;
            }
            cout << "Enter playlist name: ";
            getline(cin, playlistName);
            cout << "Enter song title to add: ";
            getline(cin, songTitle);
            if (auto song = user.PlayASongByTitle(songTitle)) {
                user.AddSongToSongPlaylist(playlistName, song);
                cout << "Added '" << songTitle << "' to " << playlistName
                     << "\n";
            } else {
                cout << "Song not found.\n";
            }
            break;

        case 3:
            cout << "\nDisplaying existing playlists: \n";
            a = user.DisplayAllUserSongPlaylists();
            if (a) {
                cout << "Nothing to delete\n";
                break;
            }
            cout << endl;
            cout << "Enter playlist name to delete: ";
            getline(cin, playlistName);
            user.DeletePlaylist(playlistName);
            cout << "Deleted playlist: " << playlistName << "\n";
            break;

        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

// Function to handle main user session actions
void userSession(Manager& user) {
    while (true) {
        cout << "----------------------------------------\n";
        int choice;
        cout << "1. Play a Song\n"
             << "2. Manage Playlist\n"
             << "3. Add Song to Library\n"
             << "4. Display All Songs\n"
             << "5. Display Playlists\n"
             << "6. Log Out\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            playSongMenu(user);
            break;
        case 2:
            managePlaylistMenu(user);
            break;
        case 3: {
            auto newSong =
                CreateSong(); // Assuming CreateSong() is defined elsewhere
            user.AddSongToLib(newSong);
            break;
        }
        case 4:
            user.DisplayAllSongs();
            break;
        case 5:
            user.DisplayAllUserSongPlaylists();
            break;
        case 6:
            return;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

int main() {
    Accounts device;
    cout << "Welcome to the Library Management System\n";

    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Manager newUser = device.CreateAccount();
            userSession(newUser);
        } else if (choice == 2) {
            string username, password;
            cout << "Enter Username: ";
            getline(cin, username);

            int userIndex = device.UserFound(username);
            if (userIndex == -1) {
                cout << "User not found.\n";
                continue;
            }

            cout << "Enter Password: ";
            getline(cin, password);

            if (device.CheckPass(password, userIndex)) {
                cout << "Login successful.\n";
                Manager existingUser = device.GetNewUser(userIndex);
                userSession(existingUser);
            } else {
                cout << "Incorrect password.\n";
            }
        } else if (choice == 3) {
            cout << "Thank you for using the Library Management System.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

merge both these codes as both these codes are from another branches and we have to merge these together in main branch merge these codes for main branch while keeping all the attributes and functionalities as they are include all the songs and podcasts present inside them.

In the beginning the code should give this output Welcome to the Library Management System
----------------------------------------
1. Create New Account
2. Login To Existing Account
3. Exit
Enter your choice: 
like it do in the first code I've given to you and then provide a interface to choose between song and podcast then, when user will switch into podcast all the functions concepts and attributes present in code 2 should work similar like they do now strictly saying they should work like they do now, similarly when user chooses songs the code should work the same like it do now after creation of account.
strictly saying don't remove or change any attributes and function.


*/