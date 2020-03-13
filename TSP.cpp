#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;

void open_store_file(int argc, char const* argv[], int* file_count, vector<int> &number, vector<int> &xcoord, vector<int> &ycoord) {
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
      cout << "could not open file [check if the file exist or you mistyped the name]" << endl; //print an error if the values could not be opened
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
      number.push_back(atoi(ch));
      ch = strtok(NULL, "\t "); //ignore tabs and spaces for the next number found
      xcoord.push_back(atoi(ch));
      ch = strtok(NULL, "\t "); //ignore tabs and spaces for the last number found
      ycoord.push_back(atoi(ch));
    }
  }
}

void TSP_KNN_2(int argc, char const* argv[], int file_count, vector<int> &number, vector<int> &xcoord, vector<int> &ycoord) {
  ofstream results; //variable declared to create and write to a file
  string first_arg = argv[1]; //converting argv[1] to a string
  string final_str = first_arg + ".tour"; //add .tour to the end of the file
  results.open(final_str.c_str()); //convert the string into a c string
  int dis_trav = 0; //will contain the total distance of the traveled path
  int traveled[file_count]; //will contain the city identifier values
  vector<int> iden; //will be used for identifying the city value in the nearest vector
  vector<int> nearest; //will be used for finding which vector has the smallest distance
  int visited = 0; //check if a value is visited

  traveled[visited] = number[0]; //starting coordinate of our nearest neighbor algorithm
  number[traveled[visited]] = -1; //since value is visited we set the number as a negative value

for (int i = 0; i < file_count-1; i++) {
  for (int b = 0; b < file_count; b++) {
        if(-1 == number[b]) { //values that are -1 are already visited
          //do nothing
        }
        else {
        int operation1 = pow((xcoord[traveled[visited]] - xcoord[number[b]]), 2.0); //calculating euclid distance
        int operation2 = pow((ycoord[traveled[visited]] - ycoord[number[b]]), 2.0); //calculating euclid distance
        nearest.push_back(rint(sqrt(operation1 + operation2))); //calculating euclid distance
        iden.push_back(number[b]); //the city identifers should be at the same push_backed value
      }
    }
       vector<int>::iterator min = min_element(nearest.begin(), nearest.end()); //find the smalest element out of all values
       int dis = distance(nearest.begin(), min); //figures out at what position the city is located

       visited++; //increment the visited value to store its next minimum element
       traveled[visited] = iden[dis]; //using the position of the dis value to get that particular value
       number[traveled[visited]] = -1; //mark the city as visited
       dis_trav += nearest[dis]; //add the value we choose to our total distance traveled
       nearest.clear(); //clear the vector
       iden.clear(); //clear the vector
    }
    int operation1 = pow((xcoord[traveled[0]] - xcoord[traveled[visited]]), 2.0); //calculating euclid distance
    int operation2 = pow((ycoord[traveled[0]] - ycoord[traveled[visited]]), 2.0); //calculating euclid distance
    int connected = rint(sqrt(operation1 + operation2)); //connect the final distance

    dis_trav += connected; //final euclid distance
    results << dis_trav << endl; //print to full distance cities into the .tour file

    for (int i = 0; i < file_count; i++) {
      results << traveled[i] << endl; //print the connected cities into the .tour file
    }
}


void TSP_KNN_1(int argc, char const* argv[], int file_count, vector<int> &number, vector<int> &xcoord, vector<int> &ycoord) {
  ofstream results; //variable declared to create and write to a file
  string first_arg = argv[1]; //converting argv[1] to a string
  string final_str = first_arg + ".tour"; //add .tour to the end of the file
  results.open(final_str.c_str()); //convert the string into a c string
  int dis_trav = 0; //will contain the total distance of the traveled path
  int traveled[file_count][file_count]; //will contain the city identifier values
  vector<int> iden; //will be used for identifying the city value in the nearest vector
  vector<int> nearest; //will be used for finding which vector has the smallest distance
  vector<int> total_smallest; //will find the smallest value possible in the TSP problem
  int visited = 0; //check if a value is visited
for (int x = 0; x < file_count; x++) {
  for (int u = 0; u < file_count; u++) {
    number[u] = u; //resets the numbers as not visited
  }

  visited = 0; //check if a value is visited
  dis_trav = 0;
  traveled[visited][x] = number[x]; //starting coordinate of our nearest neighbor algorithm
  number[traveled[visited][x]] = -1; //since value is visited we set the number as a negative value

for (int i = 0; i < file_count-1; i++) {
  for (int b = 0; b < file_count; b++) {
        if(-1 == number[b]) { //values that are -1 are already visited
          //do nothing
        }
        else {
        int operation1 = pow((xcoord[traveled[visited][x]] - xcoord[number[b]]), 2.0); //calculating euclid distance
        int operation2 = pow((ycoord[traveled[visited][x]] - ycoord[number[b]]), 2.0); //calculating euclid distance
        nearest.push_back(rint(sqrt(operation1 + operation2))); //calculating euclid distance
        iden.push_back(number[b]); //the city identifers should be at the same push_backed value
      }
    }
       vector<int>::iterator min = min_element(nearest.begin(), nearest.end()); //find the smalest element out of all values
       int dis = distance(nearest.begin(), min); //figures out at what position the city is located

       visited++; //increment the visited value to store its next minimum element
       traveled[visited][x] = iden[dis]; //using the position of the dis value to get that particular value
       number[traveled[visited][x]] = -1; //mark the city as visited
       dis_trav += nearest[dis]; //add the value we choose to our total distance traveled
       nearest.clear(); //clear the vector
       iden.clear(); //clear the vector
    }
    int operation1 = pow((xcoord[traveled[0][x]] - xcoord[traveled[visited][x]]), 2.0); //calculating euclid distance
    int operation2 = pow((ycoord[traveled[0][x]] - ycoord[traveled[visited][x]]), 2.0); //calculating euclid distance
    int connected = rint(sqrt(operation1 + operation2)); //connect the final distance

    dis_trav += connected; //final euclid distance

    total_smallest.push_back(dis_trav); //get the smallest distance possible
  }

    vector<int>::iterator min = min_element(total_smallest.begin(), total_smallest.end()); //find the smalest distance out of all values
    int dis = distance(total_smallest.begin(), min); //get the distance from the minimum value
    results << total_smallest[dis] << endl; //write the distance to the tour file

    for (size_t y = 0; y < total_smallest.size(); y++) {
      results << traveled[y][dis] << endl; //write the travled coordinates to the tour file
    }
}

int main(int argc, char const* argv[]) {
  int file_count = 0;
  vector<int> number; vector<int> xcoord; vector<int> ycoord;
  open_store_file(argc, argv, &file_count, number, xcoord, ycoord);

  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now(); //start the timer

  if(file_count < 1000) { //check if the file is bigger than 1000 because the will cause issues to the 2d array in the first function
    TSP_KNN_1(argc, argv, file_count, number, xcoord, ycoord);
  }
  else {
    TSP_KNN_2(argc, argv, file_count, number, xcoord, ycoord);
  }
  end = chrono::system_clock::now();
  chrono::duration<double> seconds = end - start; //stop the timer

  cout << "total seconds: " << seconds.count() << endl; //display how long it took to calculate the method
  cout << "created tour file successfully" << endl; //created tour file porperly
  return 0;
}
