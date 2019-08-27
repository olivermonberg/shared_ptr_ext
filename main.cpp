#include <iostream>
#include <vector>
#include "SharedPtr.hpp"

using namespace std;

int main (int argc, char *argv[])
{
    SharedPtr<vector<int>> sharedPtr( new vector<int>() );
    
    sharedPtr->push_back(1);
    sharedPtr->push_back(1);

    std::cout << sharedPtr->size() << std::endl;
}