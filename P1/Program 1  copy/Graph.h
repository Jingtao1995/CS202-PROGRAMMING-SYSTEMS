//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//Graph.h
//
//This is the Graph.h file, which use the graph data structure
//to simulate the map for the drone, thus there contains several
//class that relate to the garph data structure.
//This file include Control_center class, EdgeList class, Vertex
//and Node class.


#include "Drone.h"

using namespace std;
//predeclaration
class Vertex;
class EdgeList;
class Node;

//This class is the Control_center class, and it contain the
//restrict area information and an array of pointers point to
//Vertex class. It has copy constructor to handle with the
//dynamic memory and a pointer return type function to get the
//Vertex
class Control_center
{
private:
        Vertex ** array;
        int restrict_column_left;
        int restrict_column_right;
        int restrict_row_up;
        int restrict_row_down;
public:
        Control_center();
        Control_center(int,int,int,int);
        ~Control_center();
        Vertex * search(char *);
        void add_drone(char *,int,int,int,int type);
        void active_mode(Vertex *);
        void check_safty();
        void display();
};

//This class is the EdgeList class, it stores the head of a list of edge node
//which contains the information of the adjacent drones. It has add and remove
//functions and several wrapper functions
class EdgeList
{
private:
    Node * head;
    
    bool remove(char *, Node *&);
    void remove_all(Node *&);
    void display(Node *);
public:
    EdgeList();
    ~EdgeList();
    bool remove(char *);
    void remove_all();
    void display();
    bool add_adjacent(char *);
};

//This class is the Vertex class, and it is the basic node in the
//graph data structure. This class has a pointer points to Drone class
//and a object of EdgeList class. It has copy constructor and add and
//remove functions.
class Vertex
{
private:
        Drone * drone;
        EdgeList list;
public:
        Vertex();
        Vertex(char *,int,int,int,int type);
        ~Vertex();
        bool add_adjacent(char *);
        bool remove_adjacent(char *);
        Vertex * search(char *);
        void display();
        bool compare(char *);
        void active_mode();
        int move(int, int, int);
        bool check_safty(int,int,int,int);
};

//This is the node class with the a string and a
//pointer point to it self. It has copy construction
//and get set functions.
class Node
{
private:
    char * name;
    Node * next;
public:
    Node();
    Node(char *);
    ~Node();
    Node *& getNext();
    void setNext(Node *);
    bool compare(char *);
    void display();
};

//This function is used to check if the user want
//to continue or not
bool again();
