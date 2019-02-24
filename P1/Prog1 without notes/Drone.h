//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//Drone.h

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 20

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

class Small_Drone : public Drone
{
private:

public:
    Small_Drone();
    Small_Drone(int,int,int,char *);
    void active_mode();
};

class Medium_Drone : public Drone
{
private:

public:
    Medium_Drone();
    Medium_Drone(int,int,int,char *);
    void active_mode();
};

class Large_Drone : public Drone
{
private:
    
public:
    Large_Drone();
    Large_Drone(int,int,int,char *);
    void active_mode();
};
