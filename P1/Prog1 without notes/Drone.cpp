//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//Drone.cpp

#include "Drone.h"

Drone :: Drone()
{
    longitude = 0;
    latitude = 0;
    altitude = 0;
    name = NULL;
    type = 0;
}

Drone :: Drone(int x, int y, int z, char * Name)
{
    longitude = x;
    latitude = y;
    altitude = z;
    name = new char[strlen(Name)+1];
    strcpy(name, Name);
}

Drone :: Drone(Drone & drone)
{
    longitude = drone.longitude;
    latitude = drone.latitude;
    altitude = drone.altitude;
    name = new char[strlen(drone.name)+1];
    strcpy(name,drone.name);
}

Drone :: ~Drone()
{
    delete name;
}

void Drone :: move(int x, int y, int z)
{
    longitude = x;
    latitude = y;
    altitude = z;
}

void Drone :: active_mode()
{
    cout<<" Mode Active! "<<endl;
}

bool Drone :: compare(char * Name)
{
    if(strcmp(name,Name) == 0)
        return true;
    else
        return false;
}

int Drone :: check_type()
{
    return type;
}

bool Drone :: check_safty(int a, int b, int c, int d)
{
    if(longitude>a && longitude<b && latitude>d && latitude<c)
        return false;
    else
        return true;
}

void Drone :: display()
{
    cout<<"Drone:  "<<name<<"  ";
    cout<<"Current GPS Position:"<<endl;
    cout<<"longitude: "<<longitude<<" "<<endl;
    cout<<"latitude: "<<latitude<<" "<<endl;
    cout<<"altitude: "<<altitude<<" "<<endl;
}

Small_Drone :: Small_Drone(): Drone(){
    type = 1;
}

Small_Drone :: Small_Drone(int x, int y, int z, char * Name): Drone(x, y, z, Name){}

void Small_Drone :: active_mode()
{
    cout<<"Racing Mode Active"<<endl;
    cout<<"Exploring Mode Active"<<endl;
}

Medium_Drone :: Medium_Drone(): Drone(){
    type = 2;
}

Medium_Drone :: Medium_Drone(int x, int y, int z, char * Name): Drone(x, y, z, Name){}

void Medium_Drone :: active_mode()
{
    cout<<"Photograph Mode Active"<<endl;
    cout<<"Research Mode Active"<<endl;
}

Large_Drone :: Large_Drone(): Drone(){
    type = 3;
}

Large_Drone :: Large_Drone(int x, int y, int z, char * Name): Drone(x, y, z, Name){}


void Large_Drone :: active_mode()
{
    cout<<"Delivery Mode Active"<<endl;
    cout<<"Crop_dusing Mode Active"<<endl;
}


