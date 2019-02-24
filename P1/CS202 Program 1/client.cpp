//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//client.cpp
//This is the client.cpp file which include graph.h file
//This file implement all the function declared in the
//graph.h file

#include "Graph.h"

using namespace std;

//This is the default constructor which can initial
//all the data member stored in the control center class
Control_center :: Control_center()
{
    array = NULL;
    
    restrict_column_left = 0;
    restrict_column_right = 0;
    restrict_row_up = 0;
    restrict_row_down = 0;
}

//This is the simple copy constructor which can assign the value into the
//control center class with passed in value
Control_center :: Control_center(int rcl,int rcr,int rru,int rrd)
{
    array = new Vertex * [MAX];
    
    for(int i=0; i<MAX; i++)
    {
        array[i] = NULL;
    }
    
    restrict_column_left = rcl;
    restrict_column_right = rcr;
    restrict_row_up = rru;
    restrict_row_down = rrd;
}

//This is the basic destructor
Control_center :: ~Control_center()
{
    delete [] array;
}

//This is the search function which will call the
//search function in the Vertex class and return the
//address of the vertex object which match the member
//passed in
Vertex * Control_center :: search(char * name)
{
    if(name != NULL)
    {
        for(int i=0; i<MAX; i++)
        {
            if(array[i])
            {
                if(array[i]->search(name))
                {
                    array[i]->display();
                    return array[i]->search(name);
                }
            }
        }
        cout<<endl<<"NOT FIND"<<endl;
        return NULL;
    }
    else
    {
        cout<<endl<<"WRONG IN SEARCH"<<endl;
        return NULL;
    }
}

//This is the basic setter class which can add a new drone with the passed in values. And it
//will find the correct address one by one
void Control_center :: add_drone(char * name,int longitude,int latitude,int altitude, int type)
{
    for(int i=0; i<MAX; i++)
    {
        if(array[i] == NULL)
        {
            array[i] = new Vertex(name,longitude,latitude,altitude, type);
            cout<<endl<<"Add Success"<<endl;
            return;
        }
    }
}

//This is the member function used to impliment different type of function
//of each different type of drone
void Control_center :: active_mode(Vertex * drone)
{
    drone -> active_mode();
}

//This is the basic void function used to call several funciton is the vertex class
//This class will raise a warnning if the drone enter a restrict area
void Control_center :: check_safty()
{
    for(int i=0; i<MAX; i++)
    {
        if(array[i] != NULL)
        {
            if(!array[i]->check_safty(restrict_column_left, restrict_column_right, restrict_row_up, restrict_row_down))
                cout<<" Alert: This drone is entering a district area "<<endl;
                array[i]->display();
        }
        else
            return;
    }
}

//This is the simple display function
void Control_center :: display()
{
    for(int i=0; i<MAX; i++)
    {
        if(array[i] != NULL)
            array[i]->display();
    }
}

//This is the default constructor to initial the data member
Vertex :: Vertex()
{
    drone = NULL;
}

//This is the vertex copy constructor, they will be implement by different type of ability
Vertex :: Vertex(char * name,int longitude,int latitude,int altitude, int type)
{
    if(type == 1)
        drone = new Small_Drone(longitude,latitude,altitude,name);
    else if(type == 2)
        drone = new Medium_Drone(longitude,latitude,altitude,name);
    else if(type == 3)
        drone = new Large_Drone(longitude,latitude,altitude,name);
}

//This is the regular destructor
Vertex :: ~Vertex()
{
    delete [] drone;
}

//This is the bool add(setter) class which will add adjacent node in the list
bool Vertex :: add_adjacent(char * name)
{
    if(list.add_adjacent(name))
        return true;
    else
        return false;
}

//This is the bool remove function, used to remove adjacent node
bool Vertex :: remove_adjacent(char * name)
{
    if(name != NULL)
    {
        if(list.remove(name))
        {
            cout<<"remove success"<<endl;
            return true;
        }
        else
        {
            cout<<"remove unsuccess"<<endl;
            return false;
        }
    }
    else
    {
        cout<<endl<<"WRONG IN REMOVE ADJACENT"<<endl;
    }
    return false;
}

//This is the search function used to return a pointer to vertex
Vertex * Vertex :: search(char * name)
{
    if(name != NULL)
    {
        if(drone->compare(name))
            return this;
    }
    else
    {
        cout<<"WRONG IN SEARCH"<<endl;
    }
    return NULL;
}

//This is the basic display function to show the information stored in
//the vertex class
void Vertex :: display()
{
    cout<<"Here is the drone's info:"<<endl;
    drone->display();
    cout<<"Here is the adjacent list's info"<<endl;
    list.display();
}

//This is hte compare function used ot compare the data member
//with the data passed in
bool Vertex :: compare(char * name)
{
    if(drone->compare(name))
        return true;
    else
        return false;
}

//This is the basic function of activation
void Vertex :: active_mode()
{
    drone->active_mode();
}

//This is the move class to set up the drone to a new position
int Vertex :: move(int x, int y, int z)
{
    drone->move(x,y,z);
    return 1;
}

//This is the check function, if it agree with tht statement, thne it
//will return a true;
bool Vertex :: check_safty(int a, int b, int c, int d)
{
    if(drone->check_safty(a, b, c, d))
        return true;
    else
        return false;
}

//This is the defualt constructor
EdgeList :: EdgeList()
{
    head = NULL;
}

//This the defualt destrucotr
EdgeList :: ~EdgeList()
{
    remove_all();
}

//This is the remove function used to delete the node in the adacent
bool EdgeList :: remove(char * name, Node *& head)
{
    if(!head)
        return false;
    if(head->compare(name))
    {
        Node * temp = head;
        head = head->getNext();
        delete temp;
        cout<<"success"<<endl;
        return true;
    }
    return remove(name, head->getNext());
}

//This is the wrapper functino of the remove function
bool EdgeList :: remove(char * name)
{
    if(name != NULL)
    {
        if(!head)
            return false;
        return remove(name,head);
    }
    else
    {
        cout<<"WRONG IN REMOVE"<<endl;
        return false;
    }
}

//This is the basic wrapper function
void EdgeList :: remove_all()
{
    if(!head)
        return;
    return remove_all(head);
}

//This is the basic function usde to clean class allocated memory recursively
void EdgeList :: remove_all(Node *& head)
{
    if(!head)
        return;
    Node * temp = head;
    head = head->getNext();
    delete temp;
    return remove_all(head);
}

//This is the wrapper display function used to show the info stored in the class
void EdgeList :: display()
{
    display(head);
}

//This is the display function recursively
void EdgeList :: display(Node * head)
{
    if(!head)
        return;
    head->display();
    return display(head->getNext());
}

//This is the setter function used to add an new adjacent node
bool EdgeList :: add_adjacent(char * name)
{
    if(name)
    {
        Node * temp = new Node(name);
        temp->setNext(head);
        head = temp;
        return true;
    }
    else
    {
        cout<<"WRONG IN ADD ADJACENT"<<endl;
        return false;
    }
}

//This is the basic constructor
Node :: Node()
{
    name = NULL;
    next = NULL;
}

//This is simple copy constructor
Node :: Node(char * name2)
{
    name = new char[strlen(name2)+1];
    strcpy(name, name2);
    next = NULL;
}

//THis is the defualt destructor
Node :: ~Node()
{
    name = NULL;
    next = NULL;
}

//This is the getter function to get the pointer point to next head.
Node *& Node :: getNext()
{
    return next;
}

//This is the setter function to set up a new shoes
void Node :: setNext(Node * to_add)
{
    next = to_add;
}

//This is the compare function,which will return true if the member
//passed in is correct.
bool Node :: compare(char * name2)
{
    if(strcmp(name, name2)==0)
        return true;
    else
        return false;
}

//This is hte basic disolay function
void Node :: display()
{
    cout<<"Adjacent Drone:  "<<name<<endl;
}

//THis is the check agian function
bool again()
{
    char a;
    cout<<" Again ? ( Y/N )"<<endl;
    cin >> a;
    cin.ignore();
    if(a=='y'||a=='Y')
    return true;
    else
    return false;
    }
