//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//client.cpp

#include "Graph.h"

using namespace std;

Control_center :: Control_center()
{
    array = NULL;
    
    restrict_column_left = 0;
    restrict_column_right = 0;
    restrict_row_up = 0;
    restrict_row_down = 0;
}

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

Control_center :: ~Control_center()
{
    delete [] array;
}

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

void Control_center :: active_mode(Vertex * drone)
{
    drone -> active_mode();
}

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

void Control_center :: display()
{
    for(int i=0; i<MAX; i++)
    {
        if(array[i] != NULL)
            array[i]->display();
    }
}

Vertex :: Vertex()
{
    drone = NULL;
}

Vertex :: Vertex(char * name,int longitude,int latitude,int altitude, int type)
{
    if(type == 1)
        drone = new Small_Drone(longitude,latitude,altitude,name);
    else if(type == 2)
        drone = new Medium_Drone(longitude,latitude,altitude,name);
    else if(type == 3)
        drone = new Large_Drone(longitude,latitude,altitude,name);
}

Vertex :: ~Vertex()
{
    delete [] drone;
}

bool Vertex :: add_adjacent(char * name)
{
    if(list.add_adjacent(name))
        return true;
    else
        return false;
}

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

Vertex * Vertex :: search(char * name)
{
    if(name != NULL)
    {
        if(drone->compare(name))
            return this;
        else
        {
            cout<<"not find"<<endl;
            return NULL;
        }
    }
    else
    {
        cout<<"WRONG IN SEARCH"<<endl;
    }
    return NULL;
}

void Vertex :: display()
{
    cout<<"Here is the drone's info:"<<endl;
    drone->display();
    cout<<"Here is the adjacent list's info"<<endl;
    list.display();
}

bool Vertex :: compare(char * name)
{
    if(drone->compare(name))
        return true;
    else
        return false;
}

void Vertex :: active_mode()
{
    drone->active_mode();
}

int Vertex :: move(int x, int y, int z)
{
    drone->move(x,y,z);
    return 1;
}

bool Vertex :: check_safty(int a, int b, int c, int d)
{
    if(drone->check_safty(a, b, c, d))
        return true;
    else
        return false;
}


EdgeList :: EdgeList()
{
    head = NULL;
}

EdgeList :: ~EdgeList()
{
    remove_all();
}

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


void EdgeList :: remove_all()
{
    if(!head)
        return;
    return remove_all(head);
}

void EdgeList :: remove_all(Node *& head)
{
    if(!head)
        return;
    Node * temp = head;
    head = head->getNext();
    delete temp;
    return remove_all(head);
}

void EdgeList :: display()
{
    display(head);
}

void EdgeList :: display(Node * head)
{
    if(!head)
        return;
    head->display();
    return display(head->getNext());
}

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

Node :: Node()
{
    name = NULL;
    next = NULL;
}

Node :: Node(char * name2)
{
    name = new char[strlen(name2)+1];
    strcpy(name, name2);
    next = NULL;
}

Node :: ~Node()
{
    name = NULL;
    next = NULL;
}

Node *& Node :: getNext()
{
    return next;
}

void Node :: setNext(Node * to_add)
{
    next = to_add;
}

bool Node :: compare(char * name2)
{
    if(strcmp(name, name2)==0)
        return true;
    else
        return false;
}

void Node :: display()
{
    cout<<"Adjacent Drone:  "<<name<<endl;
}

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
