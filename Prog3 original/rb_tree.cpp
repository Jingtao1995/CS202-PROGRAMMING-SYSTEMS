//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 3
//
//Red_Black Tree
//rb_tree.cpp

#include "rb_tree.h"

//--------------------------------------------------------------
// Implementation of functions in node Class
//--------------------------------------------------------------

node :: node()
{
    left = NULL;
    right = NULL;
    parent = NULL;
    color = false;
}

node :: node(Sport & sport) : Sport(sport)
{
    left = NULL;
    right = NULL;
    parent = NULL;
    color = false;
}

node :: ~node()
{}

node *& node :: go_left()
{
    return this->left;
}

node *& node :: go_right()
{
    return this->right;
}

node *& node :: get_parent()
{
    return this->parent;
}

void node :: set_left(node * to_set)
{
    this->left = to_set;
}

void node :: set_right(node * to_set)
{
    this->right = to_set;
}

void node :: set_parent(node * to_set)
{
    this->parent = to_set;
}

void node :: set_color(bool to_set)
{
    this->color = to_set;
}

bool node :: check_color()
{
    return color;
}


//--------------------------------------------------------------
// Implementation of functions in rb_tree Class
//--------------------------------------------------------------

rb_tree :: rb_tree()
{
    root = NULL;
}

rb_tree :: ~rb_tree()
{
    if(remove_all())
        root = NULL;
}

bool rb_tree :: insert(Sport & sport)
{
    if(root)
        return insert(root, root->get_parent(), sport);
    else
    {
        root = new node(sport);
        root->set_parent(NULL);
        return true;
    }
    return false;
}

bool rb_tree :: insert(node *& root,node *& parent,Sport & sport)
{
    if(root != NULL)
    {
        parent = root;
        if(*root > sport) //operator overloading in Sport
            return insert(root->go_left(), parent, sport);
        else
            return insert(root->go_right(), parent, sport);
    }
    root = new node(sport);
    root->set_parent(parent);
    if(parent == NULL)
    {
        return true;
    }
    else
    {
        if(strcmp(root->Sport::get_name(),parent->get_name()) < 0)
        {
            parent->set_left(root);
        }
        else
        {
            parent->set_right(root);
        }
    }
    root->set_color(true);
    insert_balancing(root);
    return true;
}

bool rb_tree :: insert_balancing(node *& root)
{
    if((root->get_parent())->check_color())
    {
        if((root->get_parent()) == ((root->get_parent())->get_parent())->go_left())
        {
            node * temp = root->get_parent()->get_parent()->go_right();
            if(temp->check_color())
            {
                root->get_parent()->set_color(false);
                temp->set_color(false);
                root->get_parent()->get_parent()->set_color(true);
                root = root->get_parent()->get_parent();
            }
            else
            {
                if(root == root->get_parent()->go_right())
                {
                    root = root->get_parent();
                    left_rotate(root);
                }
                root->get_parent()->set_color(false);
                root->get_parent()->get_parent()->set_color(true);
                root->get_parent()->go_right()->set_color(false);
                right_rotate(root->get_parent()->get_parent());
            }
        }
        else
        {
            node * temp = root->get_parent()->get_parent()->go_left();
            if(temp->check_color())
            {
                root->get_parent()->set_color(false);
                temp->set_color(false);
                root->get_parent()->get_parent()->set_color(true);
                root = root->get_parent()->get_parent();
            }
            else
            {
                if(root == root->get_parent()->go_left())
                {
                    root = root->get_parent();
                    right_rotate(root);
                }
                root->get_parent()->set_color(false);
                root->get_parent()->get_parent()->set_color(true);
                root->get_parent()->go_left()->set_color(false);
                left_rotate(root->get_parent()->get_parent());
            }
        }
        return insert_balancing(root);
    }
    root->set_color(false);
    return true;
}

bool rb_tree :: left_rotate(node *& root)
{
    node * temp = root->go_right();
    if(root->get_parent() == NULL)
        root = temp;
    else
    {
        if(root == root->get_parent()->go_left())
            root->get_parent()->set_left(temp);
        else
            root->get_parent()->set_right(temp);
    }
    temp->set_parent(root->get_parent());
    root->set_right(temp->go_left());
    temp->go_left()->set_parent(root);
    temp->set_left(root);
    root->set_parent(temp);
    return true;
}

bool rb_tree :: right_rotate(node *& root)
{
    node * temp = root->go_left();
    if(root->get_parent() == NULL)
        root = temp;
    else
    {
        if(root->get_parent()->go_left() == root)
            root->get_parent()->set_left(temp);
        else
            root->get_parent()->set_right(temp);
    }
    temp->set_parent(root->get_parent());
    root->set_left(temp->go_right());
    temp->go_right()->set_parent(root);
    temp->set_right(root);
    root->set_parent(temp);
    return true;
}

node * rb_tree :: retrieve(char * name)
{
    if(!root)
        return NULL;
    return retrieve(root,name);
}

node * rb_tree :: retrieve(node * root, char * name)
{
    if(!root)
        return NULL;
    if(root->compare(name) > 0)//strcmp(root->name, name) > 0
    {
        return retrieve(root->go_left(),name);
    }
    else if(root->compare(name) == 0) // root == name ? operator ==
    {
        return root;
    }
    else
        return retrieve(root->go_right(),name);
}

bool rb_tree :: display(char * name)
{
    if(!root)
    {
        cout<<"Error in Display: No Root"<<endl;
        return false;
    }
    else
    {
        display(root,name);
        return true;
    }
}

void rb_tree :: display(node * root, char * name)
{
    if(!root)
        return;
    if(root->get_name() == name || root->compare(name) == 0)
    {
        root->display();
    }
    else if(root->compare(name) > 0)
        return display(root->go_left(), name);
    else
        return display(root->go_right(), name);
}

bool rb_tree :: display_all()
{
    if(!root)
    {
        cout<<"Display Error: No root"<<endl;
        return false;
    }
    display_all(root);
    return true;
}

void rb_tree :: display_all(node * root)
{
    if(!root)
        return;
    root->display();
    display_all(root->go_left());
    display_all(root->go_right());
}

bool rb_tree :: remove_all()
{
    if(!root)
    {
        cout<<"Delete Error: no root"<<endl;
        return false;
    }
    remove_all(root);
    return true;
}

void rb_tree :: remove_all(node *& root)
{
    if(!root)
        return;
    remove_all(root->go_left());
    remove_all(root->go_right());
    delete root;
    root = NULL;
}

rb_tree & rb_tree :: operator += (Sport & sport)
{
    insert(sport);
    return *this;
}

//--------------------------------------------------------------
// Implementation of functions about write and read file
//--------------------------------------------------------------

//this is the creat file function that can input data into the external files
void create_file()
{
    ofstream f_out;
    f_out.open("Prog3.txt", ios::app);
    if(f_out)
    {
        f_out << "" << '|';
        
        cout<<"**********-----  Loading 'Prog3.txt' File  -----********** \n";
    }
    else
        cout<<"!!!!!!!!!!-----Can't Open 'Prog3.txt' File-----!!!!!!!!!! \n";
    f_out.close();
}

//this is the read file function
void read_file(rb_tree & tree)
{
    char * sport_name = new char[25];
    char * detail = new char[50];
    char * _time = new char[25];
    char * channel = new char[25];
    char * athlete_name = new char[25];
    char * event_name = new char[25];
    char * Medal = new char[25];
    char * Time = new char[25];
    int medals = 0;
    int type = 0;

    ifstream f_in("Prog3.txt");
    if(f_in)
    {
        cout<<"**********-----  Reading 'Prog3.txt' File  -----********** \n";
        //while(!f_in.eof())
        {
            f_in>>type;
            f_in.ignore(1,'|');
            //insert function at here
            if(type == 1)
            {
                f_in.get(sport_name, 24, '|');
                f_in.ignore();

                f_in.get(detail, 49, '|');
                f_in.ignore();

                f_in.get(_time, 24, '|');
                f_in.ignore();

                f_in.get(channel, 24, '|');
                f_in.ignore();
/*
                Sport * sport = new Sport;
                sport->insert(sport_name,detail,_time,channel);
                tree.insert(*sport);
                delete sport;
 */
            }
            
            f_in>>type;
            f_in.ignore(1,'|');
            if(type == 2)
            {
                //node * new_node = tree.retrieve(sport_name);
                f_in.get(athlete_name, 24, '|');
                f_in.ignore();
                
                f_in.get(event_name, 24, '|');
                f_in.ignore();
                
                f_in>>medals;
                f_in.ignore(1,'|');
                
/*
                Athlete * athlete = new Athlete;
                athlete->insert(athlete_name,event_name,medals);
                new_node->insert_athlete(*athlete);
                delete athlete;
 */
            }
            
            f_in>>type;
            f_in.ignore(1,'|');
            if(type == 3)
            {
                //A_node * new_A_node = new_node->retrieve(athlete_name);
                f_in.get(Medal, 24, '|');
                f_in.ignore();
                
                f_in.get(Time, 24, '|');
                f_in.ignore();
/*
                Record * record = new Record;
                record->insert(Medal, Time);
                new_A_node->insert_record(*record);
                delete record;
*/
            }
            
            Sport * sport = new Sport;
            sport->insert(sport_name,detail,_time,channel);
            tree.insert(*sport);
            delete sport;
            
            node * new_node = tree.retrieve(sport_name);
            Athlete * athlete = new Athlete;
            athlete->insert(athlete_name,event_name,medals);
            new_node->insert_athlete(*athlete);
            delete athlete;
            
            A_node * new_A_node = new_node->retrieve(athlete_name);
            Record * record = new Record;
            record->insert(Medal, Time);
            new_A_node->insert_record(*record);
            delete record;
        }
    }
    else
    {
        cout<<"!!!!!!!!!!----- Can't Open 'Prog3.txt' File -----!!!!!!!!!! \n";
        //creat_file();
    }
    f_in.close();
    delete [] sport_name;
    delete [] athlete_name;
    delete [] detail;
    delete [] _time;
    delete [] channel;
}

//this is the fcuntion to check if you want ot conitinue
bool again()
{
    char response;

    cout<<"Do you want to continue? Y/N"<<endl;
    cin>>response;
    cin.ignore();

    if(response == 'Y' || response == 'y')
        return true;
    else
        return false;
}

bool again1()
{
    char response;
    
    cout<<"Do you want to continue add athlete? Y/N"<<endl;
    cin>>response;
    cin.ignore();
    
    if(response == 'Y' || response == 'y')
        return true;
    else
        return false;
}

bool again2()
{
    char response;
    
    cout<<"Do you want to continue add record? Y/N"<<endl;
    cin>>response;
    cin.ignore();
    
    if(response == 'Y' || response == 'y')
        return true;
    else
        return false;
}
