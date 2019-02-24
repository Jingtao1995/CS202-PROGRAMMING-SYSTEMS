//Dll.h
//Name: Jingtao Cheng
//ID: 940067494
//Dll.h
//This is the header file of Dll. Including node, Dll and fire_surpression(tools,activities).
#include <iostream>
#include <cstring>
using namespace std;

/*
This class was created to build the node of DLL with it's pre and next pointer and other useful functions like getter and setter as well as display function
 */

class node //Tools node
{
public:
	node(); //constructor
	void insert_node(char *, int, int); //this function used to copy arguments in to private member.

    void setnext(node *); //this function used to connet linear linked list to set next pointer
    node *& getnext();//this function used to get address of next pointer.
    void setpre(node *);//this function used to connect linear linked list and set previous pointer
    node *& getpre();//this function used to get address of previous pointer.
    void display();//simply display function to display private member.
    bool match(int Type)//function used to check the fire type for choosing proper tools
    {
        if(Type == type || type == 4)
            return true;
        return false;
    }
	~node(); //destructor

private:
	node * pre; // previous pointer
	node * next; // next pointer

	char * tools_name; //name of tools
    int tools_number; // quantity of tools
    int type; // tool type for different situation, 1 for areal, 2 for struct, 3 for wild, 4 for all

};
/*
 this class was created to build the double linked list, including the list's head pointer and add/remove function, as well as display function
 */
class Dll
{
public:
	Dll();//constructor
	void addNode(char *, int, int);//add node in dll, pass in name and other arguments
    void removeNode(char *);//remove node in dll by it's name
    void displayall(int);//display all the tools stored in the Dll
    ~Dll();//destructor

private:
	node * head;//head pointer of Dll
    void displayall(node *, int); //display function recursively
};
/*
 This might be a base class for different fire surpression activities, the function was built to involk functions in Dll
 */
class Fire_surpression
{
public:
	Fire_surpression(); //constructor
	~Fire_surpression(); //destructor
    
    void add_tools(char * name, int number, int type);//add tools with name and other arguments
    void display_tools(int);//display funtion by type
protected:
	Dll tool_list; //dll list object


};
