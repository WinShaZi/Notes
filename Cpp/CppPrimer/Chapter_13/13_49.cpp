/*

class StrVec 
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec(StrVec&&) NOEXCEPT;
    StrVec& operator=(StrVec&&) NOEXCEPT;
    ~StrVec();

    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }

    string& at(size_t pos) { return *(elements + pos); }
    const string& at(size_t pos) const { return *(elements + pos); }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string&);

private:
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const string*, const string*);

private:
    string* elements;
    string* first_free;
    string* cap;
    allocator<string> alloc;
};

class String {
public:
    String() : String("") {}
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    String(String&&) NOEXCEPT;
    String& operator=(String&&) NOEXCEPT;
    ~String();

    const char* c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }

private:
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char* elements;
    char* end;
    allocator<char> alloc;
};

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Folder;

public:
    explicit Message(const string& str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    Message(Message&&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    string contents;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message*);

    void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    Folder(Folder&&);
    Folder& operator=(Folder&&);
    ~Folder();

    void print_debug();

private:
    set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();
    void move_Messages(Folder*);

    void addMsg(Message* m) { msgs.insert(m); }
    void remMsg(Message* m) { msgs.erase(m); }
};

void swap(Folder&, Folder&);

*/