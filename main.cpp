#include <iostream>
#include <vector>
#include "SharedPtr.hpp"

using namespace std;

int main (int argc, char *argv[])
{
    SharedPtr<vector<int>> sharedPtr1( "sharedPtr1", new vector<int>() );
    SharedPtr<vector<int>> sharedPtr2( "sharedPtr2", new vector<int>() );
    //SharedPtr<vector<int>> sharedPtr3( "sharedPtr3", new vector<int>() );

    sharedPtr1->push_back(1);

    sharedPtr2->push_back(1);
    sharedPtr2->push_back(1);

    sharedPtr1 = sharedPtr2;

    cout << "Size of sharedPtr1 resource: " << sharedPtr1->size() << endl;
    cout << "Size of sharedPtr2 resource: " << sharedPtr2->size() << endl;

}