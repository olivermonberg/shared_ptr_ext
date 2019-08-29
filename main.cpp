#include <iostream>
#include <vector>
#include "SharedPtr.hpp"

using namespace std;

int main (int argc, char *argv[])
{
    //vector<int>* ptr = new vector<int> {10, 20, 30, 40};
    //cout << "ptr " << ptr << endl;
    //cout << "&ptr " << &ptr << endl;
    //cout << "(*ptr).at(2) " << (*ptr).at(2) << endl;
    //cout << "ptr->at(2) " << ptr->at(2) << endl;
    
    SharedPtr<vector<int>> sharedPtr1( new vector<int>() );
    SharedPtr<vector<int>> sharedPtr2( new vector<int>() );
    SharedPtr<vector<int>> sharedPtr3( new vector<int>() );

    //sharedPtr1 size = 1
    sharedPtr1->push_back(1);

    //sharedPtr2 size = 2
    sharedPtr2->push_back(1);
    sharedPtr2->push_back(22);

    //sharedPtr3 size = 3
    sharedPtr3->push_back(1);
    sharedPtr3->push_back(24);
    sharedPtr3->push_back(35);

    sharedPtr1 = sharedPtr2;
    sharedPtr1 = sharedPtr3;

    SharedPtr<vector<int>> sharedPtr4 = sharedPtr2;
    
    cout << "Size of sharedPtr1 resource: " << sharedPtr1->size() << endl;
    cout << "Size of sharedPtr2 resource: " << sharedPtr2->size() << endl;
    cout << "Size of sharedPtr3 resource: " << sharedPtr3->size() << endl;
    cout << "Size of sharedPtr4 resource: " << sharedPtr4->size() << endl;

    //if (sharedPtr4)
    //   cout << "Test" << endl;

    sharedPtr2 = sharedPtr3;
    auto test = sharedPtr1 == sharedPtr2;

    //cout << test << endl;

    SharedPtr<int> sharedPtr5( new int(10) );
    cout << "sharedPtr4: " << sharedPtr4->at(1) << endl;
    cout << "sharedPtr5:* " << *sharedPtr5 << endl;
}