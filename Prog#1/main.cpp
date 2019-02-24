//Name: Jingtao Cheng
//ID: 940067494
//main.cpp
//This file was the main file as an client interface which help client to call the functions and implement the class and other members
//
//
#include "Graph.h"

int main()
{
    do
    {
        
    Graph map(20);
    char * name = new char[10];
    do
    {
        int acres, firelevel, population, firetype = 0;
        cout << " Add Fire Status? "<<endl;
        if(YoN())
        {
        cout << "State Name:    ";
        cin >> name;
        cout << endl << " Fire acres:   ";
        cin >> acres;
        cout << endl << " Fire level (1-5):   ";
        cin >> firelevel;
        cout << endl << " Population in this area:   ";
        cin >> population;
        cout << endl << "Fire type (1.Areal 2.Structual 3.Wild):    ";
        cin >> firetype;
        
        map.addVertex(name, acres, firelevel, population, firetype);
        }else
            break;
    }while (again());
    char * Name = new char[10];
    char * Edge = new char[10];
    cout << "Want to add Edge node?"<<endl;
    if(YoN())
    {
        do{
            cout << "State Name:   ";
            cin >> Name;
            cout << "Edge Name:   ";
            cin >> Edge;
            map.addEdgeNode(Name, Edge);
        }while(again());
    }
    
    char * toolName = new char[10];
    int number = 0;
    int type = 0;
    cout << "Input fire surpression tools? \n";
    if(YoN())
    {
        do
        {
            cout << " Name:   ";
            cin >> toolName;
            cout << " Quantity:   ";
            cin >> number;
            cout << " Tool Type: (1.Areal 2.Structure 3.Wild 4.Common)";
            cin >> type;
            
            map.set_surpression(toolName, number, type);
        }while(again());
    }
    map.display_info();
        
    }while(again());

}
