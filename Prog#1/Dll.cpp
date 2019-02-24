//Name: Jingtao Cheng
//ID: 940067494
//Dll.cpp
//This file was the .cpp file of Dll.h which was aiming to implement all the functions declared in Dll.h file including all the member functions in dll,node,fire_surpression class

#include "Dll.h"

/*
Class node
*/

node :: node()//initial constructor
{
  pre = NULL;
  next = NULL;

  tools_name = NULL;
}
//insert node with name and other arguments in node class
void node :: insert_node(char * tool, int number, int Type)
{
    tools_name = new char[strlen(tool)+1];
    strcpy(tools_name, tool);
    tools_number = number;
    type = Type;
}
//set next pointer in this function to maintian the privacy of class
void node :: setnext(node * _next)
{
    next = _next;
}
//find next pointer and return it's address
node *& node :: getnext()
{
    return next;
}
//set previous pointer to help connect linked list
void node :: setpre(node * _pre)
{
    pre = _pre;
}
//get previous pointer and return it's address
node *& node :: getpre()
{
    return pre;
}
//simple display function to display argumetns
void node :: display()
{
    cout << "Tool: " << tools_name << endl
    << "quality: " << tools_number <<endl;
}
//desctructor to delete dynamic allocated memory
node :: ~node()
{
    delete [] pre;
    delete [] next;
    delete [] tools_name;
}

/*
Class Dll
*/

Dll :: Dll()//constructor to initialize
{
  head = NULL;
}

Dll :: ~Dll()//destructor to deallocate dynamic allocated memory
{
    delete [] head;
}
//add node funtion and pass in name and other arguments
void Dll :: addNode(char * newtool, int number, int type)
{
    if(!head)
    {
        head = new node;
        head -> insert_node(newtool, number, type);
        head -> setpre(NULL);
        head -> setnext(NULL);
        return;
    }
    else{
        node * temp = new node;
        temp -> insert_node(newtool, number, type);
        temp -> setpre(NULL);
        head -> setpre(temp);
        temp -> setnext(head);
        head = temp;
    }
}
//simply display function aiming to display all the tools in DLL(Wrapper)
void Dll :: displayall(int type)
{
    if(!head)
        return;
    displayall(head, type);
}
//display function display all tools by theit type
void Dll :: displayall(node * head, int Type)
{
    if(!head)
        return;
    if(head -> match(Type))
        head -> display();
    return displayall(head->getnext(), Type);
}

/*
Class Fire_surpression
*/

Fire_surpression :: Fire_surpression(){}//constructor

//add tools and theri name and other arguments
void Fire_surpression :: add_tools(char * name, int number, int type)
{
    tool_list.addNode(name, number, type);
}
//display tools by its type
void Fire_surpression :: display_tools(int type)
{
    tool_list.displayall(type);
}
//destructor
Fire_surpression :: ~Fire_surpression()
{
}
