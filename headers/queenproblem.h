//Ethan Wolcott
//Data Structures
//06/20/2020
//With help from https://www.youtube.com/watch?v=3bR5dyka3fk

#ifndef QUEENPROBLEM_H
#define QUEENPROBLEM_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>

class queenproblem
{
public:
    int board[8][8];
    int numOfQueens;

    //Base constructor with starting number of queens
    queenproblem(int _numOfQueens);
    //checks to see if a position is valid or if it can be attacked
    bool isPlaceValid(int rowindex, int colindex);
    //places the queen into the valid position
    bool placeQueen(int colindex);
    //calls necessary functions and prints solution
    void solve();
    //prints solution
    void printsolution();
    //fills the board with 0s for aesthetic purposes
    void fillboard();
};

#endif