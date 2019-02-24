//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//Drone.h
//This is the Drone.h file which contains a base class Drone
//and three derived class small_drone class, medium drone class
//and large drone class. Those classed implement three different
//type of drones with different functions

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 20

//This class is the base class of three different derivered class
//they are small_drone, medium_drone, and large_drone class. This
//class contains sevearl information which every basic drone has.
//this class also has a virtual function and virtual destructor.
class Drone
{
protected:
    int longitude;
    int latitude;
    int altitude;
    char * name;
    int type;
public:
    Drone();
    Drone(int,int,int,char *);
    Drone(Drone &);
    virtual ~Drone();
    void virtual active_mode() = 0;
    void move(int,int,int);
    bool compare(char *);
    int check_type();
    bool check_safty(int,int,int,int);
    void display();
};

//This class is the deriver class from drone class
//the difference between it's base class is this class
//has sepcific function which is the racing and exploring
//function
class Small_Drone : public Drone
{
private:

public:
    Small_Drone();
    Small_Drone(int,int,int,char *);
    void active_mode();
};

//This class is the deriver class from drone class
//the difference between it's base class is this class
//has sepcific function which is the photograph and
//research function
class Medium_Drone : public Drone
{
private:

public:
    Medium_Drone();
    Medium_Drone(int,int,int,char *);
    void active_mode();
};

//This class is the deriver class from drone class
//the difference between it's base class is this class
//has sepcific function with is the delivery and crop
//dusting function
class Large_Drone : public Drone
{
private:
    
public:
    Large_Drone();
    Large_Drone(int,int,int,char *);
    void active_mode();
};
