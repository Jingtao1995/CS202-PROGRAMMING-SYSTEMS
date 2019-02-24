//Name: Jingtao Cheng 
//ID: 940067494
//prog_2.h
//this file was a header file to declare client class for
//user to operator in interface

#include "Preparation.h"

class client
{
private:
    preparation * rear;
    //function used to remove_material same with passed
    //in argument recursively
    bool remove_material(preparation *, preparation *, char *);
    //function used to search and display material same with
    //passed in argument recursively
    bool search_material(preparation *, preparation *, const char *);
    //function used to display reviewed material recursively
    void display_reviewed_material(preparation *, preparation *);
    //function used to display title and description recursively
    void display(preparation *, preparation *);
    //display n textbook (n was passed in argument) recursively
    void list_n_textbook(preparation *, preparation *, int n);
    //display n questions (n was passed in argument) recursively
    void list_n_questions(preparation *, preparation *, int n);
    //display n ppt (n was passed in argument) recursively
    void list_n_ppt(preparation *, preparation *, int n);
public:
    client();//default constructor
    ~client();//destructor
    //function used to add_textbook and implement textbook object
    bool add_textbook(const char *, const char *);
    //function used to add_practice and implement practice object
    bool add_practice(const char *, const char *);
    //function used to add_ppt and implement ppt object
    bool add_ppt(const char *, const char *);

    //display n textbook (n was passed in argument)
    void list_n_textbook(int n);
    //display n questions (n was passed in argument)
    void list_n_questions(int n);
    //display n ppt (n was passed in argument)
    void list_n_ppt(int n);

    //function used to remove_material
    bool remove_material(char *);
    //function used to set material as reviewed
    bool set_reviewed();
    // display material has been reviewed by invoke recursive
    //display_reviewed_material function
    void display_reviewed_material();
    //function used to search and display material same with
    //passed in argument by invoke recursive search material function
    bool search_material(const char *);
    //function used to add questions
    bool add_questions(char *);

    void display();//display material for review
};

bool again(); // function to ask perform again
bool YoN(); //function to response yes or no
