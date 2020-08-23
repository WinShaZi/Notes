#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <assert.h>

using namespace std;

template <typename T> 
class SharedPtr 
{
    using DelFuncPtr = void (*)(T*);

public:
    SharedPtr(T* ptr = nullptr, DelFuncPtr del = nullptr)
        : ptr_(ptr), count_ptr_(new size_t(ptr != nullptr)), del_(del) { }
    ~SharedPtr()
    {
        if (!ptr_) return;
        if (--*count_ptr_ == 0) {
            del_ ? del_(ptr_) : delete ptr_;
            delete count_ptr_;
        }
        ptr_ = nullptr;
        count_ptr_ = nullptr;
    }

    SharedPtr(const SharedPtr& sp) : ptr_(sp.ptr_), count_ptr_(sp.count_ptr_), del_(sp.del_)
    {
        ++*count_ptr_;
    }

    SharedPtr& operator=(SharedPtr sp)
    {
        swap(sp);
        return *this;
    }

    SharedPtr(const SharedPtr&& sp) noexcept : SharedPtr() { swap(sp); }

    void reset(T* ptr = nullptr, DelFuncPtr del = nullptr)
    {
        SharedPtr tmp(ptr, del);
        swap(tmp);
    }

    void swap(SharedPtr& r) noexcept
    {
        using swap;
        swap(ptr_, r.ptr_);
        swap(count_ptr_, r.count_ptr_);
        swap(del_, r.del_);
    }

    T* get() const noexcept { return ptr_; }
    T& operator*() const noexcept { return *get(); }
    T* operator->() const noexcept { return get(); }
    size_t use_count() const noexcept { return *count_ptr_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }

private:
    T* ptr_ = nullptr;
    size_t* count_ptr_ = nullptr;
    DelFuncPtr del_ = nullptr;
};

class Delete 
{
public:
    template <typename T> void operator()(T* ptr) const { delete ptr; }
};

template <typename T, typename D = Delete> 
class UniquePtr {
public:
    UniquePtr(T* ptr = nullptr, const D& d = D()) noexcept : ptr_(ptr), deleter_(d) {}
    ~UniquePtr() { deleter_(ptr_); }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr_(other.ptr_), deleter_(move(other.deleter_))
    {
        other.ptr_ = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        if (this != &other) 
		{
            reset();
            ptr_ = other.ptr_;
            deleter_ = move(other.deleter_);
            other.ptr_ = nullptr;
        }
        return *this;
    }

    UniquePtr& operator=(nullptr_t) noexcept
    {
        reset();
        return *this;
    }

    T* release() noexcept
    {
        T* ret = ptr_;
        ptr_ = nullptr;
        return ret;
    }

    void reset(T* q = nullptr) noexcept
    {
        deleter_(q);
        ptr_ = q;
    }

    void swap(UniquePtr& other) noexcept
    {
        using swap;
        swap(ptr_, other.ptr_);
        swap(deleter_, other.deleter_);
    }

    T* get() const noexcept { return ptr_; }
    D& get_deleter() noexcept { return deleter_; }
    const D& get_deleter() const noexcept { return deleter_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }
    T& operator*() const { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }
    T& operator[](size_t i) const { return ptr_[i]; }

private:
    T* ptr_ = nullptr;
    D deleter_;
};

class DebugDelete
{
public:
	DebugDelete(ostream &s = cerr):os(s) { }
	template <typename T> void operator()(T *p) const
	{
		os<<"deleting..."<<endl;
		delete p;
	}
private:
	ostream &os;
};

struct Foo 
{
    Foo() { cout << "Foo()\n"; }
    ~Foo() { cout << "~Foo()\n"; }
    Foo(const Foo&) { cout << "Foo copy ctor\n"; }
    Foo(Foo&&) { cout << "Foo move ctor\n"; }
};

struct Fooo 
{
    Fooo(int n = 0) noexcept : bar(n) { cout << "Fooo: constructor, bar = " << bar << '\n'; }
    ~Fooo() { cout << "Fooo: destructor, bar = " << bar << '\n'; }
    int GetBar() const noexcept { return bar; }

private:
    int bar;
};

struct D 
{
    void bar() { cout << "Call deleter D::bar()...\n"; }
    void operator()(Foo* p) const
    {
        cout << "Call delete from function object...\n";
        delete p;
    }
};

int main()
{

    
	system("pause");
	return 0;
}