#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void open_store_file(int argc, char const* argv[], int* file_count) {
  ifstream data; //variable declared to open a file
  string lines; //used to loop thorugh all the lines of the file
  char* ch; //used to parse data

  if(argv[1] == NULL) {
    cout << "command lines have not been entered" << endl;
    cout << "ex) ./a.out [filenamehere].txt" << endl;
    exit(1);
  }
  else {
    data.open(argv[1]); //the second argument in cmd line will be executed to open
    if(!data) { //check if the file exists
      cout << "could not open file" << endl; //print an error if the values could not be opened
      exit(1);
    }
    else {
      cout << "successfully opened file" << endl; //print a success message if file opened
    }
    while(getline(data,lines)) {
      *file_count += 1; //gets  the number of lines
      char raw_arr[lines.size()+1]; //declared raw character array (+1 because of newline)
      strcpy(raw_arr, lines.c_str()); //copy the string into a raw character array
      ch = strtok(raw_arr, "\t "); //strtok will ignore tabs and spaces in the character array of the string lines will find the first number
      int number = atoi(ch); //convert string to integer (works with character pointers)
      ch = strtok(NULL, "\t "); //ignore tabs and spaces for the next number found
      int xcoord = atoi(ch); //convert string to integer (works with character pointers)
      ch = strtok(NULL, "\t "); //ignore tabs and spaces for the last number found
      int ycoord = atoi(ch); //convert string to integer (works with character pointers)

      //store the number, xcoord, ycoord into an array here
    }
  }
}

void TSP(int* file_count) {
  ofstream results; //variable declared to create and write to a file
  cout << "TSP Function Called" << endl;
}

int main(int argc, char const* argv[]) {
  int file_count = 0;

  open_store_file(argc, argv, &file_count);
  TSP(&file_count); //pass the array here

  return 0;
}
