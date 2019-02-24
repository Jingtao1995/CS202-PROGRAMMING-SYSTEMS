//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 3
//
//Red_Black Tree
//rb_tree.h

#include "Sport.h"

using namespace std;

class node : public Sport
{
private:
    node * left;
    node * right;
    node * parent;

    bool color; // red == true & black == false
public:
    node();
    node(Sport &);
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
    rb_tree & operator += (Sport &);
};

void creat_file();
void read_file(rb_tree &);
bool again();
bool again1();
bool again2();
