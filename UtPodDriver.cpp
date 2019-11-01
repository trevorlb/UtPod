/* UtPodDriver.cpp
Demo Driver for the UtPod.

Trevor Barrett
EE 312 11/1/18

This is a basic driver for the UtPod
It test the functions used by UtPod.cpp.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("ArtistAAA", "SongBBB", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("ArtistAAA", "SongBBC", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("ArtistAAA", "SongBBC", 10);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("ArtistCCC", "SongCCC", 12);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    
    Song s5("ArtistCCC", "SongCCC", 500);
    result = t.addSong(s5);
    cout << "result of song that exceeds memory = " << result << endl;
       
    t.showSongList();
    cout << "Sorting List:\n";
    t.sortSongList();
    t.showSongList();
    cout << "Shuffling UTPod:\n";
    t.shuffle();
    t.showSongList();
    cout <<"Shuffling Again:\n";
    t.shuffle();
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "deleting result with empty list: = " << result << endl;  
   
    result = t.addSong(s1);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "Clearing Memory\n";
    t.clearMemory();
 
    result = t.addSong(s1);
    cout << "add result = " << result << endl;
 
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    

}
