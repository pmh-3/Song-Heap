//Peter Heitkemper
//songheap.cpp
//SongHeap class implementation

#include "songheap.h"

//Default constructor
SongHeap::SongHeap() {
  //dynamic memory allocation with starting capacity of 5
  songlist = new Song[5];
}


SongHeap::~SongHeap() {                                                                         
  delete[] songlist; //Dynamic memory deallocation
  songlist = nullptr;
}

///*
SongHeap::SongHeap(const SongHeap& source) {                                                                
  copy(source);
}

void SongHeap::copy(const SongHeap& source) {
  this->size = source.size;
  this->cap = source.cap;

  //copy over each element
  for (int i = 1; i < size+1; i++) {
    if (source.songlist[i].title != "") {
      for (int j = 0; j < source.songlist[i].frequency; j++) {
        //insert every instance
        string title = source.songlist[i].title;
        string artist = source.songlist[i].artist;
        string date = source.songlist[i].dates[j];
        insert(title,artist,date);
      }
    }
  }
 // cout << "Operation success" << endl;
}

void SongHeap::insert(string title, string artist, string date) {
  if (size >=cap ) {
    cout << "The array is full. Resizing array to " << cap*2 << " elements." << endl;
    reSize();
  }
  //check if song is already in heap
  if (contains(title) != -1) {
    //find index of existing song
    int index = contains(title);
    //update frequency and dates array of existing song
    songlist[index].dates[songlist[index].frequency++] = date;
    return;
  }else {
    //Create new song
    Song s;
    s.title = title;
    s.artist = artist;
    s.dates[0] = date;    //default constructor
    s.frequency = 1;

    //create hole index at next available element
    int hole = ++size - 1;                          
    songlist[0] = s;      //holding dock
    //percolate up
    while (size != 1 && s.title < songlist[p(hole)].title) {
      songlist[hole] = songlist[p(hole)];
      hole = p(hole);
    }
   //Place new song in calculated location
    songlist[hole] = songlist[0];
  }
}

void SongHeap::reSize() {
  //create new Song list with doubled capacity
  Song* tmpList = new Song[cap*2];
  //copy over each element
  for (int i = 0; i < cap; i++) {
    tmpList[i] = songlist[i];
  }
  //update new capacity
  cap *= 2;
  //deallocation
  delete [] songlist;
  songlist = tmpList;
}

void SongHeap::print() {
  //print each element of array
  for (int i = 1; i < size; i++) {
    cout << "arr["<<i<<"] = "<<songlist[i].title << endl;
    //cout << songlist[i].artist << endl;
  }
}

bool SongHeap::printSong(string title) {
  //check if song is in heap
  int index = contains(title);
  if (index == -1) {
    //song is not in array
    return false;
  }else {
    cout << "Title: " << songlist[index].title << endl;
    cout << "Artist: " << songlist[index].artist << endl;
    cout << "Appeared on the Billboard chart " << songlist[index].frequency << " time(s) on: " << endl;
    //print every date occurance
    for (int i = 0; i < songlist[index].frequency; i++) {   
      cout << songlist[index].dates[i] << endl;
    }
    //song is in array
    return true;
  }
}

string SongHeap::deleteMin() {                                                                                        //are outputs inside functions acceptable?
  if (songlist[1].title == "") {
    cout << "Heap is empty!" << endl;
    return "";
  }
  //store minimum value
  string min = songlist[1].title;
  cout << endl;
  cout << endl;
  cout << "Removing the min value. " << min << " has been removed." << endl;
  
  //replace root with last element of array
  songlist[1] = songlist[size-1];
  size--;
  int hole = 1;
  //percolate down
  int child = 0;
  Song tmp = songlist[hole];
  bool bubDown = true;
  //run until correct location is found or end of heap is reached
  while (bubDown && lc(hole) <= size) {
    child = lc(hole);
    if (child != size && songlist[child + 1].title < songlist[child].title)
      ++child;
    if (songlist[child].title < tmp.title) {
      songlist[hole] = songlist[child];
    }
    else
      bubDown = false;
    if (bubDown) hole = child;
  }
  songlist[hole] = tmp;
  return min;
}

int SongHeap::contains(string title) {
  //loop through all elements of array
  for (int i = 1; i < size; i++) {
    if (songlist[i].title == title) {
      return i; //return index of found song
    }
  }
  return -1;  //song not found
}
