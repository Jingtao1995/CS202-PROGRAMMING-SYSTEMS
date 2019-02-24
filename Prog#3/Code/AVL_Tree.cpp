/*--------------------------------------------
    Name: Jingtao Cheng
    Course: CS202
    Date: Nov 19.2017
    Program3
--------------------------------------------*/
#include <iomanip>
#include <fstream>
#include "AVL_Tree.h"

/*--------------------------------------------
This function is the defualt constructor of AVL_Node
 class, and will initialize all the data member to NULL
 --------------------------------------------*/
AVL_Node :: AVL_Node()
{
    race_type = NULL;
    year = 0;
    left = NULL;
    right = NULL;
    plan_head = NULL;
    record_head = NULL;
}

/*--------------------------------------------
 This function is the copy constructor of AVL_Node
 class and will copy the arguments into AVL_Node
 --------------------------------------------*/
AVL_Node :: AVL_Node(char * type, int y)
{
    plan_head = NULL;
    record_head = NULL;
    left = NULL;
    right = NULL;
    race_type = new char[strlen(type) + 1];
    strcpy(race_type, type);
    year = y;
}

/*--------------------------------------------
 This function is a copy constructor of AVL_Node
 class and will copy information from another node
 --------------------------------------------*/
AVL_Node :: AVL_Node(const AVL_Node & object)
{
    plan_head = NULL;
    record_head = NULL;
    left = NULL;
    right = NULL;
    race_type = new char[strlen(object.race_type) + 1];
    strcpy(race_type, object.race_type);
    year = object.year;
}
/*--------------------------------------------
 This function is the destructor of the AVL_Node
 class and will erase all the information in the AVL_Node
 --------------------------------------------*/
AVL_Node :: ~AVL_Node()
{
    delete [] race_type;
    race_type = NULL;
    remove_all_plan(plan_head);
    remove_all_record(record_head);
}

/*--------------------------------------------
 This function will return the left pointer of
 AVL_Node support to traversal
 --------------------------------------------*/
AVL_Node *& AVL_Node :: go_left()
{
    return left;
}
/*--------------------------------------------
 This function will return the right pointer of
 AVL_Node support to traversal
 --------------------------------------------*/
AVL_Node *& AVL_Node :: go_right()
{
    return right;
}

/*--------------------------------------------
 This function is used to set left pointer to
 connect each node in the tree
 --------------------------------------------*/
void AVL_Node :: set_left(AVL_Node * left_child)
{
    left = left_child;
}

/*--------------------------------------------
 This function is used to set right pointer to
 connect each node in the tree
 --------------------------------------------*/
void AVL_Node :: set_right(AVL_Node * right_child)
{
    right = right_child;
}

/*--------------------------------------------
 This function is used to insert plan information
 and call the private recursive function
 --------------------------------------------*/
void AVL_Node :: insert_plan(const Plan_Node & object)
{
    insert_plan(object, plan_head);
}

/*--------------------------------------------
 This function is used to insert record information
 and call the private recusive function
 --------------------------------------------*/
void AVL_Node :: insert_record(Record_Node & object)
{
    insert_record(object, record_head);
}

/*--------------------------------------------
 THis function is the recursive function to
 insert plan information
 --------------------------------------------*/
void AVL_Node :: insert_plan(const Plan_Node & object, Plan_Node *& head)
{
    Plan_Node * temp = new Plan_Node(object);
    * temp + head;
    head = temp;
}

/*--------------------------------------------
 THis function is the recursive function to insert
 record information
 --------------------------------------------*/void AVL_Node :: insert_record(Record_Node & object, Record_Node *& head)
{
    if(!head)
    {
        head = new Record_Node(object);
        head -> set_next(NULL);
        return;
    }
    if(object.get_year() > head -> get_year())
    {
        Record_Node * temp = new Record_Node(object);
        temp -> set_next(head);
        head = temp;
        return;
    }
    return insert_record(object, head -> go_next());
}

/*--------------------------------------------
 This function is used to display race information
 --------------------------------------------*/
void AVL_Node :: display()
{
    cout << " Race type : " << race_type << endl << "<><><><><><><><><><><>" << endl;
}

/*--------------------------------------------
 This function is used to display all plan and
 invoke recursive function
 --------------------------------------------*/
void AVL_Node :: display_plan()
{
    display_plan(plan_head);
}

/*--------------------------------------------
 This function is used to display all record
 and invoke recursive funciton
 --------------------------------------------*/
void AVL_Node :: display_record()
{
    display_record(record_head);
}

/*--------------------------------------------
 This function is used to display all plan
 recursively
 --------------------------------------------*/
void AVL_Node :: display_plan(Plan_Node * head)
{
    if(!head)
        return;
    head -> display();
    cout << endl;
    return display_plan(head -> go_next());
}

/*--------------------------------------------
 This function is used to display all record
 recursively
 --------------------------------------------*/
void AVL_Node :: display_record(Record_Node * head)
{
    if(!head)
        return;
    head -> display();
    cout << endl;
    return display_record(head -> go_next());
}
/*
Those several function was designed to support search function
to running for test



bool AVL_Node :: search_plan(char * to_find)
{
    if(search_plan(plan_head, to_find))
        return true;
    return false;
}
bool AVL_Node :: search_plan(Plan_Node *head, char *to_find)
{
    if(!head)
        return false;
    if(*head != to_find)
    {
        head -> display();
    }
    return search_plan(head -> go_next(), to_find);
}

bool AVL_Node :: search_record(char * to_find)
{
    if(search_record(record_head, to_find))
        return true;
    return false;
}

bool AVL_Node :: search_record(Record_Node *head, char *to_find)
{
    if(!head)
        return false;
    if(*head != to_find)
        head -> display();
    return search_record(head -> go_next(), to_find);
}
*/

/*--------------------------------------------
 This function is used to compare race_type and
 return -1 0 1
 --------------------------------------------*/
int AVL_Node :: compare(char * to_compare)
{
    int i = strcmp(race_type, to_compare);
    return i;
}

/*--------------------------------------------
 This funciton is used to remove all plan node
 recursively support destructor to erase all node
 --------------------------------------------*/
void AVL_Node :: remove_all_plan(Plan_Node *& head)
{
    if(!head)
        return;
    Plan_Node * temp = head;
    head = head -> go_next();
    delete temp;
    temp = NULL;
    return remove_all_plan(head);
}

/*--------------------------------------------
 This function is used to remove all record node
 recursively and support destructor to erase all node
 --------------------------------------------*/
void AVL_Node :: remove_all_record(Record_Node *& head)
{
    if(!head)
        return;
    Record_Node * temp = head;
    head = head -> go_next();
    delete temp;
    temp = NULL;
    return remove_all_record(head);
}

/*--------------------------------------------
 This is the default constructor of AVL_Tree class
 and set root to NULL
 --------------------------------------------*/
AVL_Tree :: AVL_Tree()
{
    root = NULL;
}

/*--------------------------------------------
 This is the default destructor of AVL_Tree class
 and used to delete all node in AVL tree
 --------------------------------------------*/
AVL_Tree :: ~AVL_Tree()
{
    remove_all(root);
}

/*--------------------------------------------
 This function is used to remove all node in
 AVL tree
 --------------------------------------------*/
void AVL_Tree :: remove_all(AVL_Node *& root)
{
    if(root)
    {
        if(root -> go_left())
            remove_all(root -> go_left());
        if(root -> go_right())
            remove_all(root -> go_right());
        delete root;
        root = NULL;
    }
}

/*--------------------------------------------
 This is the display function to display all
 root in tree
 --------------------------------------------*/
void AVL_Tree :: display()
{
    display(root);
}

/*--------------------------------------------
 THis is the recursive display function to
 display all node in tree
 --------------------------------------------*/
int AVL_Tree :: display(AVL_Node * root)
{
    if(!root)
        return 0;
    root -> display();
    root -> display_plan();
    root -> display_record();
    cout << endl << "==========================================" << endl;
    return display(root -> go_left()) + display(root -> go_right());
}

/*--------------------------------------------
 THis is the search function to search race_type
 in the AVL tree
 --------------------------------------------*/
bool AVL_Tree :: search_race(char * to_find)
{
    if(search_race(to_find, root))
        return true;
    return false;
}

/*--------------------------------------------
 THis is the funciton used to search race_type
 recursively
 --------------------------------------------*/
bool AVL_Tree :: search_race(char *to_find, AVL_Node *root)
{
    if(!root)
        return false;
    if(root -> compare(to_find))
    {
        root -> display();
        return true;
    }
    return search_race(to_find, root -> go_left()) + search_race(to_find, root -> go_right());
}

/*--------------------------------------------
 This is the function used to insert plan into
 AVL tree
 --------------------------------------------*/
void AVL_Tree :: insert_plan(const Plan_Node & object, AVL_Node * dest)
{
    dest -> insert_plan(object);
}

/*--------------------------------------------
 This is the function used to insert record into
 AVL tree
 --------------------------------------------*/
void AVL_Tree :: insert_record(Record_Node & object, AVL_Node * dest)
{
    dest -> insert_record(object);
}

/*--------------------------------------------
 This is the function used to get tree's height
 or subtree's height
 --------------------------------------------*/
int AVL_Tree :: get_height(AVL_Node * root)
{
    if(!root)
        return 0;
    if(get_height(root -> go_left()) > get_height(root -> go_right()))
        return get_height(root -> go_left()) + 1;
    return get_height(root -> go_right()) + 1;
}

/*--------------------------------------------
 This function is used to get the tree balanced
 by left left rotate
 --------------------------------------------*/
AVL_Node * AVL_Tree :: left_left_rotation(AVL_Node *&k2)
{
    AVL_Node * k1;
    k1 = k2 -> go_left();
    k2 -> go_left() = k1 -> go_right();
    k1 -> go_right() = k2;
    return k1;
}

/*--------------------------------------------
 THis function is used to get the tree balacned
 by right right rotate
 --------------------------------------------*/
AVL_Node * AVL_Tree :: right_right_rotation(AVL_Node *&k1)
{
    AVL_Node * k2;
    k2 = k1 -> go_right();
    k1 -> go_right() = k2 -> go_left();
    k2 -> go_left() = k1;
    return k2;
}

/*--------------------------------------------
 This is the function used to get the tree
 balanced by left right rotate
 --------------------------------------------*/
AVL_Node * AVL_Tree :: left_right_rotation(AVL_Node *&k2)
{
    k2 -> go_left() = right_right_rotation(k2 -> go_left());
    return left_left_rotation(k2);
}

/*--------------------------------------------
 This is the function used to get the tree
 balanced by right left rotate
 --------------------------------------------*/
AVL_Node * AVL_Tree :: right_left_rotation(AVL_Node *&k2)
{
    k2 -> go_right() = left_left_rotation(k2 -> go_right());
    return right_right_rotation(k2);
}

/*--------------------------------------------
 This funciton is used to inser race and
 invoke recursive function
 --------------------------------------------*/
AVL_Node * AVL_Tree :: insert_race(char * race, int date)
{
    return insert_race(root, race, date);
}

/*--------------------------------------------
 This is the recursive fuction to insert race
 and if the tree is not balanced it will do
 rotate to make the tree balanced
 --------------------------------------------*/
AVL_Node * AVL_Tree :: insert_race(AVL_Node *& root, char * race, int date)
{
    if(!root)
    {
        root = new AVL_Node(race, date);
        root -> set_left(NULL);
        root -> set_right(NULL);
    }
    else if(root -> compare(race) == 0)
    {
        cout << "Already Exist" << endl;
    }
    else if(root -> compare(race) < 0)
    {
        insert_race(root -> go_left(), race, date);
        if((get_height(root -> go_left()) - get_height(root -> go_right())) == 3)
        {
            if(root -> go_left() -> compare(race) > 0)
                root = left_left_rotation(root);
            else
                root = left_right_rotation(root);
        }
    }
    else if(root -> compare(race) > 0)
    {
        insert_race(root -> go_right(), race, date);
        if((get_height(root -> go_right()) - get_height(root -> go_left()))== 3)
        {
            if(root -> go_right() -> compare(race) < 0)
                root = right_right_rotation(root);
            else
                root = right_left_rotation(root);
        }
    }
    return root;
}

/*--------------------------------------------
This is the function used to read file and get
 information into the tree
 --------------------------------------------*/
void AVL_Tree :: read_file()
{
    char race[21];
    int date;
    char record[21];
    int time;
    char name[21];
    int freq;
    char exercise[21];
    int days;

    ifstream f_in("race.txt");
    if(f_in)
    {

        while(!f_in.eof())
        {
            f_in.get(race, 21, '|');
            f_in.ignore();

            f_in >> date;
            f_in.ignore();

            f_in.get(record, 21, '|');
            f_in.ignore();

            f_in >> time;
            f_in.ignore();

            f_in.get(name, 21, '|');
            f_in.ignore();

            f_in >> freq;
            f_in.ignore();

            f_in.get(exercise, 21, '|');
            f_in.ignore();

            f_in >> days;
            f_in.ignore();

            //insert function at here
            AVL_Node * temp = insert_race(race, date);
            Plan_Node plan_object(name, exercise, freq, days);
            Record_Node record_object(record, time);
            insert_plan(plan_object, temp);
            insert_record(record_object, temp);
        }
        cout<<"**********-----  Reading 'race.txt' File  -----********** \n";
    }
    else
        cout<<"!!!!!!!!!!----- Can't Open 'race.txt' File -----!!!!!!!!!! \n";
    f_in.close();
}

/*--------------------------------------------
 This is the function used to write file and get
 information into the file
 --------------------------------------------*/
void create_file(char * race, int date, char * record, int time, char * name, char * exercise, int freq, int days)
{
    ofstream f_out;
    f_out.open("race.txt", ios::app);
    if(f_out)
    {
        f_out << race << '|';
        f_out << date << '|';
        f_out << record << '|';
        f_out << time << '|';
        f_out << name << '|';
        f_out << freq << '|';
        f_out << exercise << '|';
        f_out << days << '|';
        cout<<"**********-----  Loading 'race.txt' File  -----********** \n";
    }
    else
        cout<<"!!!!!!!!!!-----Can't Open 'race.txt' File-----!!!!!!!!!! \n";
    f_out.close();
}
