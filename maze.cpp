#include <iostream>
#include <fstream>
#include "queue.h"
#include "list.h"

using namespace std;


/* -------- Prototypes -------- */
void populateMaze(char** a, int grSize, int gcSize, string s);
bool mazeNotFinished(char** a, int r, int c, int grSize, int gcSize);

/* -------- Template Print Function -------- */
template <typename T> void printMaze( T a, int grSize, int gcSize){
  for (int i = 0; i < grSize; i++){
    for (int j = 0; j < gcSize; j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(){

  /* -------- Variables -------- */

  int grSize, gcSize;
  string s; // maze file
  char c; // character of maze
  int currR;
  int currC;
  Queue qR, qC;

  /* -------- Getting the Maze File -------- */

  cout << "Enter desired maze:" << endl;

  cin >> s;
  fstream f(s);

  f >> grSize;
  f >> gcSize;

  /* -------- Creating an Array To Track Visited Cells ------ */

  int** v = new int*[grSize];

  for (int i = 0; i< grSize; i++){
    v[i] = new int[gcSize];
  }
  for(int i = 0; i < grSize; i++){
    for (int j = 0; j < gcSize; j++){
      v[i][j] = 0;
    }
  }

  /* -------- Creating and Populating the Maze -------- */

  char** a = new char*[grSize]; //dynamically allocated 2d array

  for (int i = 0; i < grSize; i++){
    a[i] = new char[gcSize];
  }

  populateMaze(a, grSize, gcSize, s);
  printMaze<char**>(a, grSize, gcSize);

  /* -------- Maze Search Algorithm -------- */
  for (int i = 0; i < grSize; i++){
    for (int j = 0; j < gcSize; j++){
      if( a[i][j] == 'S'){
        currR = i;
        currC = j;
      }
    }
  }

  int count = 1;

  while (mazeNotFinished(a,currR,currC,grSize,gcSize)){
    /* -------- Sets Visited -------- */
    v[currR][currC] = count;

    /* ------ Edge Cases -------- */
    int rowS = currR-1;
    int colS = currC-1;
    int rowE = currR+1;
    int colE = currC+1;

    if (currR+1 > grSize-1){rowE--;}
    if(currR-1 < 0){rowS++;}

    if (currC+1 > gcSize-1){colE--;}
    if(currC-1 < 0){colS++;}

    /* -------- Add Unvisited to Queue -------- */
    for (int i = rowS; i <= rowE; i++){
      for (int j = colS; j <= colE; j++){
        if( a[i][j] == '.' && v[i][j] == 0){
          if(i == currR || j == currC){
            qR.Insert(i);
            qC.Insert(j);
          } 
        }
      }
    }

    /* -------- Remove the Next Element From Queue and Go There -------- */

    if (qR.IsEmpty()){
      cout << "Maze is Impossible" << endl;
      break;
    }

    currR = qR.GetFront();
    currC = qC.GetFront();
    
    qR.Delete();
    qC.Delete(); 
    
    a[currR][currC] = 'v'; 
    count++;
  }
  v[currR][currC] = count;
  
  cout << "All Visited Cells:" << endl;
  printMaze<char**>(a,grSize,gcSize);

  //Deleting the arrays
  for (int i = 0; i < grSize; i++){
    delete[] a[i];
    delete[] v[i];
  }
  delete[] a;
  delete[] v;

  return 0;
}

void populateMaze(char** a, int grSize, int gcSize, string s){
  fstream f(s);
  int trashSizeNums;
  f >> trashSizeNums >> trashSizeNums;

  for( int i = 0; i < grSize; i++){
    for (int j = 0; j < gcSize; j++){
      f >> a[i][j]; 
    }
  }

}

bool mazeNotFinished(char** a, int r, int c, int grSize, int gcSize){
  int rowS = r-1;
  int colS = c-1;
  int rowE = r+1;
  int colE = c+1;

  if (r+1 > grSize-1){rowE--;}
  if(r-1 < 0){rowS++;}

  if (c+1 > gcSize-1){colE--;}
  if(c-1 < 0){colS++;}

  for (int i = rowS; i <= rowE; i++){
    for (int j = colS; j <= colE; j++){
      if (a[i][j] == 'G'){
        return false;
      }
    }
  }
  return true;
}
