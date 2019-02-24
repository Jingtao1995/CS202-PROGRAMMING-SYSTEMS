//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 3
//
//Red_Black Tree
//rb_tree.h
//This is the rb_tree.h file which declare two class node class and rb_tree class
//This two class is used to assemble the self balancing tree - red black tree.


#include "Sport.h"

using namespace std;

//This is the node class which derived from the sport class
//so it is an object of Sport, it's also the basic node of the red - black tree.
//it has the basic element color to sign the red black
class node : public Sport
{
private:
    //basic element of a tree node
    node * left;
    node * right;
    node * parent;

    bool color; // red == true & black == false
public:
    node();
    node(Sport &); //copy constructor
    ~node();

    node *& go_left();
    node *& go_right();
    node *& get_parent();

    void set_left(node *);
    void set_right(node *);
    void set_parent(node *);
    void set_color(bool);

    bool check_color();

};

//this is the rb_tree class which has the basic elemnt root. This is the 
//self balancing tree - red - black tree, it has left and right rotate function
//to help make it self balancing
class rb_tree
{
private:
    node * root;

    bool insert(node *&, node *&, Sport &);
    bool insert_balancing(node *&);
    bool left_rotate(node *&);
    bool right_rotate(node  *&);

    //node *& successor(node *);
    node * retrieve(node *, char *);
    void display(node *, char *);
    void display_all(node *);
    void remove_all(node *&);

public:
    rb_tree();
    ~rb_tree();

    bool insert(Sport &);
    node * retrieve(char *);
    bool display(char *);
    bool display_all();
    bool remove_all();
    rb_tree & operator += (Sport &); //operator overloading += return reference to rb_tree
};

//function used to get in external file
void creat_file();
void read_file(rb_tree &);
bool again();
bool again1();
bool again2();
