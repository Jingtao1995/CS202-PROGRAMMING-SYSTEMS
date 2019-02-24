//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//Drone.cpp

#include "Drone.h"

//This function is the basic and defualt constructor
//to initialize the data stored in the Drone class
Drone :: Drone()
{
    longitude = 0;
    latitude = 0;
    altitude = 0;
    name = NULL;
    type = 0;
}

//This function is a constructor, which can be used to initial
//and assian the value to the those members
Drone :: Drone(int x, int y, int z, char * Name)
{
    longitude = x;
    latitude = y;
    altitude = z;
    name = new char[strlen(Name)+1];
    strcpy(name, Name);
}

//This function is the copy constructor which can copy the
//members more efficiently
Drone :: Drone(Drone & drone)
{
    longitude = drone.longitude;
    latitude = drone.latitude;
    altitude = drone.altitude;
    name = new char[strlen(drone.name)+1];
    strcpy(name,drone.name);
}

//This is the basic destructor
Drone :: ~Drone()
{
    delete name;
}

//This function used to set a new position of the drone
void Drone :: move(int x, int y, int z)
{
    longitude = x;
    latitude = y;
    altitude = z;
}

//This function used to active the specific function of
//each different type of objects
void Drone :: active_mode()
{
    cout<<" Mode Active! "<<endl;
}

//This funciton is used to compare the member passed in
//with the members store in the Drone class
bool Drone :: compare(char * Name)
{
    if(strcmp(name,Name) == 0)
        return true;
    else
        return false;
}

//This function is used to check and return the type of
//the class to ensure the type used want to use is correct
int Drone :: check_type()
{
    return type;
}

//This function is used to check the position of the drone is
//located in a safty are, if not return false to active the
//warning
bool Drone :: check_safty(int a, int b, int c, int d)
{
    if(longitude>a && longitude<b && latitude>d && latitude<c)
        return false;
    else
        return true;
}

//This is the basic display function to display the information
//stored in the Drone class
void Drone :: display()
{
    cout<<"Drone:  "<<name<<"  ";
    cout<<"Current GPS Position:"<<endl;
    cout<<"longitude: "<<longitude<<" "<<endl;
    cout<<"latitude: "<<latitude<<" "<<endl;
    cout<<"altitude: "<<altitude<<" "<<endl;
}

//This is the basic default constructor with initialization list
Small_Drone :: Small_Drone(): Drone(){
    type = 1;
}
//This is the copy constructor of the small drone class with initialization list
Small_Drone :: Small_Drone(int x, int y, int z, char * Name): Drone(x, y, z, Name){}

//This is the overloading function to active different type of functions
void Small_Drone :: active_mode()
{
    cout<<"Racing Mode Active"<<endl;
    cout<<"Exploring Mode Active"<<endl;
}

//This is the default constructor with initialization list
Medium_Drone :: Medium_Drone(): Drone(){
    type = 2;
}

//This is the copy constructor with the initialization list
Medium_Drone :: Medium_Drone(int x, int y, int z, char * Name): Drone(x, y, z, Name){}

//This is the overloading function to active different type of functions
void Medium_Drone :: active_mode()
{
    cout<<"Photograph Mode Active"<<endl;
    cout<<"Research Mode Active"<<endl;
}

//This is the default constructor with initialization list
Large_Drone :: Large_Drone(): Drone(){
    type = 3;
}
//This is the copy constructor with the initialization list
Large_Drone :: Large_Drone(int x, int y, int z, char * Name): Drone(x, y, z, Name){}

//This is the overloading function to active different type of functions
void Large_Drone :: active_mode()
{
    cout<<"Delivery Mode Active"<<endl;
    cout<<"Crop_dusing Mode Active"<<endl;
}


