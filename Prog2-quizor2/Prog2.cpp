//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 2
//
//This is the main .cpp file which contains all
//the implentations. There are constructors,
//destructors and all the other support for the
//different data structures.

#include "Prog2.h"

//This is the default constructor for the Linear
//linked list, to initialize the member in the list
LNode :: LNode()
{
    next = NULL;
    key = NULL;
    result = NULL;
}

//this is the copy constructor, which can do a 
//deep copy of the passed in reference
LNode :: LNode(LNode & node)
{
    key = new char[strlen(node.key)+1];
    strcpy(key, node.key);
    result = new char[strlen(node.result)+1];
    strcpy(result, node.result);
    next = NULL;
}

//this is also a copy constructor but with
//the arguments passed in, with deep copy
LNode :: LNode(char * key1, char * result1)
{
    key = new char[strlen(key1)+1];
    strcpy(key,key1);
    result = new char[strlen(result1)+1];
    strcpy(result, result1);
    next = NULL;
}

//this is the destructure to deallocate the
//dynamic memory
LNode :: ~LNode()
{
    if(key != NULL)
        delete key;
    if(result != NULL)
        delete result;
}

//this function is used to get the next node's
//point so the list can get traverse
LNode *& LNode :: go_next()
{
    return this->next;
}

//this function is used to set the current node's
//next pointer, so the list can be linked together
void LNode :: set_next(LNode * to_set)
{
    next = to_set;
}

//this is the compare function to compare the member
//inside the class, and will return true or false
bool LNode :: compare(char * key1)
{
    if(strcmp(key,key1)==0)
    {
        return true;
    }
    else
        return false;
}

//this is the translate function which combine the
//retrieve function and transform function
int LNode :: translate(char * key1)
{
    if(strcmp(key,key1)==0)
    {
        cout << this->result;
        return 1;
    }
        return 0;
}

//this is the simple display function
void LNode :: display()
{
    cout<<this->key<<" ----> "<<this->result<<endl;
}



//This is the defualt constructor for the 
//initialization of the doubly linked list
DNode :: DNode()
{
    pre = NULL;
    next = NULL;
    trans = NULL;
}

//this is the copy constructor for the doubly linked
//list, shallow copy
DNode :: DNode(Translator * trans1)
{
    trans = trans1;
    pre = NULL;
    next = NULL;
}

//this is the defualt destructor
DNode :: ~DNode()
{}

//this function is used to get the next node's
//point so the list can get traverse
DNode *& DNode :: go_pre()
{
    return this->pre;
}

//this function is used to get the next node's
//point so the list can get traverse
DNode *& DNode :: go_next()
{
    return this->next;
}

//this function is used to set the current node's
//next pointer, so the list can be linked together
void DNode :: set_pre(DNode * to_set)
{
    pre = to_set;
}

//this function is used to set the current node's
//next pointer, so the list can be linked together
void DNode :: set_next(DNode * to_set)
{
    next = to_set;
}

//this is the translate function which combine the
//retrieve function and transform function
int DNode :: translate(char * key1)
{
    return trans->translate(key1);
}

//this is the remove function, to find the correct
//matching objects by passed in values
bool DNode :: remove(char * key1)
{
    if(key1 != NULL)
    {
        return trans->remove(key1);
    }
    else
    {
        cout<<"NULL STRING:DNode_remove"<<endl;
        return false;
    }
}

//display function
void DNode :: display()
{
    cout<<"<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>"<<endl;
    trans->display();
    cout<<"<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>"<<endl;
}

//this is the defalut constructor of the abstract 
//class
Translator :: Translator()
{
    head = NULL;
}

//this is the virtual destructor
Translator :: ~Translator()
{}

//this is the display function
void Translator :: display()
{
    cout<<"........."<<endl;
}

//this is the default constructor with the initialization list
Text :: Text() : Translator() {}

//this is the destructor for the derived class Text
Text :: ~Text()
{
    remove_all();
}

//This is the remove all function which can deallocate all of 
//the nodes when function in destructing
bool Text :: remove_all()
{
    if(!head)
        return false;
    return remove_all(head);
}

//This is the recursion part of the remove all function
bool Text :: remove_all(LNode *& head)
{
    if(!head)
        return false;
    else
    {
        LNode * temp = head;
        head = head->go_next();
        delete temp;
        temp = NULL;
        return remove_all(head);
    }
}

//this is the insert function which has two arguments passed
//in and will usd the front insert
bool Text :: insert(char * key1, char * result1)
{
    if(key1 != NULL && result1 != NULL)
    {
        LNode * temp = new LNode(key1, result1);
        temp->set_next(head);
        head = temp;
        return true;
    }
    else
    {
        cout<<"NULL STRING: Text_insert"<<endl;
        return false;
    }
}

//This is the remove fuction in the Text class and will 
//remove the object which matching the passed in value
bool Text :: remove(char * key1)
{
    if(key1 == NULL)
    {
        cout<<"NULL STRING: Text_remove"<<endl;
        return false;
    }
    return remove(key1, head);
}

//this is the recursion part of the remove function
bool Text :: remove(char * key1, LNode *& head)
{
    if(!head)
        return false;
    if(head->compare(key1))
    {
        LNode * temp = head;
        head = head->go_next();
        delete temp;
        temp = NULL;
        return true;
    }
    return remove(key1, head->go_next());
}

//this is the translate function which combine the
//retrieve function and transform function
int Text :: translate(char * key1)
{
    if(key1 == NULL)
    {
        cout<<"NULL STRING: Text_translate"<<endl;
        return 0;
    }
    else
        return translate(key1, head);
}

//this is the recursive translate function which combine the
//retrieve function and transform function
int Text :: translate(char * key1, LNode * head)
{
    if(!head)
        return 0;
    if(head->compare(key1))
    {
        head->translate(key1);
        return 1;
    }
    return translate(key1, head->go_next());
}

//this is the display function
void Text :: display()
{
    if(!head)
        return;
    cout<<"Type : Text"<<endl;
    return display(head);
}

//this is the recursion display function
void Text :: display(LNode * head)
{
    if(!head)
        return;
    head->display();
    return display(head->go_next());
}

//this is the defualt constructor of the Formal class
Formal :: Formal() : Translator() {}

//this is the defualt destructor of the Formal class
Formal :: ~Formal()
{
    //remove_all();
}

//this is the remove all function which will remove all nodes
//in the list
bool Formal :: remove_all()
{
    if(!head)
        return false;
    return remove_all(head);
}

//this is the remove all function which will recursively
//remove all nodes
bool Formal :: remove_all(LNode *& head)
{
    if(!head)
        return false;
    else
    {
        LNode * temp = head;
        head = head->go_next();
        delete temp;
        temp = NULL;
        return remove_all(head);
    }
}

//this is the insert function which has two passed in arguments
bool Formal :: insert(char * key1, char * result1)
{
    if(key1 != NULL && result1 != NULL)
    {
        LNode * temp = new LNode(key1, result1);
        temp->set_next(head);
        head = temp;
        return true;
    }
    else
    {
        cout<<"NULL STRING: Formal_insert"<<endl;
        return false;
    }
}

//this is the remove function for formal class
bool Formal :: remove(char * key1)
{
    if(!key1)
    {
        cout<<"NULL STRING: Formal_remove"<<endl;
        return false;
    }
    return remove(key1, head);
}
//this is the remove function which can finc and remove nodes
bool Formal :: remove(char * key1, LNode *& head)
{
    if(!head)
        return false;
    if(head->compare(key1))
    {
        LNode * temp = head;
        head = head->go_next();
        delete temp;
        temp = NULL;
        return true;
    }
    return remove(key1, head->go_next());
}

//this is the translate function which combine the
//retrieve function and transform function
int Formal :: translate(char * key1)
{
    if(key1 == NULL)
    {
        cout<<"NULL STRING: Text_translate"<<endl;
        return 0;
    }
    else
        return translate(key1, head);
}

//this is the recursive translate function which combine the
//retrieve function and transform function
int Formal :: translate(char * key1, LNode * head)
{
    if(!head)
        return 0;
    if(head->compare(key1))
    {
        head->translate(key1);
        return 1;
    }
    return translate(key1, head->go_next());
}

//this is the display function
void Formal :: display()
{
    if(!head)
        return;
    cout<<"Type : Formal"<<endl;
    return display(head);
}

//this is the recursive display function
void Formal :: display(LNode * head)
{
    if(!head)
        return;
    head->display();
    return display(head->go_next());
}

//this is the default constructor for the Special class
Special :: Special() : Translator() {}

//this is the defualt destructor
Special :: ~Special()
{
    remove_all();
}

//this is the remove_all funciton which will remove
//all nodes in the list
bool Special :: remove_all()
{
    if(!head)
        return false;
    return remove_all(head);
}

//this is the rmecursive remove all function
bool Special :: remove_all(LNode *& head)
{
    if(!head)
        return false;
    else
    {
        LNode * temp = head;
        head = head->go_next();
        delete temp;
        temp = NULL;
        return remove_all(head);
    }
}

//this is the insert function which use front insert
bool Special :: insert(char * key1, char * result1)
{
    if(key1 != NULL && result1 != NULL)
    {
        LNode * temp = new LNode(key1, result1);
        temp->set_next(head);
        head = temp;
        return true;
    }
    else
    {
        cout<<"NULL STRING: Special_insert"<<endl;
        return false;
    }
}

//this is hte remove function in the Special class
bool Special :: remove(char * key1)
{
    if(!key1)
    {
        cout<<"NULL STRING: Special_remove"<<endl;
        return false;
    }
    return remove(key1, head);
}

//this is the recursive remvoe function
bool Special :: remove(char * key1, LNode *& head)
{
    if(!head)
        return false;
    if(head->compare(key1))
    {
        LNode * temp = head;
        head = head->go_next();
        delete temp;
        temp = NULL;
        return true;
    }
    return remove(key1, head->go_next());
}

////this is the translate function which combine the
//retrieve function and transform function
int Special :: translate(char * key1)
{
    if(key1 == NULL)
    {
        cout<<"NULL STRING: Text_translate"<<endl;
        return 0;
    }
    else
        return translate(key1, head);
}

//this is the recursive translate function which combine the
//retrieve function and transform function
int Special :: translate(char * key1, LNode * head)
{
    if(!head)
        return 0;
    if(head->compare(key1))
    {
        head->translate(key1);
        return 1;
    }
    return translate(key1, head->go_next());
}

//this is the display function
void Special :: display()
{
    if(!head)
        return;
    cout<<"Type : Special"<<endl;
    return display(head);
}
//this is the recursive display function
void Special :: display(LNode * head)
{
    if(!head)
        return;
    head->display();
    return display(head->go_next());
}

//this is the client console of the applicaiton

//this is the default constructor of the client class
client :: client()
{
    head = NULL;
    tail = NULL;
}

//this is the default destructor 
client :: ~client()
{
    //remove_all();
}

//this is the remove all function
bool client :: remove_all()
{
    if(!head)
        return false;
    return remove_all(head);
}

//this is the recursive remove all function
bool client :: remove_all(DNode * head)
{
    if(!head)
        return false;
    DNode * temp = head;
    head = head->go_next();
    head->set_pre(NULL);
    delete temp;
    temp = NULL;
    return remove_all(head->go_next());
}

//this is the insert function with the pointer of 
//the Translator passed in
bool client :: insert(Translator * trans)
{
    DNode * temp = new DNode(trans);
    temp->set_pre(NULL);
    temp->set_next(head);
    head = temp;
    return true;
}

//this is hte convert funciton
void client :: formal_convert(char * arr)
{
    for(unsigned int i=0; i<(strlen(arr)+1); i++)
    {
    	cout<<arr[i];
        if(arr[i]==','||arr[i]=='!'||arr[i]=='?')
        {
            cout<<"  ";
        }
        else if(arr[i]=='.'||arr[i]==';'||arr[i]==':')
        {
            cout<<"  ";
        }
    }
}

//this is the display function
void client :: display()
{
    if(!head)
        cout<<"EMPTY LIST"<<endl;
    else
        display(head);
}

//this is the recursive display function
void client :: display(DNode * head)
{
    if(!head)
        return;
    head->display();
    return display(head->go_next());
}

//this is the read file function
void client :: read_file(int t, Translator * trans)
{
    int type = 0;
    char key[25];
    char result[25];

    ifstream f_in("Prog2.txt");
    if(f_in)
    {

        while(!f_in.eof())
        {
            f_in>>type;
            f_in.ignore();

            f_in.get(key, 25, '|');
            f_in.ignore();

            f_in.get(result, 25, '|');
            f_in.ignore();

            //insert function at here
            if(type == t)
                trans->insert(key, result);

        }
        cout<<"**********-----  Reading 'Prog2.txt' File  -----********** \n";
    }
    else
        cout<<"!!!!!!!!!!----- Can't Open 'Prog2.txt' File -----!!!!!!!!!! \n";
    f_in.close();
}

//this is the creat file function that can input data into the external files
void client :: create_file(int type, char * key, char * result)
{
    ofstream f_out;
    f_out.open("Prog2.txt", ios::app);
    if(f_out)
    {
        f_out << type << '|';
        f_out << key << '|';
        f_out << result << '|';

        cout<<"**********-----  Loading 'Prog2.txt' File  -----********** \n";
    }
    else
        cout<<"!!!!!!!!!!-----Can't Open 'Prog2.txt' File-----!!!!!!!!!! \n";
    f_out.close();
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
