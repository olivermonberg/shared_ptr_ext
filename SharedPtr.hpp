using namespace std;

class ReferenceCount
{
private:
  size_t _refCount = 0;
public:
  void Increment() { ++_refCount; }
  int Decrement() { return --_refCount; }
  int GetCount() const { return _refCount; }
};

template<typename T>
class SharedPtr
{
private:
    T* _ptr;
    ReferenceCount* _referenceCount = nullptr;
    string _name;
    
public:
    explicit SharedPtr(string name, T* t = nullptr)
    : _name(name), _ptr(t), _referenceCount(new ReferenceCount)
    {
        _referenceCount->Increment();

        cout << _name << ": " << "Shared pointer created. Reference count is " 
            << _referenceCount->GetCount() << endl;
    } 
    
    ~SharedPtr() 
    { 
        _referenceCount->Decrement();

        cout << _name << ": " << "Destructor was called. Reference count is "
            << _referenceCount->GetCount() << endl;

        if (_referenceCount->GetCount() <= 0)
        {
            delete _referenceCount;
            delete _ptr;

            cout << _name << ": " << "Resource was deleted." << endl;
        }
    }

    SharedPtr(string name, const SharedPtr& existingObject)
    : _name(name), _ptr(existingObject._ptr)
    , _referenceCount(existingObject._referenceCount)
    {
        _referenceCount->Increment();
        cout << _name << ": " << "Copy constructor called. Shared pointer was copied. " 
            << "Reference count is " << _referenceCount->GetCount() << endl;
    }
    
    SharedPtr& operator=(const SharedPtr& existingObject)
    {
        if (&existingObject != this)
        {
            _referenceCount->Decrement();

            cout << _name << ": " << "Assignment operator called. Reference count is " 
                << _referenceCount->GetCount() << endl;

            if (_referenceCount->GetCount() == 0)
            {
                delete _referenceCount;
                delete _ptr;

                cout << _name << ": " << "Assignment operator called. " 
                    << "Resource was deleted." << endl;
            }

            _ptr = existingObject._ptr;
            _referenceCount = existingObject._referenceCount;
            _referenceCount->Increment();

            cout << _name << ": " << "Assigned shared pointer to resource of " 
                << existingObject.GetName() << ". Reference count is "
                << _referenceCount->GetCount() << endl;

            return *this;
        }   

        cout << _name << ": " << "Assigned shared pointer to it self. Reference count is " 
            << _referenceCount->GetCount() << endl;

        return *this;     
    }
    
    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }

    string GetName() const { return _name; }
};

