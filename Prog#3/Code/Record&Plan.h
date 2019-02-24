/*--------------------------------------------
    Name: Jingtao Cheng
    Course: CS202
    Date: Nov 19.2017
    Program3
--------------------------------------------*/
/*--------------------------------------------
 This is the prototype of the record and plan
 class to build the node of record list and
 plan list and store the information
 --------------------------------------------*/
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

/*--------------------------------------------
 This is the record class used to store the
 record information and the base class of record
 node class
 --------------------------------------------*/
class Record
{
protected:
    char * race_record;
    int year;
public:
    Record();
    Record(char *, int);
    Record(const Record&);
    ~Record();
    void display();
    bool compare(char *);
};

/*--------------------------------------------
 This is the record node class inherit from
 record class used to build the node of the
 linear link list
 --------------------------------------------*/
class Record_Node : public Record
{
private:
    Record_Node * next;
public:
    Record_Node();
    Record_Node(char *, int);
    Record_Node(const Record_Node&);
    Record_Node *& go_next();
    void set_next(Record_Node *);
    void display();
    int get_year();
    bool operator != (char *); // chack match
};

/*--------------------------------------------
 THis is the plan class used to store the infor
 about plan and be the base class of plan node
 class
 --------------------------------------------*/
class Plan
{
protected:
    char * plan_name;
    char * exercise_type; // Endurance Strengh Balance Flexbility
    int frequency; //every n days per training
    int training_days;
public:
    Plan();
    Plan(char *, char *, int, int);
    Plan(const Plan &);
    ~Plan();
    void display();
    bool compare(char *);
};

/*--------------------------------------------
 This is the plan node class that inherit from
 plan class used to build node of linear linked
 list
 --------------------------------------------*/
class Plan_Node : public Plan
{
private:
    Plan_Node * next;
public:
    Plan_Node();
    Plan_Node(char *, char *, int, int);
    Plan_Node(const Plan_Node &);
    Plan_Node *& go_next();
    void set_next(Plan_Node *);
    void display();
    //bool search_by_name(char *);
    void operator + (Plan_Node *); // connect node to next;
    bool operator != (char *);
};
