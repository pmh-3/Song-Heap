//Heitkemper,Peter
//songheap.h
//3/1/21

//----------------------------------------------------------------------
//DESCRIPTION: The program below stores the Billboard 100 in a minimum heap
//using a dynamic array implementation. The program automatically reads in
//song information from a csv file and inputs into heap, doubling array size as needed.
//The title is used as the key and the songs are sorted alphabetically such that A<B<C. 

//ASSUMPTIONS: This program assumes that no two inputed songs have the same title.
//The heap will not be printed in alphabetical order as that is not a trait of 
//this data structure.

//SOURCES: Input file, top1.csv, was provided by Proffessor Kong.
//----------------------------------------------------------------------                                          

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SongHeap {
public:                                                                                         
  //default constructor
  SongHeap();
  //destructor
 ~SongHeap();                                                                                       
 //copy constructor
  SongHeap(const SongHeap& source);                                                                
  //copy assignment
  SongHeap& operator = (const SongHeap& source) {
    return *this;
  }

// description: This insert function takes in the title and artist of a song, 
  //as well as the date the song appeared on Billboard 100.
  //If array becomes full, a resize is performed, doubling the capacity.
  //if song is already in heap, the frequency and dates array are updated.
// preconditions: Title must have each word capitilized. 
// postconditions: Displays message showing array resizing.
  void insert(string title, string artist, string date);

// description: This function returns the title with the lowest alphabetical order A<B<C. 
  //The song at the root is deleted and the heap is updated.
// preconditions: There must be elements in songlist else error message shown.
// postconditions: Can be performed for as many elements in heap.
  string deleteMin();

 // description: Prints array position and title of song from array[1] on.
// preconditions: Function cannot print an empty array.
// postconditions: Does not alter heap in any way.                     
  void print();

 // description: Prints information of inputted song:
  //title, artist, number of appearances, and date.
 // preconditions: Title must match exactly.
 // postconditions: returns false if title is not in heap, true otherwise.
  bool printSong(string title);

private:                                                                                     
  struct Song {
    string title; //used as key
    string artist;
    string dates[52]; //filled starting from index 0
    int frequency; //should match # of elements in dates                           
  };

  Song* songlist;
  int size = 0;
  int cap = 5;    //Array capacity                                               
                                                              
  Song s;

 //HELPER FUNCTIONS---------------------------------------------------

 // description: Determines if song is in heap.
 // preconditions: Title must match exactly.
 // postconditions: returns index of song if in heap, else -1.
  int contains(string title);

// description: Doubles size of array and coppies over 
  //all pre-existing values in same location.
// preconditions: Doubles initial capacity every time called.
// postconditions: May create unused space in array.
  void reSize();

  void copy(const SongHeap& source);
  // Parent = i / 2
  int p(int i) { return i >> 1; };  
  //Left Child = i*2
  int lc(int i) { return i << 1; }; 
  // Right Child = i*2 +1
  int rc(int i) { return (i << 1) + 1;}; 
};