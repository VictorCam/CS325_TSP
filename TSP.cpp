#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void open_store_file(int argc, char const* argv[], int* file_size) {
  ifstream data; //variable declared to open a file
  ofstream results; //variable declared used to create and write to a file
  string lines; //used to loop thorugh all the lines of the file
  char* ch; //used to parse

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
    /*store data using getline and the size of the file*/
  }
}

int main(int argc, char const* argv[]) {
  int file_size = 0;

  open_store_file(argc, argv, &file_size);

  return 0;
}
