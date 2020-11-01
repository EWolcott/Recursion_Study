#include "queenproblem.h"

//constructor with chosen number of queens, fills board with 0s
queenproblem::queenproblem(int _numOfQueens)
{
    numOfQueens = _numOfQueens;
    fillboard();
}

//fills board with 0sfor aesthetic purposes
void queenproblem::fillboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
}

//prints board to terminal
void queenproblem::printsolution()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < 8; j++)
        {
            std::cout << board[i][j] << " ";
        }
    }
}

//calls placequeen() with the starting column position and continues if it reaches true
void queenproblem::solve()
{
    if (placeQueen(0))
    {
        printsolution();
    }
    else
    {
        std::cout << "Unable to find solution." << std::endl;
    }
}

//returns true once it has placed a queen in every column
//checks to see if position is valid and calls function again until it is
//Because it eliminates a column with each iteration, the complexity is cut in half by 
//only needing to check for collision from behind. However, backtracking is often necessary, so
//it is difficult to tell how much work the program will do depending on the starting paramaters
bool queenproblem::placeQueen(int colindex)
{
    //end recursion and be done if number of columns completed
    if (colindex == numOfQueens)
    {
        return true;
    }
    for (int rowindex = 0; rowindex < numOfQueens; rowindex++)
    {
        if (isPlaceValid(rowindex, colindex))
        {
            board[rowindex][colindex] = 1; //places the queen in the valid position
            if (placeQueen(colindex + 1))
            {
                return true;
            }
            board[rowindex][colindex] = 0;
        }
    }
    return false;
}

//makes sure queen cannot be attacked by previous queens
bool queenproblem::isPlaceValid(int rowindex, int colindex)
{
    //check for horizontal queens
    for (int i = 0; i < colindex; i++)
    {
        if (board[rowindex][i] == 1)
        {
            return false;
        }
    }
    //check upper-left diagonal
    for (int i = rowindex, j = colindex; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    //check bottom-left diagonal
    for (int i = rowindex, j = colindex; i < numOfQueens && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}