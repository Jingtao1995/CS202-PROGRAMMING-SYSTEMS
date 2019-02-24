//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 3
//
//Sport, Athlete, and Record Class and the Data Structure
//Sport.cpp
//This is the Sport.h file which implement the Sport class, Athlete class
//A_node class which is derived from the Athlete, and R_node class which
//is derived from the Record class.
#include "Sport.h"

//--------------------------------------------------------------
// Implementation of class Sport
//--------------------------------------------------------------

//default constructor to initialize elements
Sport :: Sport()
{
    Name = NULL;
    Detail = NULL;
    Time = NULL;
    Channel = NULL;
    A_head = NULL;
}

//copy constructor to copy from passed in reference
Sport :: Sport(Sport & sport)
{
    Name = new char[strlen(sport.Name)+1];
    strcpy(Name,sport.Name);
    Detail = new char[strlen(sport.Detail)+1];
    strcpy(Detail,sport.Detail);
    Time = new char[strlen(sport.Time)+1];
    strcpy(Time,sport.Time);
    Channel = new char[strlen(sport.Channel)+1];
    strcpy(Channel,sport.Channel);
    
    A_head = NULL;
    //copy_list(A_head, sport.A_head);
}

//copy list function to copy the list of Athlete
void Sport :: copy_list(A_node *& des, A_node * head)
{
    if(!head)
        return;
    else
    {
        des = new A_node(*head);
        return copy_list(des->go_next(), head->go_next());
    }
}

//destructor
Sport :: ~Sport()
{
    delete Name;
    delete Detail;
    delete Time;
    delete Channel;

    remove_all(A_head);
}

//remove_all function to help deallocate all dynamic memory
void Sport :: remove_all(A_node *& head)
{
    if(!head)
        return;
    A_node * temp = head;
    head = head->go_next();
    delete temp;
    temp = NULL;
    return remove_all(head);
}

//insert function for Sport class
bool Sport :: insert(char * name,char * detail,char * time,char * channel)
{
    Name = new char[strlen(name)+1];
    strcpy(Name, name);
    Detail = new char[strlen(detail)+1];
    strcpy(Detail, detail);
    Time = new char[strlen(time)+1];
    strcpy(Time, time);
    Channel = new char[strlen(channel)+1];
    strcpy(Channel, channel);
    
    A_head = NULL;
    return true;
}

//insert athlete by paased in reference
bool Sport :: insert_athlete(Athlete & athlete)
{
    if(A_head)
        return insert_athlete(A_head, athlete);
    else
    {
        A_head = new A_node(athlete);
        return true;
    }
}

//recursive part of the insert athlete function
bool Sport :: insert_athlete(A_node *& head, Athlete & athlete)
{
    A_node * temp = new A_node(athlete);
    temp->set_next(head);
    head = temp;
    return true;
}

//compare the passed in value with the private element
int Sport :: compare(char * name)
{
    return strcmp(this->Name, name);
}

//return name of the Sport object
char * Sport :: get_name()
{
    return Name;
}

//display function of the sport class/object
void Sport :: display()
{
    if(Name != NULL)
    {
        cout<<"Name: "<<this->Name<<endl;
        cout<<"Detail: "<<this->Detail<<endl;
        cout<<"Time: "<<this->Time<<endl;
        cout<<"Channel: "<<this->Channel<<endl;
        cout<<"List all Athletes Below: "<<endl;
    }
    if(A_head != NULL)
        return display(A_head);
}

//recursive part of the display function
void Sport :: display(A_node * head)
{
    if(!head)
        return;
    head->display();
    return display(head->go_next());
}

//operator > overloading to compare the private element of two Sport object
bool Sport :: operator > (Sport & sport)
{
    if(strcmp(this->get_name(), sport.get_name()) >= 0)
        return true;
    else
        return false;
}

//operator += overloading to achieve a insert athlete goal
A_node *& Sport :: operator += (Athlete & athlete)
{
    this->insert_athlete(athlete);
    return A_head;
}

//research function with the passed in value
A_node * Sport :: retrieve(char * name)
{
    if(A_head == NULL)
        return NULL;
    return retrieve(A_head,name);
}

//recursive part of the reseach function
A_node * Sport :: retrieve(A_node * head, char * name)
{
    if(head == NULL)
        return NULL;
    if(head->compare(name))
    {
        return head;
    }
    else
        return retrieve(head->go_next(),name);
}

//--------------------------------------------------------------
// Implementation of Class Athlete
//--------------------------------------------------------------

//default constructor to initialize
Athlete :: Athlete()
{
    Name = NULL;
    Event = NULL;
    medals = 0;
    R_head = NULL;
}

//copy constructor to copy info from passed in object
Athlete :: Athlete(Athlete & athlete)
{
    Name = new char[strlen(athlete.Name)+1];
    strcpy(Name, athlete.Name);
    Event = new char[strlen(athlete.Event)+1];
    strcpy(Event, athlete.Event);
    medals = athlete.medals;

    R_head = NULL;
    //copy_list(R_head, athlete.R_head);
}

//destructor
Athlete :: ~Athlete()
{
    delete Name;
    delete Event;
    remove_all(R_head);
}

//part of destructor ot deallocate dynamic memory
void Athlete :: remove_all(R_node *& head)
{
    if(!head)
        return;
    R_node * temp = head;
    head = head->go_next();
    delete temp;
    temp = NULL;
    return remove_all(head);
}

//insert funtion with 3 arguments
bool Athlete :: insert(char * name, char * event, int m)
{
    Name = new char[strlen(name)+1];
    strcpy(Name, name);
    Event = new char[strlen(event)+1];
    strcpy(Event, event);
    medals = m;
    
    R_head = NULL;
    return true;
}

//insert function with passed in reference
bool Athlete :: insert_record(Record & record)
{   if(R_head == NULL)
    {
        R_head = new R_node(record);
        return true;
    }else
        return insert_record(R_head, record);
}

//insert record recursive part
bool Athlete :: insert_record(R_node *& head, Record & record)
{
    R_node * temp = new R_node(record);
    temp->set_next(head);
    head = temp;
    return true;
}

//compare function to comapre passed in value wiht private elemnt
bool Athlete :: compare(char * name)
{
    if(strcmp(this->Name, name) == 0)
        return true;
    else
        return false;
}

//athlete class's display function
void Athlete :: display()
{
    if(this->Name != NULL)
    {
    cout<<"Name : "<<this->Name<<endl;
    cout<<"Event : "<<this->Event<<endl;
    cout<<"Medals : "<<this->medals<<endl;
    cout<<"Record List :"<<endl;
    }
    if(R_head)
        display_record(R_head);
}

//display function of display record recursively
void Athlete :: display_record(R_node * head)
{
    if(!head)
        return;
    else
    {
        head->display();
        display_record(head->go_next());
    }
}

//copy LLL from passed in list
void Athlete :: copy_list(R_node * head)
{
    return copy_list(R_head, head);
}

//recursive part of copy list 
void Athlete :: copy_list(R_node *&des, R_node *head)
{
    if(!head)
        return;
    des = new R_node(*head);
    return copy_list(des->go_next(), head->go_next());
}

//--------------------------------------------------------------
// Implementation of Class A_node
//--------------------------------------------------------------

//default constructor function
A_node :: A_node()
{
    next = NULL;
}

//copy constructor to call base class's copy conwstructor
A_node :: A_node(Athlete & athlete) : Athlete(athlete)
{
    next = NULL;
}

A_node :: ~A_node()
{}

//function used to get next pointer
A_node *& A_node :: go_next()
{
    return this->next;
}

//funciton used to set next poiter
void A_node :: set_next(A_node * to_set)
{
    this->next = to_set;
}

//--------------------------------------------------------------
// Implementation of Class Record
//--------------------------------------------------------------

//default constructor
Record :: Record()
{
    Medal = NULL;
    Time = NULL;
}

//copy constructor with passed in reference
Record :: Record(Record & record)
{
    Medal = new char[strlen(record.Medal)+1];
    strcpy(this->Medal, record.Medal);
    Time = new char[strlen(record.Time)+1];
    strcpy(this->Time, record.Time);
}

//destructor
Record :: ~Record()
{
    delete Medal;
    delete Time;
}

//insert function of the record class
bool Record :: insert(char * medals, char * time)
{
    Medal = new char[strlen(medals)+1];
    strcpy(this->Medal, medals);
    Time = new char[strlen(time)+1];
    strcpy(this->Time, time);
    return true;
}

//display function of the record class
void Record :: display()
{
    if(this->Medal != NULL)
    {
    cout<<"Medals: "<<this->Medal<<endl;
    cout<<"Time: "<<this->Time<<endl;
    }
}

//--------------------------------------------------------------
// Implementation of Class R_node
//--------------------------------------------------------------
//default constructor
R_node :: R_node()
{
    next = NULL;
}

//copy constructor
R_node :: R_node(Record & record) : Record(record)
{
    next = NULL;
}

//destructor which will not work and the base class's destructor will work instead
R_node :: ~R_node()
{}

//function used to get next pointer
R_node *& R_node :: go_next()
{
    return this->next;
}

//function used to set next pointer
void R_node :: set_next(R_node * to_set)
{
    this->next = to_set;
}
