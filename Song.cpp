//Author: Trevor Barrett
//Date: 11/1/2019
//Implements functions from Song.h

#include "Song.h"
#include <iostream>
using namespace std;

   Song::Song(string _artist, string _title, int _size){
      title = _title;
      artist = _artist;
      size = _size;
   }

   Song::Song(){
      title = "";
      artist = "";
      size = 0;
   } 

   Song::~Song(){
      //cout << "destructor called\n";
   }
   string Song::getTitle() const{
      return title;
   }
   string Song::getArtist() const{
      return artist;
   }
   int Song::getSize() const{
      return size;
   }

   void Song::setTitle(string title) {
      this->title = title;   
   }
   void Song::setArtist(string artist){
       this->artist = artist;
   } 
   void Song::setSize(int size){
      this->size = size;
   }
   
   //First it checks the artists of the song
   //Second it checks the title of the song
   //Third it checks the size of the song
   //Returns true if the attributes are less
   bool Song::operator >(Song const &rhs){
      if (artist == rhs.artist){
         if (title == rhs.title){
            return (size > rhs.size);
         }
         else{
            return (title > rhs.title);
         }
      }
      else{
         return (artist > rhs.artist); 
      }
   }
   
   //Does the opposite of the > operator
   //Returns true if it's less than
   bool Song::operator <(Song const &rhs){
      if (artist == rhs.artist){
         if (title == rhs.title){
            return (size < rhs.size);
         }
         else{
            return (title < rhs.title);
         }
      }
      else{
         return (artist < rhs.artist); 
      }
   }
   
   //Checks if all the attributes of a song are equal to each other
   //Returns true if they are all equal  
   bool Song::operator ==(Song const &rhs){
      return (artist == rhs.artist &&
              title == rhs.title &&
              size == size);
   }



