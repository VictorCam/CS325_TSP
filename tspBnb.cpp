#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int sizeOfTour(char* testfile) {
  ifstream f;
  f.open(testfile);
  int numCities= 0;
  int gargbage_val = 0;
  while(!f.eof()) {
    // 3 for one line
    f >> gargbage_val;
    f >> gargbage_val;
    f >> gargbage_val;
    numCities++;
  }
  numCities--;
  cout << numCities << endl;
  f.close();
  return numCities;
}

void getData(char* testfile, int* city, int* xcord, int* ycord, int numCities, int** tour) {
  ifstream f;
  f.open(testfile);

  for(int i = 0; i < numCities; i++) {
    f >> city[i];
    f >> xcord[i];
    f >> ycord[i];
  }
  f.close();

  // int tour[numCities][numCities];
  for(int i = 0; i < numCities; i ++) {
    for(int j = 0; j < numCities; j++) {

      if(i == j) {
        tour[i][j] = -1;
      }
      else {
        tour[i][j] = sqrt(pow(xcord[j]-xcord[i], 2) + pow(ycord[j]-ycord[i], 2));
      }

    }
  }
  // prints the matrix
  // for(int i = 0; i < numCities; i++) {
  //   for(int j = 0; j < numCities; j++) {
  //     cout << tour[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}

void printMatrix(int** tour, int numCities) {
  for(int i = 0; i < numCities; i++) {
    for(int j = 0; j < numCities; j++) {
      cout << tour[i][j] << " ";
    }
    cout << endl;
  }
}

int firstMin(int** tour, int numCities, int index) {
  int min = INT_MAX;
  for(int i = 0; i < numCities; i++) {
    if(tour[index][i] < min && index != i) {
      min = tour[index][i];
    }
  }
  return min;
}

int secondMin(int** tour, int numCities, int index) {
  int first = INT_MAX;
  int second = INT_MAX;
  for(int i = 0; i < numCities; i++) {
    if(index != i) {
      if(tour[index][i] <= first) {
        second = first;
        first = tour[index][i];
      }
      else if (tour[index][i] <= second && tour[index][i] != first) {
        second = tour[index][i];
      }
    }
  }
  return second;
}

void copyToFinal(int* path, int numCities, int* finalPath) {

  for(int i = 0; i < numCities; i++) {
    finalPath[i] = path[i];
    // cout << finalPath[i] << " ";
  }
  // cout << endl;
  finalPath[numCities] = path[0];
}

void tspRec(int** tour, int numCities, int bound, int weight, int level, int* path, int* finalPath, int &finalWeight, bool* visited) {
  if(level == numCities) {

    if(tour[path[level-1]][path[0]] != -1) {

      int currentSolutionWeight = weight + tour[path[level-1]][path[0]];

      if(currentSolutionWeight < finalWeight) {

        copyToFinal(path, numCities, finalPath);
        finalWeight = currentSolutionWeight;
        // cout << "in the if statement final weight: " << finalWeight << endl;
      }
    }
    return;
  }

  for(int i = 0; i < numCities; i++) {

    if(tour[path[level-1]][i] != -1 && visited[i] == false) {
      int temp = bound;
      weight += tour[path[level-1]][i];

      if(level==1) {
        bound -= ((firstMin(tour, numCities, path[level-1]) + firstMin(tour, numCities, i))/2);
      }
      else {
        bound -= ((secondMin(tour, numCities, path[level-1]) + firstMin(tour, numCities,i))/2);
      }

      if((bound + weight) < finalWeight) {
        path[level] = i;
        visited[i] = true;

        tspRec(tour, numCities, bound, weight, level+1, path, finalPath, finalWeight, visited);
      }

      weight -= tour[path[level-1]][i];
      bound = temp;

      for(int j = 0; j < numCities; j++) {
        visited[j] = false;
      }
      for(int j =0; j <= level-1; j++) {
        visited[path[j]] = true;
      }
    }
  }
}

void tsp(int** tour, int numCities, int* finalPath, int &finalWeight, bool* visited) {
  int path[numCities+1];

  int bound = 0;
  for(int i = 0; i < numCities; i++) {
    visited[i] = false;
    path[i] = -1;
  }
  path[numCities] = -1;

  for(int i = 0; i < numCities; i++) {
    bound += (firstMin(tour, numCities, i) + secondMin(tour, numCities, i));
  }

  // cout << bound << endl;
  visited[0] = true;
  path[0] = 0;

  tspRec(tour, numCities, bound, 0, 1, path, finalPath, finalWeight, visited);
}


/** done with help from
https://www.youtube.com/watch?v=1FEP_sNb62k -- helped with the concepts
https://www.geeksforgeeks.org/traveling-salesman-problem-using-branch-and-bound-2/ -- gives a basic example used to start this 
*/
int main(int argc, char ** argv) {

  int numCities = sizeOfTour(argv[1]);
  cout << numCities << endl;
  int city[numCities];
  int xcord[numCities];
  int ycord[numCities];
  int finalPath[numCities];
  int finalWeight = INT_MAX;
  bool visited[numCities];
  int* tour[numCities];
  for(int i = 0; i < numCities; i++) {
    tour[i] = new int[numCities];
  }

  getData(argv[1], city, xcord, ycord, numCities, tour);
  printMatrix(tour, numCities);
  tsp(tour, numCities, finalPath, finalWeight, visited);
  cout << "final weight: " << finalWeight << endl;
  for(int i = 0; i < numCities; i++) {
    cout << finalPath[i] << endl;
  }
  return 0;
}
