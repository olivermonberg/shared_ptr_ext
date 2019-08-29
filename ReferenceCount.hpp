class ReferenceCount
{
private:
  size_t _refCount = 0;
public:
  void Increment() { ++_refCount; }
  int Decrement() { return --_refCount; }
  int GetCount() const { return _refCount; }
};