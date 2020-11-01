#include <iostream>
#include "blobproblem.h"
#include "queenproblem.h"

int main()
{
    std::cout << "Hello!" << std::endl;

    std::cout << "Which problem do you want to solve?" << std::endl;
    std::cout << "1. Blob Problem" << std::endl;
    std::cout << "2. Queen Problem" << std::endl;
    int input;
    std::cin >> input;
    blobproblem blob;        //make a blobproblem
    queenproblem queenie(8); //make a queenproblem

    switch (input)
    {
    case 1:
        blob.solve();
        break; //solve the blobs
    case 2:
        queenie.solve();
        break; //solve the queens
        break;
    }

    return 0;
}