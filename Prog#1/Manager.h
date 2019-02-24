//Name: Jingtao Cheng
//ID: 940067494
//  Manager.h
//This file was used to declare the fire behavior class and IC manager class and their related functions

#include <stdio.h>
#include <iostream>
#include "Dll.h"
#include "TimeCounter.h"

using namespace std;
//Fire_behavior class was used to store the fire status helps to operate it's derived class IC_manager
class Fire_behavior
{
protected:
    int acres;//fire area
    int firelevel;//fire serious level
    int population;//population in this area
    int firetype;//1 for areal. 2 for struct. 3 for wild

public:
    Fire_behavior();//constructor
    //copy constructor
    Fire_behavior(int area, int fire_level, int popu, int fire_type):acres(area), firelevel(fire_level), population(popu), firetype(fire_type){}
    
    void display();//display function
    ~Fire_behavior();//destructor
};
//IC_manager class was biult to manage all the performance of the fire surpression to resist fire
class IC_manager : public Fire_behavior
{
private:
    Fire_surpression tools_support; //object of fire_surpression
    
    TimeCounter currentTime; //a time count object
 
public:
    IC_manager();//constructor
    //copy constructor
    IC_manager(int area, int fire_level, int popu, int fire_type):Fire_behavior(area, fire_level, popu, fire_type){}
    //function was used to pass in the fire status
    void set_info(int area, int fire_level, int pop, int fire_type);
    //function used to edit fire surpression such as: tools
    void edit_surpression(char *, int, int);
    //function used to display such tools and their using status
    void display_surpression();
    //display fire information(status)
    void display_info();
    //function used to alert client based on working time
    void alert();
    //function used to determin the evacuation
    void evacuation();
    //function used to automatic choose proper surpression to against different fire status
    void choose_surpression();
    
    ~IC_manager();//destructor
};


