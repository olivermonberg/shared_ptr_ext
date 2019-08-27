template<typename T>
class SharedPtr
{
private:
    T* _ptr;
    
public:
    explicit SharedPtr(T* t = nullptr) : _ptr(t) {} 
    //SharedPtr(const SharedPtr&);
    //SharedPtr& operator=(const SharedPtr&);
    ~SharedPtr() { delete _ptr; }
    
    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }
    size_t count() { return 0;}
};