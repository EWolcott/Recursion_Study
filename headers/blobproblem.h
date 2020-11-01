//Ethan Wolcott
//Data Structures
//06/20/2020

#ifndef BLOBPROBLEM_H
#define BLOBPROBLEM_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>

class blobproblem
{
public:
    bool blob[20][20];   //2d array of booleans
    int blobvis[20][20]; //2d array of ints for solution

    //Base empty constructor
    blobproblem();
    //search all eight directions of a true cell for joining true cells
    void searchSurroundingCells(int rowindex, int colindex, int blobid);
    //find a true cell as a starting point for new blob
    bool lookFor();
    //call the necessary functions and print solution
    void solve();
    //print solution
    void printsolution();
    //build the boolean blob
    void buildBlobs();
};

#endif