#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Folder;

class Message 
{
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Folder;

public:
    explicit Message(const std::string& str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder 
{
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void print_debug();

private:
    std::set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();

    void addMsg(Message* m) { msgs.insert(m); }
    void remMsg(Message* m) { msgs.erase(m); }
};

void swap(Folder&, Folder&);

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message& Message::operator=(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder& f)
{
    addFldr(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    remFldr(&f);
    f.remMsg(this);
}

void Message::print_debug()
{
    std::cout << contents << std::endl;
}

void Message::add_to_Folders(const Message& m)
{
    for (auto f : m.folders) f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders) f->remMsg(this);
}

void swap(Folder& lhs, Folder& rhs)
{
    using std::swap;
    lhs.remove_from_Messages();
    rhs.remove_from_Messages();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}

Folder::Folder(const Folder& f) : msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder& Folder::operator=(const Folder& rhs)
{
    remove_from_Messages();
    msgs = rhs.msgs;
    add_to_Messages(rhs);
    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void Folder::print_debug()
{
    for (auto m : msgs) std::cout << m->contents << " ";
    std::cout << std::endl;
}

void Folder::add_to_Messages(const Folder& f)
{
    for (auto m : f.msgs) m->addFldr(this);
}

void Folder::remove_from_Messages()
{
    for (auto m : msgs) m->remFldr(this);
}

int main()
{


	system("pause");
	return 0;
}