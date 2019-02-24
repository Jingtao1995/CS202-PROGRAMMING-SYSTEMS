//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 3
//
//Sport, Athlete, and Record Class and the Data Structure
//Sport.h
//This is the Sport.h file which declare the Sport class, Athlete class
//A_node class which is derived from the Athlete, and R_node class which
//is derived from the Record class.

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

//pre declaration
class A_node;
class R_node;
class Athlete;
class Record;

//this is the Sport class which is the basic node of the red-blakc tree.
//there has 4 arguments and a list of athlete class
class Sport
{
private:
    char * Name;
    char * Detail;
    char * Time;
    char * Channel;

    A_node * A_head;
    void copy_list(A_node *& des, A_node * head);
    bool insert_athlete(A_node *& head, Athlete &);
    void remove_all(A_node *&);
    void display(A_node *);
    A_node * retrieve(A_node *, char *);
public:
    Sport();
    Sport(Sport &);
    ~Sport();

    bool insert(char *,char *,char *,char *);
    bool insert_athlete(Athlete &);
    int compare(char *);
    char * get_name();
    void display();
    bool operator > (Sport &); //operator overloading >
    A_node * retrieve(char *);

    A_node *& operator += (Athlete &); //operation overloading +=
};

//this is the Athlete class and the base class of the A_node class.
//it has 3 arguments and a list of Record class
class Athlete
{
private:
    char * Name;
    char * Event;
    int medals;

    R_node * R_head;
    void copy_list(R_node *& des, R_node * head);
    void remove_all(R_node *&);
    bool insert_record(R_node *&, Record &);
    void display_record(R_node *);
public:
    Athlete();
    Athlete(Athlete &);
    ~Athlete();

    bool insert(char *,char *,int);
    bool insert_record(Record &);
    bool compare(char *);
    void display();
    void copy_list(R_node *);

    Athlete & operator = (const Athlete &);
    bool operator == (const Athlete &);
};

//the A_node class which is derived from the Athlete to achieve the LLL 
//data structor
class A_node : public Athlete
{
private:
    A_node * next;
public:
    A_node();
    A_node(Athlete &);
    ~A_node();

    A_node *& go_next();
    void set_next(A_node *);
};

//this is the record class which stores the historical information of the athletes
class Record
{
private:
    char * Medal;
    char * Time;
public:
    Record();
    Record(Record &);
    ~Record();

    bool insert(char *,char *);
    void display();
};

//this is the R_node class derived from Record class act as the LLL data structure
class R_node : public Record
{
private:
    R_node * next;
public:
    R_node();
    R_node(Record &);
    ~R_node();

    R_node *& go_next();
    void set_next(R_node *);
};
