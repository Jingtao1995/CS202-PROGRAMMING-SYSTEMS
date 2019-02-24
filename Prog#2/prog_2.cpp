//Name: Jingtao Cheng 
//ID: 940067494
//prog_2.cpp
//this file was a .cpp file to implement client class

#include "prog_2.h"

//client class implement below :

//default constructor
client :: client()
{
    rear = NULL;
}
//destructor
client :: ~client()
{
}

//function used to add_textbook and implement textbook object
bool client :: add_textbook(const char * to_add, const char * description)
{
    if(to_add != NULL)
    {
        if(!rear)
        {
            rear = new textbook(to_add, description);
            rear -> connect_next(rear);
            return true;
        }
        preparation * temp = new textbook(to_add, description);
        temp -> connect_next(rear -> get_next());
        rear -> connect_next(temp);
        rear = temp;
        return true;
    }
    return false;
}
//function used to add_practice and implement practice object
bool client :: add_practice(const char * to_add, const char * description)
{
    if(to_add != NULL)
    {
        if(!rear)
        {
            rear = new practice(to_add, description);
            rear -> connect_next(rear);
            return true;
        }
        preparation * temp = new practice(to_add, description);
        temp -> connect_next(rear -> get_next());
        rear -> connect_next(temp);
        rear = temp;
        return true;
    }
    return false;
}

//function used to add_ppt and implement ppt object
bool client :: add_ppt(const char * to_add, const char * description)
{
    if(to_add != NULL)
    {
        if(!rear)
        {
            rear = new ppt(to_add, description);
            rear -> connect_next(rear);
            return true;
        }
        preparation * temp = new ppt(to_add, description);
        temp -> connect_next(rear -> get_next());
        rear -> connect_next(temp);
        rear = temp;
        return true;
    }
    return false;
}

//function used to add questions
bool client :: add_questions(char * questions)
{
    if(questions != NULL)
    {
        rear -> add_questions(questions);
    }
    return false;
}

//display material for review
void client :: display()
{
    preparation * head = rear -> get_next();
    return display(head, rear);
}

//function used to display title and description recursively
void client :: display(preparation * head, preparation * sign)
{
    if(head == sign)
    {
        head -> display();
        return;
    }
    head -> display();
    return display(head -> get_next(), sign);
}

//function used to set material as reviewed
bool client :: set_reviewed()
{
    rear -> set_reviewed();
    return true;
}

// display material has been reviewed by invoke recursive
//display_reviewed_material function
void client :: display_reviewed_material()
{
    preparation * head = rear -> get_next();
    return display_reviewed_material(head, rear);
}

//function used to display reviewed material recursively
void client :: display_reviewed_material(preparation * head, preparation * sign)
{
    if(head == sign)
    {
        head -> display_reviewed();
        return;
    }
    head -> display_reviewed();
    return display_reviewed_material(head -> get_next(), sign);
}

//display n textbook (n was passed in argument)
void client :: list_n_textbook(int n)
{
    preparation * head = rear -> get_next();
    return list_n_textbook(head, rear, n);
}

//display n textbook (n was passed in argument) recursively
void client :: list_n_textbook(preparation * head, preparation * sign, int n)
{
    if(n > 0)
    {
        if(head -> check_type(1))
        {
            head -> display();
            head -> set_reviewed();
        }
        if(head == sign)
            return;
        return list_n_textbook(head -> get_next(), sign, --n);
    }
    return;
}

//display n questions (n was passed in argument)
void client :: list_n_questions(int n)
{
    preparation * head = rear -> get_next();
    return list_n_questions(head, rear, n);
}

//display n questions (n was passed in argument) recursively
void client :: list_n_questions(preparation * head, preparation * sign, int n)
{
    if(n > 0)
    {
        if(head -> check_type(2))
        {
            n = head -> display_question(n);
            head -> set_reviewed();
        }
        if(head == sign)
            return;
        return list_n_questions(head -> get_next(), sign, n);
    }
    return;
}

//display n ppt (n was passed in argument)
void client :: list_n_ppt(int n)
{
    preparation * head = rear -> get_next();
    return list_n_ppt(head, rear, n);
}

//display n ppt (n was passed in argument) recursively
void client :: list_n_ppt(preparation * head, preparation * sign, int n)
{
    if(n > 0)
    {
        if(head -> check_type(3))
        {
            head -> display();
            head -> set_reviewed();
        }
        if(head == sign)
            return;
        return list_n_ppt(head -> get_next(), sign, --n);
    }
    return;
}

//function used to remove_material
bool client :: remove_material(char * to_remove)
{
    if(to_remove == NULL)
        return false;
    preparation * head = rear -> get_next();
    return remove_material(head, rear, to_remove);
}

//function used to search and display material same with
//passed in argument recursively
bool client :: remove_material(preparation * head, preparation * sign, char * to_remove)
{
    if(head -> remove_material(to_remove))
    {
        preparation * temp = head;
        head = head -> get_next();
        delete temp;
        temp = NULL;
        return true;
    }
    if(head == sign)
        return false;
    return remove_material(head -> get_next(), sign, to_remove);
}

//function used to search and display material same with
//passed in argument by invoke recursive search material function
bool client :: search_material(const char * to_find)
{
    if(to_find == NULL)
        return false;
    preparation * head = rear -> get_next();
    return search_material(head, rear, to_find);
}

//function used to search and display material same with
//passed in argument recursively
bool client :: search_material(preparation * head, preparation * sign, const char * to_find)
{
    if(head -> compare(to_find))
    {
        head -> display();
        return true;
    }
    if(head == sign)
        return false;
    return search_material(head -> get_next(), sign, to_find);
}






//check again function below:
bool again()
{
    char response;

    cout<<"Again? Y/N"<<endl;
    cin>>response;
    cin.ignore(100, '\n');

    if(response == 'Y' || response == 'y')
        return true;
    else
        return false;
}

bool YoN()
{
    char response;

    cout<<"Y/N"<<endl;
    cin>>response;
    cin.ignore(100, '\n');

    if(response == 'Y' || response == 'y')
        return true;
    else
        return false;
}
