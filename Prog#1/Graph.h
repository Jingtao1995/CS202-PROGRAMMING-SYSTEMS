//Name: Jingtao Cheng
//ID: 940067494
//Graph.h
//This file was used to built a map related with fire status and IC manager
#include <iostream>
#include <cstring>
#include "Manager.h"

using namespace std;
//pre implementation
class VertexNode;
class Fire_behavior;
//Edge node class for building edge list
class EdgeNode
{
public:
	EdgeNode();//constructor
	void addadjacent(VertexNode *);//add Edge node pointer to vertex's address
    void setnext(EdgeNode * _next);//set next function to link every node as a list
	~EdgeNode();//desctructor
    void display_all(EdgeNode *);//display all edge node
private:
    VertexNode * adjacent; // adjacent pointer to vertex node
	EdgeNode * next; // next pointer point to edge node

};
//class of vertex node
class VertexNode
{
public:
	VertexNode();//constructor
	void addVertex(char *, int, int, int, int);//a function used to add Edge node with specific vertex node's address
    bool match(char *);//match function to check and help find the specific vertex
    bool check_valid();//function used to check vertex exsit or not
    void addEdge(VertexNode *);//display funtion  of vertex
	void deleteVertex(char *);//function used to delete vertex base on their name
	~VertexNode();//destructor
    void set_surpression(char *, int, int);//set surpression like tools etc.
    
    void display_info();//display fire situation
private:
	EdgeNode * head; //head pointer  of edge list
	char * Name; // vertex's name (state name)
    IC_manager control; //object of IC_manager
};
//graph class form the map and declare other funtions as getter setter and display etc
class Graph
{
public:
	Graph();//constructor
    Graph(int size);//constructor with arguments
	void addVertex(char *, int, int, int, int);//function used to add vertex with arguments in Graph class to invoke function in vertex class
	void addEdgeNode(char *, char *);//function used to add Edge node in Graph class to invoke add function in vertex class
    void display_info();//display fire behavior's information(wrapper)

    VertexNode * getVertex(char *);//function used to get vertex' address for building edge list

    void set_surpression(char *, int, int);//function used to set (edit) fire surpression : tools etc.
    
	~Graph();
    int Size;
private:
    bool addEdgeNode(char *, char *, VertexNode *, int);//add edge fuction with arguments to find and add Edge recursivel    void display_info(VertexNode *, int);
    void display_info(VertexNode *, int);//display relative information about fire status
	VertexNode * vertex; //pointer to vertex node
	bool * visited; // a label check visiting


};
//check continue function
bool again();
bool YoN();
