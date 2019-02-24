//Name: Jingtao Cheng
//ID: 940067494
//Manager.cpp
//This function was created to manage the core function in this program including IC manager and fire behavior

#include "Manager.h"
//constructor
Fire_behavior :: Fire_behavior()
{
}
//desctructor
Fire_behavior :: ~Fire_behavior()
{
}
/*
void Fire_behavior :: set_behavior(int area, int fire_levl, int popl, const char * type)
{
    acres = area;
    firelevel = fire_levl;
    population = popl;
    strcpy(firetype, type);
}
*/
//display function to display private member function
void Fire_behavior :: display()
{
    cout << "Fire acres: " << acres <<endl
    << "Fire level: " << firelevel <<endl
    << "Population in this area: " << population <<endl
    << "Fire type: " << firetype << endl;
}
//construtor
IC_manager :: IC_manager()
{
}
//basic function for passing in area acres and other arguments
void IC_manager :: set_info(int area, int fire_level, int pop, int fire_type)
{
    acres = area;
    firelevel = fire_level;
    population = pop;
    firetype = fire_type;
}

//function was used to modify the surppression and edit or update the tools requirments
void IC_manager :: edit_surpression(char * name, int number, int type)
{
    tools_support.add_tools(name, number, type);
}
//wraper function of display function
void IC_manager :: display_surpression()
{
    tools_support.display_tools(firetype);
}
//Very important information and function which will alert people in any time
void IC_manager :: alert()
{
    if(currentTime.getTime())
    {
        cout << "!!!!!!!!!!!! -ALERT- !!!!!!!!!!!!"<<endl;

        currentTime.printTime();
    }
    currentTime.reset();
}
//function used for evacuation functions
void IC_manager :: evacuation()
{
    if(firelevel > 3)
        cout << "!!!!!!!!!!!! -EVACUATE- !!!!!!!!!!!!"<<endl;
}
//functions used to show the tools and surpression choosing
void IC_manager :: choose_surpression()
{
    cout << " SURPRESSION LIST :"<<endl;
    if(firelevel > 3)
        cout << "Use full surpression support."<<endl;
    display_surpression();
}
//wrapper function
void IC_manager :: display_info()
{
    cout << "Acres: " << acres << endl
    << "Fire level: " << firelevel << endl
    << "Population: " << population << endl;
    cout << "Fire type: ";
    if(firetype == 1)
        cout << "Areal.\n";
    else if(firetype == 2)
        cout << "Structure.\n";
    else if(firetype == 3)
        cout << "Wild.\n";
    else
        cout << "ERROR.\n";
    
    evacuation();
    choose_surpression();
    alert();
}

IC_manager :: ~IC_manager()//desctructor
{
}
