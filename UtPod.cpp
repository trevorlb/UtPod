//Author: Trevor Barrett
//Date: 11/1/2019
//Implements the functions of the UtPod.h to


#include "UtPod.h"
#include "Song.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

   UtPod::UtPod(){
      memSize = MAX_MEMORY;
      songs = NULL;
   }
   
   //Sets the memSize to size if size
   //is greater than zero or less than MAX_MEMORY
   UtPod::UtPod(int size){
      if (size > MAX_MEMORY || size <= 0){
         memSize = MAX_MEMORY;
      }
      else{
         memSize = size;
      }
      songs = NULL;
   }

   UtPod::~UtPod(){
      //cout << "destructor called\n";
   }

   //checks the remaining memory to make sure the new song will not exceed the memSize
   //Creates a new SongNode to be added to the linked list
   int UtPod::addSong(Song const &s){
      if (getRemainingMemory() - (s).getSize() < 0){
         return NO_MEMORY;
      }
      else{
         SongNode* temp = new SongNode();
         temp -> s = s;
         temp -> next = songs; 
         songs = temp;
         (*temp).s.setSize(s.getSize()); 
         return SUCCESS;
      }  
   }

   //Removes a song that matches the input song
   //Deletes the SongNode that matches the song
   //Traverses the linked list looking for a matching song
   int UtPod::removeSong(Song const &s){
      SongNode *current = songs;
      SongNode *previous = songs;
      while ((current) != NULL){
         if ((current) -> s == s){
            if (current == songs){
               songs = songs -> next;
            }
            else{
            previous -> next = current -> next;
            delete (current);
            return SUCCESS; 
            } 
            delete(current);
            return SUCCESS; 
         }
         previous = current;
         current = current -> next;
      }
         return NOT_FOUND;
        
   }

   //Using the ctime and cstdlib to create a random integer
   //The random integers are then used to swap two values in the linked list
   void UtPod::shuffle(){
      unsigned int currentTime = (unsigned)time(0);
      srand(currentTime);
      int numSongs = 0;
      int rand1 = 0;      
      int rand2 = 0;
      SongNode *temp = songs;
      Song swap;
      while (temp != NULL){
         numSongs++;
         temp = temp -> next;
      }   
      for (int k = 0; k < (5 * numSongs); k++){
         SongNode *s1 = songs;
         SongNode *s2 = songs;
         rand1 = rand() % numSongs;		//ensures that random number will not exceed
         rand2 = rand() % numSongs;             //the total number of songs
         for (int i = 0; i < rand1; i++){
            s1 = s1 -> next;
         }
         for (int j = 0; j < rand2; j++){
            s2 = s2 -> next;
         }
         swap = s1 -> s;			//uses temporary song to swap two random songs
         s1 -> s = s2 -> s;
         s2 -> s = swap;
      }
   }

   
   //traverses the linked list and prints each song object in the list
   //with the correct formate
   void UtPod::showSongList(){
      SongNode *temp = songs;
      if (temp == NULL){
         cout << '\n';
      }      
      while (temp != NULL){
         cout << (temp -> s).getTitle() << ", ";
         cout << (temp -> s).getArtist() << ", ";
         cout << (temp -> s).getSize() << '\n';
         temp = temp -> next;
      } 
   }

   //Uses a nested for loop to check each linked list node to each other
   //Swaps the songs of two nodes if one is greater than the other
   void UtPod::sortSongList(){
      SongNode *current;
      SongNode *next;
      Song swap;
      for (current = songs; current != NULL; current = current -> next){
         for (next = current -> next; next != NULL; next = next -> next){
            if (current -> s > next -> s){
               swap = current -> s;
               current -> s = next -> s;
               next -> s = swap;
            }
         }
      }
   }

   void UtPod::clearMemory(){
      SongNode *current = songs;
      SongNode *next = songs;
      while(current != NULL){
         delete(current);
         current = next -> next;
         next = next -> next;
      }
      songs = NULL;
   }

   //traverses the linked list to add the size of each node into memTotal
   //returns the total remaining memory
   int UtPod::getRemainingMemory(){
      int memTotal = 0;
      SongNode *temp = songs;
      while (temp != NULL){
         memTotal += (temp -> s).getSize();
         temp = temp -> next;
      }
      return (memSize - memTotal);

   }




