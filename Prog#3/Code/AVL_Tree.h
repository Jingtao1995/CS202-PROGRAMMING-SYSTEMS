/*--------------------------------------------
    Name: Jingtao Cheng
    Course: CS202
    Date: Nov 19.2017
    Program3
--------------------------------------------*/
/*--------------------------------------------
 This is the prototype of AVL node and AVL tree
 class which is used to store the race information
 and build a AVL tree, this is also a interface
 of this program
 --------------------------------------------*/
#include "Record&Plan.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

/*--------------------------------------------
 This is the AVL node class and store the race
 information and plan'head pointer and record's
 head pointer also provide funciton to operator
 --------------------------------------------*/
class AVL_Node
{
private:
    char * race_type;
    int year;

    AVL_Node * left;
    AVL_Node * right;

    Plan_Node * plan_head;
    Record_Node * record_head;

    //bool search_plan(Plan_Node * head, char * to_find);
    //bool search_record(Record_Node * head, char * to_find);
    void display_plan(Plan_Node * head);
    void display_record(Record_Node * head);

    void insert_plan(const Plan_Node & object, Plan_Node *& head);
    void insert_record(Record_Node & object, Record_Node *& head);
    void remove_all_plan(Plan_Node *&);
    void remove_all_record(Record_Node *&);
public:
    AVL_Node();
    AVL_Node(char *, int);
    AVL_Node(const AVL_Node &);
    ~AVL_Node();

    AVL_Node *& go_left();
    AVL_Node *& go_right();
    void set_left(AVL_Node *);
    void set_right(AVL_Node *);

    void display_plan();
    void display_record();
    void display();

    bool search_race(char * to_find);
    //bool search_plan(char * to_find);
    //bool search_record(char * to_find);
    int compare(char * to_compare);

    void insert_plan(const Plan_Node &);
    void insert_record(Record_Node &);
};

/*--------------------------------------------
 This is the AVL tree class used to form a AVL
 tree and doing many operation to manage the race
 information, plan information, record inforamtion
 and self balancing function
 --------------------------------------------*/
class AVL_Tree
{
private:
    AVL_Node * root;

    int display(AVL_Node *);
    bool search_race(char * to_find, AVL_Node * root);
    int get_height(AVL_Node *);
    AVL_Node * insert_race(AVL_Node *&, char *, int);

    void remove_all(AVL_Node *&);

    AVL_Node * left_left_rotation(AVL_Node *& k2);
    AVL_Node * right_right_rotation(AVL_Node *& k1);
    AVL_Node * left_right_rotation(AVL_Node *& k2);
    AVL_Node * right_left_rotation(AVL_Node *& k2);
public:
    AVL_Tree();
    ~AVL_Tree();

    AVL_Node * insert_race(char *, int);
    void display();
    bool search_race(char *);
    void insert_plan(const Plan_Node &, AVL_Node * dest);
    void insert_record(Record_Node &, AVL_Node * dest);
    void read_file();
};
//global function used to create file;
void create_file(char * race, int date, char * record, int time, char * name, char * exercise, int freq, int days);
