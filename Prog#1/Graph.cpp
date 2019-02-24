//Name: Jingtao Cheng
//ID: 940067494
//Graph.cpp
//This file was used to implement function for building a graph
#include "Graph.h"
//costructor of EdgeNode
EdgeNode :: EdgeNode()
{
    adjacent = NULL;
    next = NULL;
}
//destructor
EdgeNode :: ~EdgeNode()
{
    delete [] adjacent;
    delete [] next;
}
//function was used to add Edge in vertex
void EdgeNode :: addadjacent(VertexNode * newEdge)
{
    adjacent = newEdge;
}
//function used to set the next pointer to build the linear linked list
void EdgeNode :: setnext(EdgeNode *_next)
{
    next = _next;
}
//constructor
VertexNode :: VertexNode()
{
    head = NULL;
    Name = NULL;
}
//destructor
VertexNode :: ~VertexNode()
{
    delete [] head;
    delete [] Name;
}
//function used to add vertex node with arguments
void VertexNode :: addVertex(char * name, int area, int fire_lev, int popl, int type)
{
    Name = new char[strlen(name)+1];
    strcpy(Name, name);
    control.set_info(area, fire_lev, popl, type);
}
 //function used to add Edge node with specific vertex node's address
void VertexNode :: addEdge(VertexNode * address)
{
    if(!head)
    {
        head = new EdgeNode;
        head -> setnext(NULL);
        head -> addadjacent(address);
    }
    EdgeNode * temp = new EdgeNode;
    temp -> addadjacent(address);
    temp -> setnext(head);
    head = temp;
}
//match function to check and help find the specific vertex
bool VertexNode :: match(char * name)
{
    if(strcmp(Name, name))
        return true;
    else
        return false;
}
//function used to check vertex exsit or not
bool VertexNode :: check_valid()
{
    if(!Name)
        return true;
    return false;
}
//display funtion  of vertex
void VertexNode :: display_info()
{
    cout << "State Name: " << Name << endl;
    control.display_info();
}
//constructor
Graph :: Graph()
{
    vertex = NULL;
    visited = NULL;
}
//initialize constructor
Graph :: Graph(int size)
{
    vertex = new VertexNode[size];
    Size = size;
}
//function used to add vertex with arguments in Graph class to invoke function in vertex class
void Graph :: addVertex(char * name, int area, int fire_lev, int popl, int type)
{
    for(int i = 0; i < Size; i++)
    {
        if(vertex[i].check_valid())
        {
            vertex[i].addVertex(name, area, fire_lev, popl, type);
            return;
            break;
        }
    }
}
//function used to add Edge node in Graph class to invoke add function in vertex class
void Graph :: addEdgeNode(char * VertexName, char * EdgeName)
{
    if(!vertex)
    {
        return;
    }
    if(addEdgeNode(VertexName, EdgeName, vertex, 1))
        cout << "Success"<<endl;
    else
        cout << "Insert Fault"<<endl;
}
//add edge fuction with arguments to find and add Edge recursively
bool Graph :: addEdgeNode(char *VertexName, char *EdgeName, VertexNode * head, int i)
{
    if(!head || i >= Size || head -> check_valid())
        return false;
    if(head -> match(VertexName))
    {
        head -> addEdge(getVertex(EdgeName));
        return true;
    }
    return addEdgeNode(VertexName, EdgeName, head+i, ++i);
}
//function used to get vertex' address for building edge list
VertexNode * Graph :: getVertex(char * name)
{
    for(int i = 0; i < Size; i++)
    {
        if(vertex -> match(name))
            return vertex;
    }
    return NULL;
}
//display fire behavior's information(wrapper)
void Graph :: display_info()
{
    display_info(vertex, 1);
}
//display relative information about fire status
void Graph :: display_info(VertexNode * head, int i)
{
    if(!head || i >= Size || head -> check_valid())
        return;
    head -> display_info();
    display_info(head+i, ++i);
}
//function used to set (edit) fire surpression : tools etc.
void Graph :: set_surpression(char * toolname, int quantity, int type)
{
    vertex -> set_surpression(toolname, quantity, type);
}
//function used to edit fire surpression in vertex class
void VertexNode :: set_surpression(char * toolname, int quantity, int type)
{
    control.edit_surpression(toolname, quantity, type);
}


//destructor
Graph :: ~Graph()
{}
//check again function below:
bool again()
{
    char response;
    
    cout<<"Again? Y/N"<<endl;
    cin>>response;
    cin.ignore(100, '\n');
    
    if(response == 'Y' || response == 'y')
        return true;
    else
        return false;
}

bool YoN()
{
    char response;
    
    cout<<"Y/N"<<endl;
    cin>>response;
    cin.ignore(100, '\n');
    
    if(response == 'Y' || response == 'y')
        return true;
    else
        return false;
}
