//Name: Jingtao Cheng 
//ID: 940067494
//node.cpp
//this file was a .cpp file for implementation of node.h

#include "node.h"
//question class implementation below :


question :: question()//default constructor
{
    number = 0;
    _question = NULL;
}
//copy constructor by argumetns
question :: question(const char * initial)
{
    if(initial != NULL)
    {
        _question = new char[strlen(initial)+1];
        strcpy(_question, initial);
    }
    else
        _question = NULL;
}
//copy constructor by reference
question :: question(const question & source)
{
    if(source._question != NULL)
    {
        _question = new char[strlen(source._question)+1];
        strcpy(_question, source._question);
    }
    else
        _question = NULL;
}
//destructor
question :: ~question()
{
    if(_question != NULL)
        delete [] _question;
}
//compare function used to check _question
//and return true or false
int question :: compare(const char * match) const
{
    if(match != NULL)
    {
        if(!strcmp(_question, match))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
//compare function used to check number
//and return true or false
int question :: compare(const int num) const
{
    if(num > 0 && num == number)
    {
        return 1;
    }
    return 0;
}
//display funtion to display private member
void question :: display() const
{
    if(_question != NULL)
        cout << _question <<endl;
    else
        cout << " EMPTY." <<endl;
}
//lll_node class implementation below :


lll_node :: lll_node()//default constructor
{
    next = NULL; //initial private menmber
}
//copy constructor by arguments
lll_node :: lll_node(const char * problem) : question(problem)
{}
//copy constructor by reference
lll_node :: lll_node(const question & source) : question(source)
{}
//destructor
lll_node :: ~lll_node()
{}
//display function to invoke display function in
//the question class
void lll_node :: display()
{
    question :: display();
}
//function used to get node's next for traverse or
//other purpose
lll_node *& lll_node :: get_next()
{
    return next;
}
//function used to connect each node
bool lll_node :: connect_next(lll_node * connection)
{
    if(connection != NULL)
    {
        next = connection;
        return true;
    }
    return false;
}
