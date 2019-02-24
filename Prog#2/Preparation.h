//Name: Jingtao Cheng 
//ID: 940067494
//Preparation.h
//this file was a header file for declare abstract base
//class(preparation) and it's child


#include <iostream>
#include <cstdio>
#include <cstring>
#include "node.h"

using namespace std;


//preparation class was a abstract base class for
//prepare materials which has title, description,
//a signal for review, and type
//I design it as a node of cll
class preparation
{
protected:
    char * title; //titile of each materials
    char * description;// a papragraph description of materials
    int type; //materials' type

    preparation * next;//next pointer used to link cll
    bool reviewed;//signal for check reviewed

public:
    preparation();//default constructor
    virtual ~preparation();//virtual destructor
    //virtual remove function
    virtual bool remove_material(char *) = 0;
    //virtual compare function
    virtual bool compare(const char *) = 0;
    //virtual add question function
    virtual bool add_questions(char *) = 0;
    //virtual check type function
    virtual bool check_type(int t) = 0;
    //virtual display function
    virtual void display() const = 0;
    //virtual display question function
    virtual int display_question(int & num) = 0;
    //function used to set materials as reviewed
    void set_reviewed();
    //function to find and display reviewed materials
    void display_reviewed() const;
    //virtual get next pointer function
    virtual preparation *& get_next() = 0;
    //virtual connect next function
    virtual bool connect_next(preparation *) = 0;
};

class textbook : public preparation
{
protected:

public:
    //copy constructor with 2 arguments
    textbook(const char * _title, const char * _description);
    //textbook(const preparation &);
    ~textbook();//destructor

    virtual bool remove_material(char * book_title);//function used to remove_material
    virtual bool compare(const char *);//function used to compare title with argumetns passed in
    virtual bool add_questions(char *);//function to add question
    virtual bool check_type(int t);//function to check type for display

    virtual int display_question(int & num);//function used to display question
    virtual void display() const;//function used to display title and description

    virtual preparation *& get_next();//derived function to get next pointer
    virtual bool connect_next(preparation *);//function to set next pointer
};

class practice : public preparation
{
protected:
    lll_node * head; //head pointer of lll
    lll_node * tail; //tail pointer of lll
    //function used to display_question recursively
    void display_question(int & num, lll_node * head);
    //function to add question recursively
    bool add_questions(char *, lll_node *&, lll_node *&);
    //remove_all_nodes by reference recursively
    bool remove_all_nodes(lll_node *& head);
public:

    practice(); //default constructor
    //copy constructor with 2 argumetns
    practice(const char * _title, const char * _description);
    ~practice();//destructor

    //function to remove_all_nodes in lll
    bool remove_all_nodes();
    //wrapper function to invoke recursive add question function
    bool add_questions(char *);
    //function to find and remove_material
    virtual bool remove_material(char * question_title);
    //function to compare title with arguments passed in
    virtual bool compare(const char * source);
    //function to check type with arguments passed in
    virtual bool check_type(int t);

    //function to display title and description
    virtual void display() const;
    //function to display questions by invoke recursive display function
    int display_question(int & num);

    //function to get next pointer
    virtual preparation *& get_next();
    //function to connect next pointer
    virtual bool connect_next(preparation *);
};

class ppt : public preparation
{
protected:

public:
    //copy constructor with 2 argumetns
    ppt(const char * _title, const char * _description);
    //ppt(const preparation &);
    ~ppt();//destructor

    //function to find and remove_material
    virtual bool remove_material(char * ppt_title);
    //function to compare title with arguments passed in
    virtual bool compare(const char * source);
    //function used to add question
    virtual bool add_questions(char *);
    //function to check type with arguments passed in
    virtual bool check_type(int t);
    //function used to display_question
    virtual int display_question(int & num);

    //function to get next pointer
    virtual preparation *& get_next();
    //function to connect next pointer
    virtual bool connect_next(preparation *);
    //function to display title and description
    virtual void display() const;
};
