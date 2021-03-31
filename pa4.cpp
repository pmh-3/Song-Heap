//Peter Heitkemper
//pa4.cpp
//3-1-21
//Driver file for SongHeap class

#include "songheap.h"

// description: Function to capitalize each word of a phrase.
// preconditions: Does not discriminate between words.
//"a" will be capitilzed even if not usually capitilize in a title.
//Does not work with "123numbers".
// postconditions:uses toupper() to capitlize letter at the start or directly after space.
//no change if phrase is already capitilized.say so -> Say So
string titlize(string phrase);

int main(){
	//change input file with fileName. Place in local directory or include file path.																		//What should constructor/destructor testing look like?
	string fileName = "top1.csv";																																										//can you provide PA solutions?
	string first, title, artist, date, titleIn;	//string input parameters																						//How rigourous should I comment

	SongHeap s;														//Default constructor

	/*
	//Begin Testing----------------------------------------------------
	//SongHeap s1;
	//s1.insert("Test", "Test", "Test");
	//cout << "Printing heap" << endl;
	//s1.print();
	//SongHeap s2 = s;											//copy constructor called
	cout << "Printing copied heap" << endl;
	//s2.print();
	//s2.deleteMin();
	cout << "Printing original heap after copy delete function called"<< endl;
	//s1.print();
	//SongHeap s3;													//copy assignment called
	//s3 = s1;
	cout << "Printing assignment copied heap" << endl;
	//s3.print();
	cout << "Printing origninal heap" << endl;
	//s1.print();
	//End Testing----------------------------------------------------
	*/

	cout << "Welcome! Processing the " << fileName << " file..." << endl;
	cout << endl;

	//reading in file
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "ERROR";
		return -1;
	}
	//first line discarded
	getline(file, first);	
	//extract all data
	while (file.good())
	{
		getline(file, title, ',');
		//cout << title << endl;
		getline(file, artist, ',');
		//cout << artist << endl;
		getline(file, date);
		//cout << date << endl;
		s.insert(title, artist, date);
		//cout << "bREAK0" << endl;
	}
	cout << endl;
	cout << endl;
	cout << "Printing heap:" << endl;
	s.print();
	cout << endl;
	cout << endl;
	cout << "Which song do you want to print?  " <<endl;
	getline(cin,titleIn);
	//Capitalize each word of user input
	titleIn = titlize(titleIn);
	cout << endl;
	cout << endl;
	//Keep asking for valid title if not in heap
	while(!s.printSong(titleIn)) {
		cout << titleIn << " is not in the heap. Please enter a valid title"<< endl;
		getline(cin, titleIn);
		cout << endl;
		cout << endl;
	}
	s.deleteMin();			
	//s.deleteMin();	
	cout << "Printing the updated heap: " << endl;
	cout << endl;
	cout << endl;
	s.print();
	cout << endl;
	cout << endl;
  cout << "End of execution example; thanks for stopping, bye!";
	return 0;
}

string titlize(string phrase) {																																	//Should i enclude function in class?
	 bool isSpace = true; //space status           
	int i = 0;   //index

	while (phrase[i]) {
		if (isSpace) {
			phrase[i] = toupper(phrase[i]); //capitilize letter after space
			isSpace = false;
		}
		else if (isspace(phrase[i]))
			isSpace = true;							//set flag 
		i++;
	}
	//cout << "Processed string: " << phrase << endl;
	return phrase;
}