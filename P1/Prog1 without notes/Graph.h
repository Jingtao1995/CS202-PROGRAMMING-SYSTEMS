//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//Graph.h

#include "Drone.h"

using namespace std;

class Vertex;
class EdgeList;
class Node;

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

bool again();
