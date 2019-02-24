//Name: Jingtao Cheng 
//ID: 940067494
//Preparation.cpp
//this file was a .cpp file to implement preparation.h
//for abstract base class and it's child


#include "Preparation.h"

preparation :: preparation()//default constructor
{
    title = NULL;
    description = NULL;
    type = 0;
    reviewed = false;
    next = NULL;
}

preparation :: ~preparation()//virtual destructor
{
    if(title != NULL)
        delete title;
    if(description != NULL)
        delete description;
    if(next != NULL)
        delete next;
}

//function used to set materials as reviewed
void preparation :: set_reviewed()
{
    reviewed = true;
}
/*
void preparation :: display() const
{
    cout << "Title of this preparation : " << title << endl;
    cout << "Info of this preparation : " << description << endl;
}
*/
//function to find and display reviewed materials
void preparation :: display_reviewed() const
{
    if(reviewed)
        cout << " < " << title << " > " << endl;
}

// textbook class implementation belows :


//copy constructor with 2 arguments
textbook :: textbook(const char * _title, const char * _description)
{
    if(_title != NULL)
    {
        title = new char[strlen(_title)+1];
        strcpy(title, _title);
    }
    if(_description != NULL)
    {
        description = new char[strlen(_description)+1];
        strcpy(description, _description);
    }
    type = 1;
}
/*
textbook :: textbook(const preparation & source)
{
    if(source.title != NULL)
    {
        title = new char[strlen(source.title)+1];
        strcpy(title, source.title);
    }
    if(source.description != NULL)
    {
        description = new char[strlen(source.description)+1];
        strcpy(description, source.description);
    }
}
*/
textbook :: ~textbook()//destructor
{
    if(title != NULL)
        delete title;
    if(description != NULL)
        delete description;
    //if(next != NULL)
        //delete next;
}
//function used to add question
bool textbook :: add_questions(char * questions){return true;}
//function used to display_question
int textbook :: display_question(int & num){return 1;}

//function used to remove_material
bool textbook :: remove_material(char * book_title)
{
    if(book_title != NULL)
    {
        if(!strcmp(title, book_title))
        {
            return true;
        }
        return false;
    }
    cout << "Wrong input" << endl;
    return false;
}

//function used to compare title with argumetns passed in
bool textbook :: compare(const char * source)
{
    if(source != NULL)
    {
        if(!strcmp(title, source))
            return true;
        return false;
    }
    cout << "Wrong input" << endl;
    return false;
}
//function to check type for display
bool  textbook :: check_type(int t)
{
    if(type == t)
        return true;
    return false;
}
//function used to display title and description
void textbook :: display() const
{
    cout << "Textbook Title : " << title << " ; " << endl;
    cout << "Description : " << description << " ; " << endl;
}
//derived function to get next pointer
preparation *& textbook :: get_next()
{
    return next;
}
//function to connect list (set next pointer)
bool textbook :: connect_next(preparation * nx)
{
    if(nx)
    {
        next = nx;
        return true;
    }
    return false;
}

practice :: practice()//default constructor
{
    head = NULL;
    tail = NULL;
}
//copy constructor with 2 argumetns
practice :: practice(const char * _title, const char * _description)
{
    if(_title != NULL)
    {
        title = new char[strlen(_title)+1];
        strcpy(title, _title);
    }
    if(_description != NULL)
    {
        description = new char[strlen(_description)+1];
        strcpy(description, _description);
    }
    type = 2;
}
/*
practice :: practice(const preparation & source)
{
    if(source._title != NULL)
    {
        title = new char[strlen(source._title)+1];
        strcpy(title, source._title);
    }
    if(source._description != NULL)
    {
        description = new char[strlen(source._description)+1];
        strcpy(description, source._description);
    }
}
*/

practice :: ~practice()//destructor
{
    if(title != NULL)
        delete title;
    if(description != NULL)
        delete description;
    if(next != NULL)
        delete next;
    if(head != NULL)
        delete head;
}
//wrapper function to invoke recursive add question function
bool practice :: add_questions(char * questions)
{
    return add_questions(questions, head, tail);
}
//function to add question recursively
bool practice :: add_questions(char * questions, lll_node *& head, lll_node *& tail)
{
    if(!head)
    {
        head = new lll_node(questions);
        head -> connect_next(NULL);
        tail = head;
        return true;
    }
    lll_node * temp = new lll_node(questions);
    temp -> connect_next(head);
    head = temp;
    return true;
}
//function used to display_question recursively
void practice :: display_question(int & num, lll_node * head)
{
    if(num > 0)
    {
        head -> display();
        return display_question(--num, head -> get_next());
    }
    return;
}
//function to display questions by invoke recursive display function
int practice :: display_question(int & num)
{
    display_question(num, head);
    return num;
}
//remove_all_nodes in lll
bool practice :: remove_all_nodes()
{
    return remove_all_nodes(head);
}
//remove_all_nodes by reference recursively
bool practice :: remove_all_nodes(lll_node *& head)
{
    if(!head)
        return false;
    lll_node * temp = head;
    head = head -> get_next();
    delete temp;
    temp = NULL;
    return remove_all_nodes(head) + true;
}
//function to find and remove_material
bool practice :: remove_material(char * question_title)
{
    if(question_title != NULL)
    {
        if(!strcmp(title, question_title))
        {

            remove_all_nodes();
            head = NULL;
            tail = NULL;
            return true;
        }
        return false;
    }
    cout << "Wrong input" << endl;
    return false;
}
//function to compare title with arguments passed in
bool practice :: compare(const char * source)
{
    if(source != NULL)
    {
        if(!strcmp(title, source))
            return true;
        return false;
    }
    cout << "Wrong input" << endl;
    return false;
}
//function to check type with arguments passed in
bool  practice :: check_type(int t)
{
    if(type == t)
        return true;
    return false;
}
//function to display title and description
void practice :: display() const
{
    cout << "Topic of questions : " << title << " ; " << endl;
    cout << "Description : " << description << " ; " << endl;
}
//function to get next pointer
preparation *& practice :: get_next()
{
    return next;
}
//function to connect next pointer
bool practice :: connect_next(preparation * nx)
{
    if(nx)
    {
        next = nx;
        return true;
    }
    return false;
}

//ppt class implementation belows :

//copy constructor with 2 argumetns
ppt :: ppt(const char * _title, const char * _description)
{
    if(_title != NULL)
    {
        title = new char[strlen(_title)+1];
        strcpy(title, _title);
    }
    if(_description != NULL)
    {
        description = new char[strlen(_description)+1];
        strcpy(description, _description);
    }
    type = 3;
}
/*
ppt :: ppt(const preparation & source)
{
    if(source._title != NULL)
    {
        title = new char[strlen(source._title)+1];
        strcpy(title, source._title);
    }
    if(source._description != NULL)
    {
        description = new char[strlen(source._description)+1];
        strcpy(description, source._description);
    }
}
*/
ppt :: ~ppt()//destructor
{
    if(title != NULL)
        delete title;
    if(description != NULL)
        delete description;
    if(next != NULL)
        delete next;
}

//function used to add question
bool ppt :: add_questions(char * questions){return true;}
//function used to display_question
int ppt :: display_question(int & num){return 1;}

//function to find and remove_material
bool ppt :: remove_material(char * ppt_title)
{
    if(ppt_title != NULL)
    {
        if(!strcmp(title, ppt_title))
        {

            return true;
        }
        return false;
    }
    cout << "Wrong input" << endl;
    return false;
}

//function to compare title with arguments passed in
bool ppt :: compare(const char * source)
{
    if(source != NULL)
    {
        if(!strcmp(title, source))
            return true;
        return false;
    }
    cout << "Wrong input" << endl;
    return false;
}

//function to check type with arguments passed in
bool  ppt :: check_type(int t)
{
    if(type == t)
        return true;
    return false;
}

//function to display title and description
void ppt :: display() const
{
    cout << "PPT title : " << title << " ; " << endl;
    cout << "Description : " << description << " ; " << endl;
}

//function to get next pointer
preparation *& ppt :: get_next()
{
    return next;
}

//function to connect next pointer
bool ppt :: connect_next(preparation * nx)
{
    if(nx)
    {
        next = nx;
        return true;
    }
    return false;
}
