//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 2
//
//this is the defualt .h file which contains all the 
//prototype of the class and functions
//there has two data structure, doubly linked list and liear linked list.

#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

class Translator;


//this is the Node class for the linear linked list. which cantians
//3 members and sevearl functions including de/constructor and compare.
//display function....
class LNode
{
protected:
    LNode * next;

    char * key;
    char * result;
public:
    LNode();
    LNode(LNode &);
    LNode(char *, char *);
    ~LNode();

    LNode *& go_next();
    void set_next(LNode *);

    bool compare(char *);

    int translate(char *);
    void display();
};

//THis is the node class for the doubly linked list. and has 3 members 
//with the tranlate remove function and display de/constructor
class DNode
{
protected:
    DNode * pre;
    DNode * next;

    Translator * trans;
public:
    DNode();
    DNode(Translator *);
    ~DNode();

    DNode *& go_pre();
    DNode *& go_next();
    void set_pre(DNode *);
    void set_next(DNode *);

    int translate(char *);
    bool remove(char *);

    void display();

};

//this is the abstract base class and has constructor, pure virtual destructor,
//and other pure virtual function
class Translator
{
protected:
    LNode * head;

public:
    Translator();
    virtual ~Translator();
    virtual bool insert(char *, char *) = 0;
    virtual bool remove(char *) = 0;
    virtual bool remove_all() = 0;

    virtual int translate(char *) = 0;
    virtual void display() = 0;

};

//this is the derived class of the abstract base class
//it contains a linear linked list and all the functions
//to support that data structure
class Text : public Translator
{
protected:
    bool remove(char *, LNode *&);
    int translate(char *, LNode *);
    void display(LNode *);

    bool remove_all(LNode *&);
public:
    Text();
    ~Text();

    bool remove_all();

    bool insert(char *, char *);
    bool remove(char *);

    int translate(char *);
    void display();
};

//this is the derived class of the abstract base class
//it contains a linear linked list and all the functions
//to support that data structure
class Formal : public Translator
{
protected:
    bool remove(char *, LNode *&);
    int translate(char *, LNode *);
    void display(LNode *);

    bool remove_all(LNode *&);
public:
    Formal();
    ~Formal();

    bool remove_all();

    bool insert(char *, char *);
    bool remove(char *);

    int translate(char *);
    void display();
};

//this is the derived class of the abstract base class
//it contains a linear linked list and all the functions
//to support that data structure
class Special : public Translator
{
protected:
    bool remove(char *, LNode *&);
    int translate(char *, LNode *);
    void display(LNode *);

    bool remove_all(LNode *&);
public:
    Special();
    ~Special();

    bool remove_all();

    bool insert(char *, char *);
    bool remove(char *);

    int translate(char *);
    void display();
};

//this is the client class which acts like a interface for the 
//client to the console, which can manage the operation and functions
//of the application
class client
{
protected:
    DNode * head;
    DNode * tail;

    bool remove_all(DNode *);
    void display(DNode *);
public:
    client();
    ~client();

    bool insert(Translator *);
    void display();
    bool remove_all();

    void read_file(int t, Translator *);
    void create_file(int type, char * key, char * result);

    void formal_convert(char *);
};

bool again();
