#include <iostream>
#include <vector>
#include "SharedPtr.hpp"

using namespace std;

int main (int argc, char *argv[])
{
    SharedPtr<vector<int>> sharedPtr1( "sharedPtr1", new vector<int>() );
    SharedPtr<vector<int>> sharedPtr2( "sharedPtr2", new vector<int>() );
    SharedPtr<vector<int>> sharedPtr3( "sharedPtr3", new vector<int>() );

    //sharedPtr1 size = 1
    sharedPtr1->push_back(1);

    //sharedPtr2 size = 2
    sharedPtr2->push_back(1);
    sharedPtr2->push_back(1);

    //sharedPtr3 size = 3
    sharedPtr3->push_back(1);
    sharedPtr3->push_back(1);
    sharedPtr3->push_back(1);

    sharedPtr1 = sharedPtr2;
    sharedPtr1 = sharedPtr3;

    SharedPtr<vector<int>> sharedPtr4 = sharedPtr2;
    
    cout << "Size of sharedPtr1 resource: " << sharedPtr1->size() << endl;
    cout << "Size of sharedPtr2 resource: " << sharedPtr2->size() << endl;
    cout << "Size of sharedPtr3 resource: " << sharedPtr3->size() << endl;
    cout << "Size of sharedPtr4 resource: " << sharedPtr4->size() << endl;
}