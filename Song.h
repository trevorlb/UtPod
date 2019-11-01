/* Song.h

   Author: Trevor Barrett
   Date: 11/1/2019
   This is the header file for the Song class.
   These functions are implemented by Song.cpp.
*/

#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song {

   //The three attributes of a song object
   private:
      string title;
      string artist;
      int size;
 
   public:
      Song(string artist, string title, int size);
      Song();
   //Returns the title of a song object
   string getTitle() const;

   //Returns the artist of a song object
   string getArtist() const;

   //Returns the size of a song object
   int getSize() const;

   //Input: String title of a song
   //Changes the title of a song object to t
   void setTitle(string t);

   //Input: String artist of a song
   //Changes the artist of a song object to a
   void setArtist(string a);

   //Input: int size of a song
   //Changes the size of a song
   void setSize(int s);
   
   //Overloads the >,<,== operator so songs can be compared
   bool operator >(Song const &rhs);
   bool operator <(Song const &rhs);
   bool operator ==(Song const &rhs);

   ~Song();
};

#endif

