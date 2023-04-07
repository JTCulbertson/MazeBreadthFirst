# MazeBreadthFirst

This is a maze search algorith that is breadth-first and uses queues. The arrays are automatically dynamically allocated.

When running the program, compile with g++ maze.cpp list.cpp queue.cpp on unix based machines.

Enter a maze text file in the format shown in the example maze text files (ex. maze1.txt)

The program does not need to be recompiled to do different mazes, simply use ./a.out once compiled and input the maze text file.


Maze Files:

Dots are places the program can go, hashtags are walls. The program initially starts at S and ends when adjacent to G. 

The program outputs the visited cells. 
