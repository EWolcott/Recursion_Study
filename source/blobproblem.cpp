#include "blobproblem.h"
#include <fstream>

blobproblem::blobproblem()
{
    buildBlobs();
}

//this function will start with a 'true' cell, and then check all eight possible cells surrounding it.
//The algorithm will work at O(n) where n is the number of true cells times eight
//Once a cell is passed into this function, it is marked at false so that it is not accidentally called
//again by the lookfor() function.
//The base case occurs when all of the surrounding positions for each cell are false
void blobproblem::searchSurroundingCells(int rowindex, int colindex, int blobid)
{
    blobvis[rowindex][colindex] = blobid;
    blob[rowindex][colindex] = false;

    if (rowindex < 20 && rowindex >= 0 && colindex < 20 && colindex >= 0)
    {
        blob[rowindex][colindex] = false; //change value to prevent repeat sample

        if (colindex - 1 >= 0 && rowindex - 1 >= 0)
        { //make sure column is valid
            if (blob[rowindex - 1][colindex - 1] == true)
            { //check upper left diagonal
                searchSurroundingCells(rowindex - 1, colindex - 1, blobid);
            }
        }

        if (colindex - 1 >= 0)
        { //make sure column is valid
            if (blob[rowindex][colindex - 1] == true)
            { //check column to the left
                searchSurroundingCells(rowindex, colindex - 1, blobid);
            }
        }

        if (colindex - 1 >= 0 && rowindex + 1 < 20)
        { //make sure column is valid
            if (blob[rowindex + 1][colindex - 1] == true)
            { //check lower left diagonal
                searchSurroundingCells(rowindex + 1, colindex - 1, blobid);
            }
        }
        if (rowindex + 1 < 20)
        { //make sure row is valid
            if (blob[rowindex + 1][colindex] == true)
            { //check directly below
                searchSurroundingCells(rowindex + 1, colindex, blobid);
            }
        }

        if (rowindex + 1 < 20 && colindex + 1 < 20)
        { //make sure row is valid
            if (blob[rowindex + 1][colindex + 1] == true)
            { //check lower right diagonal
                searchSurroundingCells(rowindex + 1, colindex + 1, blobid);
            }
        }

        if (colindex + 1 < 20)
        { //make sure row is valid
            if (blob[rowindex][colindex + 1] == true)
            { //check column to the right
                searchSurroundingCells(rowindex, colindex + 1, blobid);
            }
        }
        if (colindex + 1 < 20 && rowindex - 1 >= 0)
        { //make sure column is valid
            if (blob[rowindex - 1][colindex + 1] == true)
            { //check upper right diagonal
                searchSurroundingCells(rowindex - 1, colindex + 1, blobid);
            }
        }

        if (colindex + 1 < 20 && rowindex - 1 >= 0)
        { //make sure column is valid
            if (blob[rowindex - 1][colindex + 1] == true)
            { //check upper right diagonal
                searchSurroundingCells(rowindex - 1, colindex + 1, blobid);
            }
        }
        if (rowindex - 1 >= 0)
        { //make sure row is valid
            if (blob[rowindex - 1][colindex] == true)
            { //check directly above
                searchSurroundingCells(rowindex - 1, colindex, blobid);
            }
        }
    }
}

//this function will iterate through the 2d array looking for true cells, and then passing them to the search function
bool blobproblem::lookFor()
{
    int blobid = 1;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (blob[i][j] == true)
            {
                // blobvis[i][j] = blobid;
                searchSurroundingCells(i, j, blobid);
                // blob[i][j] = false;
                blobid++;
            }
        }
    }

    return true;
}

//Prints the imported data, calls the algorithm, and prints the solution
//also creates a second 2d array of integers to store the solution
void blobproblem::solve()
{
    std::cout << "Here is the imported data:" << std::endl;
    std::cout << "**************************" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < 20; j++)
        {
            if (blob[i][j] == true)
            {
                blobvis[i][j] = 1;
                std::cout << "1 ";
            }
            else
            {
                blobvis[i][j] = 0;
                std::cout << "0 ";
            }
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

    if (lookFor())
    {
        printsolution();
    }
    else
    {
        std::cout << "There appears to be an error with the program";
    }
}

//prints solution
void blobproblem::printsolution()
{
    std::cout << "And here are the blobs:" << std::endl;
    std::cout << "**************************" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < 20; j++)
        {
            if (blobvis[i][j] == 0)
            {
                std::cout << "  "; //I found the space to more aesthetically pleasing than 0
            }
            else if (blobvis[i][j] < 10){
                std::cout << blobvis[i][j] << " "; //helps with spacing
            }
            else
                std::cout << blobvis[i][j];
        }
    }
}

//import the txt file and build a 2s array of booleans
void blobproblem::buildBlobs()
{
    std::ifstream fio("blob_test1.txt"); // Open a file for input/output
    char s;
    int i = 0;
    int j = 0;
    while (!fio.eof())
    {
        fio.get(s);
        if (s != '\n')
        {
            if (s == '0')
            {
                blob[i][j] = false;
            }
            else if (s == '1')
            {
                blob[i][j] = true;
            }

            j++;
            if (j == 20)
            {
                j = 0;
                i++;
            }
        }
    }
}