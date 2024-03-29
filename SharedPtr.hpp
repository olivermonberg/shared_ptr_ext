#include <iostream>
#include "ReferenceCount.hpp"
using namespace std;

template<typename T>
class SharedPtr
{
private:
    T* _ptr;
    ReferenceCount* _referenceCount = nullptr;
    
public:
    explicit SharedPtr(T* t = nullptr)
    : _ptr(t), _referenceCount(new ReferenceCount)
    {
        _referenceCount->Increment();

        cout << "Shared pointer created. Reference count is " 
            << _referenceCount->GetCount() << endl;
    } 
    
    ~SharedPtr() 
    { 
        _referenceCount->Decrement();

        cout << "Destructor was called. Reference count is "
            << _referenceCount->GetCount() << endl;

        if (_referenceCount->GetCount() <= 0)
        {
            delete _referenceCount;
            delete _ptr;

            cout << "Resource was deleted." << endl;
        }
    }

    SharedPtr(const SharedPtr& existingObject)
    : _ptr(existingObject._ptr)
    , _referenceCount(existingObject._referenceCount)
    {
        _referenceCount->Increment();
        cout << "Copy constructor called. Shared pointer was copied. " 
            << "Reference count is " << _referenceCount->GetCount() << endl;
    }
    
    SharedPtr& operator=(const SharedPtr& existingObject)
    {
        if (&existingObject != this)
        {
            _referenceCount->Decrement();

            cout << "Assignment operator called. Reference count is " 
                << _referenceCount->GetCount() << endl;

            if (_referenceCount->GetCount() == 0)
            {
                delete _referenceCount;
                delete _ptr;

                cout << "Resource was deleted." << endl;
            }

            _ptr = existingObject._ptr;
            _referenceCount = existingObject._referenceCount;
            _referenceCount->Increment();

            cout << "Assigned shared pointer. Reference count is "
                << _referenceCount->GetCount() << endl;

            return *this;
        }   

        cout << "Assigned shared pointer to it self. Reference count is " 
            << _referenceCount->GetCount() << endl;

        return *this;     
    }
    
    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }

    explicit operator bool() const { return true; }

    bool operator==(const SharedPtr& obj) const
    {
        //cout << _ptr << endl;
        //cout << obj._ptr << endl;
        //cout << &_ptr << endl;
        //cout << &obj._ptr << endl;
        
        return _ptr == obj._ptr;
    }
};

