//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 3
//
//Sport, Athlete, and Record Class and the Data Structure
//Sport.h

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

class A_node;
class R_node;
class Athlete;
class Record;

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
    bool operator > (Sport &);
    A_node * retrieve(char *);

    A_node *& operator += (Athlete &);
};

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
};

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
